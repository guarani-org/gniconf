#include <accel.h>

#define field_at(X) _fields[static_cast<int>(findex::X)]

bool acc::data_t::parse(pugi::xml_node &node) noexcept {
  _error_flag = false;
  int index = 0;
  if (node == nullptr) {
    _error_flag = true;
    return false;
  }

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

bool acc::data_t::node(pugi::xml_node &node) noexcept {

  int index = 0;
  for (auto &field : fname) {
    if (index < static_cast<int>(findex::_fields_count)) {
      node.append_attribute(field) = _fields[index++];
    } else {
      _error_flag = true;
      break;
    }
  }
  return !_error_flag;
}

uint8_t acc::data_t::field(findex index) noexcept {
  return _fields[static_cast<uint8_t>(index)];
}

bool acc::data_t::has_error() noexcept { return _error_flag; }

acc::data_t::data_t()
    : decimation(field_at(decimation)),
      z_axis_output_enable(field_at(z_axis_output_enable)),
      y_axis_output_enable(field_at(y_axis_output_enable)),
      x_axis_output_enable(field_at(x_axis_output_enable)),
      output_data_rate(field_at(output_data_rate)),
      full_scale(field_at(full_scale)),
      bandwidth_selection(field_at(bandwidth_selection)),
      antialising_filter_bandwidth_selection(
          field_at(antialising_filter_bandwidth_selection)),
      high_resolution_mode(field_at(high_resolution_mode)),
      digital_filter_cutoff_frequency(
          field_at(digital_filter_cutoff_frequency)),
      filtered_data_selection(field_at(filtered_data_selection)),
      high_pass_filter_enable(field_at(high_pass_filter_enable)),
      bdu(field_at(bdu)), ble(field_at(ble)), _error_flag(false) {
  memset(_fields.data(), 0x00, _fields.size());
}