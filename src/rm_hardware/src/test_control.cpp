#include "rm_hardware/engineer_driver.hpp"  
#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <thread>

int main(int argc, char *argv[]) {
    // 1. 初始化 ROS 2（全局唯一初始化）
    rclcpp::init(argc, argv);
    std::cout << "=== ROS 2 初始化完成 ===" << std::endl;

    // 2. 创建驱动实例
    DMDriver dm_driver;
    std::cout << "=== 机械臂驱动实例创建完成 ===" << std::endl;

    // 3. 检查下位机话题连通性
    std::cout << "=== 检查下位机话题连通性（超时1秒）===" << std::endl;
    bool is_connected = dm_driver.check_joint_state_topic_data(1.0);
    if (!is_connected) {
        std::cout << "警告：未检测到下位机数据，请检查连接！" << std::endl;
    }

    // 4. 读取并打印关节位置（等待数据接收）
    std::cout << "=== 读取关节位置 ===" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 等待数据接收
    std::vector<double> pos_array = dm_driver.getPosition();
    
    std::cout << "关节位置（弧度）：";
    for (size_t i = 0; i < pos_array.size(); i++) {
        std::cout << "J" << (i+1) << "=" << std::fixed << std::setprecision(3) << pos_array[i] << " ";
    }
    std::cout << std::endl;

    // 5. 测试发送控制指令
    std::cout << "=== 测试发送关节控制指令 ===" << std::endl;
    double target_joints[6] = {0.5, 0.1, 0.2, 0.2, 0.1, 0.4}; // 示例目标位置
    int8_t gripper_ctrl = 1; // 夹爪控制指令
    dm_driver.setTargetPositionRadian(target_joints, gripper_ctrl);

    // 6. 测试设置自动状态
    std::cout << "=== 测试设置自动状态 ===" << std::endl;
    dm_driver.set_auto_state_nuc(1); // 开启自动抓取

    // 7. 清理资源
    rclcpp::shutdown();
    std::cout << "=== 测试程序已退出 ===" << std::endl;

    return 0;
}