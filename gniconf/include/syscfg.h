#include <pugixml.hpp>

namespace sys {
struct sys_t {
  bool sync_time_with_gps = true;

  bool parse(pugi::xml_node &node) noexcept;
  bool node(pugi::xml_node &node) noexcept;
  bool has_error() noexcept;

private:
  bool _error_flag = false;
};
} // namespace sys