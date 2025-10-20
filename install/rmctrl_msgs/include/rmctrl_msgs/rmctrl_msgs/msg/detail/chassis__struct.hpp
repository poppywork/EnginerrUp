// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmctrl_msgs:msg/Chassis.idl
// generated code does not contain a copyright notice

#ifndef RMCTRL_MSGS__MSG__DETAIL__CHASSIS__STRUCT_HPP_
#define RMCTRL_MSGS__MSG__DETAIL__CHASSIS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rmctrl_msgs__msg__Chassis __attribute__((deprecated))
#else
# define DEPRECATED__rmctrl_msgs__msg__Chassis __declspec(deprecated)
#endif

namespace rmctrl_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Chassis_
{
  using Type = Chassis_<ContainerAllocator>;

  explicit Chassis_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->chassis_target_linear_x = 0.0;
      this->chassis_target_linear_y = 0.0;
      this->chassis_target_linear_z = 0.0;
      this->chassis_target_angular_x = 0.0;
      this->chassis_target_angular_y = 0.0;
      this->chassis_target_angular_z = 0.0;
    }
  }

  explicit Chassis_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->chassis_target_linear_x = 0.0;
      this->chassis_target_linear_y = 0.0;
      this->chassis_target_linear_z = 0.0;
      this->chassis_target_angular_x = 0.0;
      this->chassis_target_angular_y = 0.0;
      this->chassis_target_angular_z = 0.0;
    }
  }

  // field types and members
  using _chassis_target_linear_x_type =
    double;
  _chassis_target_linear_x_type chassis_target_linear_x;
  using _chassis_target_linear_y_type =
    double;
  _chassis_target_linear_y_type chassis_target_linear_y;
  using _chassis_target_linear_z_type =
    double;
  _chassis_target_linear_z_type chassis_target_linear_z;
  using _chassis_target_angular_x_type =
    double;
  _chassis_target_angular_x_type chassis_target_angular_x;
  using _chassis_target_angular_y_type =
    double;
  _chassis_target_angular_y_type chassis_target_angular_y;
  using _chassis_target_angular_z_type =
    double;
  _chassis_target_angular_z_type chassis_target_angular_z;

  // setters for named parameter idiom
  Type & set__chassis_target_linear_x(
    const double & _arg)
  {
    this->chassis_target_linear_x = _arg;
    return *this;
  }
  Type & set__chassis_target_linear_y(
    const double & _arg)
  {
    this->chassis_target_linear_y = _arg;
    return *this;
  }
  Type & set__chassis_target_linear_z(
    const double & _arg)
  {
    this->chassis_target_linear_z = _arg;
    return *this;
  }
  Type & set__chassis_target_angular_x(
    const double & _arg)
  {
    this->chassis_target_angular_x = _arg;
    return *this;
  }
  Type & set__chassis_target_angular_y(
    const double & _arg)
  {
    this->chassis_target_angular_y = _arg;
    return *this;
  }
  Type & set__chassis_target_angular_z(
    const double & _arg)
  {
    this->chassis_target_angular_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rmctrl_msgs::msg::Chassis_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmctrl_msgs::msg::Chassis_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmctrl_msgs::msg::Chassis_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmctrl_msgs::msg::Chassis_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmctrl_msgs::msg::Chassis_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmctrl_msgs::msg::Chassis_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmctrl_msgs::msg::Chassis_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmctrl_msgs::msg::Chassis_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmctrl_msgs::msg::Chassis_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmctrl_msgs::msg::Chassis_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmctrl_msgs__msg__Chassis
    std::shared_ptr<rmctrl_msgs::msg::Chassis_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmctrl_msgs__msg__Chassis
    std::shared_ptr<rmctrl_msgs::msg::Chassis_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Chassis_ & other) const
  {
    if (this->chassis_target_linear_x != other.chassis_target_linear_x) {
      return false;
    }
    if (this->chassis_target_linear_y != other.chassis_target_linear_y) {
      return false;
    }
    if (this->chassis_target_linear_z != other.chassis_target_linear_z) {
      return false;
    }
    if (this->chassis_target_angular_x != other.chassis_target_angular_x) {
      return false;
    }
    if (this->chassis_target_angular_y != other.chassis_target_angular_y) {
      return false;
    }
    if (this->chassis_target_angular_z != other.chassis_target_angular_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Chassis_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Chassis_

// alias to use template instance with default allocator
using Chassis =
  rmctrl_msgs::msg::Chassis_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rmctrl_msgs

#endif  // RMCTRL_MSGS__MSG__DETAIL__CHASSIS__STRUCT_HPP_
