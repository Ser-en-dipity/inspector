// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ins_msgs:msg/Product.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ins_msgs/msg/detail/product__rosidl_typesupport_introspection_c.h"
#include "ins_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ins_msgs/msg/detail/product__functions.h"
#include "ins_msgs/msg/detail/product__struct.h"


// Include directives for member types
// Member `name`
// Member `desp`
#include "rosidl_runtime_c/string_functions.h"
// Member `spec_value`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ins_msgs__msg__Product__init(message_memory);
}

void ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_fini_function(void * message_memory)
{
  ins_msgs__msg__Product__fini(message_memory);
}

size_t ins_msgs__msg__Product__rosidl_typesupport_introspection_c__size_function__Product__spec_value(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * ins_msgs__msg__Product__rosidl_typesupport_introspection_c__get_const_function__Product__spec_value(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ins_msgs__msg__Product__rosidl_typesupport_introspection_c__get_function__Product__spec_value(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void ins_msgs__msg__Product__rosidl_typesupport_introspection_c__fetch_function__Product__spec_value(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    ins_msgs__msg__Product__rosidl_typesupport_introspection_c__get_const_function__Product__spec_value(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void ins_msgs__msg__Product__rosidl_typesupport_introspection_c__assign_function__Product__spec_value(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    ins_msgs__msg__Product__rosidl_typesupport_introspection_c__get_function__Product__spec_value(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool ins_msgs__msg__Product__rosidl_typesupport_introspection_c__resize_function__Product__spec_value(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_message_member_array[5] = {
  {
    "client_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ins_msgs__msg__Product, client_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    10,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ins_msgs__msg__Product, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "desp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ins_msgs__msg__Product, desp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ins_msgs__msg__Product, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "spec_value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ins_msgs__msg__Product, spec_value),  // bytes offset in struct
    NULL,  // default value
    ins_msgs__msg__Product__rosidl_typesupport_introspection_c__size_function__Product__spec_value,  // size() function pointer
    ins_msgs__msg__Product__rosidl_typesupport_introspection_c__get_const_function__Product__spec_value,  // get_const(index) function pointer
    ins_msgs__msg__Product__rosidl_typesupport_introspection_c__get_function__Product__spec_value,  // get(index) function pointer
    ins_msgs__msg__Product__rosidl_typesupport_introspection_c__fetch_function__Product__spec_value,  // fetch(index, &value) function pointer
    ins_msgs__msg__Product__rosidl_typesupport_introspection_c__assign_function__Product__spec_value,  // assign(index, value) function pointer
    ins_msgs__msg__Product__rosidl_typesupport_introspection_c__resize_function__Product__spec_value  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_message_members = {
  "ins_msgs__msg",  // message namespace
  "Product",  // message name
  5,  // number of fields
  sizeof(ins_msgs__msg__Product),
  ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_message_member_array,  // message members
  ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_init_function,  // function to initialize message memory (memory has to be allocated)
  ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_message_type_support_handle = {
  0,
  &ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ins_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ins_msgs, msg, Product)() {
  if (!ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_message_type_support_handle.typesupport_identifier) {
    ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
