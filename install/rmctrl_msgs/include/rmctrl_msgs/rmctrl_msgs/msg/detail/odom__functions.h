// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rmctrl_msgs:msg/Odom.idl
// generated code does not contain a copyright notice

#ifndef RMCTRL_MSGS__MSG__DETAIL__ODOM__FUNCTIONS_H_
#define RMCTRL_MSGS__MSG__DETAIL__ODOM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rmctrl_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rmctrl_msgs/msg/detail/odom__struct.h"

/// Initialize msg/Odom message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rmctrl_msgs__msg__Odom
 * )) before or use
 * rmctrl_msgs__msg__Odom__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
bool
rmctrl_msgs__msg__Odom__init(rmctrl_msgs__msg__Odom * msg);

/// Finalize msg/Odom message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
void
rmctrl_msgs__msg__Odom__fini(rmctrl_msgs__msg__Odom * msg);

/// Create msg/Odom message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rmctrl_msgs__msg__Odom__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
rmctrl_msgs__msg__Odom *
rmctrl_msgs__msg__Odom__create();

/// Destroy msg/Odom message.
/**
 * It calls
 * rmctrl_msgs__msg__Odom__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
void
rmctrl_msgs__msg__Odom__destroy(rmctrl_msgs__msg__Odom * msg);

/// Check for msg/Odom message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
bool
rmctrl_msgs__msg__Odom__are_equal(const rmctrl_msgs__msg__Odom * lhs, const rmctrl_msgs__msg__Odom * rhs);

/// Copy a msg/Odom message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
bool
rmctrl_msgs__msg__Odom__copy(
  const rmctrl_msgs__msg__Odom * input,
  rmctrl_msgs__msg__Odom * output);

/// Initialize array of msg/Odom messages.
/**
 * It allocates the memory for the number of elements and calls
 * rmctrl_msgs__msg__Odom__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
bool
rmctrl_msgs__msg__Odom__Sequence__init(rmctrl_msgs__msg__Odom__Sequence * array, size_t size);

/// Finalize array of msg/Odom messages.
/**
 * It calls
 * rmctrl_msgs__msg__Odom__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
void
rmctrl_msgs__msg__Odom__Sequence__fini(rmctrl_msgs__msg__Odom__Sequence * array);

/// Create array of msg/Odom messages.
/**
 * It allocates the memory for the array and calls
 * rmctrl_msgs__msg__Odom__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
rmctrl_msgs__msg__Odom__Sequence *
rmctrl_msgs__msg__Odom__Sequence__create(size_t size);

/// Destroy array of msg/Odom messages.
/**
 * It calls
 * rmctrl_msgs__msg__Odom__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
void
rmctrl_msgs__msg__Odom__Sequence__destroy(rmctrl_msgs__msg__Odom__Sequence * array);

/// Check for msg/Odom message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
bool
rmctrl_msgs__msg__Odom__Sequence__are_equal(const rmctrl_msgs__msg__Odom__Sequence * lhs, const rmctrl_msgs__msg__Odom__Sequence * rhs);

/// Copy an array of msg/Odom messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmctrl_msgs
bool
rmctrl_msgs__msg__Odom__Sequence__copy(
  const rmctrl_msgs__msg__Odom__Sequence * input,
  rmctrl_msgs__msg__Odom__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RMCTRL_MSGS__MSG__DETAIL__ODOM__FUNCTIONS_H_
