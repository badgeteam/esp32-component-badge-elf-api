
// SPDX-License-Identifier: MIT
// SPDX-CopyRightText: 2025 Badge.Team

#include "asp/power.h"
#include "bsp/power.h"
#include "err.h"

asp_err_t asp_power_get_battery_info(asp_battery_info_t* out_info) {
    if (!out_info) {
        return ASP_ERR_PARAM;
    }

    bsp_power_battery_information_t bsp_info = {0};
    esp_err_t err = bsp_power_get_battery_information(&bsp_info);
    if (err != ESP_OK) {
        return asp_esp_err_conv(err);
    }

    out_info->power_supply_available = bsp_info.power_supply_available;
    out_info->battery_available = bsp_info.battery_available;
    out_info->charging_disabled = bsp_info.charging_disabled;
    out_info->battery_charging = bsp_info.battery_charging;
    out_info->voltage = bsp_info.voltage;
    out_info->charging_target_voltage = bsp_info.charging_target_voltage;
    out_info->maximum_charging_current = bsp_info.maximum_charging_current;
    out_info->current_charging_current = bsp_info.current_charging_current;
    out_info->remaining_percentage = (uint8_t)bsp_info.remaining_percentage;

    return ASP_OK;
}

asp_err_t asp_power_get_system_voltage(uint16_t* out_millivolt) {
    if (!out_millivolt) {
        return ASP_ERR_PARAM;
    }
    return asp_esp_err_conv(bsp_power_get_system_voltage(out_millivolt));
}

asp_err_t asp_power_get_battery_voltage(uint16_t* out_millivolt) {
    if (!out_millivolt) {
        return ASP_ERR_PARAM;
    }
    return asp_esp_err_conv(bsp_power_get_battery_voltage(out_millivolt));
}

asp_err_t asp_power_get_input_voltage(uint16_t* out_millivolt) {
    if (!out_millivolt) {
        return ASP_ERR_PARAM;
    }
    return asp_esp_err_conv(bsp_power_get_input_voltage(out_millivolt));
}

asp_err_t asp_power_get_charging_config(bool* out_disabled, uint16_t* out_current_ma) {
    return asp_esp_err_conv(bsp_power_get_charging_configuration(out_disabled, out_current_ma));
}

asp_err_t asp_power_set_charging(bool disable, uint16_t current_ma) {
    return asp_esp_err_conv(bsp_power_configure_charging(disable, current_ma));
}

asp_err_t asp_power_get_usb_boost(bool* out_enabled) {
    if (!out_enabled) {
        return ASP_ERR_PARAM;
    }
    return asp_esp_err_conv(bsp_power_get_usb_host_boost_enabled(out_enabled));
}

asp_err_t asp_power_set_usb_boost(bool enable) {
    return asp_esp_err_conv(bsp_power_set_usb_host_boost_enabled(enable));
}
