#pragma once
#include <array>
#include <cstdint>
#include <pugixml.hpp>

namespace mg {
enum class findex {
  x_offset_h,
  x_offset_l,
  y_offset_h,
  y_offset_l,
  z_offset_h,
  z_offset_l,
  temp_compensation,
  xy_axis_operation,
  output_data_rate,
  fast_odr,
  full_scale,
  low_power,
  operating_mode,
  z_axis_operating_mode,
  ble,
  fast_read,
  bdu,
  _fields_count
};

static const std::array<const char *, static_cast<int>(findex::_fields_count)>
    fname = {"x_offset_h",
             "x_offset_l",
             "y_offset_h",
             "y_offset_l",
             "z_offset_h",
             "z_offset_l",
             "temp_compensation",
             "xy_axis_operation",
             "output_data_rate",
             "fast_odr",
             "full_scale",
             "low_power",
             "operating_mode",
             "z_axis_operating_mode",
             "ble",
             "fast_read",
             "bdu"};

struct data_t {
  uint8_t &x_offset_h;
  uint8_t &x_offset_l;
  uint8_t &y_offset_h;
  uint8_t &y_offset_l;
  uint8_t &z_offset_h;
  uint8_t &z_offset_l;
  uint8_t &temp_compensation;
  uint8_t &xy_axis_operation;
  uint8_t &output_data_rate;
  uint8_t &fast_odr;
  uint8_t &full_scale;
  uint8_t &low_power;
  uint8_t &operating_mode;
  uint8_t &z_axis_operating_mode;
  uint8_t &ble;
  uint8_t &fast_read;
  uint8_t &bdu;

  data_t();
  ~data_t() = default;

  bool parse(pugi::xml_document &doc) noexcept;
  pugi::xml_node node(pugi::xml_document &doc) noexcept;

  uint8_t field(findex index) noexcept;

  bool has_error() noexcept;

  operator bool() const noexcept { return _error_flag; }

private:
  bool _error_flag;
  std::array<uint8_t, static_cast<size_t>(findex::_fields_count)> _fields;
};
} // namespace mg
