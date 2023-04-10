// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ins_msgs:msg/Product.idl
// generated code does not contain a copyright notice

#ifndef INS_MSGS__MSG__DETAIL__PRODUCT__STRUCT_H_
#define INS_MSGS__MSG__DETAIL__PRODUCT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'desp'
#include "rosidl_runtime_c/string.h"
// Member 'spec_value'
#include "rosidl_runtime_c/primitives_sequence.h"

// constants for array fields with an upper bound
// name
enum
{
  ins_msgs__msg__Product__name__MAX_STRING_SIZE = 10
};

/// Struct defined in msg/Product in the package ins_msgs.
typedef struct ins_msgs__msg__Product
{
  int64_t client_id;
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String desp;
  int64_t timestamp;
  rosidl_runtime_c__double__Sequence spec_value;
} ins_msgs__msg__Product;

// Struct for a sequence of ins_msgs__msg__Product.
typedef struct ins_msgs__msg__Product__Sequence
{
  ins_msgs__msg__Product * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ins_msgs__msg__Product__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INS_MSGS__MSG__DETAIL__PRODUCT__STRUCT_H_
