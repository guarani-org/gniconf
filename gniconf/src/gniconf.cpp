// gniconf.cpp : Defines the entry point for the application.
//

#include "gniconf.h"
#include <accel.h>
#include <pugixml.hpp>

bool imu_config_t::serialize(std::string_view file) noexcept
{
    pugi::xml_document doc;
    doc.append_move(accel.node(doc));
    doc.save(std::cout, "    ");
    return false;
}
