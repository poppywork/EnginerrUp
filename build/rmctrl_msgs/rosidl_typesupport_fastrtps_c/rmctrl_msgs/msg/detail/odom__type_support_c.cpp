// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rmctrl_msgs:msg/Odom.idl
// generated code does not contain a copyright notice
#include "rmctrl_msgs/msg/detail/odom__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rmctrl_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rmctrl_msgs/msg/detail/odom__struct.h"
#include "rmctrl_msgs/msg/detail/odom__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Odom__ros_msg_type = rmctrl_msgs__msg__Odom;

static bool _Odom__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Odom__ros_msg_type * ros_message = static_cast<const _Odom__ros_msg_type *>(untyped_ros_message);
  // Field name: odom_position_x
  {
    cdr << ros_message->odom_position_x;
  }

  // Field name: odom_position_y
  {
    cdr << ros_message->odom_position_y;
  }

  // Field name: odom_position_z
  {
    cdr << ros_message->odom_position_z;
  }

  // Field name: odom_orientation_x
  {
    cdr << ros_message->odom_orientation_x;
  }

  // Field name: odom_orientation_y
  {
    cdr << ros_message->odom_orientation_y;
  }

  // Field name: odom_orientation_z
  {
    cdr << ros_message->odom_orientation_z;
  }

  // Field name: odom_orientation_w
  {
    cdr << ros_message->odom_orientation_w;
  }

  return true;
}

static bool _Odom__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Odom__ros_msg_type * ros_message = static_cast<_Odom__ros_msg_type *>(untyped_ros_message);
  // Field name: odom_position_x
  {
    cdr >> ros_message->odom_position_x;
  }

  // Field name: odom_position_y
  {
    cdr >> ros_message->odom_position_y;
  }

  // Field name: odom_position_z
  {
    cdr >> ros_message->odom_position_z;
  }

  // Field name: odom_orientation_x
  {
    cdr >> ros_message->odom_orientation_x;
  }

  // Field name: odom_orientation_y
  {
    cdr >> ros_message->odom_orientation_y;
  }

  // Field name: odom_orientation_z
  {
    cdr >> ros_message->odom_orientation_z;
  }

  // Field name: odom_orientation_w
  {
    cdr >> ros_message->odom_orientation_w;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rmctrl_msgs
size_t get_serialized_size_rmctrl_msgs__msg__Odom(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Odom__ros_msg_type * ros_message = static_cast<const _Odom__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name odom_position_x
  {
    size_t item_size = sizeof(ros_message->odom_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name odom_position_y
  {
    size_t item_size = sizeof(ros_message->odom_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name odom_position_z
  {
    size_t item_size = sizeof(ros_message->odom_position_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name odom_orientation_x
  {
    size_t item_size = sizeof(ros_message->odom_orientation_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name odom_orientation_y
  {
    size_t item_size = sizeof(ros_message->odom_orientation_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name odom_orientation_z
  {
    size_t item_size = sizeof(ros_message->odom_orientation_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name odom_orientation_w
  {
    size_t item_size = sizeof(ros_message->odom_orientation_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Odom__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rmctrl_msgs__msg__Odom(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rmctrl_msgs
size_t max_serialized_size_rmctrl_msgs__msg__Odom(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: odom_position_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: odom_position_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: odom_position_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: odom_orientation_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: odom_orientation_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: odom_orientation_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: odom_orientation_w
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rmctrl_msgs__msg__Odom;
    is_plain =
      (
      offsetof(DataType, odom_orientation_w) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Odom__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rmctrl_msgs__msg__Odom(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Odom = {
  "rmctrl_msgs::msg",
  "Odom",
  _Odom__cdr_serialize,
  _Odom__cdr_deserialize,
  _Odom__get_serialized_size,
  _Odom__max_serialized_size
};

static rosidl_message_type_support_t _Odom__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Odom,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rmctrl_msgs, msg, Odom)() {
  return &_Odom__type_support;
}

#if defined(__cplusplus)
}
#endif
