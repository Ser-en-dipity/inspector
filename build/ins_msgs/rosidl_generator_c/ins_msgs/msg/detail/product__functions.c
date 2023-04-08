// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ins_msgs:msg/Product.idl
// generated code does not contain a copyright notice
#include "ins_msgs/msg/detail/product__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `desp`
#include "rosidl_runtime_c/string_functions.h"

bool
ins_msgs__msg__Product__init(ins_msgs__msg__Product * msg)
{
  if (!msg) {
    return false;
  }
  // client_id
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    ins_msgs__msg__Product__fini(msg);
    return false;
  }
  // desp
  if (!rosidl_runtime_c__String__init(&msg->desp)) {
    ins_msgs__msg__Product__fini(msg);
    return false;
  }
  return true;
}

void
ins_msgs__msg__Product__fini(ins_msgs__msg__Product * msg)
{
  if (!msg) {
    return;
  }
  // client_id
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // desp
  rosidl_runtime_c__String__fini(&msg->desp);
}

bool
ins_msgs__msg__Product__are_equal(const ins_msgs__msg__Product * lhs, const ins_msgs__msg__Product * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // client_id
  if (lhs->client_id != rhs->client_id) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // desp
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->desp), &(rhs->desp)))
  {
    return false;
  }
  return true;
}

bool
ins_msgs__msg__Product__copy(
  const ins_msgs__msg__Product * input,
  ins_msgs__msg__Product * output)
{
  if (!input || !output) {
    return false;
  }
  // client_id
  output->client_id = input->client_id;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // desp
  if (!rosidl_runtime_c__String__copy(
      &(input->desp), &(output->desp)))
  {
    return false;
  }
  return true;
}

ins_msgs__msg__Product *
ins_msgs__msg__Product__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ins_msgs__msg__Product * msg = (ins_msgs__msg__Product *)allocator.allocate(sizeof(ins_msgs__msg__Product), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ins_msgs__msg__Product));
  bool success = ins_msgs__msg__Product__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ins_msgs__msg__Product__destroy(ins_msgs__msg__Product * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ins_msgs__msg__Product__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ins_msgs__msg__Product__Sequence__init(ins_msgs__msg__Product__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ins_msgs__msg__Product * data = NULL;

  if (size) {
    data = (ins_msgs__msg__Product *)allocator.zero_allocate(size, sizeof(ins_msgs__msg__Product), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ins_msgs__msg__Product__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ins_msgs__msg__Product__fini(&data[i - 1]);
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
ins_msgs__msg__Product__Sequence__fini(ins_msgs__msg__Product__Sequence * array)
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
      ins_msgs__msg__Product__fini(&array->data[i]);
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

ins_msgs__msg__Product__Sequence *
ins_msgs__msg__Product__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ins_msgs__msg__Product__Sequence * array = (ins_msgs__msg__Product__Sequence *)allocator.allocate(sizeof(ins_msgs__msg__Product__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ins_msgs__msg__Product__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ins_msgs__msg__Product__Sequence__destroy(ins_msgs__msg__Product__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ins_msgs__msg__Product__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ins_msgs__msg__Product__Sequence__are_equal(const ins_msgs__msg__Product__Sequence * lhs, const ins_msgs__msg__Product__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ins_msgs__msg__Product__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ins_msgs__msg__Product__Sequence__copy(
  const ins_msgs__msg__Product__Sequence * input,
  ins_msgs__msg__Product__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ins_msgs__msg__Product);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ins_msgs__msg__Product * data =
      (ins_msgs__msg__Product *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ins_msgs__msg__Product__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ins_msgs__msg__Product__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ins_msgs__msg__Product__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
