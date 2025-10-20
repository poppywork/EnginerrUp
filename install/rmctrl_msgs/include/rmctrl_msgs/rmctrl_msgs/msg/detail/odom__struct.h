// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmctrl_msgs:msg/Odom.idl
// generated code does not contain a copyright notice

#ifndef RMCTRL_MSGS__MSG__DETAIL__ODOM__STRUCT_H_
#define RMCTRL_MSGS__MSG__DETAIL__ODOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Odom in the package rmctrl_msgs.
/**
  * BCP odometry msgs define
 */
typedef struct rmctrl_msgs__msg__Odom
{
  double odom_position_x;
  double odom_position_y;
  double odom_position_z;
  double odom_orientation_x;
  double odom_orientation_y;
  double odom_orientation_z;
  double odom_orientation_w;
} rmctrl_msgs__msg__Odom;

// Struct for a sequence of rmctrl_msgs__msg__Odom.
typedef struct rmctrl_msgs__msg__Odom__Sequence
{
  rmctrl_msgs__msg__Odom * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmctrl_msgs__msg__Odom__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMCTRL_MSGS__MSG__DETAIL__ODOM__STRUCT_H_
