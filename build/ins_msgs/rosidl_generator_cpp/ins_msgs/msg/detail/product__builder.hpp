// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ins_msgs:msg/Product.idl
// generated code does not contain a copyright notice

#ifndef INS_MSGS__MSG__DETAIL__PRODUCT__BUILDER_HPP_
#define INS_MSGS__MSG__DETAIL__PRODUCT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ins_msgs/msg/detail/product__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ins_msgs
{

namespace msg
{

namespace builder
{

class Init_Product_desp
{
public:
  explicit Init_Product_desp(::ins_msgs::msg::Product & msg)
  : msg_(msg)
  {}
  ::ins_msgs::msg::Product desp(::ins_msgs::msg::Product::_desp_type arg)
  {
    msg_.desp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ins_msgs::msg::Product msg_;
};

class Init_Product_name
{
public:
  explicit Init_Product_name(::ins_msgs::msg::Product & msg)
  : msg_(msg)
  {}
  Init_Product_desp name(::ins_msgs::msg::Product::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Product_desp(msg_);
  }

private:
  ::ins_msgs::msg::Product msg_;
};

class Init_Product_client_id
{
public:
  Init_Product_client_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Product_name client_id(::ins_msgs::msg::Product::_client_id_type arg)
  {
    msg_.client_id = std::move(arg);
    return Init_Product_name(msg_);
  }

private:
  ::ins_msgs::msg::Product msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ins_msgs::msg::Product>()
{
  return ins_msgs::msg::builder::Init_Product_client_id();
}

}  // namespace ins_msgs

#endif  // INS_MSGS__MSG__DETAIL__PRODUCT__BUILDER_HPP_
