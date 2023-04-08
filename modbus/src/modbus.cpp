#include "modbus/modbus.hpp"
#include "rcutils/logging_macros.h"
#include <cstdio>
#include <cstring>
#include <optional>
#include <sys/types.h>
#include <unistd.h>

namespace {
#define let const auto
#define let_mut auto
#define CRC_START_MODBUS 0xFFFF
#define CRC_POLY_16 0xA001

#ifndef RETRY_TIMES
#define RETRY_TIMES 10
#endif

#ifndef MODBUS_LOG_NAME
#define MODBUS_LOG_NAME "modbus"
#endif

bool crc_tab16_init = false;
uint16_t crc_tab16[256];

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
namespace modbus {

auto read_coil(int fd, uint8_t slave_addr, uint16_t coil_addr,
               uint16_t num_coils, uint8_t *dest) -> int {
  auto read_once = [fd, slave_addr, coil_addr, num_coils, dest]() -> bool {
    u_char read_cmd[8] = {
        slave_addr,
        0x01,
        static_cast<u_char>(coil_addr >> 8),
        static_cast<u_char>(coil_addr & 0xFF),
        static_cast<u_char>(num_coils >> 8),
        static_cast<u_char>(num_coils & 0xFF),
        0x0,
        0x0,
    };

    let crc = crc_modbus(read_cmd, 6);
    read_cmd[7] = crc >> 8;
    read_cmd[6] = crc & 0xFF;

    let n_wr = write(fd, read_cmd, 8);
    if (n_wr < 0) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error writing to serial port %d\n", fd);

      return false;
    }

    unsigned char response[1024];
    let n_rd = ::read(fd, response, 1024);
    if (n_rd < 6) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error reading from serial port\n");
      return false;
    }

    let crc_resp = crc_modbus(response, n_rd - 2);
    let crc_lo = crc_resp >> 8;
    let crc_hi = crc_resp & 0xFF;
    if (crc_hi != response[n_rd - 2] || crc_lo != response[n_rd - 1]) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME, "crc error %d\n", fd);
      return false;
    }
    //  return
    let num_bytes = response[2];
    let num_bytes_expected = (num_coils + 7) / 8;
    if (num_bytes != num_bytes_expected) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME,
                             "Unexpected number of bytes %d != 4\n", num_bytes);
      return false;
    }

    memcpy(dest, response + 3, num_bytes);
    return true;
  };

  for (int i = 0; i < RETRY_TIMES; i++) {
    if (read_once()) {
      return 0;
    }
  }
  return -1;
}
auto read_single_coil(int fd, uint8_t slave_addr, uint16_t coil_addr,
                      bool *dest) -> int {
  auto read_once = [fd, slave_addr, coil_addr, dest]() -> bool {
    u_char read_cmd[8] = {
        slave_addr,
        0x01,
        static_cast<u_char>(coil_addr >> 8),
        static_cast<u_char>(coil_addr & 0xFF),
        0,
        static_cast<u_char>(1 & 0xFF),
        0x0,
        0x0,
    };

    let crc = crc_modbus(read_cmd, 6);
    read_cmd[7] = crc >> 8;
    read_cmd[6] = crc & 0xFF;

    let n_wr = write(fd, read_cmd, 8);
    if (n_wr < 0) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error writing to serial port %d\n", fd);

      return false;
    }

    unsigned char response[1024];
    let n_rd = ::read(fd, response, 1024);
    if (n_rd < 6) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error reading from serial port\n");
      return false;
    }

    let crc_resp = crc_modbus(response, n_rd - 2);
    let crc_lo = crc_resp >> 8;
    let crc_hi = crc_resp & 0xFF;
    if (crc_hi != response[n_rd - 2] || crc_lo != response[n_rd - 1]) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME, "crc error %d\n", fd);
      return false;
    }
    //  return
    let num_bytes = response[2];
    let num_bytes_expected = (1 + 7) / 8;
    if (num_bytes != num_bytes_expected) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME,
                             "Unexpected number of bytes %d != 4\n", num_bytes);
      return false;
    }
    if (response[3] == 0x00)
      *dest = false;
    else
      *dest = true;

    return true;
  };

  for (int i = 0; i < RETRY_TIMES; i++) {
    if (read_once()) {
      return 0;
    }
  }
  return -1;
}

