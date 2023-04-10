#include <functional>
#define let const auto

#include "inspect_node/inspect_node.hpp"
#include "inspect_node/product.hpp"
#include "lifecycle_msgs/msg/state.hpp"
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <exception>
#include <memory>
#include <rclcpp/logging.hpp>
#include <sys/types.h>

using namespace std::literals::chrono_literals;

namespace inspect_node {
auto InspectNode::init() -> CallbackReturn {

  try {
    param_listener_ =
        std::make_shared<ParamListener>(this->get_node_parameters_interface());
    params_ = param_listener_->get_params();

  } catch (const std::exception &e) {
    fprintf(stderr, "Exception: %s", e.what());
    return CallbackReturn::ERROR;
  }

  return CallbackReturn::SUCCESS;
}

auto InspectNode::on_configure(const rclcpp_lifecycle::State &previous_state)
    -> CallbackReturn {

  if (previous_state.id() >
      lifecycle_msgs::msg::State::PRIMARY_STATE_UNCONFIGURED) {
    RCLCPP_WARN(get_logger(), "on_configure was called while in state [%s]. ",
                previous_state.label().c_str());
    return CallbackReturn::SUCCESS;
  }

  if (previous_state.id() !=
      lifecycle_msgs::msg::State::PRIMARY_STATE_UNCONFIGURED) {
    RCLCPP_WARN(get_logger(), "on_configure was called while in state [%s]. ",
                previous_state.label().c_str());
    return CallbackReturn::ERROR;
  }
  let ret = rclcpp_lifecycle::LifecycleNode::on_configure(previous_state);
  if (ret != CallbackReturn::SUCCESS) {
    return ret;
  }

  RCLCPP_INFO(get_logger(), "on_configure()");
  if (params_.air_gauge_spec_names.size() !=
      params_.air_gauge_spec_reader_devices.size()) {
    RCLCPP_ERROR(get_logger(),
                 "spec_names and spec_values must have the same size");
    return CallbackReturn::ERROR;
  }
  let air_gauge_spec_size = params_.air_gauge_spec_names.size();
  air_gauge_readers_.reserve(air_gauge_spec_size);
  air_gauge_results_.reserve(air_gauge_spec_size);

  for (uint idx = 0; idx < air_gauge_spec_size; idx++) {
    let spec_name = params_.air_gauge_spec_names[idx];
    let dev_name = params_.air_gauge_spec_reader_devices[idx];
    auto air_gauge_reader =
        std::make_unique<air_gauge::AirGaugeReader>(dev_name);
    if (!air_gauge_reader->open()) {
      RCLCPP_ERROR(get_logger(), "Failed to open air gauge device");
      return CallbackReturn::ERROR;
    }
    air_gauge_readers_.emplace(spec_name, std::move(air_gauge_reader));
    air_gauge_results_.emplace(spec_name, 0.0);
  }

  publisher_ = this->create_publisher<ins_msgs::msg::Product>("topic", 10);
  timer_ = this->create_wall_timer(1s, [this] { timer_callback_(); });
  return CallbackReturn::SUCCESS;
}

void InspectNode::timer_callback_() {
  // publish msg
  auto message = ins_msgs::msg::Product();
  message.client_id = 0;
  message.name = "test";
  publisher_->publish(message);
  RCLCPP_INFO_STREAM(this->get_logger(),
                     "Publishing: '" << message.name << "'");
}

auto InspectNode::on_activate(const rclcpp_lifecycle::State &previous_state)
    -> CallbackReturn {
  if (previous_state.id() !=
      lifecycle_msgs::msg::State::PRIMARY_STATE_INACTIVE) {
    RCLCPP_WARN(get_logger(), "on_activate was called while in state [%s]. ",
                previous_state.label().c_str());
    return CallbackReturn::SUCCESS;
  }

  let ret = rclcpp_lifecycle::LifecycleNode::on_activate(previous_state);
  if (ret != CallbackReturn::SUCCESS) {
    return ret;
  }

  RCLCPP_INFO(get_logger(), "on_activate()");

  try {
    for (let & [ n, ar ] : air_gauge_readers_) {
      if (!ar->is_open()) {
        if (!ar->open()) {
          RCLCPP_ERROR(get_logger(), "Failed to open air gauge device");
          return CallbackReturn::ERROR;
        }
      }
    }

  } catch (const std::exception &e) {
    RCLCPP_ERROR(get_logger(), "Exception: %s while activate cam", e.what());
    return CallbackReturn::ERROR;
  }

  return CallbackReturn::SUCCESS;
}
auto InspectNode::on_shutdown(const rclcpp_lifecycle::State &previous_state)
    -> CallbackReturn {

  if (previous_state.id() ==
      lifecycle_msgs::msg::State::PRIMARY_STATE_FINALIZED) {
    return CallbackReturn::SUCCESS;
  }

  let ret = rclcpp_lifecycle::LifecycleNode::on_shutdown(previous_state);
  if (ret != CallbackReturn::SUCCESS) {
    return ret;
  }

  RCLCPP_INFO(get_logger(), "on_shutdown()");

  return CallbackReturn::SUCCESS;
}
} // namespace inspect_node