// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from rmctrl_msgs:msg/Odom.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rmctrl_msgs/msg/detail/odom__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace rmctrl_msgs
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _Odom_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Odom_type_support_ids_t;

static const _Odom_type_support_ids_t _Odom_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Odom_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Odom_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Odom_type_support_symbol_names_t _Odom_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rmctrl_msgs, msg, Odom)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rmctrl_msgs, msg, Odom)),
  }
};

typedef struct _Odom_type_support_data_t
{
  void * data[2];
} _Odom_type_support_data_t;

static _Odom_type_support_data_t _Odom_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Odom_message_typesupport_map = {
  2,
  "rmctrl_msgs",
  &_Odom_message_typesupport_ids.typesupport_identifier[0],
  &_Odom_message_typesupport_symbol_names.symbol_name[0],
  &_Odom_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Odom_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Odom_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace rmctrl_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rmctrl_msgs::msg::Odom>()
{
  return &::rmctrl_msgs::msg::rosidl_typesupport_cpp::Odom_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, rmctrl_msgs, msg, Odom)() {
  return get_message_type_support_handle<rmctrl_msgs::msg::Odom>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
