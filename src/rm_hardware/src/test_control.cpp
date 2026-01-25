#include "rm_hardware/engineer_driver.hpp"
#include <iostream>
#include <vector>
#include <iomanip>  // 用于格式化输出

int main(int argc, char *argv[]) {
    // 初始化 ROS 2
    rclcpp::init(argc, argv);
    std::cout << "ROS 2 初始化完成，创建机械臂驱动实例..." << std::endl;

    // 创建驱动实例
    DMDriver dm_driver;
    int a  = dm_driver.check_joint_state_topic_data();
    std::cout<<"a="<<a<<std::endl;   
    rclcpp::shutdown();
    std::cout << "测试程序已退出！" << std::endl;
    return 0;
}
