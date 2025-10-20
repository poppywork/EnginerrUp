// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmctrl_msgs:msg/Chassis.idl
// generated code does not contain a copyright notice

#ifndef RMCTRL_MSGS__MSG__DETAIL__CHASSIS__BUILDER_HPP_
#define RMCTRL_MSGS__MSG__DETAIL__CHASSIS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmctrl_msgs/msg/detail/chassis__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmctrl_msgs
{

namespace msg
{

namespace builder
{

class Init_Chassis_chassis_target_angular_z
{
public:
  explicit Init_Chassis_chassis_target_angular_z(::rmctrl_msgs::msg::Chassis & msg)
  : msg_(msg)
  {}
  ::rmctrl_msgs::msg::Chassis chassis_target_angular_z(::rmctrl_msgs::msg::Chassis::_chassis_target_angular_z_type arg)
  {
    msg_.chassis_target_angular_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmctrl_msgs::msg::Chassis msg_;
};

class Init_Chassis_chassis_target_angular_y
{
public:
  explicit Init_Chassis_chassis_target_angular_y(::rmctrl_msgs::msg::Chassis & msg)
  : msg_(msg)
  {}
  Init_Chassis_chassis_target_angular_z chassis_target_angular_y(::rmctrl_msgs::msg::Chassis::_chassis_target_angular_y_type arg)
  {
    msg_.chassis_target_angular_y = std::move(arg);
    return Init_Chassis_chassis_target_angular_z(msg_);
  }

private:
  ::rmctrl_msgs::msg::Chassis msg_;
};

class Init_Chassis_chassis_target_angular_x
{
public:
  explicit Init_Chassis_chassis_target_angular_x(::rmctrl_msgs::msg::Chassis & msg)
  : msg_(msg)
  {}
  Init_Chassis_chassis_target_angular_y chassis_target_angular_x(::rmctrl_msgs::msg::Chassis::_chassis_target_angular_x_type arg)
  {
    msg_.chassis_target_angular_x = std::move(arg);
    return Init_Chassis_chassis_target_angular_y(msg_);
  }

private:
  ::rmctrl_msgs::msg::Chassis msg_;
};

class Init_Chassis_chassis_target_linear_z
{
public:
  explicit Init_Chassis_chassis_target_linear_z(::rmctrl_msgs::msg::Chassis & msg)
  : msg_(msg)
  {}
  Init_Chassis_chassis_target_angular_x chassis_target_linear_z(::rmctrl_msgs::msg::Chassis::_chassis_target_linear_z_type arg)
  {
    msg_.chassis_target_linear_z = std::move(arg);
    return Init_Chassis_chassis_target_angular_x(msg_);
  }

private:
  ::rmctrl_msgs::msg::Chassis msg_;
};

class Init_Chassis_chassis_target_linear_y
{
public:
  explicit Init_Chassis_chassis_target_linear_y(::rmctrl_msgs::msg::Chassis & msg)
  : msg_(msg)
  {}
  Init_Chassis_chassis_target_linear_z chassis_target_linear_y(::rmctrl_msgs::msg::Chassis::_chassis_target_linear_y_type arg)
  {
    msg_.chassis_target_linear_y = std::move(arg);
    return Init_Chassis_chassis_target_linear_z(msg_);
  }

private:
  ::rmctrl_msgs::msg::Chassis msg_;
};

class Init_Chassis_chassis_target_linear_x
{
public:
  Init_Chassis_chassis_target_linear_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Chassis_chassis_target_linear_y chassis_target_linear_x(::rmctrl_msgs::msg::Chassis::_chassis_target_linear_x_type arg)
  {
    msg_.chassis_target_linear_x = std::move(arg);
    return Init_Chassis_chassis_target_linear_y(msg_);
  }

private:
  ::rmctrl_msgs::msg::Chassis msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmctrl_msgs::msg::Chassis>()
{
  return rmctrl_msgs::msg::builder::Init_Chassis_chassis_target_linear_x();
}

}  // namespace rmctrl_msgs

#endif  // RMCTRL_MSGS__MSG__DETAIL__CHASSIS__BUILDER_HPP_
