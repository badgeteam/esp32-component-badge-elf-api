
// SPDX-License-Identifier: MIT
// SPDX-CopyRightText: 2025 Badge.Team

#include "asp/i2c.h"

// Stub implementations - actual I2C operations are provided by the host (plugin_api.c).
// These exist so the badge-elf-api component compiles; at runtime, kbelf resolves
// the real symbols from the launcher.

asp_err_t asp_i2c_open(plugin_context_t* ctx, asp_i2c_device_t* out_i2c_device_handle, uint8_t bus, uint16_t address, uint32_t speed_hz) {
    (void)ctx; (void)out_i2c_device_handle; (void)bus; (void)address; (void)speed_hz;
    return ASP_ERR_UNSUPPORTED;
}

asp_err_t asp_i2c_close(asp_i2c_device_t device) {
    (void)device;
    return ASP_ERR_UNSUPPORTED;
}

asp_err_t asp_i2c_write(asp_i2c_device_t device, const uint8_t* data, size_t len) {
    (void)device; (void)data; (void)len;
    return ASP_ERR_UNSUPPORTED;
}

asp_err_t asp_i2c_read(asp_i2c_device_t device, uint8_t* data, size_t len) {
    (void)device; (void)data; (void)len;
    return ASP_ERR_UNSUPPORTED;
}

asp_err_t asp_i2c_write_read(asp_i2c_device_t device,
                         const uint8_t* write_data, size_t write_len,
                         uint8_t* read_data, size_t read_len) {
    (void)device; (void)write_data; (void)write_len; (void)read_data; (void)read_len;
    return ASP_ERR_UNSUPPORTED;
}

asp_err_t asp_i2c_probe(uint8_t bus, uint16_t address) {
    (void)bus; (void)address;
    return ASP_ERR_UNSUPPORTED;
}
