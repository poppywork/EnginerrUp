// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rmctrl_msgs:msg/Odom.idl
// generated code does not contain a copyright notice
#include "rmctrl_msgs/msg/detail/odom__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rmctrl_msgs/msg/detail/odom__struct.hpp"

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
  const rmctrl_msgs::msg::Odom & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: odom_position_x
  cdr << ros_message.odom_position_x;
  // Member: odom_position_y
  cdr << ros_message.odom_position_y;
  // Member: odom_position_z
  cdr << ros_message.odom_position_z;
  // Member: odom_orientation_x
  cdr << ros_message.odom_orientation_x;
  // Member: odom_orientation_y
  cdr << ros_message.odom_orientation_y;
  // Member: odom_orientation_z
  cdr << ros_message.odom_orientation_z;
  // Member: odom_orientation_w
  cdr << ros_message.odom_orientation_w;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmctrl_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rmctrl_msgs::msg::Odom & ros_message)
{
  // Member: odom_position_x
  cdr >> ros_message.odom_position_x;

  // Member: odom_position_y
  cdr >> ros_message.odom_position_y;

  // Member: odom_position_z
  cdr >> ros_message.odom_position_z;

  // Member: odom_orientation_x
  cdr >> ros_message.odom_orientation_x;

  // Member: odom_orientation_y
  cdr >> ros_message.odom_orientation_y;

  // Member: odom_orientation_z
  cdr >> ros_message.odom_orientation_z;

  // Member: odom_orientation_w
  cdr >> ros_message.odom_orientation_w;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmctrl_msgs
get_serialized_size(
  const rmctrl_msgs::msg::Odom & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: odom_position_x
  {
    size_t item_size = sizeof(ros_message.odom_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: odom_position_y
  {
    size_t item_size = sizeof(ros_message.odom_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: odom_position_z
  {
    size_t item_size = sizeof(ros_message.odom_position_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: odom_orientation_x
  {
    size_t item_size = sizeof(ros_message.odom_orientation_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: odom_orientation_y
  {
    size_t item_size = sizeof(ros_message.odom_orientation_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: odom_orientation_z
  {
    size_t item_size = sizeof(ros_message.odom_orientation_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: odom_orientation_w
  {
    size_t item_size = sizeof(ros_message.odom_orientation_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmctrl_msgs
max_serialized_size_Odom(
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


  // Member: odom_position_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: odom_position_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: odom_position_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: odom_orientation_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: odom_orientation_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: odom_orientation_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: odom_orientation_w
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
    using DataType = rmctrl_msgs::msg::Odom;
    is_plain =
      (
      offsetof(DataType, odom_orientation_w) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Odom__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rmctrl_msgs::msg::Odom *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Odom__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rmctrl_msgs::msg::Odom *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Odom__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rmctrl_msgs::msg::Odom *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Odom__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Odom(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Odom__callbacks = {
  "rmctrl_msgs::msg",
  "Odom",
  _Odom__cdr_serialize,
  _Odom__cdr_deserialize,
  _Odom__get_serialized_size,
  _Odom__max_serialized_size
};

static rosidl_message_type_support_t _Odom__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Odom__callbacks,
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
get_message_type_support_handle<rmctrl_msgs::msg::Odom>()
{
  return &rmctrl_msgs::msg::typesupport_fastrtps_cpp::_Odom__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rmctrl_msgs, msg, Odom)() {
  return &rmctrl_msgs::msg::typesupport_fastrtps_cpp::_Odom__handle;
}

#ifdef __cplusplus
}
#endif
