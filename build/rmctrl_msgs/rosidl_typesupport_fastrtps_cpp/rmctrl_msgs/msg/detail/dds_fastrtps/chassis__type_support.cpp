// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rmctrl_msgs:msg/Chassis.idl
// generated code does not contain a copyright notice
#include "rmctrl_msgs/msg/detail/chassis__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rmctrl_msgs/msg/detail/chassis__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rmctrl_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmctrl_msgs
cdr_serialize(
  const rmctrl_msgs::msg::Chassis & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: chassis_target_linear_x
  cdr << ros_message.chassis_target_linear_x;
  // Member: chassis_target_linear_y
  cdr << ros_message.chassis_target_linear_y;
  // Member: chassis_target_linear_z
  cdr << ros_message.chassis_target_linear_z;
  // Member: chassis_target_angular_x
  cdr << ros_message.chassis_target_angular_x;
  // Member: chassis_target_angular_y
  cdr << ros_message.chassis_target_angular_y;
  // Member: chassis_target_angular_z
  cdr << ros_message.chassis_target_angular_z;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmctrl_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rmctrl_msgs::msg::Chassis & ros_message)
{
  // Member: chassis_target_linear_x
  cdr >> ros_message.chassis_target_linear_x;

  // Member: chassis_target_linear_y
  cdr >> ros_message.chassis_target_linear_y;

  // Member: chassis_target_linear_z
  cdr >> ros_message.chassis_target_linear_z;

  // Member: chassis_target_angular_x
  cdr >> ros_message.chassis_target_angular_x;

  // Member: chassis_target_angular_y
  cdr >> ros_message.chassis_target_angular_y;

  // Member: chassis_target_angular_z
  cdr >> ros_message.chassis_target_angular_z;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmctrl_msgs
get_serialized_size(
  const rmctrl_msgs::msg::Chassis & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: chassis_target_linear_x
  {
    size_t item_size = sizeof(ros_message.chassis_target_linear_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: chassis_target_linear_y
  {
    size_t item_size = sizeof(ros_message.chassis_target_linear_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: chassis_target_linear_z
  {
    size_t item_size = sizeof(ros_message.chassis_target_linear_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: chassis_target_angular_x
  {
    size_t item_size = sizeof(ros_message.chassis_target_angular_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: chassis_target_angular_y
  {
    size_t item_size = sizeof(ros_message.chassis_target_angular_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: chassis_target_angular_z
  {
    size_t item_size = sizeof(ros_message.chassis_target_angular_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmctrl_msgs
max_serialized_size_Chassis(
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


  // Member: chassis_target_linear_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: chassis_target_linear_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: chassis_target_linear_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: chassis_target_angular_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: chassis_target_angular_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: chassis_target_angular_z
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
    using DataType = rmctrl_msgs::msg::Chassis;
    is_plain =
      (
      offsetof(DataType, chassis_target_angular_z) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Chassis__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rmctrl_msgs::msg::Chassis *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Chassis__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rmctrl_msgs::msg::Chassis *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Chassis__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rmctrl_msgs::msg::Chassis *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Chassis__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Chassis(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Chassis__callbacks = {
  "rmctrl_msgs::msg",
  "Chassis",
  _Chassis__cdr_serialize,
  _Chassis__cdr_deserialize,
  _Chassis__get_serialized_size,
  _Chassis__max_serialized_size
};

static rosidl_message_type_support_t _Chassis__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Chassis__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rmctrl_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rmctrl_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<rmctrl_msgs::msg::Chassis>()
{
  return &rmctrl_msgs::msg::typesupport_fastrtps_cpp::_Chassis__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rmctrl_msgs, msg, Chassis)() {
  return &rmctrl_msgs::msg::typesupport_fastrtps_cpp::_Chassis__handle;
}

#ifdef __cplusplus
}
#endif
