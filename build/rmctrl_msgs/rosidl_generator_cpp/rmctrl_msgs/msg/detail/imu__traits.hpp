// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmctrl_msgs:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef RMCTRL_MSGS__MSG__DETAIL__IMU__TRAITS_HPP_
#define RMCTRL_MSGS__MSG__DETAIL__IMU__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmctrl_msgs/msg/detail/imu__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rmctrl_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Imu & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Imu & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Imu & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rmctrl_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rmctrl_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rmctrl_msgs::msg::Imu & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmctrl_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmctrl_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rmctrl_msgs::msg::Imu & msg)
{
  return rmctrl_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rmctrl_msgs::msg::Imu>()
{
  return "rmctrl_msgs::msg::Imu";
}

template<>
inline const char * name<rmctrl_msgs::msg::Imu>()
{
  return "rmctrl_msgs/msg/Imu";
}

template<>
struct has_fixed_size<rmctrl_msgs::msg::Imu>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<rmctrl_msgs::msg::Imu>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<rmctrl_msgs::msg::Imu>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RMCTRL_MSGS__MSG__DETAIL__IMU__TRAITS_HPP_
