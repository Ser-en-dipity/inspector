// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ins_msgs:msg/Product.idl
// generated code does not contain a copyright notice
#include "ins_msgs/msg/detail/product__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ins_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ins_msgs/msg/detail/product__struct.h"
#include "ins_msgs/msg/detail/product__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // spec_value
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // spec_value
#include "rosidl_runtime_c/string.h"  // desp, name
#include "rosidl_runtime_c/string_functions.h"  // desp, name

// forward declare type support functions


using _Product__ros_msg_type = ins_msgs__msg__Product;

static bool _Product__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Product__ros_msg_type * ros_message = static_cast<const _Product__ros_msg_type *>(untyped_ros_message);
  // Field name: client_id
  {
    cdr << ros_message->client_id;
  }

  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: desp
  {
    const rosidl_runtime_c__String * str = &ros_message->desp;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: timestamp
  {
    cdr << ros_message->timestamp;
  }

  // Field name: spec_value
  {
    size_t size = ros_message->spec_value.size;
    auto array_ptr = ros_message->spec_value.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _Product__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Product__ros_msg_type * ros_message = static_cast<_Product__ros_msg_type *>(untyped_ros_message);
  // Field name: client_id
  {
    cdr >> ros_message->client_id;
  }

  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  // Field name: desp
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->desp.data) {
      rosidl_runtime_c__String__init(&ros_message->desp);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->desp,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'desp'\n");
      return false;
    }
  }

  // Field name: timestamp
  {
    cdr >> ros_message->timestamp;
  }

  // Field name: spec_value
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->spec_value.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->spec_value);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->spec_value, size)) {
      fprintf(stderr, "failed to create array for field 'spec_value'");
      return false;
    }
    auto array_ptr = ros_message->spec_value.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ins_msgs
size_t get_serialized_size_ins_msgs__msg__Product(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Product__ros_msg_type * ros_message = static_cast<const _Product__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name client_id
  {
    size_t item_size = sizeof(ros_message->client_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);
  // field.name desp
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->desp.size + 1);
  // field.name timestamp
  {
    size_t item_size = sizeof(ros_message->timestamp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name spec_value
  {
    size_t array_size = ros_message->spec_value.size;
    auto array_ptr = ros_message->spec_value.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Product__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ins_msgs__msg__Product(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ins_msgs
size_t max_serialized_size_ins_msgs__msg__Product(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: client_id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        10 +
        1;
    }
  }
  // member: desp
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: timestamp
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: spec_value
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Product__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ins_msgs__msg__Product(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Product = {
  "ins_msgs::msg",
  "Product",
  _Product__cdr_serialize,
  _Product__cdr_deserialize,
  _Product__get_serialized_size,
  _Product__max_serialized_size
};

static rosidl_message_type_support_t _Product__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Product,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ins_msgs, msg, Product)() {
  return &_Product__type_support;
}

#if defined(__cplusplus)
}
#endif
