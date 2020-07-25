#include <recorder.h>

bool rec::rec_t::parse(pugi::xml_node &node) noexcept {
  if (node != nullptr) {

    file_size_rollout = node.attribute("file_size_rollout").as_uint();
    file_name_prefix = node.attribute("file_name_prefix").as_string();
    unbuffered = node.attribute("unbuffered_write").as_bool();

  } else {
    _error_flag = true;
  }

  return !_error_flag;
}
bool rec::rec_t::node(pugi::xml_node &node) noexcept {
  if (node != nullptr) {
    node.append_attribute("file_size_rollout") = file_size_rollout;
    node.append_attribute("file_name_prefix") = file_name_prefix.data();
    node.append_attribute("unbuffered_write") = unbuffered;
    return true;
  }
  _error_flag = true;
  return false;
}

bool rec::rec_t::has_error() noexcept { return false; }