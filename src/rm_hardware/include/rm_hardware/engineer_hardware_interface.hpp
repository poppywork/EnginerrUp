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

    std::shared_ptr<DMDriver> dm_driver_;

    double hw_states_position1_;
    double hw_states_velocity1_;
    double hw_commands_position1_;

    double hw_states_position2_;
    double hw_states_velocity2_;
    double hw_commands_position2_;

    double hw_states_position3_;
    double hw_states_velocity3_;
    double hw_commands_position3_;

    double hw_states_position4_;
    double hw_states_velocity4_;
    double hw_commands_position4_;

    double hw_states_position5_;
    double hw_states_velocity5_;
    double hw_commands_position5_;

    double hw_states_position6_;
    double hw_states_velocity6_;
    double hw_commands_position6_;

    double hw_states_gripper_;
    double hw_commands_gripper_;

}; 

} 

#endif 
