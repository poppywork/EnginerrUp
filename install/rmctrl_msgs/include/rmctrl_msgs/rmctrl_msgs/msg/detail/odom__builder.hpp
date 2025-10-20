// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmctrl_msgs:msg/Odom.idl
// generated code does not contain a copyright notice

#ifndef RMCTRL_MSGS__MSG__DETAIL__ODOM__BUILDER_HPP_
#define RMCTRL_MSGS__MSG__DETAIL__ODOM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmctrl_msgs/msg/detail/odom__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmctrl_msgs
{

namespace msg
{

namespace builder
{

class Init_Odom_odom_orientation_w
{
public:
  explicit Init_Odom_odom_orientation_w(::rmctrl_msgs::msg::Odom & msg)
  : msg_(msg)
  {}
  ::rmctrl_msgs::msg::Odom odom_orientation_w(::rmctrl_msgs::msg::Odom::_odom_orientation_w_type arg)
  {
    msg_.odom_orientation_w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmctrl_msgs::msg::Odom msg_;
};

class Init_Odom_odom_orientation_z
{
public:
  explicit Init_Odom_odom_orientation_z(::rmctrl_msgs::msg::Odom & msg)
  : msg_(msg)
  {}
  Init_Odom_odom_orientation_w odom_orientation_z(::rmctrl_msgs::msg::Odom::_odom_orientation_z_type arg)
  {
    msg_.odom_orientation_z = std::move(arg);
    return Init_Odom_odom_orientation_w(msg_);
  }

private:
  ::rmctrl_msgs::msg::Odom msg_;
};

class Init_Odom_odom_orientation_y
{
public:
  explicit Init_Odom_odom_orientation_y(::rmctrl_msgs::msg::Odom & msg)
  : msg_(msg)
  {}
  Init_Odom_odom_orientation_z odom_orientation_y(::rmctrl_msgs::msg::Odom::_odom_orientation_y_type arg)
  {
    msg_.odom_orientation_y = std::move(arg);
    return Init_Odom_odom_orientation_z(msg_);
  }

private:
  ::rmctrl_msgs::msg::Odom msg_;
};

class Init_Odom_odom_orientation_x
{
public:
  explicit Init_Odom_odom_orientation_x(::rmctrl_msgs::msg::Odom & msg)
  : msg_(msg)
  {}
  Init_Odom_odom_orientation_y odom_orientation_x(::rmctrl_msgs::msg::Odom::_odom_orientation_x_type arg)
  {
    msg_.odom_orientation_x = std::move(arg);
    return Init_Odom_odom_orientation_y(msg_);
  }

private:
  ::rmctrl_msgs::msg::Odom msg_;
};

class Init_Odom_odom_position_z
{
public:
  explicit Init_Odom_odom_position_z(::rmctrl_msgs::msg::Odom & msg)
  : msg_(msg)
  {}
  Init_Odom_odom_orientation_x odom_position_z(::rmctrl_msgs::msg::Odom::_odom_position_z_type arg)
  {
    msg_.odom_position_z = std::move(arg);
    return Init_Odom_odom_orientation_x(msg_);
  }

private:
  ::rmctrl_msgs::msg::Odom msg_;
};

class Init_Odom_odom_position_y
{
public:
  explicit Init_Odom_odom_position_y(::rmctrl_msgs::msg::Odom & msg)
  : msg_(msg)
  {}
  Init_Odom_odom_position_z odom_position_y(::rmctrl_msgs::msg::Odom::_odom_position_y_type arg)
  {
    msg_.odom_position_y = std::move(arg);
    return Init_Odom_odom_position_z(msg_);
  }

private:
  ::rmctrl_msgs::msg::Odom msg_;
};

class Init_Odom_odom_position_x
{
public:
  Init_Odom_odom_position_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Odom_odom_position_y odom_position_x(::rmctrl_msgs::msg::Odom::_odom_position_x_type arg)
  {
    msg_.odom_position_x = std::move(arg);
    return Init_Odom_odom_position_y(msg_);
  }

private:
  ::rmctrl_msgs::msg::Odom msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmctrl_msgs::msg::Odom>()
{
  return rmctrl_msgs::msg::builder::Init_Odom_odom_position_x();
}

}  // namespace rmctrl_msgs

#endif  // RMCTRL_MSGS__MSG__DETAIL__ODOM__BUILDER_HPP_
