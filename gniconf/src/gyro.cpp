#include <gyro.h>

#define field_at(X) _fields[static_cast<int>(findex::X)]

bool gyr::data_t::parse(pugi::xml_node &node) noexcept {
  _error_flag = false;
  int index = 0;

  if (node != nullptr) {
    for (auto &attr : node.attributes()) {
      if (index < static_cast<int>(findex::_fields_count)) {
        _fields[index++] = static_cast<uint8_t>(attr.as_int());
      } else {
        _error_flag = true;
        break;
      }
    }
  } else {
    _error_flag = true;
  }

  return !_error_flag;
}

bool gyr::data_t::node(pugi::xml_node &node) noexcept {
  if (node == nullptr) {
    _error_flag = true;
    return false;
  }

  int index = 0;
  for (auto &field : fname) {
    if (index < static_cast<int>(findex::_fields_count)) {
      node.append_attribute(field) = _fields[index++];
    } else {
      _error_flag = true;
      break;
    }
  }
  return true;
}

uint8_t gyr::data_t::field(findex index) noexcept {
  return _fields[static_cast<int>(index)];
}

bool gyr::data_t::has_error() noexcept { return false; }

gyr::data_t::data_t()
    : reference_g(field_at(reference_g)),
      output_data_rate(field_at(output_data_rate)),
      full_scale(field_at(full_scale)),
      bandwidth_selection(field_at(bandwidth_selection)),
      low_power_enable(field_at(low_power_enable)),
      high_pass_filter_enable(field_at(high_pass_filter_enable)),
      high_pass_cutoff_frequency(field_at(high_pass_cutoff_frequency)),
      _error_flag(false) {
  memset(_fields.data(), 0x00, _fields.size());
}