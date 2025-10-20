// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rmctrl_msgs:msg/Chassis.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "rmctrl_msgs/msg/detail/chassis__struct.h"
#include "rmctrl_msgs/msg/detail/chassis__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rmctrl_msgs__msg__chassis__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[33];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("rmctrl_msgs.msg._chassis.Chassis", full_classname_dest, 32) == 0);
  }
  rmctrl_msgs__msg__Chassis * ros_message = _ros_message;
  {  // chassis_target_linear_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "chassis_target_linear_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->chassis_target_linear_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // chassis_target_linear_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "chassis_target_linear_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->chassis_target_linear_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // chassis_target_linear_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "chassis_target_linear_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->chassis_target_linear_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // chassis_target_angular_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "chassis_target_angular_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->chassis_target_angular_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // chassis_target_angular_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "chassis_target_angular_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->chassis_target_angular_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // chassis_target_angular_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "chassis_target_angular_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->chassis_target_angular_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rmctrl_msgs__msg__chassis__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Chassis */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rmctrl_msgs.msg._chassis");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Chassis");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rmctrl_msgs__msg__Chassis * ros_message = (rmctrl_msgs__msg__Chassis *)raw_ros_message;
  {  // chassis_target_linear_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->chassis_target_linear_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chassis_target_linear_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chassis_target_linear_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->chassis_target_linear_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chassis_target_linear_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chassis_target_linear_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->chassis_target_linear_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chassis_target_linear_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chassis_target_angular_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->chassis_target_angular_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chassis_target_angular_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chassis_target_angular_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->chassis_target_angular_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chassis_target_angular_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chassis_target_angular_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->chassis_target_angular_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chassis_target_angular_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
