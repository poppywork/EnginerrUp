#ifndef MY_ENGINEER_DRIVER_HPP
#define MY_ENGINEER_DRIVER_HPP
#include <rclcpp/rclcpp.hpp>
#include "rmctrl_msgs/msg/arm_state_data.hpp"
#include <chrono>
#include <thread>
#include <mutex>
#include "rmctrl_msgs/msg/arm_ctrl_data.hpp"

#define JOINT_NUM 6 //关节数量

class DMDriver {
public:
    // 构造函数：移除重复的ROS初始化，由外部统一初始化
    DMDriver() 
    {
        // 初始化成员变量，避免野值
        auto_state_mcu_ = 0;
        auto_state_nuc_ = 0;
        gripper_state_ = 0;
        // 初始化关节数据数组
        for (int i = 0; i < JOINT_NUM; i++) {
            joint_positions_[i] = 0.0;
            joint_velocities_[i] = 0.0;
        }

        // 创建节点（用于订阅/发布话题）
        node_ = std::make_shared<rclcpp::Node>("dm_driver_node");
        if (!node_) {
            RCLCPP_ERROR(rclcpp::get_logger("DMDriver"), "驱动节点创建失败！");
            return;
        }

        // 创建发布者：发布arm控制命令给上位机中转处再通过串口发给下位机
        pub_moveit2_arm_cmd_to_nuc_ = node_->create_publisher<rmctrl_msgs::msg::ArmCtrlData>(
            "joint_cmd_from_moveit2", 
            rclcpp::QoS(10)
        );
        if (!pub_moveit2_arm_cmd_to_nuc_) {
            RCLCPP_ERROR(node_->get_logger(), "发布者未初始化，无法发布关节指令！");
            return;
        }

        // 启动话题订阅线程（后台持续接收数据）
        start_sub_thread();
        RCLCPP_INFO(node_->get_logger(), "DMDriver驱动初始化完成");
    }

    // 析构函数：确保线程正确退出和资源释放
    ~DMDriver() {
        stop_sub_ = true;
        // 等待订阅线程退出
        if (sub_thread_.joinable()) {
            sub_thread_.join();
        }
        // 释放ROS资源
        pub_moveit2_arm_cmd_to_nuc_.reset();
        node_.reset();
        RCLCPP_INFO(rclcpp::get_logger("DMDriver"), "DMDriver驱动已销毁");
    }

