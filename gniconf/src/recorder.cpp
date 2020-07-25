#include <recorder.h>

bool rec::rec_t::parse(pugi::xml_document &doc) noexcept {

  auto node = doc.child("recording").child("configuration");
  if (node != nullptr) {

    for (auto &attr : node.attributes()) {
      if (attr.name() == "file_size_rollout") {
        file_size_rollout = attr.as_uint();
      }
      if (attr.name() == "file_name_prefix") {
        file_name_prefix = attr.as_string();
      }
      if (attr.name() == "unbuffered_write") {
        unbuffered = attr.as_bool();
      }
    }
  } else {
    _error_flag = true;
  }

  return !_error_flag;
}
pugi::xml_node rec::rec_t::node(pugi::xml_document &doc) noexcept {
  auto node = doc.append_child("recording").append_child("configuration");

  node.append_attribute("file_size_rollout") = file_size_rollout;
  node.append_attribute("file_name_prefix") = file_name_prefix.data();
  node.append_attribute("unbuffered_write") = unbuffered;
  return std::move(node);
}

bool rec::rec_t::has_error() noexcept { return false; }