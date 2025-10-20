// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmctrl_msgs:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef RMCTRL_MSGS__MSG__DETAIL__IMU__BUILDER_HPP_
#define RMCTRL_MSGS__MSG__DETAIL__IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmctrl_msgs/msg/detail/imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmctrl_msgs
{

namespace msg
{

namespace builder
{

class Init_Imu_roll
{
public:
  explicit Init_Imu_roll(::rmctrl_msgs::msg::Imu & msg)
  : msg_(msg)
  {}
  ::rmctrl_msgs::msg::Imu roll(::rmctrl_msgs::msg::Imu::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmctrl_msgs::msg::Imu msg_;
};

class Init_Imu_pitch
{
public:
  explicit Init_Imu_pitch(::rmctrl_msgs::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_roll pitch(::rmctrl_msgs::msg::Imu::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Imu_roll(msg_);
  }

private:
  ::rmctrl_msgs::msg::Imu msg_;
};

class Init_Imu_yaw
{
public:
  explicit Init_Imu_yaw(::rmctrl_msgs::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_pitch yaw(::rmctrl_msgs::msg::Imu::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Imu_pitch(msg_);
  }

private:
  ::rmctrl_msgs::msg::Imu msg_;
};

class Init_Imu_header
{
public:
  Init_Imu_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Imu_yaw header(::rmctrl_msgs::msg::Imu::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Imu_yaw(msg_);
  }

private:
  ::rmctrl_msgs::msg::Imu msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmctrl_msgs::msg::Imu>()
{
  return rmctrl_msgs::msg::builder::Init_Imu_header();
}

}  // namespace rmctrl_msgs

#endif  // RMCTRL_MSGS__MSG__DETAIL__IMU__BUILDER_HPP_
