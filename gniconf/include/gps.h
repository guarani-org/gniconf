#pragma once

#include <pugixml.hpp>

namespace gps {
struct gps_conf_t {
  uint32_t baud_rate = 0;
  std::string serial_port;
  std::string config_file;

  bool parse(pugi::xml_node &node) noexcept;
  bool node(pugi::xml_node &node) noexcept;
  bool has_error() noexcept;

private:
  bool _error_flag = false;
};
} // namespace gps