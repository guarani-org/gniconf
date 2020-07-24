#include <accel.h>

bool acc::accel_config_t::parse(pugi::xml_document& doc) noexcept
{
    _error_flag = false;
    int index = 0;

    auto node = doc.child("accelerometer").child("configuration");
  
    if (node == nullptr) {
        _error_flag = true;
        return _error_flag;
    }

    for (auto& attr : node.attributes()) {
        if (index < static_cast<int>(fields_index::_fields_count)) {
            _fields[index++] = static_cast<uint8_t>(attr.as_int());
        }
        else
        {
            _error_flag = true;
            break;
        }
    }

    return _error_flag;
}

pugi::xml_node acc::accel_config_t::node(pugi::xml_document& doc) noexcept
{
    auto node = doc.append_child("accelerometer");
    auto cfg = node.append_child("configuration");

    int index = 0;
    for (auto& field : fields) {
        if (index < static_cast<int>(fields_index::_fields_count)) {
            cfg.append_attribute(field) = _fields[index++];
        }
        else {
            _error_flag = true;
            break;
        }
    }
    return std::move(node);
}

uint8_t acc::accel_config_t::field(fields_index index) noexcept
{
    return _fields[static_cast<uint8_t>(index)];
}

bool acc::accel_config_t::has_error() noexcept
{
    return _error_flag;
}

acc::accel_config_t::accel_config_t() :
    decimation(_fields[static_cast<uint8_t>(fields_index::decimation)]),
    z_axis_output_enable(_fields[static_cast<uint8_t>(fields_index::z_axis_output_enable)]),
    y_axis_output_enable(_fields[static_cast<uint8_t>(fields_index::y_axis_output_enable)]),
    x_axis_output_enable(_fields[static_cast<uint8_t>(fields_index::x_axis_output_enable)]),
    output_data_rate(_fields[static_cast<uint8_t>(fields_index::output_data_rate)]),
    full_scale(_fields[static_cast<uint8_t>(fields_index::full_scale)]),
    bandwidth_selection(_fields[static_cast<uint8_t>(fields_index::bandwidth_selection)]),
    antialising_filter_bandwidth_selection(_fields[static_cast<uint8_t>(fields_index::antialising_filter_bandwidth_selection)]),
    high_resolution_mode(_fields[static_cast<uint8_t>(fields_index::high_resolution_mode)]),
    digital_filter_cutoff_frequency(_fields[static_cast<uint8_t>(fields_index::digital_filter_cutoff_frequency)]),
    filtered_data_selection(_fields[static_cast<uint8_t>(fields_index::filtered_data_selection)]),
    high_pass_filter_enable(_fields[static_cast<uint8_t>(fields_index::high_pass_filter_enable)]),
    bdu(_fields[static_cast<uint8_t>(fields_index::bdu)]),
    ble(_fields[static_cast<uint8_t>(fields_index::ble)]),
    _error_flag(false)
{
    memset(_fields.data(), 0x00, _fields.size());
}