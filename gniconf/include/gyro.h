//
// Created by gui on 7/20/20.
//

#ifndef GNICONF_GYRO_H
#define GNICONF_GYRO_H

#include <cstdint>
#include <pugixml.hpp>
#include <array>
namespace gyr {
    static const std::array<char*, 7> fields = {
        "reference_g",
        "output_data_rate",
        "full_scale",
        "bandwidth_selection",
        "low_power_enable",
        "high_pass_filter_enable",
        "high_pass_cutoff_frequency"
    };
    enum class fields_index {
        reference_g,
        output_data_rate,
        full_scale,
        bandwidth_selection,
        low_power_enable,
        high_pass_filter_enable,
        high_pass_cutoff_frequency,
        _fields_count
    };

    struct gyro_config_t {
        uint8_t &reference_g;
        uint8_t &output_data_rate;
        uint8_t &full_scale;
        uint8_t &bandwidth_selection;
        uint8_t &low_power_enable;
        uint8_t &high_pass_filter_enable;
        uint8_t &high_pass_cutoff_frequency;

        gyro_config_t();
        ~gyro_config_t() = default;

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

#endif //GNICONF_GYRO_H
