#ifndef INSPECT_NODE__INSPECT_NODE_HPP_
#define INSPECT_NODE__INSPECT_NODE_HPP_

#include "air_gauge/air_gauge_reader.hpp"
#include "inspect_node/product.hpp"
#include "inspect_node/visibility_control.h"
#include "inspect_node_parameters.hpp"
#include "ins_msgs/msg/product.hpp"
#include <atomic>
#include <memory>
#include <mutex>
#include <rclcpp/client.hpp>
#include <rclcpp/service.hpp>
#include <rclcpp/utilities.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace inspect_node {

class InspectNode : public rclcpp_lifecycle::LifecycleNode {
public:
  InspectNode() : InspectNode("inspect_node") {}

  explicit InspectNode(
      const std::string &node_name,
      const rclcpp::NodeOptions &options = rclcpp::NodeOptions())
      : rclcpp_lifecycle::LifecycleNode(node_name, options) {}

  ~InspectNode() override = default;

  /**
   * @brief param listen
   *
   * @return CallbackReturn
   */
  auto init() -> CallbackReturn;

  /**
   * @brief
   *
   * @param previous_state
   * @return CallbackReturn
   */
  auto on_configure(const rclcpp_lifecycle::State &previous_state)
      -> CallbackReturn final;

  auto on_activate(const rclcpp_lifecycle::State &previous_state)
      -> CallbackReturn final;

  auto on_shutdown(const rclcpp_lifecycle::State &previous_state)
      -> CallbackReturn final;

  enum class state {
    IDLE,
    TIME_OUT,
    WAIT_FOR_CB,
  };
  
  [[nodiscard]] auto get_air_gauge_results() const
      -> const std::unordered_map<std::string, double> & {
    return air_gauge_results_;
  }

private:
  Params params_;
  std::shared_ptr<ParamListener> param_listener_;
  using AirGaugeReaderPtr = std::unique_ptr<air_gauge::AirGaugeReader>;
  
  std::unordered_map<std::string, AirGaugeReaderPtr> air_gauge_readers_;
  std::unordered_map<std::string, double> air_gauge_results_;
  };

  void timer_callback() ;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<ins_msgs::msg::Product>::SharedPtr publisher_;
  size_t count_;

} // namespace inspect_node

#endif // INSPECT_NODE__INSPECT_NODE_HPP_
