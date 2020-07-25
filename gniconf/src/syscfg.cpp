#include <syscfg.h>

bool sys::sys_t::parse(pugi::xml_document &doc) noexcept {
  auto node = doc.child("system").child("configuration");
  if (nullptr != node) {
    for (auto &attr : node.attributes()) {
      if (attr.name() == "sync_time_gps") {
        sync_time_with_gps = attr.as_bool();
      }
    }
  } else {
    _error_flag = true;
  }

  return !_error_flag;
}
pugi::xml_node sys::sys_t::node(pugi::xml_document &doc) noexcept {
  auto node = doc.append_child("system").append_child("configuration");
  node.append_attribute("sync_time_gps") = sync_time_with_gps;
  return std::move(node);
}
bool sys::sys_t::has_error() noexcept { return _error_flag; }