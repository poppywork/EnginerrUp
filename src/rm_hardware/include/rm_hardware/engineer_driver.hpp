#ifndef MY_ENGINEER_DRIVER_HPP
#define MY_ENGINEER_DRIVER_HPP
#include <rclcpp/rclcpp.hpp>
#include "rmctrl_msgs/msg/arm_state_data.hpp"
#include <chrono>
#include <thread>
#include "rmctrl_msgs/msg/arm_ctrl_data.hpp"

#define JOINT_NUM 6 //关节数量


class DmDriver {
    public:
    DmDriver() {
        // 初始化ROS 2上下文（确保节点能创建）
        if (!rclcpp::ok()) {
            rclcpp::init(0, nullptr);
        }
        // 创建节点（用于订阅话题）
        node_ = std::make_shared<rclcpp::Node>("dm_driver_node");
        //创建发布者发布arm控制命令给上位机中转处再通过串口发给下位机
        pub_moveit2_arm_cmd_to_nuc_ = node_->create_publisher<rmctrl_msgs::msg::ArmCtrlData>("joint_cmd_from_moveit2",10);
        if (!pub_moveit2_arm_cmd_to_nuc_)
        {
            RCLCPP_ERROR(node_->get_logger(), "发布者未初始化，无法发布关节指令！");
            return;
        }
        // 启动话题订阅线程（后台持续接收数据）
        start_sub_thread();
    }


    bool check_joint_state_topic_data(double timeout_sec = 1.0)
    {
        
        // 1. 检查ROS是否初始化
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("DmDriver"), "ROS2没有初始化");
            return false;
        }

        // 2. 创建独立的临时节点
        auto temp_node = std::make_shared<rclcpp::Node>(
            "temp_joint_state_check_node",
            rclcpp::NodeOptions().use_global_arguments(false)  // 隔离参数，避免冲突
        );
        if (!temp_node) {
            RCLCPP_ERROR(rclcpp::get_logger("DmDriver"), "临时节点没有创建成功!");
            return false;
        }

        bool has_data = false;
        // 3. 创建订阅器（使用临时节点）
        auto sub = temp_node->create_subscription<rmctrl_msgs::msg::ArmStateData>(
            "/joint_state_sub_from_mcu",
            rclcpp::QoS(10),
            [&has_data](const rmctrl_msgs::msg::ArmStateData::SharedPtr /*msg*/) { 
                has_data = true; 
            });

        // 4. 超时检测逻辑
        const auto start_time = temp_node->now();
        while (rclcpp::ok()) {
            // 检查超时
            const double elapsed = (temp_node->now() - start_time).seconds();
            if (elapsed >= timeout_sec) {
                RCLCPP_WARN(temp_node->get_logger(), "话题检查超时 (%.2fs)", elapsed);
                break;
            }
            // 处理回调（必须调用）
            rclcpp::spin_some(temp_node);
            // 收到数据立即退出
            if (has_data) {
                RCLCPP_INFO(temp_node->get_logger(), "接收到下位机发来的机械臂数据");
                break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        // 5. 清理临时节点
        sub.reset();
        temp_node.reset();

        return has_data;
    }  


    float getPosition(int id) 
    {
        if (id < 1 || id > JOINT_NUM) {
            RCLCPP_WARN(node_->get_logger(), "无效的关节ID:%d, 有效范围1-%d,返回0.0", id, JOINT_NUM);
            return 0.0f;
        }

        // 加锁保证线程安全（后台线程写，主线程读）
        std::lock_guard<std::mutex> lock(joint_mutex_);
        return joint_positions_[id-1]; // 数组索引从0开始，ID从1开始
    }
    
    
        /**
         * @brief 设置目标位置（弧度单位）和夹爪控制命令
         * @param dxl_id 目标舵机的ID号
         * @param command 目标位置（弧度）
         */
    void setTargetPositionRadian(float joint_position_cmd_array[6],int gripper_ctrl) 
    {
        rmctrl_msgs::msg::ArmCtrlData pub_moveit2_arm_cmd_to_nuc_msg;

        pub_moveit2_arm_cmd_to_nuc_msg.joint1_position = joint_position_cmd_array[0];
        pub_moveit2_arm_cmd_to_nuc_msg.joint2_position = joint_position_cmd_array[1];
        pub_moveit2_arm_cmd_to_nuc_msg.joint3_position = joint_position_cmd_array[2];
        pub_moveit2_arm_cmd_to_nuc_msg.joint4_position = joint_position_cmd_array[3];
        pub_moveit2_arm_cmd_to_nuc_msg.joint5_position = joint_position_cmd_array[4];
        pub_moveit2_arm_cmd_to_nuc_msg.joint6_position = joint_position_cmd_array[5];
        pub_moveit2_arm_cmd_to_nuc_msg.gripper_ctrl = gripper_ctrl;
        pub_moveit2_arm_cmd_to_nuc_msg.auto_state = auto_state_nuc_;
        pub_moveit2_arm_cmd_to_nuc_->publish(pub_moveit2_arm_cmd_to_nuc_msg);
    }

    int getGripperState() 
    {
        std::lock_guard<std::mutex> lock(joint_mutex_);
        return gripper_state_;
    }
    
    private:

    rclcpp::Node::SharedPtr node_;
    std::thread sub_thread_;
    bool stop_sub_ = false;
    rclcpp::Publisher<rmctrl_msgs::msg::ArmCtrlData>::SharedPtr pub_moveit2_arm_cmd_to_nuc_;
    int auto_state_mcu_;//下位机通过这个变量控制上位机开启自动抓取
    int auto_state_nuc_;//上位机通过这个变量证明自己开始计算，将这个变量传给下位机形成闭环

    float joint_positions_[JOINT_NUM] = {0.0f};  // 关节位置数组（6个元素）
    float joint_velocities_[JOINT_NUM] = {0.0f}; // 关节速度数组（6个元素）
    int gripper_state_ = 0;                      // 夹爪状态
    std::mutex joint_mutex_;

    void start_sub_thread() {
        sub_thread_ = std::thread([this]() {
            // 订阅/joint_state_sub_from_mcu话题
            auto sub = node_->create_subscription<rmctrl_msgs::msg::ArmStateData>(
                "/joint_state_sub_from_mcu", rclcpp::QoS(10),
                [this](const rmctrl_msgs::msg::ArmStateData::SharedPtr msg) {
                    joint_positions_[0] = msg->joint1_position;
                    joint_positions_[1] = msg->joint2_position;
                    joint_positions_[2] = msg->joint3_position;
                    joint_positions_[3] = msg->joint4_position;
                    joint_positions_[4] = msg->joint5_position;
                    joint_positions_[5] = msg->joint6_position;

                    joint_velocities_[0] = msg->joint1_velocity;
                    joint_velocities_[1] = msg->joint2_velocity;
                    joint_velocities_[2] = msg->joint3_velocity;
                    joint_velocities_[3] = msg->joint4_velocity;
                    joint_velocities_[4] = msg->joint5_velocity;
                    joint_velocities_[5] = msg->joint6_velocity;

                    gripper_state_ = msg->gripper_state;
                    auto_state_mcu_ = msg->auto_state;
                });

            // 持续处理话题回调
            while (rclcpp::ok() && !stop_sub_) {
                rclcpp::spin_some(node_);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
            sub.reset();
            RCLCPP_INFO(node_->get_logger(), "订阅线程回调处理结束");
        });
    }
};

#endif
