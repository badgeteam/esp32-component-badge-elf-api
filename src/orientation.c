// SPDX-License-Identifier: MIT
// SPDX-CopyRightText: 2026 Rene Schickbauer

#include "asp/orientation.h"
#include "bsp/orientation.h"
#include "err.h"

asp_err_t asp_orientation_enable_gyroscope(void) {
    return asp_esp_err_conv(bsp_orientation_enable_gyroscope());
}

asp_err_t asp_orientation_disable_gyroscope(void) {
    return asp_esp_err_conv(bsp_orientation_disable_gyroscope());
}

asp_err_t asp_orientation_enable_accelerometer(void) {
    return asp_esp_err_conv(bsp_orientation_enable_accelerometer());
}

asp_err_t asp_orientation_disable_accelerometer(void) {
    return asp_esp_err_conv(bsp_orientation_disable_accelerometer());
}

asp_err_t asp_orientation_get(bool* out_gyro_ready, bool* out_accel_ready,
                              float* out_gyro_x, float* out_gyro_y, float* out_gyro_z,
                              float* out_accel_x, float* out_accel_y, float* out_accel_z) {
    return asp_esp_err_conv(bsp_orientation_get(
        out_gyro_ready, out_accel_ready,
        out_gyro_x, out_gyro_y, out_gyro_z,
        out_accel_x, out_accel_y, out_accel_z));
}
