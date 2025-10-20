// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmctrl_msgs:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef RMCTRL_MSGS__MSG__DETAIL__IMU__STRUCT_H_
#define RMCTRL_MSGS__MSG__DETAIL__IMU__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/Imu in the package rmctrl_msgs.
typedef struct rmctrl_msgs__msg__Imu
{
  std_msgs__msg__Header header;
  double yaw;
  double pitch;
  double roll;
} rmctrl_msgs__msg__Imu;

// Struct for a sequence of rmctrl_msgs__msg__Imu.
typedef struct rmctrl_msgs__msg__Imu__Sequence
{
  rmctrl_msgs__msg__Imu * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmctrl_msgs__msg__Imu__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMCTRL_MSGS__MSG__DETAIL__IMU__STRUCT_H_
