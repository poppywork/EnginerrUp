#ifndef MY_ENGINEER_DRIVER_HPP
#define MY_ENGINEER_DRIVER_HPP
#include <rclcpp/rclcpp.hpp>
#include "rmctrl_msgs/msg/arm_state_data.hpp"
#include <chrono>
#include <thread>
#include "rmctrl_msgs/msg/arm_ctrl_data.hpp"
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
        switch (id) 
        {
        case 1:
            return joint1_position;
        case 2:
            return joint2_position;
        case 3:
            return joint3_position;
        case 4:
            return joint4_position;
        case 5:
            return joint5_position;
        case 6:
            return joint6_position;
        default:
            RCLCPP_WARN(rclcpp::get_logger("ArmData"), "无效的关节ID:%d,返回0.0", id);
            return 0.0f;
        }
    }
    
        /**
         * @brief 设置目标位置（弧度单位）
         * @param dxl_id 目标舵机的ID号
         * @param command 目标位置（弧度）
         */
    void setTargetPositionRadian(float joint_position_cmd_array[6]) 
    {
        rmctrl_msgs::msg::ArmCtrlData pub_moveit2_arm_cmd_to_nuc_msg;

        pub_moveit2_arm_cmd_to_nuc_msg.joint1_position = joint_position_cmd_array[0];
        pub_moveit2_arm_cmd_to_nuc_msg.joint2_position = joint_position_cmd_array[1];
        pub_moveit2_arm_cmd_to_nuc_msg.joint3_position = joint_position_cmd_array[2];
        pub_moveit2_arm_cmd_to_nuc_msg.joint4_position = joint_position_cmd_array[3];
        pub_moveit2_arm_cmd_to_nuc_msg.joint5_position = joint_position_cmd_array[4];
        pub_moveit2_arm_cmd_to_nuc_msg.joint6_position = joint_position_cmd_array[5];

        pub_moveit2_arm_cmd_to_nuc_->publish(pub_moveit2_arm_cmd_to_nuc_msg);
    }
    
    private:

    rclcpp::Node::SharedPtr node_;
    std::thread sub_thread_;
    bool stop_sub_ = false;
    rclcpp::Publisher<rmctrl_msgs::msg::ArmCtrlData>::SharedPtr pub_moveit2_arm_cmd_to_nuc_;
    
    float joint1_position=0.0f;
    float joint2_position=0.0f;
    float joint3_position=0.0f;
    float joint4_position=0.0f;
    float joint5_position=0.0f;
    float joint6_position=0.0f;

    float joint1_velocity=0.0f;
    float joint2_velocity=0.0f;
    float joint3_velocity=0.0f;
    float joint4_velocity=0.0f;
    float joint5_velocity=0.0f;
    float joint6_velocity=0.0f;

    int gripper_state =0;

    void start_sub_thread() {
        sub_thread_ = std::thread([this]() {
            // 订阅/joint_state_sub_from_mcu话题
            auto sub = node_->create_subscription<rmctrl_msgs::msg::ArmStateData>(
                "/joint_state_sub_from_mcu", rclcpp::QoS(10),
                [this](const rmctrl_msgs::msg::ArmStateData::SharedPtr msg) {
                    joint1_position = msg->joint1_position;
                    joint2_position = msg->joint2_position;
                    joint3_position = msg->joint3_position;
                    joint4_position = msg->joint4_position;
                    joint5_position = msg->joint5_position;
                    joint6_position = msg->joint6_position;

                    joint1_velocity = msg->joint1_velocity;
                    joint2_velocity = msg->joint2_velocity;
                    joint3_velocity = msg->joint3_velocity;
                    joint4_velocity = msg->joint4_velocity;
                    joint5_velocity = msg->joint5_velocity;
                    joint6_velocity = msg->joint6_velocity;

                    gripper_state = msg->gripper_state;
                });

            // 持续处理话题回调
            while (rclcpp::ok() && !stop_sub_) {
                rclcpp::spin_some(node_);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        });
    }

};

#endif
