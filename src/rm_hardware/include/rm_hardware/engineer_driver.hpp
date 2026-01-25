#ifndef MY_ENGINEER_DRIVER_HPP
#define MY_ENGINEER_DRIVER_HPP
#include <rclcpp/rclcpp.hpp>
#include "rmctrl_msgs/msg/arm_state_data.hpp"
#include <chrono>
#include <thread>
#include "rmctrl_msgs/msg/arm_ctrl_data.hpp"

#define JOINT_NUM 6 //关节数量


class DMDriver {
    public:
    DMDriver() 
    {
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


    std::vector<double> getPosition(void)
    {
        std::lock_guard<std::mutex> lock(joint_mutex_);
        std::vector<double> pos_array(JOINT_NUM);
        for (int i = 0; i < JOINT_NUM; i++) {
            pos_array[i] = joint_positions_[i];
        }
        return pos_array;
    }
    
    
        /**
         * @brief 设置目标位置（弧度单位）和夹爪控制命令
         * @param dxl_id 目标舵机的ID号
         * @param command 目标位置（弧度）
         */
    void setTargetPositionRadian(double joint_position_cmd_array[6],double gripper_ctrl) 
    {
        rmctrl_msgs::msg::ArmCtrlData pub_moveit2_arm_cmd_to_nuc_msg;

        pub_moveit2_arm_cmd_to_nuc_msg.joint1_position = joint_position_cmd_array[0];
        pub_moveit2_arm_cmd_to_nuc_msg.joint2_position = joint_position_cmd_array[1];
        pub_moveit2_arm_cmd_to_nuc_msg.joint3_position = joint_position_cmd_array[2];
        pub_moveit2_arm_cmd_to_nuc_msg.joint4_position = joint_position_cmd_array[3];
        pub_moveit2_arm_cmd_to_nuc_msg.joint5_position = joint_position_cmd_array[4];
        pub_moveit2_arm_cmd_to_nuc_msg.joint6_position = joint_position_cmd_array[5];
        pub_moveit2_arm_cmd_to_nuc_msg.gripper_ctrl = (int8_t)gripper_ctrl;//告诉下位机要控制的夹爪cmd
        pub_moveit2_arm_cmd_to_nuc_msg.auto_state = (int8_t)auto_state_nuc_;//告诉下位机收到开启一键夹取的cmd
        pub_moveit2_arm_cmd_to_nuc_->publish(pub_moveit2_arm_cmd_to_nuc_msg);
    }

    int8_t getGripperState(void) 
    {
        std::lock_guard<std::mutex> lock(joint_mutex_);
        return gripper_state_;
    }
    
    int getActiveCmd(void)
    {
        return auto_state_mcu_;
    }

    void set_auto_state_nuc(int set_state)
    {
        if(set_state == 1)
        {
            auto_state_nuc_ = 1;
        }
        else if(set_state == 0)
        {
            auto_state_nuc_ = 0;
        }
        else
        {
            RCLCPP_ERROR(node_->get_logger(), "设置auto_state_nuc的值不合法");
        }
    }
    private:

    rclcpp::Node::SharedPtr node_;
    std::thread sub_thread_;
    bool stop_sub_ = false;
    rclcpp::Publisher<rmctrl_msgs::msg::ArmCtrlData>::SharedPtr pub_moveit2_arm_cmd_to_nuc_;
    int8_t auto_state_mcu_;//下位机通过这个变量控制上位机开启自动抓取
    int8_t auto_state_nuc_;//上位机通过这个变量证明自己开始计算，将这个变量传给下位机形成闭环
    int8_t gripper_state_ = 0;                      // 记录夹爪状态
    double joint_positions_[JOINT_NUM] = {0.0f};  // 关节位置数组（6个元素）
    double joint_velocities_[JOINT_NUM] = {0.0f}; // 关节速度数组（6个元素）
    std::mutex joint_mutex_;//互斥锁，避免主线程读取时拿到 “半更新” 的脏数据


    void start_sub_thread() 
    {
            sub_thread_ = std::thread([this]() {//后台线程不断订阅机械臂数据
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
                    //只是读取，上位机通过这个变量读取夹爪状态闭环发送控制夹爪命令
                    gripper_state_ = msg->gripper_state;//上控下
                    //只是控制，下位机通过改变这个状态控制上位机开始一键抓取
                    auto_state_mcu_ = msg->auto_state;//下控上
                });

            // 持续处理话题回调
            while (rclcpp::ok() && !stop_sub_) 
            {
                rclcpp::spin_some(node_);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
            sub.reset();
            RCLCPP_INFO(node_->get_logger(), "订阅线程回调处理结束");
        });
    }
};

#endif
