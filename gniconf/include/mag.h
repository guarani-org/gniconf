//
// Created by gui on 7/21/20.
//

#ifndef GNICONF_MAG_H
#define GNICONF_MAG_H
#include <cstdint>

struct mag_config_t{
    uint16_t x_offset;
    uint16_t y_offset;
    uint16_t z_offset;
    uint8_t  temp_compensation; // 0=disabled, 1=enabled
    uint8_t xy_axis_operation;
    uint8_t output_data_rate;
    uint8_t fast_odr;
    uint8_t full_scale;
    uint8_t low_power;
    uint8_t operating_mode;
    uint8_t z_axis_operating_mode;
    uint8_t ble; // big/little endian data selection;
    uint8_t fast_read;
    uint8_t bdu;
};
#endif //GNICONF_MAG_H
