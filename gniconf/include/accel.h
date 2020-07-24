//
// Created by gui on 7/20/20.
//

#ifndef GNICONF_ACCEL_H
#define GNICONF_ACCEL_H

#include <cstdint>
#include <pugixml.hpp>
#include <array>

namespace acc {

    static const std::array<char*, 14 > fields = {
       "decimation",
       "z_axis_output_enable",
       "y_axis_output_enable",
       "x_axis_output_enable",
       "output_data_rate",
       "full_scale",
       "bandwidth_selection",
       "antialising_filter_bandwidth_selection",
       "high_resolution_mode",
       "digital_filter_cutoff_frequency",
       "filtered_data_selection",
       "high_pass_filter_enable",
       "bdu",
       "ble",
    };

    enum class fields_index {
        decimation = 0,
        z_axis_output_enable,
        y_axis_output_enable,
        x_axis_output_enable,
        output_data_rate,
        full_scale,
        bandwidth_selection,
        antialising_filter_bandwidth_selection,
        high_resolution_mode,
        digital_filter_cutoff_frequency,
        filtered_data_selection,
        high_pass_filter_enable,
        bdu,
        ble,
        _fields_count
    };


    struct accel_config_t {
        uint8_t& decimation;
        uint8_t& z_axis_output_enable;
        uint8_t& y_axis_output_enable;
        uint8_t& x_axis_output_enable;
        uint8_t& output_data_rate;
        uint8_t& full_scale;
        uint8_t& bandwidth_selection;
        uint8_t& antialising_filter_bandwidth_selection;
        uint8_t& high_resolution_mode;
        uint8_t& digital_filter_cutoff_frequency;
        uint8_t& filtered_data_selection;
        uint8_t& high_pass_filter_enable;
        uint8_t& bdu;
        uint8_t& ble;

        accel_config_t();
        ~accel_config_t() = default;

        bool parse(pugi::xml_document& doc)noexcept;
        pugi::xml_node node(pugi::xml_document& doc)noexcept;

        uint8_t field(fields_index index)noexcept;
        
        bool has_error()noexcept;

        operator bool()const noexcept {
            return _error_flag;
        }

    private:
        bool _error_flag;
        std::array<uint8_t,
            static_cast<size_t>(fields_index::_fields_count)> _fields;
    };
}

#endif //GNICONF_ACCEL_H