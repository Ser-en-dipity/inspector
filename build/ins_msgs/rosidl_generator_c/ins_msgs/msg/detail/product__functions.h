// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ins_msgs:msg/Product.idl
// generated code does not contain a copyright notice

#ifndef INS_MSGS__MSG__DETAIL__PRODUCT__FUNCTIONS_H_
#define INS_MSGS__MSG__DETAIL__PRODUCT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ins_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "ins_msgs/msg/detail/product__struct.h"

/// Initialize msg/Product message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ins_msgs__msg__Product
 * )) before or use
 * ins_msgs__msg__Product__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
bool
ins_msgs__msg__Product__init(ins_msgs__msg__Product * msg);

/// Finalize msg/Product message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
void
ins_msgs__msg__Product__fini(ins_msgs__msg__Product * msg);

/// Create msg/Product message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ins_msgs__msg__Product__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
ins_msgs__msg__Product *
ins_msgs__msg__Product__create();

/// Destroy msg/Product message.
/**
 * It calls
 * ins_msgs__msg__Product__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
void
ins_msgs__msg__Product__destroy(ins_msgs__msg__Product * msg);

/// Check for msg/Product message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
bool
ins_msgs__msg__Product__are_equal(const ins_msgs__msg__Product * lhs, const ins_msgs__msg__Product * rhs);

/// Copy a msg/Product message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
bool
ins_msgs__msg__Product__copy(
  const ins_msgs__msg__Product * input,
  ins_msgs__msg__Product * output);

/// Initialize array of msg/Product messages.
/**
 * It allocates the memory for the number of elements and calls
 * ins_msgs__msg__Product__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
bool
ins_msgs__msg__Product__Sequence__init(ins_msgs__msg__Product__Sequence * array, size_t size);

/// Finalize array of msg/Product messages.
/**
 * It calls
 * ins_msgs__msg__Product__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
void
ins_msgs__msg__Product__Sequence__fini(ins_msgs__msg__Product__Sequence * array);

/// Create array of msg/Product messages.
/**
 * It allocates the memory for the array and calls
 * ins_msgs__msg__Product__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
ins_msgs__msg__Product__Sequence *
ins_msgs__msg__Product__Sequence__create(size_t size);

/// Destroy array of msg/Product messages.
/**
 * It calls
 * ins_msgs__msg__Product__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
void
ins_msgs__msg__Product__Sequence__destroy(ins_msgs__msg__Product__Sequence * array);

/// Check for msg/Product message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
bool
ins_msgs__msg__Product__Sequence__are_equal(const ins_msgs__msg__Product__Sequence * lhs, const ins_msgs__msg__Product__Sequence * rhs);

/// Copy an array of msg/Product messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ins_msgs
bool
ins_msgs__msg__Product__Sequence__copy(
  const ins_msgs__msg__Product__Sequence * input,
  ins_msgs__msg__Product__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // INS_MSGS__MSG__DETAIL__PRODUCT__FUNCTIONS_H_
