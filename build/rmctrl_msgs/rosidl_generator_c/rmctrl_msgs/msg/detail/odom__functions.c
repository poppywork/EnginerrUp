// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rmctrl_msgs:msg/Odom.idl
// generated code does not contain a copyright notice
#include "rmctrl_msgs/msg/detail/odom__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rmctrl_msgs__msg__Odom__init(rmctrl_msgs__msg__Odom * msg)
{
  if (!msg) {
    return false;
  }
  // odom_position_x
  // odom_position_y
  // odom_position_z
  // odom_orientation_x
  // odom_orientation_y
  // odom_orientation_z
  // odom_orientation_w
  return true;
}

void
rmctrl_msgs__msg__Odom__fini(rmctrl_msgs__msg__Odom * msg)
{
  if (!msg) {
    return;
  }
  // odom_position_x
  // odom_position_y
  // odom_position_z
  // odom_orientation_x
  // odom_orientation_y
  // odom_orientation_z
  // odom_orientation_w
}

bool
rmctrl_msgs__msg__Odom__are_equal(const rmctrl_msgs__msg__Odom * lhs, const rmctrl_msgs__msg__Odom * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // odom_position_x
  if (lhs->odom_position_x != rhs->odom_position_x) {
    return false;
  }
  // odom_position_y
  if (lhs->odom_position_y != rhs->odom_position_y) {
    return false;
  }
  // odom_position_z
  if (lhs->odom_position_z != rhs->odom_position_z) {
    return false;
  }
  // odom_orientation_x
  if (lhs->odom_orientation_x != rhs->odom_orientation_x) {
    return false;
  }
  // odom_orientation_y
  if (lhs->odom_orientation_y != rhs->odom_orientation_y) {
    return false;
  }
  // odom_orientation_z
  if (lhs->odom_orientation_z != rhs->odom_orientation_z) {
    return false;
  }
  // odom_orientation_w
  if (lhs->odom_orientation_w != rhs->odom_orientation_w) {
    return false;
  }
  return true;
}

bool
rmctrl_msgs__msg__Odom__copy(
  const rmctrl_msgs__msg__Odom * input,
  rmctrl_msgs__msg__Odom * output)
{
  if (!input || !output) {
    return false;
  }
  // odom_position_x
  output->odom_position_x = input->odom_position_x;
  // odom_position_y
  output->odom_position_y = input->odom_position_y;
  // odom_position_z
  output->odom_position_z = input->odom_position_z;
  // odom_orientation_x
  output->odom_orientation_x = input->odom_orientation_x;
  // odom_orientation_y
  output->odom_orientation_y = input->odom_orientation_y;
  // odom_orientation_z
  output->odom_orientation_z = input->odom_orientation_z;
  // odom_orientation_w
  output->odom_orientation_w = input->odom_orientation_w;
  return true;
}

rmctrl_msgs__msg__Odom *
rmctrl_msgs__msg__Odom__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmctrl_msgs__msg__Odom * msg = (rmctrl_msgs__msg__Odom *)allocator.allocate(sizeof(rmctrl_msgs__msg__Odom), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rmctrl_msgs__msg__Odom));
  bool success = rmctrl_msgs__msg__Odom__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rmctrl_msgs__msg__Odom__destroy(rmctrl_msgs__msg__Odom * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rmctrl_msgs__msg__Odom__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rmctrl_msgs__msg__Odom__Sequence__init(rmctrl_msgs__msg__Odom__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmctrl_msgs__msg__Odom * data = NULL;

  if (size) {
    data = (rmctrl_msgs__msg__Odom *)allocator.zero_allocate(size, sizeof(rmctrl_msgs__msg__Odom), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rmctrl_msgs__msg__Odom__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rmctrl_msgs__msg__Odom__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rmctrl_msgs__msg__Odom__Sequence__fini(rmctrl_msgs__msg__Odom__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rmctrl_msgs__msg__Odom__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rmctrl_msgs__msg__Odom__Sequence *
rmctrl_msgs__msg__Odom__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmctrl_msgs__msg__Odom__Sequence * array = (rmctrl_msgs__msg__Odom__Sequence *)allocator.allocate(sizeof(rmctrl_msgs__msg__Odom__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rmctrl_msgs__msg__Odom__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rmctrl_msgs__msg__Odom__Sequence__destroy(rmctrl_msgs__msg__Odom__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rmctrl_msgs__msg__Odom__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rmctrl_msgs__msg__Odom__Sequence__are_equal(const rmctrl_msgs__msg__Odom__Sequence * lhs, const rmctrl_msgs__msg__Odom__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rmctrl_msgs__msg__Odom__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rmctrl_msgs__msg__Odom__Sequence__copy(
  const rmctrl_msgs__msg__Odom__Sequence * input,
  rmctrl_msgs__msg__Odom__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rmctrl_msgs__msg__Odom);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rmctrl_msgs__msg__Odom * data =
      (rmctrl_msgs__msg__Odom *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rmctrl_msgs__msg__Odom__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rmctrl_msgs__msg__Odom__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rmctrl_msgs__msg__Odom__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
