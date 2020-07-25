#include <sensors.h>

bool sens::sensors_cfg_t::parse(pugi::xml_node &node) noexcept {

  if (node == nullptr) {
    _error_flag = true;
    return false;
  }

  auto node_imu = node.child("imu");
  imu.address = static_cast<uint8_t>(node_imu.attribute("address").as_uint());
  imu.accel_cfg.parse(node_imu.child("acceletrometer").child("configuration"));
  imu.gyro_cfg.parse(node_imu.child("gyrometer").child("configuration"));

  mag.cfg.parse(node.child("magnetometer").child("configuration"));
  // baro.cfg.parse(node.child("barometer").child("configuration"));

  return true;
}

bool sens::sensors_cfg_t::node(pugi::xml_node &node) noexcept {
  if (node != nullptr) {
    node.append_attribute("bus") = i2c_bus.data();
    auto node_imu = node.append_child("imu");
    node_imu.append_attribute("address") = imu.address;

    auto accel_cfg_node =
        node_imu.append_child("accelerometer").append_child("configuration");
    imu.accel_cfg.node(accel_cfg_node);

    auto gyro_cfg_node =
        node_imu.append_child("gyrometer").append_child("configuration");
    imu.gyro_cfg.node(gyro_cfg_node);

    auto mag_node = node.append_child("magnetometer");
    mag_node.append_attribute("address") = mag.address;
    auto mag_node_cfg = mag_node.append_child("configuration");

    mag.cfg.node(mag_node_cfg);

    auto baro_node = node.append_child("baro");
    baro_node.append_attribute("address") = baro.address;
    auto baro_cfg_node = baro_node.append_child("configuration");
    // baro.node(baro_cfg_node);
    return true;
  }

  return false;
}
