#include <gps.h>

bool gps::gps_conf_t::parse(pugi::xml_node &node) noexcept {

  if (nullptr != node) {

    serial_port = node.attribute("serial_port").as_string();
    baud_rate = node.attribute("baud_rate").as_uint();
    config_file = node.attribute("conf_file").as_string();
  } else {
    _error_flag = true;
  }

  return !_error_flag;
}
bool gps::gps_conf_t::node(pugi::xml_node &node) noexcept {

  if (nullptr != node) {
    node.append_attribute("serial_port") = serial_port.data();
    node.append_attribute("baud_rate") = baud_rate;
    node.append_attribute("conf_file") = config_file.data();

  } else {
    _error_flag = true;
  }

  return !_error_flag;
}
bool gps::gps_conf_t::has_error() noexcept { return false; }