#pragma once

#include <pugixml.hpp>

namespace gps {
struct gps_conf_t {
  uint32_t baud_rate;
  std::string serial_port;
  std::string config_file;

  bool parse(pugi::xml_document &doc) noexcept;
  pugi::xml_node node(pugi::xml_document &doc) noexcept;
  bool has_error() noexcept;

private:
  bool _error_flag = false;
};
}