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

static rosidl_typesupport_introspection_c__MessageMember ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_message_member_array[3] = {
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
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ins_msgs__msg__Product__rosidl_typesupport_introspection_c__Product_message_members = {
  "ins_msgs__msg",  // message namespace
  "Product",  // message name
  3,  // number of fields
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
