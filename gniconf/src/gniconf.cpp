
#include <fstream>
#include <gniconf.h>

bool gniconfig_t::parse(std::string_view file) noexcept {
  pugi::xml_document doc;
  auto resp = doc.load_file(file.data());
  if (resp.status == pugi::status_ok) {
    sensors_cfg.i2c_bus = doc.child("sensors").attribute("bus").as_string();

    sensors_cfg.imu.address =
        doc.child("sensors").child("imu").attribute("address").as_uint();

    if (!sensors_cfg.imu.accel_cfg.parse(doc.child("sensors")
                                             .child("imu")
                                             .child("accelerometer")
                                             .child("configuration"))) {
      return false;
    }

    if (!sensors_cfg.imu.gyro_cfg.parse(doc.child("sensors")
                                            .child("imu")
                                            .child("gyrometer")
                                            .child("configuration"))) {
      return false;
    }

    sensors_cfg.mag.address = doc.child("sensors")
                                  .child("magnetometer")
                                  .attribute("address")
                                  .as_uint();

    if (!sensors_cfg.mag.cfg.parse(doc.child("sensors")
                                       .child("magnetometer")
                                       .child("configuration"))) {
      return false;
    }

    // sensors_cfg.baro.cfg.parse(
    // doc.child("sensors").child("baro").child("configuration"));

    if (!system_cfg.parse(doc.child("system").child("configuration"))) {
      return false;
    }
    if (!gps_cfg.parse(doc.child("gps").child("configuration"))) {
      return false;
    }

    if (!rec_cfg.parse(doc.child("recording").child("configuration"))) {
      return false;
    }

    return true;
  }
  return false;
}
bool gniconfig_t::create(std::string_view file) noexcept {
  pugi::xml_document doc;
  auto sens_node = doc.append_child("sensors");
  auto sys_node = doc.append_child("system").append_child("configuration");
  auto gps_node = doc.append_child("gps").append_child("configuration");
  auto rec_node = doc.append_child("recording").append_child("configuration");

  if (!sensors_cfg.node(sens_node)) {
    return false;
  }
  if (!system_cfg.node(sys_node)) {
    return false;
  }
  if (!gps_cfg.node(gps_node)) {
    return false;
  }
  if (!rec_cfg.node(rec_node)) {
    return false;
  }

  std::ofstream out(file.data(), std::ios::binary | std::ios::out);
  if (out.good()) {
    doc.save(out, "    ");
    return true;
  }

  return false;
}