auto write_single_coil(int fd, uint8_t slave_addr, uint16_t coil_addr,
                       bool value) -> int {
  RCUTILS_LOG_DEBUG_NAMED(MODBUS_LOG_NAME, "write_single_coil %d %d %d", fd,
                          slave_addr, coil_addr);
  let write_once = [fd, slave_addr, coil_addr, value]() -> bool {
    u_char write_cmd[8] = {
        slave_addr,
        0x05,
        static_cast<u_char>(coil_addr >> 8),
        static_cast<u_char>(coil_addr & 0xFF),
        static_cast<u_char>(value ? 0xFF : 0x00),
        00,
        0x0,
        0x0,
    };

    let crc = crc_modbus(write_cmd, 6);
    write_cmd[6] = crc & 0xFF;
    write_cmd[7] = crc >> 8;

    let n_wr = write(fd, write_cmd, 8);
    if (n_wr < 0) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error writing to serial port %d\n", fd);
      return false;
    }

    unsigned char response[1024];
    let n_rd = ::read(fd, response, 1024);
    if (n_rd < 8) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error reading from serial port %d\n", fd);
      return false;
    }

    let crc_resp = crc_modbus(response, n_rd - 2);
    let crc_lo = crc_resp >> 8;
    let crc_hi = crc_resp & 0xFF;

    if (crc_hi != response[n_rd - 2] || crc_lo != response[n_rd - 1]) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME, "crc error %d\n", fd);
      return false;
    }

    if (response[0] != slave_addr || response[1] != 0x05) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME, "Unexpected response from %d\n",
                             fd);
      return false;
    }

    if (response[2] != (coil_addr >> 8) || response[3] != (coil_addr & 0xFF)) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME, "Unexpected coil address %d\n",
                             fd);
      return false;
    }

    if (response[4] != (value ? 0xFF : 0x00) || response[5] != 0x00) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME, "Unexpected coil value %d\n", fd);
      return false;
    }

    return true;
  };

  for (int i = 0; i < RETRY_TIMES; i++) {
    if (write_once()) {
      return 0;
    }
  }
  RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME, "write_single_coil failed %d %d %d",
                          fd, slave_addr, coil_addr);
  return -1;
}

auto read_holding_registers(int fd, uint8_t slave_addr, uint16_t reg_addr,
                            uint16_t num_regs, uint16_t *dest) -> int {

  let read_once = [fd, slave_addr, reg_addr, num_regs, dest]() -> bool {
    RCUTILS_LOG_DEBUG_NAMED(MODBUS_LOG_NAME,
                            "read once from fd: %d, slave_addr %d, reg 0x%04x",
                            fd, slave_addr, reg_addr);
    u_char read_cmd[8] = {
        slave_addr,
        0x03,
        static_cast<u_char>(reg_addr >> 8),
        static_cast<u_char>(reg_addr & 0xFF),
        static_cast<u_char>(num_regs >> 8),
        static_cast<u_char>(num_regs & 0xFF),
        0x0,
        0x0,
    };

    let crc = crc_modbus(read_cmd, 6);
    read_cmd[7] = crc >> 8;
    read_cmd[6] = crc & 0xFF;

    let n_wr = write(fd, read_cmd, 8);
    if (n_wr < 0) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error writing to serial port %d\n", fd);
      return false;
    }

    unsigned char response[1024];
    let n_rd = ::read(fd, response, 1024);
    if (n_rd < 8) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error reading from serial port %d\n", fd);

      return false;
    }

    let crc_resp = crc_modbus(response, n_rd - 2);
    let crc_lo = crc_resp >> 8;
    let crc_hi = crc_resp & 0xFF;
    if (crc_hi != response[n_rd - 2] || crc_lo != response[n_rd - 1]) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME, "crc error from serial port %d\n",
                             fd);

      return false;
    }

    let num_bytes = response[2];
    let num_bytes_expected = num_regs * 2;

    if (num_bytes != num_bytes_expected) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME,
                             "Unexpected number of bytes %d != %d\n", num_bytes,
                             num_bytes_expected);
      return false;
    }

    RCUTILS_LOG_DEBUG_NAMED(MODBUS_LOG_NAME, "num_bytes: %d", num_bytes);
    // dump content
    for (int i = 0; i < num_bytes; i++) {
      let start_pos = 3 + i * 2;
      dest[i] = response[start_pos] << 8 | response[start_pos + 1];
    }
    // memcpy(dest, response + 3, num_bytes);

    return true;
  };

  for (int i = 0; i < RETRY_TIMES; i++) {
    if (read_once()) {
      return 0;
    }
  }
  return -1;
}

