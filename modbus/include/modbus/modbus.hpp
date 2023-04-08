#ifndef MODBUS__MODBUS_HPP_
#define MODBUS__MODBUS_HPP_

#include "modbus/visibility_control.h"
#include <cstdint>

namespace modbus {

#define MODBUS_OK 0

[[nodiscard]] auto read_single_coil(int fd, uint8_t slave_addr,
                                    uint16_t coil_addr, bool *dest) -> int;
[[nodiscard]] auto read_coil(int fd, uint8_t slave_addr, uint16_t coil_addr,
                             uint16_t num_coils, uint8_t *dest) -> int;
[[nodiscard]] auto write_single_coil(int fd, uint8_t slave_addr,
                                     uint16_t coil_addr, bool value) -> int;
[[nodiscard]] auto read_holding_registers(int fd, uint8_t slave_addr,
                                          uint16_t reg_addr, uint16_t num_regs,
                                          uint16_t *dest) -> int;

[[nodiscard]] auto read_input_registers(int fd, uint8_t slave_addr,
                                        uint16_t reg_addr, uint16_t num_regs,
                                        uint16_t *dest) -> int;

[[nodiscard]] auto write_holding_register(int fd, uint8_t slave_addr,
                                          uint16_t reg_addr, uint16_t value)
    -> int;

auto write_multiple_registers(int fd, uint8_t slave_addr, uint16_t reg_addr,
                              uint16_t num_regs, const uint16_t *src) -> int;
} // namespace modbus

#endif // MODBUS__MODBUS_HPP_
