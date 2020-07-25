// gniconf.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include "accel.h"
#include "gyro.h"
#include "mag.h"
#include <iostream>
#include <pugixml.hpp>
#include <string>
#include <string_view>

/*TODO
    - recorder configuration
        file size rollout
        file name prefix
        buffer/nobuffer;

        -system
            sync time with gps

        -GPS
            serial port
            baud_rate
            gps_config_file

        -sensors
            i2c-bus
            magnetometer address
            imu address
            barometer address
            baro_config
            mag_config
            imu_config
                accel
                gyrometer
*/

struct imu_config_t {
  mg::data_t mag;
  acc::data_t accel;
  gyr::data_t gyro;

  bool parse(std::string_view file) noexcept;
  bool serialize(std::string_view file) noexcept;
};

// TODO: Reference additional headers your program requires here.
