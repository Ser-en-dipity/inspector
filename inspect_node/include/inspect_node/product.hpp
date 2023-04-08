#ifndef __INSPECT_NODE__PRODUCT_HPP__
#define __INSPECT_NODE__PRODUCT_HPP__

#include <cstdint>
namespace inspect_node {

struct product {
  double s_5a = 0;
  double s_5b = 0;

  double l = 0;
  double theta = 0;

  bool t_chamfer = true;
  bool b_chamfer = true;

  bool success = false;

  uint8_t top_id;
  uint8_t btm_id;

  // ctor
  product() = default;
};

} // namespace inspect_node

#endif