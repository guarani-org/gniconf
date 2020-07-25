#pragma once
#include <array>
#include <cstdint>
#include <pugixml.hpp>
namespace gyr {

enum class findex {
  reference_g,
  output_data_rate,
  full_scale,
  bandwidth_selection,
  low_power_enable,
  high_pass_filter_enable,
  high_pass_cutoff_frequency,
  _fields_count
};
static const std::array<const char *, static_cast<int>(findex::_fields_count)>
    fname = {"reference_g",
             "output_data_rate",
             "full_scale",
             "bandwidth_selection",
             "low_power_enable",
             "high_pass_filter_enable",
             "high_pass_cutoff_frequency"};

struct data_t {
  uint8_t &reference_g;
  uint8_t &output_data_rate;
  uint8_t &full_scale;
  uint8_t &bandwidth_selection;
  uint8_t &low_power_enable;
  uint8_t &high_pass_filter_enable;
  uint8_t &high_pass_cutoff_frequency;

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
} // namespace gyr
