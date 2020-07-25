// gniconf.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <gps.h>
#include <sensors.h>
#include <syscfg.h>

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

struct gniconfig_t {
  sens::sensors_cfg_t sensors_cfg;
  sys::sys_t system_cfg;
  gps::gps_conf_t gps_cfg;

  bool parse(std::string_view file) noexcept;
  bool create(std::string_view file) noexcept;
};

// TODO: Reference additional headers your program requires here.