auto read_input_registers(int fd, uint8_t slave_addr, uint16_t reg_addr,
                          uint16_t num_regs, uint16_t *dest) -> int {

  let read_once = [fd, slave_addr, reg_addr, num_regs, dest]() -> bool {
    RCUTILS_LOG_DEBUG_NAMED(MODBUS_LOG_NAME,
                            "read once from fd: %d, slave_addr %d, reg 0x%04x",
                            fd, slave_addr, reg_addr);
    u_char read_cmd[8] = {
        slave_addr,
        0x04,
        static_cast<u_char>(reg_addr >> 8),
        static_cast<u_char>(reg_addr & 0xFF),
        static_cast<u_char>(num_regs >> 8),
        static_cast<u_char>(num_regs & 0xFF),
        0x0,
        0x0,
    };

    let crc = crc_modbus(read_cmd, 6);
    read_cmd[7] = crc >> 8;
    read_cmd[6] = crc & 0xFF;

    let n_wr = write(fd, read_cmd, 8);
    if (n_wr < 0) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error writing to serial port %d\n", fd);
      return false;
    }

    unsigned char response[1024];
    let n_rd = ::read(fd, response, 1024);
    if (n_rd < 8) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error reading from serial port %d\n", fd);

      return false;
    }

    let crc_resp = crc_modbus(response, n_rd - 2);
    let crc_lo = crc_resp >> 8;
    let crc_hi = crc_resp & 0xFF;
    if (crc_hi != response[n_rd - 2] || crc_lo != response[n_rd - 1]) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME, "crc error from serial port %d\n",
                             fd);

      return false;
    }

    let num_bytes = response[2];
    let num_bytes_expected = num_regs * 2;

    if (num_bytes != num_bytes_expected) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME,
                             "Unexpected number of bytes %d != %d\n", num_bytes,
                             num_bytes_expected);
      return false;
    }

    RCUTILS_LOG_DEBUG_NAMED(MODBUS_LOG_NAME, "num_bytes: %d", num_bytes);
    // dump content
    for (int i = 0; i < num_bytes; i++) {
      let start_pos = 3 + i * 2;
      dest[i] = response[start_pos] << 8 | response[start_pos + 1];
    }

    return true;
  };

  for (int i = 0; i < RETRY_TIMES; i++) {
    if (read_once()) {
      return 0;
    }
  }
  return -1;
}

auto write_holding_register(int fd, uint8_t slave_addr, uint16_t reg_addr,
                            uint16_t value) -> int {
  RCUTILS_LOG_DEBUG_NAMED(
      MODBUS_LOG_NAME,
      "write holding register; fd: %d slave_addr: %d reg_addr 0x%04x", fd,
      slave_addr, reg_addr);
  let write_once = [fd, slave_addr, reg_addr, value]() -> bool {
    u_char write_cmd[8] = {
        slave_addr,
        0x06,
        static_cast<u_char>(reg_addr >> 8),
        static_cast<u_char>(reg_addr & 0xFF),
        static_cast<u_char>(value >> 8),
        static_cast<u_char>(value & 0xFF),
        0x0,
        0x0,
    };

    let crc = crc_modbus(write_cmd, 6);
    write_cmd[6] = crc & 0xFF;
    write_cmd[7] = crc >> 8;

    let n_wr = write(fd, write_cmd, 8);
    if (n_wr < 0) {
      // printf("Error writing to serial port %d\n", fd);
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error writing to serial port %d\n", fd);
      return false;
    }

    unsigned char response[1024];
    let n_rd = ::read(fd, response, 1024);
    if (n_rd < 8) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME,
                              "Error reading from serial port %d\n", fd);
      return false;
    }

    let crc_resp = crc_modbus(response, n_rd - 2);
    let crc_lo = crc_resp >> 8;
    let crc_hi = crc_resp & 0xFF;
    if (crc_hi != response[n_rd - 2] || crc_lo != response[n_rd - 1]) {
      // printf("CRC error\n");
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME, "CRC error\n");
      return false;
    }

    if (response[0] != slave_addr || response[1] != 0x06) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME, "Unexpected response\n");
      return false;
    }
    if (response[2] != (reg_addr >> 8) || response[3] != (reg_addr & 0xFF)) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME, "Unexpected register address\n");
      return false;
    }
    if (response[4] != (value >> 8) || response[5] != (value & 0xFF)) {
      RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME, "Unexpected register value\n");
      return false;
    }

    return true;
  };

  for (int i = 0; i < RETRY_TIMES; i++) {
    if (write_once()) {
      return 0;
    }
  }
  return -1;
}

