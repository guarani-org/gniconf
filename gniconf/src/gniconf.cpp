// gniconf.cpp : Defines the entry point for the application.
//

#include "gniconf.h"
#include <accel.h>
#include <fstream>
#include <pugixml.hpp>

bool imu_config_t::serialize(std::string_view file) noexcept {
  std::ofstream out(file.data(), std::ios::binary | std::ios::out);
  pugi::xml_document doc;
  doc.append_move(accel.node(doc));
  doc.append_move(gyro.node(doc));
  doc.append_move(mag.node(doc));
  doc.save(out, "    ");
  return false;
}

bool imu_config_t::parse(std::string_view file) noexcept {

  pugi::xml_document doc;
  auto result = doc.load_file(file.data());


  accel.parse(doc);
  gyro.parse(doc);
  mag.parse(doc);
  return false;
}