    /**
     * @brief 检查关节状态话题是否有数据
     * @param timeout_sec 超时时间（秒）
     * @return 是否成功接收到数据
     */
    bool check_joint_state_topic_data(double timeout_sec = 1.0)
    {
        // 1. 检查ROS是否初始化
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("DMDriver"), "ROS2没有初始化");
            return false;
        }

        // 2. 创建独立的临时节点（隔离参数，避免冲突）
        auto temp_node = std::make_shared<rclcpp::Node>(
            "temp_joint_state_check_node",
            rclcpp::NodeOptions().use_global_arguments(false)
        );
        if (!temp_node) {
            RCLCPP_ERROR(rclcpp::get_logger("DMDriver"), "临时节点创建失败!");
            return false;
        }

        bool has_data = false;
        // 3. 创建订阅器
        auto sub = temp_node->create_subscription<rmctrl_msgs::msg::ArmStateData>(
            "/joint_state_sub_from_mcu",
            rclcpp::QoS(10),
            [&has_data](const rmctrl_msgs::msg::ArmStateData::SharedPtr /*msg*/) { 
                has_data = true; 
            }
        );

        // 4. 超时检测逻辑
        const auto start_time = temp_node->now();
        while (rclcpp::ok()) {
            // 检查超时
            const double elapsed = (temp_node->now() - start_time).seconds();
            if (elapsed >= timeout_sec) {
                RCLCPP_WARN(temp_node->get_logger(), "话题检查超时 (%.2fs)", elapsed);
                break;
            }
            // 处理回调
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

    /**
     * @brief 获取当前关节位置（弧度）
     * @return 6个关节的位置数组
     */
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
     * @param joint_position_cmd_array 6个关节的目标位置（弧度）数组
     * @param gripper_ctrl 夹爪控制指令
     */
    void setTargetPositionRadian(double joint_position_cmd_array[6], int8_t gripper_ctrl) 
    {
        if (!pub_moveit2_arm_cmd_to_nuc_) {
            RCLCPP_ERROR(node_->get_logger(), "发布者未初始化，无法发送控制指令！");
            return;
        }

        rmctrl_msgs::msg::ArmCtrlData pub_moveit2_arm_cmd_to_nuc_msg;

        pub_moveit2_arm_cmd_to_nuc_msg.joint1_position = joint_position_cmd_array[0];
        pub_moveit2_arm_cmd_to_nuc_msg.joint2_position = joint_position_cmd_array[1];
        pub_moveit2_arm_cmd_to_nuc_msg.joint3_position = joint_position_cmd_array[2];
        pub_moveit2_arm_cmd_to_nuc_msg.joint4_position = joint_position_cmd_array[3];
        pub_moveit2_arm_cmd_to_nuc_msg.joint5_position = joint_position_cmd_array[4];
        pub_moveit2_arm_cmd_to_nuc_msg.joint6_position = joint_position_cmd_array[5];
        pub_moveit2_arm_cmd_to_nuc_msg.gripper_ctrl = gripper_ctrl;
        pub_moveit2_arm_cmd_to_nuc_msg.auto_state = auto_state_nuc_;

        // 发布控制指令
        pub_moveit2_arm_cmd_to_nuc_->publish(pub_moveit2_arm_cmd_to_nuc_msg);
        RCLCPP_DEBUG(node_->get_logger(), "已发布关节控制指令：J1=%.3f, J2=%.3f, J3=%.3f, J4=%.3f, J5=%.3f, J6=%.3f, 夹爪=%d, 自动状态=%d",
            joint_position_cmd_array[0], joint_position_cmd_array[1], joint_position_cmd_array[2],
            joint_position_cmd_array[3], joint_position_cmd_array[4], joint_position_cmd_array[5],
            pub_moveit2_arm_cmd_to_nuc_msg.gripper_ctrl, pub_moveit2_arm_cmd_to_nuc_msg.auto_state);
    }

    /**
     * @brief 获取当前夹爪状态
     * @return 夹爪状态值
     */
    int8_t getGripperState(void) 
    {
        std::lock_guard<std::mutex> lock(joint_mutex_);
        return gripper_state_;
    }
    
    /**
     * @brief 获取下位机发送的自动抓取指令
     * @return 自动抓取状态
     */
    int getActiveCmd(void)
    {
        std::lock_guard<std::mutex> lock(joint_mutex_);
        return auto_state_mcu_;
    }

    /**
     * @brief 设置上位机自动状态（给下位机的闭环反馈）
     * @param set_state 0=关闭，1=开启
     */
    void set_auto_state_nuc(int set_state)
    {
        std::lock_guard<std::mutex> lock(joint_mutex_);
        if (set_state == 1) {
            auto_state_nuc_ = 1;
            RCLCPP_INFO(node_->get_logger(), "自动状态已设置为：开启");
        } else if (set_state == 0) {
            auto_state_nuc_ = 0;
            RCLCPP_INFO(node_->get_logger(), "自动状态已设置为：关闭");
        } else {
            RCLCPP_ERROR(node_->get_logger(), "设置auto_state_nuc的值不合法！仅支持0或1");
        }
    }

private:
    rclcpp::Node::SharedPtr node_;
    std::thread sub_thread_;
    bool stop_sub_ = false;
    rclcpp::Publisher<rmctrl_msgs::msg::ArmCtrlData>::SharedPtr pub_moveit2_arm_cmd_to_nuc_;
    
    // 线程安全的成员变量（读写都需要加锁）
    int8_t auto_state_mcu_;       // 下位机控制上位机的自动抓取指令
    int8_t auto_state_nuc_;       // 上位机反馈给下位机的自动状态
    int8_t gripper_state_;        // 夹爪状态
    double joint_positions_[JOINT_NUM];  // 关节位置数组（弧度）
    double joint_velocities_[JOINT_NUM]; // 关节速度数组
    std::mutex joint_mutex_;      // 互斥锁：保护上述共享数据

    /**
     * @brief 启动订阅线程（后台持续接收下位机数据）
     */
    void start_sub_thread() 
    {
        sub_thread_ = std::thread([this]() {
            RCLCPP_INFO(node_->get_logger(), "开始订阅机械臂状态话题：/joint_state_sub_from_mcu");
            
            // 创建订阅器
            auto sub = node_->create_subscription<rmctrl_msgs::msg::ArmStateData>(
                "/joint_state_sub_from_mcu", 
                rclcpp::QoS(10),
                [this](const rmctrl_msgs::msg::ArmStateData::SharedPtr msg) {
                    // 加锁保护共享数据，避免数据竞争
                    std::lock_guard<std::mutex> lock(joint_mutex_);
                    
                    // 更新关节位置
                    joint_positions_[0] = msg->joint1_position;
                    joint_positions_[1] = msg->joint2_position;
                    joint_positions_[2] = msg->joint3_position;
                    joint_positions_[3] = msg->joint4_position;
                    joint_positions_[4] = msg->joint5_position;
                    joint_positions_[5] = msg->joint6_position;

                    // 更新关节速度
                    joint_velocities_[0] = msg->joint1_velocity;
                    joint_velocities_[1] = msg->joint2_velocity;
                    joint_velocities_[2] = msg->joint3_velocity;
                    joint_velocities_[3] = msg->joint4_velocity;
                    joint_velocities_[4] = msg->joint5_velocity;
                    joint_velocities_[5] = msg->joint6_velocity;

                    // 更新夹爪状态和自动指令
                    gripper_state_ = msg->gripper_state;
                    auto_state_mcu_ = msg->auto_state;

                }
            );

            // 持续处理回调
            while (rclcpp::ok() && !stop_sub_) {
                rclcpp::spin_some(node_);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }

            // 释放订阅器
            sub.reset();
            RCLCPP_INFO(node_->get_logger(), "订阅线程已退出");
        });
    }
};

#endif