
// SPDX-License-Identifier: MIT
// SPDX-CopyRightText: 2025 Badge.Team

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Opaque I2C device handle returned by asp_i2c_open
typedef void* asp_i2c_device_t;

// Forward declaration
typedef struct plugin_context plugin_context_t;

// Open an I2C device on the specified bus.
// bus: 0 = primary (internal), 1 = external (QWIIC/SAO)
// address: 7-bit I2C device address
// speed_hz: clock speed (e.g. 100000 for 100kHz, 400000 for 400kHz)
// Returns opaque device handle, or NULL on failure.
asp_i2c_device_t asp_i2c_open(plugin_context_t* ctx, uint8_t bus, uint16_t address, uint32_t speed_hz);

// Close an I2C device and release resources.
void asp_i2c_close(asp_i2c_device_t device);

// Write data to an I2C device.
// The first byte of data is typically the register address.
bool asp_i2c_write(asp_i2c_device_t device, const uint8_t* data, size_t len);

// Read data from an I2C device.
bool asp_i2c_read(asp_i2c_device_t device, uint8_t* data, size_t len);

// Write then read in a single I2C transaction (repeated start).
bool asp_i2c_write_read(asp_i2c_device_t device,
                         const uint8_t* write_data, size_t write_len,
                         uint8_t* read_data, size_t read_len);

// Probe for an I2C device on the specified bus.
// Returns true if a device responds at the given address.
bool asp_i2c_probe(uint8_t bus, uint16_t address);
