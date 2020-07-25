#include <syscfg.h>

bool sys::sys_t::parse(pugi::xml_node &node) noexcept {

  if (nullptr != node) {
    sync_time_with_gps = node.attribute("sync_time_gps").as_bool();
  } else {
    _error_flag = true;
  }

  return !_error_flag;
}

bool sys::sys_t::node(pugi::xml_node &node) noexcept {
  if (node != nullptr) {
    node.append_attribute("sync_time_gps") = sync_time_with_gps;
    return true;
  }

  _error_flag = true;
  return false;
}
bool sys::sys_t::has_error() noexcept { return _error_flag; }