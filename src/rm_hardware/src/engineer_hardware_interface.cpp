#include <rclcpp/rclcpp.hpp>
#include "rm_hardware/engineer_hardware_interface.hpp"
#include "rm_hardware/engineer_driver.hpp"
#include <chrono>
#include <thread>
#include <vector>
#include <cstdint>
// 命名空间：封装机械臂硬件相关的类和函数
namespace arm_hardware {


hardware_interface::CallbackReturn ArmHardwareInterface::on_init
    (const hardware_interface::HardwareInfo & info)
{
    (void)info;//消除WARN

    if(hardware_interface::SystemInterface::on_init(info) != hardware_interface::CallbackReturn::SUCCESS)
    {
        return hardware_interface::CallbackReturn::ERROR;
    }
    info_ = info;

    dm_driver_ = std::make_shared<DMDriver>();

    
    hw_states_position1_ = 0.0;
    hw_states_velocity1_ = 0.0;
    hw_commands_position1_ = 0.0;

    hw_states_position2_ = 0.0;
    hw_states_velocity2_ = 0.0;
    hw_commands_position2_ = 0.0;

    hw_states_position3_ = 0.0;
    hw_states_velocity3_ = 0.0;
    hw_commands_position3_ = 0.0;

    hw_states_position4_ = 0.0;
    hw_states_velocity4_ = 0.0;
    hw_commands_position4_ = 0.0;

    hw_states_position5_ = 0.0;
    hw_states_velocity5_ = 0.0;
    hw_commands_position5_ = 0.0;

    hw_states_position6_ = 0.0;
    hw_states_velocity6_ = 0.0;
    hw_commands_position6_ = 0.0;

    hw_states_gripper_ = 0.0;
    hw_commands_gripper_ = 0.0;

    return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn ArmHardwareInterface::on_configure
    (const rclcpp_lifecycle::State & previous_state)
{
    (void)previous_state;
    bool has_data = dm_driver_->check_joint_state_topic_data();
        
        return has_data ? hardware_interface::CallbackReturn::SUCCESS 
                        : hardware_interface::CallbackReturn::ERROR;
}


hardware_interface::CallbackReturn ArmHardwareInterface::on_activate
    (const rclcpp_lifecycle::State & previous_state)
{
    (void)previous_state;
    if(dm_driver_->getActiveCmd() == 1)
    {
        dm_driver_->set_auto_state_nuc(1);//向下位机发送数据，告诉上位机收到指令
        return hardware_interface::CallbackReturn::SUCCESS;        
    }
    else
    {
        return hardware_interface::CallbackReturn::ERROR;        
    }

}


hardware_interface::CallbackReturn ArmHardwareInterface::on_deactivate
    (const rclcpp_lifecycle::State & previous_state)
{
    (void)previous_state;

    if(dm_driver_->getActiveCmd() == 0)
    {
        dm_driver_->set_auto_state_nuc(0);//向下位机发送数据，告诉上位机收到指令
        return hardware_interface::CallbackReturn::SUCCESS;        
    }
    else
    {
        return hardware_interface::CallbackReturn::ERROR;        
    }
}


hardware_interface::return_type ArmHardwareInterface::read
    (const rclcpp::Time & time, const rclcpp::Duration & period)
{
    (void)time;
    (void)period;
    std::vector<double> joint_pos(JOINT_NUM);

    joint_pos = dm_driver_->getPosition();

    hw_states_position1_ = joint_pos[0];//hw_states_position1_已被指针所指，改变自动会传入
    hw_states_position2_ = joint_pos[1];
    hw_states_position3_ = joint_pos[2];
    hw_states_position4_ = joint_pos[3];
    hw_states_position5_ = joint_pos[4];
    hw_states_position6_ = joint_pos[5];

    int8_t gripper_state = dm_driver_->getGripperState();
    hw_states_gripper_ = gripper_state;

    return hardware_interface::return_type::OK;
}


hardware_interface::return_type ArmHardwareInterface::write
    (const rclcpp::Time & time, const rclcpp::Duration & period)
{
    (void)time;
    (void)period;
    double joint_pos_ctrl[6];
    int8_t gripper_ctrl;
    joint_pos_ctrl[0] = hw_commands_position1_;
    joint_pos_ctrl[1] = hw_commands_position2_;
    joint_pos_ctrl[2] = hw_commands_position3_;
    joint_pos_ctrl[3] = hw_commands_position4_;
    joint_pos_ctrl[4] = hw_commands_position5_;
    joint_pos_ctrl[5] = hw_commands_position6_;

    if(hw_commands_gripper_ > 0.5)//double向int的转换，防止0.9999999变成0
    {
        gripper_ctrl = 1;
    }
    else
    {
        gripper_ctrl = 0;
    }
    dm_driver_->setTargetPositionRadian(joint_pos_ctrl,gripper_ctrl);
    return hardware_interface::return_type::OK;
}

std::vector<hardware_interface::StateInterface> ArmHardwareInterface::export_state_interfaces()
{
    std::vector<hardware_interface::StateInterface> state_interfaces;

    state_interfaces.emplace_back(
        hardware_interface::StateInterface("arm_joint1", "position", &hw_states_position1_));

    state_interfaces.emplace_back(
        hardware_interface::StateInterface("arm_joint2", "position", &hw_states_position2_));

    state_interfaces.emplace_back(
        hardware_interface::StateInterface("arm_joint3", "position", &hw_states_position3_));

    state_interfaces.emplace_back(
        hardware_interface::StateInterface("arm_joint4", "position", &hw_states_position4_));

    state_interfaces.emplace_back(
        hardware_interface::StateInterface("arm_joint5", "position", &hw_states_position5_));

    state_interfaces.emplace_back(
        hardware_interface::StateInterface("arm_joint6", "position", &hw_states_position6_));
    
    state_interfaces.emplace_back(
        hardware_interface::StateInterface("gripper", "position", &hw_states_gripper_));

    return state_interfaces;
}


std::vector<hardware_interface::CommandInterface> ArmHardwareInterface::export_command_interfaces()
{
    std::vector<hardware_interface::CommandInterface> command_interfaces;
    command_interfaces.emplace_back(
        hardware_interface::CommandInterface("arm_joint1", "position", &hw_commands_position1_));
                                            //这里要修改名称，对应urdf中的名称
    command_interfaces.emplace_back(
        hardware_interface::CommandInterface("arm_joint2", "position", &hw_commands_position2_));
    
    command_interfaces.emplace_back(
        hardware_interface::CommandInterface("arm_joint3", "position", &hw_commands_position3_));
                                            //这里要修改名称，对应urdf中的名称
    command_interfaces.emplace_back(
        hardware_interface::CommandInterface("arm_joint4", "position", &hw_commands_position4_));

    command_interfaces.emplace_back(
        hardware_interface::CommandInterface("arm_joint5", "position", &hw_commands_position5_));
                                            //这里要修改名称，对应urdf中的名称
    command_interfaces.emplace_back(
        hardware_interface::CommandInterface("arm_joint6", "position", &hw_commands_position6_));
    
    command_interfaces.emplace_back(
        hardware_interface::CommandInterface("gripper", "position", &hw_commands_gripper_));
    return command_interfaces;
}

} // namespace arm_hardware


#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(arm_hardware::ArmHardwareInterface, hardware_interface::SystemInterface)
