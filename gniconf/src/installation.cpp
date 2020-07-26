#include "..\include\installation.h"

bool inst::install_t::parse(pugi::xml_node &node) noexcept {
  if (node != nullptr) {
    auto node_pos = node.child("position");
    position_x = node_pos.attribute("x").as_double();
    position_y = node_pos.attribute("y").as_double();
    position_z = node_pos.attribute("z").as_double();

    auto node_orientation = node.child("orientation");
    invert_x_axis = node_orientation.attribute("invert_x").as_bool();
    invert_y_axis = node_orientation.attribute("invert_y").as_bool();
    invert_z_axis = node_orientation.attribute("invert_z").as_bool();
 

    auto node_tilt = node.child("tilt");
    pitch = node_tilt.attribute("pitch").as_double();
    roll = node_tilt.attribute("roll").as_double();
    yaw = node_tilt.attribute("yaw").as_double();

    return true;
  }
  return false;
}
bool inst::install_t::node(pugi::xml_node &node) noexcept {
  if (node != nullptr) {
    auto node_pos = node.append_child("position");
    node_pos.append_attribute("x") = position_x;
    node_pos.append_attribute("y") = position_y;
    node_pos.append_attribute("z") = position_z;

    auto node_orientation = node.append_child("orientation");
    node_orientation.append_attribute("invert_x") = invert_x_axis;
    node_orientation.append_attribute("invert_y") = invert_y_axis;
    node_orientation.append_attribute("invert_z") = invert_z_axis;

    auto node_tilt = node.append_child("tilt");
    node_tilt.append_attribute("pitch") = pitch;
    node_tilt.append_attribute("roll") = roll;
    node_tilt.append_attribute("yaw") = yaw;
    return true;
  }
  return false;
}