#include "rm_hardware/engineer_hardware_interface.hpp"
#include <rclcpp/rclcpp.hpp>
#include "rm_hardware/engineer_driver.hpp"
#include <chrono>
#include <thread>

// 命名空间：封装机械臂硬件相关的类和函数
namespace arm_hardware {


// hardware_interface::CallbackReturn ArmHardwareInterface::on_init
//     (const hardware_interface::HardwareInfo & info)
// {

//     return hardware_interface::CallbackReturn::SUCCESS;
// }

hardware_interface::CallbackReturn ArmHardwareInterface::on_configure
    (const rclcpp_lifecycle::State & previous_state)
{
    (void)previous_state;
    DmDriver dm_driver;
    bool has_data = dm_driver.check_joint_state_topic_data();
        
        return has_data ? hardware_interface::CallbackReturn::SUCCESS 
                        : hardware_interface::CallbackReturn::ERROR;
}


hardware_interface::CallbackReturn ArmHardwareInterface::on_activate
    (const rclcpp_lifecycle::State & previous_state)
{

    return hardware_interface::CallbackReturn::SUCCESS;
}


hardware_interface::CallbackReturn ArmHardwareInterface::on_deactivate
    (const rclcpp_lifecycle::State & previous_state)
{

    return hardware_interface::CallbackReturn::SUCCESS;
}


hardware_interface::return_type ArmHardwareInterface::read
    (const rclcpp::Time & time, const rclcpp::Duration & period)
{
    (void)time;
    (void)period;
    // set_state("joint1/position", getPosition(joint1_motor_id_));
    // set_state("joint2/position", getPosition(joint2_motor_id_));
    //卡在这里了，对照文档找不到，所以写完这几个函数后还得去B站进修
    return hardware_interface::return_type::OK;
}


hardware_interface::return_type ArmHardwareInterface::write
    (const rclcpp::Time & time, const rclcpp::Duration & period)
{

    return hardware_interface::return_type::OK;
}

} // namespace arm_hardware


#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(arm_hardware::ArmHardwareInterface, hardware_interface::SystemInterface)
