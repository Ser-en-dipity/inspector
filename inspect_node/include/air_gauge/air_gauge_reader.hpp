#ifndef __INSPECT_NODE_AIR_GAUGE_READER_HPP__
#define __INSPECT_NODE_AIR_GAUGE_READER_HPP__

#include <optional>
#include <string>

namespace inspect_node::air_gauge {

class AirGaugeReader {

public:
  AirGaugeReader() = delete;
  explicit AirGaugeReader(std::string dev_name) noexcept;

  ~AirGaugeReader();

  [[nodiscard]] auto open() -> bool;

  [[nodiscard]] auto read(int retry_times = 10) const -> std::optional<double>;

  [[nodiscard]] auto is_open() const -> bool;

private:
  const std::string dev_name_;

  // file descriptor
  int serial_fd_ = -1;
};

} // namespace inspect_node::air_gauge

#endif