auto write_multiple_registers(int fd, uint8_t slave_addr, uint16_t reg_addr,
                              uint16_t num_regs, const uint16_t *src) -> int {
  let write_once = [fd, slave_addr, reg_addr, num_regs, src]() -> bool {
    u_char write_cmd[1024] = {
        slave_addr,
        0x10,
        static_cast<u_char>(reg_addr >> 8),
        static_cast<u_char>(reg_addr & 0xFF),
        static_cast<u_char>(num_regs >> 8),
        static_cast<u_char>(num_regs & 0xFF),
        static_cast<u_char>(num_regs * 2),
    };

    for (int i = 0; i < num_regs; i++) {
      write_cmd[7 + i * 2] = static_cast<u_char>(src[i] >> 8);
      write_cmd[8 + i * 2] = static_cast<u_char>(src[i] & 0xFF);
    }

    let crc = crc_modbus(write_cmd, 7 + num_regs * 2);
    write_cmd[7 + num_regs * 2 + 1] = crc >> 8;
    write_cmd[7 + num_regs * 2] = crc & 0xFF;

    let n_wr = write(fd, write_cmd, 7 + num_regs * 2 + 2);
    if (n_wr < 0) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME,
                             "Error writing to serial port %d\n", fd);
      return false;
    }

    unsigned char response[1024];
    let n_rd = ::read(fd, response, 1024);
    if (n_rd < 6) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME,
                             "Error reading from serial port %d\n", fd);
      return false;
    }

    let crc_resp = crc_modbus(response, n_rd - 2);
    let crc_lo = crc_resp >> 8;
    let crc_hi = crc_resp & 0xFF;
    if (crc_hi != response[n_rd - 2] || crc_lo != response[n_rd - 1]) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME, "crc error from serial port %d\n",
                             fd);
      return false;
    }

    if (response[0] != slave_addr || response[1] != 0x10) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME,
                             "Unexpected response from serial "
                             "port %d; slave_addr: %d "
                             "response[0]: %d response[1]: %d",
                             fd, slave_addr, response[0], response[1]);
    };

    if (response[2] != (reg_addr >> 8) || response[3] != (reg_addr & 0xFF)) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME,
                             "Unexpected register address from serial "
                             "port %d; reg_addr: 0x%04x "
                             "response[2]: %d response[3]: %d",
                             fd, reg_addr, response[2], response[3]);
      return false;
    }

    if (response[4] != (num_regs >> 8) || response[5] != (num_regs & 0xFF)) {
      RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME,
                             "Unexpected register number from serial "
                             "port %d; num_regs: %d "
                             "response[4]: %d response[5]: %d",
                             fd, num_regs, response[4], response[5]);
      return false;
    }

    return true;
  };

  for (int i = 0; i < RETRY_TIMES; i++) {
    if (write_once()) {
      return 0;
    }
    RCUTILS_LOG_WARN_NAMED(MODBUS_LOG_NAME,
                           "write_multiple_registers times:%d failed", i);
  }
  RCUTILS_LOG_ERROR_NAMED(MODBUS_LOG_NAME, "write_multiple_registers failed");
  return -1;
}

} // namespace modbus
