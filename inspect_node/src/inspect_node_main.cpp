#define let const auto

#include "inspect_node/inspect_node.hpp"
#include <chrono>
#include <memory>
#include <rclcpp/executors/multi_threaded_executor.hpp>
#include <rclcpp/executors/single_threaded_executor.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/utilities.hpp>
#include <rcutils/logging_macros.h>
#include <sstream>

namespace {

struct worker {
  auto operator()(const std::shared_ptr<inspect_node::InspectNode> &in)
      -> void {
    for (uint idx = 0; idx < 1 && rclcpp::ok(); idx++) {
      using str_ss = std::stringstream;

      str_ss ss;

      for (let & [ n, r ] : in->get_air_gauge_results()) {
        ss << n << ": " << r << ", ";
      }
      RCUTILS_LOG_INFO_NAMED("inspect_node", "%s", ss.str().c_str());
    }

    // rclcpp::shutdown();
  }
};

} // namespace


auto main(int argc, char **argv) -> int {
    rclcpp::init(argc, argv);

    auto inspect_node =
        std::make_shared<inspect_node::InspectNode>("in");

    let executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();

    inspect_node->init();
    inspect_node->configure();
    inspect_node->activate();

    executor->add_node(inspect_node->get_node_base_interface());

    std::jthread t(worker(), inspect_node);

    executor->spin();
    t.join();



    rclcpp::shutdown();

    return 0;
}