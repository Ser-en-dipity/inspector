// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ins_msgs:msg/Product.idl
// generated code does not contain a copyright notice

#ifndef INS_MSGS__MSG__DETAIL__PRODUCT__TRAITS_HPP_
#define INS_MSGS__MSG__DETAIL__PRODUCT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ins_msgs/msg/detail/product__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ins_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Product & msg,
  std::ostream & out)
{
  out << "{";
  // member: client_id
  {
    out << "client_id: ";
    rosidl_generator_traits::value_to_yaml(msg.client_id, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: desp
  {
    out << "desp: ";
    rosidl_generator_traits::value_to_yaml(msg.desp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Product & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: client_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "client_id: ";
    rosidl_generator_traits::value_to_yaml(msg.client_id, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: desp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "desp: ";
    rosidl_generator_traits::value_to_yaml(msg.desp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Product & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ins_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ins_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ins_msgs::msg::Product & msg,
  std::ostream & out, size_t indentation = 0)
{
  ins_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ins_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ins_msgs::msg::Product & msg)
{
  return ins_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ins_msgs::msg::Product>()
{
  return "ins_msgs::msg::Product";
}

template<>
inline const char * name<ins_msgs::msg::Product>()
{
  return "ins_msgs/msg/Product";
}

template<>
struct has_fixed_size<ins_msgs::msg::Product>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ins_msgs::msg::Product>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ins_msgs::msg::Product>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INS_MSGS__MSG__DETAIL__PRODUCT__TRAITS_HPP_
