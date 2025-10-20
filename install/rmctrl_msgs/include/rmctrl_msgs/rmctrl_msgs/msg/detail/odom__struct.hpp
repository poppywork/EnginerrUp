// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmctrl_msgs:msg/Odom.idl
// generated code does not contain a copyright notice

#ifndef RMCTRL_MSGS__MSG__DETAIL__ODOM__STRUCT_HPP_
#define RMCTRL_MSGS__MSG__DETAIL__ODOM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rmctrl_msgs__msg__Odom __attribute__((deprecated))
#else
# define DEPRECATED__rmctrl_msgs__msg__Odom __declspec(deprecated)
#endif

namespace rmctrl_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Odom_
{
  using Type = Odom_<ContainerAllocator>;

  explicit Odom_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->odom_position_x = 0.0;
      this->odom_position_y = 0.0;
      this->odom_position_z = 0.0;
      this->odom_orientation_x = 0.0;
      this->odom_orientation_y = 0.0;
      this->odom_orientation_z = 0.0;
      this->odom_orientation_w = 0.0;
    }
  }

  explicit Odom_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->odom_position_x = 0.0;
      this->odom_position_y = 0.0;
      this->odom_position_z = 0.0;
      this->odom_orientation_x = 0.0;
      this->odom_orientation_y = 0.0;
      this->odom_orientation_z = 0.0;
      this->odom_orientation_w = 0.0;
    }
  }

  // field types and members
  using _odom_position_x_type =
    double;
  _odom_position_x_type odom_position_x;
  using _odom_position_y_type =
    double;
  _odom_position_y_type odom_position_y;
  using _odom_position_z_type =
    double;
  _odom_position_z_type odom_position_z;
  using _odom_orientation_x_type =
    double;
  _odom_orientation_x_type odom_orientation_x;
  using _odom_orientation_y_type =
    double;
  _odom_orientation_y_type odom_orientation_y;
  using _odom_orientation_z_type =
    double;
  _odom_orientation_z_type odom_orientation_z;
  using _odom_orientation_w_type =
    double;
  _odom_orientation_w_type odom_orientation_w;

  // setters for named parameter idiom
  Type & set__odom_position_x(
    const double & _arg)
  {
    this->odom_position_x = _arg;
    return *this;
  }
  Type & set__odom_position_y(
    const double & _arg)
  {
    this->odom_position_y = _arg;
    return *this;
  }
  Type & set__odom_position_z(
    const double & _arg)
  {
    this->odom_position_z = _arg;
    return *this;
  }
  Type & set__odom_orientation_x(
    const double & _arg)
  {
    this->odom_orientation_x = _arg;
    return *this;
  }
  Type & set__odom_orientation_y(
    const double & _arg)
  {
    this->odom_orientation_y = _arg;
    return *this;
  }
  Type & set__odom_orientation_z(
    const double & _arg)
  {
    this->odom_orientation_z = _arg;
    return *this;
  }
  Type & set__odom_orientation_w(
    const double & _arg)
  {
    this->odom_orientation_w = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rmctrl_msgs::msg::Odom_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmctrl_msgs::msg::Odom_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmctrl_msgs::msg::Odom_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmctrl_msgs::msg::Odom_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmctrl_msgs::msg::Odom_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmctrl_msgs::msg::Odom_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmctrl_msgs::msg::Odom_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmctrl_msgs::msg::Odom_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmctrl_msgs::msg::Odom_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmctrl_msgs::msg::Odom_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmctrl_msgs__msg__Odom
    std::shared_ptr<rmctrl_msgs::msg::Odom_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmctrl_msgs__msg__Odom
    std::shared_ptr<rmctrl_msgs::msg::Odom_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Odom_ & other) const
  {
    if (this->odom_position_x != other.odom_position_x) {
      return false;
    }
    if (this->odom_position_y != other.odom_position_y) {
      return false;
    }
    if (this->odom_position_z != other.odom_position_z) {
      return false;
    }
    if (this->odom_orientation_x != other.odom_orientation_x) {
      return false;
    }
    if (this->odom_orientation_y != other.odom_orientation_y) {
      return false;
    }
    if (this->odom_orientation_z != other.odom_orientation_z) {
      return false;
    }
    if (this->odom_orientation_w != other.odom_orientation_w) {
      return false;
    }
    return true;
  }
  bool operator!=(const Odom_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Odom_

// alias to use template instance with default allocator
using Odom =
  rmctrl_msgs::msg::Odom_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rmctrl_msgs

#endif  // RMCTRL_MSGS__MSG__DETAIL__ODOM__STRUCT_HPP_
