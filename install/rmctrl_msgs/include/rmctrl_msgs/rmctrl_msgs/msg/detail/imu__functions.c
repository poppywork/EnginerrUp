// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rmctrl_msgs:msg/Imu.idl
// generated code does not contain a copyright notice
#include "rmctrl_msgs/msg/detail/imu__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
rmctrl_msgs__msg__Imu__init(rmctrl_msgs__msg__Imu * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    rmctrl_msgs__msg__Imu__fini(msg);
    return false;
  }
  // yaw
  // pitch
  // roll
  return true;
}

void
rmctrl_msgs__msg__Imu__fini(rmctrl_msgs__msg__Imu * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // yaw
  // pitch
  // roll
}

bool
rmctrl_msgs__msg__Imu__are_equal(const rmctrl_msgs__msg__Imu * lhs, const rmctrl_msgs__msg__Imu * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  return true;
}

bool
rmctrl_msgs__msg__Imu__copy(
  const rmctrl_msgs__msg__Imu * input,
  rmctrl_msgs__msg__Imu * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // yaw
  output->yaw = input->yaw;
  // pitch
  output->pitch = input->pitch;
  // roll
  output->roll = input->roll;
  return true;
}

rmctrl_msgs__msg__Imu *
rmctrl_msgs__msg__Imu__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmctrl_msgs__msg__Imu * msg = (rmctrl_msgs__msg__Imu *)allocator.allocate(sizeof(rmctrl_msgs__msg__Imu), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rmctrl_msgs__msg__Imu));
  bool success = rmctrl_msgs__msg__Imu__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rmctrl_msgs__msg__Imu__destroy(rmctrl_msgs__msg__Imu * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rmctrl_msgs__msg__Imu__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rmctrl_msgs__msg__Imu__Sequence__init(rmctrl_msgs__msg__Imu__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmctrl_msgs__msg__Imu * data = NULL;

  if (size) {
    data = (rmctrl_msgs__msg__Imu *)allocator.zero_allocate(size, sizeof(rmctrl_msgs__msg__Imu), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rmctrl_msgs__msg__Imu__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rmctrl_msgs__msg__Imu__fini(&data[i - 1]);
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
rmctrl_msgs__msg__Imu__Sequence__fini(rmctrl_msgs__msg__Imu__Sequence * array)
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
      rmctrl_msgs__msg__Imu__fini(&array->data[i]);
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

rmctrl_msgs__msg__Imu__Sequence *
rmctrl_msgs__msg__Imu__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmctrl_msgs__msg__Imu__Sequence * array = (rmctrl_msgs__msg__Imu__Sequence *)allocator.allocate(sizeof(rmctrl_msgs__msg__Imu__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rmctrl_msgs__msg__Imu__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rmctrl_msgs__msg__Imu__Sequence__destroy(rmctrl_msgs__msg__Imu__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rmctrl_msgs__msg__Imu__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rmctrl_msgs__msg__Imu__Sequence__are_equal(const rmctrl_msgs__msg__Imu__Sequence * lhs, const rmctrl_msgs__msg__Imu__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rmctrl_msgs__msg__Imu__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rmctrl_msgs__msg__Imu__Sequence__copy(
  const rmctrl_msgs__msg__Imu__Sequence * input,
  rmctrl_msgs__msg__Imu__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rmctrl_msgs__msg__Imu);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rmctrl_msgs__msg__Imu * data =
      (rmctrl_msgs__msg__Imu *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rmctrl_msgs__msg__Imu__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rmctrl_msgs__msg__Imu__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rmctrl_msgs__msg__Imu__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
