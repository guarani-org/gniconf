#include <mag.h>

#define field_at(X) _fields[static_cast<int>(findex::X)]

mg::data_t::data_t()
    : x_offset_h(field_at(x_offset_h)), x_offset_l(field_at(x_offset_l)),
      y_offset_h(field_at(y_offset_h)), y_offset_l(field_at(y_offset_l)),
      z_offset_h(field_at(z_offset_h)), z_offset_l(field_at(z_offset_l)),
      temp_compensation(field_at(temp_compensation)),
      xy_axis_operation(field_at(xy_axis_operation)),
      output_data_rate(field_at(output_data_rate)),
      fast_odr(field_at(fast_odr)), full_scale(field_at(full_scale)),
      low_power(field_at(low_power)), operating_mode(field_at(operating_mode)),
      z_axis_operating_mode(field_at(z_axis_operating_mode)),
      ble(field_at(ble)), fast_read(field_at(fast_read)), bdu(field_at(bdu)),
      _error_flag(false) {
  memset(_fields.data(), 0x00, _fields.size());
}

bool mg::data_t::parse(pugi::xml_node &node) noexcept {
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

bool mg::data_t::node(pugi::xml_node &node) noexcept {

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
  return !_error_flag;
}

uint8_t mg::data_t::field(findex index) noexcept {
  return _fields[static_cast<int>(index)];
}