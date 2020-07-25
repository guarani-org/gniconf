#include <gps.h>
/*serial port
            baud_rate
            gps_config_file*/
bool gps::gps_conf_t::parse(pugi::xml_document &doc) noexcept {
  auto node = doc.child("gps").child("configuration");

  if (nullptr != node) {

    serial_port = node.attribute("serial_port").as_string();
    baud_rate = node.attribute("baud_rate").as_uint();
    config_file = node.attribute("conf_file").as_string();
  } else {
    _error_flag = true;
  }

  return !_error_flag;
}
pugi::xml_node gps::gps_conf_t::node(pugi::xml_document &doc) noexcept {
  auto node = doc.append_child("gps").append_child("configuration");
  if (nullptr != node) {
    node.append_attribute("serial_port") = serial_port.data();
    node.append_attribute("baud_arte") = baud_rate;
    node.append_attribute("conf_file") = config_file.data();

  } else {
    _error_flag = true;
  }

  return std::move(node);
}
bool gps::gps_conf_t::has_error() noexcept { return false; }