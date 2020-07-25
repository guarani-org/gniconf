#pragma once

#include <pugixml.hpp>

namespace rec {
struct rec_t {
  uint32_t file_size_rollout = 1024; // kb
  std::string file_name_prefix;
  bool unbuffered = false;

  bool parse(pugi::xml_node &node) noexcept;
  bool node(pugi::xml_node &node) noexcept;
  bool has_error() noexcept;

private:
  bool _error_flag = false;
};
} // namespace rec