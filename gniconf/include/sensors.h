#pragma once

#include <accel.h>
#include <gyro.h>
#include <mag.h>
#include <pugixml.hpp>

namespace sens {
struct imu_t {
  uint8_t address = 0x00;
  gyr::data_t gyro_cfg;
  acc::data_t accel_cfg;
};

struct mag_t {
  uint8_t address = 0x00;
  mg::data_t cfg;
};

struct baro_t {
  uint8_t address = 0x00;
};

struct sensors_cfg_t {
  std::string i2c_bus;
  imu_t imu;
  mag_t mag;
  baro_t baro;

  bool parse(pugi::xml_node &node) noexcept;
  bool node(pugi::xml_node &node) noexcept;

private:
  bool _error_flag = false;
};
} // namespace sens