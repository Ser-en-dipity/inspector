// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ins_msgs:msg/Product.idl
// generated code does not contain a copyright notice

#ifndef INS_MSGS__MSG__DETAIL__PRODUCT__STRUCT_HPP_
#define INS_MSGS__MSG__DETAIL__PRODUCT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ins_msgs__msg__Product __attribute__((deprecated))
#else
# define DEPRECATED__ins_msgs__msg__Product __declspec(deprecated)
#endif

namespace ins_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Product_
{
  using Type = Product_<ContainerAllocator>;

  explicit Product_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->client_id = 0ll;
      this->name = "";
      this->desp = "";
      this->timestamp = 0ll;
    }
  }

  explicit Product_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    desp(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->client_id = 0ll;
      this->name = "";
      this->desp = "";
      this->timestamp = 0ll;
    }
  }

  // field types and members
  using _client_id_type =
    int64_t;
  _client_id_type client_id;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _desp_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _desp_type desp;
  using _timestamp_type =
    int64_t;
  _timestamp_type timestamp;
  using _spec_value_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _spec_value_type spec_value;

  // setters for named parameter idiom
  Type & set__client_id(
    const int64_t & _arg)
  {
    this->client_id = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__desp(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->desp = _arg;
    return *this;
  }
  Type & set__timestamp(
    const int64_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__spec_value(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->spec_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ins_msgs::msg::Product_<ContainerAllocator> *;
  using ConstRawPtr =
    const ins_msgs::msg::Product_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ins_msgs::msg::Product_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ins_msgs::msg::Product_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ins_msgs::msg::Product_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ins_msgs::msg::Product_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ins_msgs::msg::Product_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ins_msgs::msg::Product_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ins_msgs::msg::Product_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ins_msgs::msg::Product_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ins_msgs__msg__Product
    std::shared_ptr<ins_msgs::msg::Product_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ins_msgs__msg__Product
    std::shared_ptr<ins_msgs::msg::Product_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Product_ & other) const
  {
    if (this->client_id != other.client_id) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->desp != other.desp) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->spec_value != other.spec_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const Product_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Product_

// alias to use template instance with default allocator
using Product =
  ins_msgs::msg::Product_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ins_msgs

#endif  // INS_MSGS__MSG__DETAIL__PRODUCT__STRUCT_HPP_
