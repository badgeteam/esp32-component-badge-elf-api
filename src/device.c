
// SPDX-License-Identiefier: MIT
// SPDX-CopyRightText: 2025 Badge.Team

#include "bsp/device.h"
#include <stdbool.h>
#include <stdint.h>
#include "asp/err.h"
#include "err.h"

asp_err_t asp_device_get_name(char* output, uint8_t buffer_length) {
    return asp_esp_err_conv(bsp_device_get_name(output, buffer_length));
}

asp_err_t asp_device_get_manufacturer(char* output, uint8_t buffer_length) {
    return asp_esp_err_conv(bsp_device_get_manufacturer(output, buffer_length));
}
