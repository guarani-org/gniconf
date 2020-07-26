#pragma once

#include <cstdint>
#include <pugixml.hpp>
namespace inst {
struct install_t {
  double position_x = 0.0, position_y = 0.0, position_z = 0.0;
  bool invert_x_axis = false, invert_y_axis = false, invert_z_axis = false;
  double pitch = 0.0, roll = 0.0, yaw = 0.0;

  bool parse(pugi::xml_node &node) noexcept;
  bool node(pugi::xml_node &node) noexcept;
};
} // namespace inst