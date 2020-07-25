// gniconf.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "mag.h"
#include "accel.h"
#include "gyro.h"
#include <pugixml.hpp>
#include <string>
#include <string_view>


struct imu_config_t {
    mg::data_t mag;
    acc::data_t accel;
    gyr::data_t gyro;

    bool parse(std::string_view file)noexcept;
    bool serialize(std::string_view file)noexcept;
};

// TODO: Reference additional headers your program requires here.
