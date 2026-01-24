#ifndef ENGINEER_HARDWARE_INTERFACE_HPP
#define ENGINEER_HARDWARE_INTERFACE_HPP

#include "hardware_interface/system_interface.hpp"
#include "rm_hardware/engineer_driver.hpp"

namespace arm_hardware {


class ArmHardwareInterface : public hardware_interface::SystemInterface
{
public:

    hardware_interface::CallbackReturn
        on_configure(const rclcpp_lifecycle::State & previous_state) override;

    hardware_interface::CallbackReturn
        on_activate(const rclcpp_lifecycle::State & previous_state) override;

    hardware_interface::CallbackReturn
        on_deactivate(const rclcpp_lifecycle::State & previous_state) override;

    hardware_interface::CallbackReturn
        on_init(const hardware_interface::HardwareInfo & info) override;

    hardware_interface::return_type
        read(const rclcpp::Time & time, const rclcpp::Duration & period) override;

    hardware_interface::return_type
        write(const rclcpp::Time & time, const rclcpp::Duration & period) override;

    std::vector<hardware_interface::StateInterface> export_state_interfaces() override;
    std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

private:

    int joint1_motor_id_;
    int joint2_motor_id_;
    int joint3_motor_id_;
    int joint4_motor_id_;
    int joint5_motor_id_;
    int joint6_motor_id_;


}; 

} 

#endif 
