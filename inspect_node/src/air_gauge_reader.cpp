#include "air_gauge/air_gauge_reader.hpp"
#include "rcutils/logging_macros.h"
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <fcntl.h>
#include <optional>
#include <stdexcept>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <utility>

namespace {

#define let const auto
#define let_mut auto
#define CRC_START_MODBUS 0xFFFF
#define CRC_POLY_16 0xA001

bool crc_tab16_init = false;
uint16_t crc_tab16[256];
u_char read_cmd[8] = {0x01, 0x03, 0x00, 0x01, 0x00, 0x02, 0x95, 0xCB};

// can we construct the table at compile time?
void init_crc16_table() {

  uint16_t i;
  uint16_t j;
  uint16_t crc;
  uint16_t c;

  for (i = 0; i < 256; i++) {

    crc = 0;
    c = i;

    for (j = 0; j < 8; j++) {

      if (((crc ^ c) & 0x0001) > 0)
        crc = (crc >> 1) ^ CRC_POLY_16;
      else
        crc = crc >> 1;

      c = c >> 1;
    }

    crc_tab16[i] = crc;
  }

  crc_tab16_init = true;

} /* init_crc16_tab */

auto crc_modbus(const unsigned char *input_str, size_t num_bytes) -> uint16_t {

  uint16_t crc;
  const unsigned char *ptr;
  size_t a;

  if (!crc_tab16_init)
    init_crc16_table();

  crc = CRC_START_MODBUS;
  ptr = input_str;

  if (ptr != nullptr)
    for (a = 0; a < num_bytes; a++) {

      crc = (crc >> 8) ^
            crc_tab16[(crc ^ static_cast<uint16_t>(*ptr++)) & 0x00FF];
    }

  return crc;

} /* crc_modbus */

} // namespace

namespace inspect_node::air_gauge {

AirGaugeReader::AirGaugeReader(std::string dev_name) noexcept
    : dev_name_(std::move(dev_name)) {}

/**
 * @brief Open the serial device
 */
auto AirGaugeReader::open() -> bool {
  serial_fd_ = ::open(dev_name_.c_str(), O_RDWR);

  struct termios options;

  if (tcgetattr(serial_fd_, &options) < 0) {
    RCUTILS_LOG_ERROR("Error from tcgetattr %s", strerror(errno));
    return false;
  }

  options.c_cflag &= ~PARENB; // no parity
  options.c_cflag &= ~CSTOPB; // 1 stop bit
  options.c_cflag &= ~CSIZE;  // 8 data bits
  options.c_cflag |= CS8;
  options.c_cflag &= ~CRTSCTS; // no hardware flow control
  options.c_cflag |=
      CREAD | CLOCAL; // enable receiver, ignore modem control lines
  options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // raw input
  options.c_oflag &= ~OPOST;                          // raw output

  options.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
  options.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR |
                       ICRNL); // Disable any special handling of received bytes

  // set timeout to 0.1 seconds
  options.c_cc[VMIN] = 0;
  options.c_cc[VTIME] = 8;

  // set baud rate 9600, 8N1
  cfsetispeed(&options, B9600);

  if (tcsetattr(serial_fd_, TCSANOW, &options) < 0) {
    RCUTILS_LOG_WARN_NAMED("air_gauge_reader", "Error %i from tcsetattr: %s\n",
                           errno, strerror(errno));
    return false;
  }
  return true;
}

/**
 * @brief Read the air pressure from the gauge
 *
 * @param retry_times
 * @return std::optional<double>
 */
auto AirGaugeReader::read(int retry_times) const -> std::optional<double> {

  auto read_once = [&]() -> std::optional<double> {
    let n_wr = write(serial_fd_, read_cmd, 8);
    if (n_wr < 0) {
      RCUTILS_LOG_WARN_NAMED("air_gauge_reader",
                             "Error writing to serial port");
      return std::nullopt;
    }

    unsigned char response[1024];
    let n_rd = ::read(serial_fd_, response, 1024);
    if (n_rd < 8) {
      RCUTILS_LOG_WARN_NAMED("air_gauge_reader",
                             "Error reading from serial port");
      return std::nullopt;
    }

    let crc = crc_modbus(response, n_rd - 2);
    let crc_lo = crc >> 8;
    let crc_hi = crc & 0xFF;
    if (crc_hi != response[n_rd - 2] || crc_lo != response[n_rd - 1]) {
      RCUTILS_LOG_WARN_NAMED("air_gauge_reader", "CRC error");
      return std::nullopt;
    }
    //  return
    let num_bytes = response[2];
    if (num_bytes != 4) {
      RCUTILS_LOG_WARN_NAMED("air_gauge_reader",
                             "Unexpected number of bytes %d != 4", num_bytes);

      return std::nullopt;
    }
    let int_part = response[3] << 8 | response[4];
    let dec_part = response[5] << 8 | response[6];

    return int_part + dec_part / 10000.0;
  };

  for (int i = 0; i < retry_times; ++i) {
    if (auto val = read_once(); val.has_value()) {
      return val;
    }
  }

  return std::nullopt;
}

auto AirGaugeReader::is_open() const -> bool { return serial_fd_ != -1; }

AirGaugeReader::~AirGaugeReader() {
  if (is_open()) {
    close(serial_fd_);
  }
}

} // namespace inspect_node::air_gauge