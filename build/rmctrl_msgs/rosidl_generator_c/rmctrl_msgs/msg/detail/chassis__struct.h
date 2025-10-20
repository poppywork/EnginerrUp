// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmctrl_msgs:msg/Chassis.idl
// generated code does not contain a copyright notice

#ifndef RMCTRL_MSGS__MSG__DETAIL__CHASSIS__STRUCT_H_
#define RMCTRL_MSGS__MSG__DETAIL__CHASSIS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Chassis in the package rmctrl_msgs.
typedef struct rmctrl_msgs__msg__Chassis
{
  double chassis_target_linear_x;
  double chassis_target_linear_y;
  double chassis_target_linear_z;
  double chassis_target_angular_x;
  double chassis_target_angular_y;
  double chassis_target_angular_z;
} rmctrl_msgs__msg__Chassis;

// Struct for a sequence of rmctrl_msgs__msg__Chassis.
typedef struct rmctrl_msgs__msg__Chassis__Sequence
{
  rmctrl_msgs__msg__Chassis * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmctrl_msgs__msg__Chassis__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMCTRL_MSGS__MSG__DETAIL__CHASSIS__STRUCT_H_
