// SPDX-License-Identifier: MIT
// SPDX-CopyrightText: 2026 Rene Schickbauer

#include "asp/led.h"
#include "bsp/led.h"
#include "err.h"

uint32_t asp_led_get_count(void) {
    uint32_t count = 0;
    bsp_led_get_count(&count);
    return count;
}

asp_err_t asp_led_set_brightness(uint8_t percentage) {
    return asp_esp_err_conv(bsp_led_set_brightness(percentage));
}

asp_err_t asp_led_get_brightness(uint8_t* out_percentage) {
    if (!out_percentage) return ASP_ERR_PARAM;
    return asp_esp_err_conv(bsp_led_get_brightness(out_percentage));
}

asp_err_t asp_led_set_mode(bool automatic) {
    return asp_esp_err_conv(bsp_led_set_mode(automatic));
}

asp_err_t asp_led_get_mode(bool* out_automatic) {
    if (!out_automatic) return ASP_ERR_PARAM;
    return asp_esp_err_conv(bsp_led_get_mode(out_automatic));
}

asp_err_t asp_led_set_pixel(uint32_t index, uint32_t color) {
    if (index >= asp_led_get_count()) return ASP_ERR_PARAM;
    uint8_t red   = (color >> 16) & 0xFF;
    uint8_t green = (color >> 8) & 0xFF;
    uint8_t blue  = color & 0xFF;
    return asp_led_set_pixel_rgb(index, red, green, blue);
}

asp_err_t asp_led_set_pixel_rgb(uint32_t index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index >= asp_led_get_count()) return ASP_ERR_PARAM;
    return asp_esp_err_conv(bsp_led_set_pixel_rgb(index, red, green, blue));
}

asp_err_t asp_led_set_pixel_hsv(uint32_t index, uint16_t hue, uint8_t saturation, uint8_t value) {
    if (index >= asp_led_get_count()) return ASP_ERR_PARAM;
    return asp_esp_err_conv(bsp_led_set_pixel_hsv(index, hue, saturation, value));
}

asp_err_t asp_led_send(void) {
    return asp_esp_err_conv(bsp_led_send());
}

asp_err_t asp_led_clear(void) {
    uint32_t count = asp_led_get_count();
    for (uint32_t i = 0; i < count; i++) {
        bsp_led_set_pixel_rgb(i, 0, 0, 0);
    }
    return asp_esp_err_conv(bsp_led_send());
}
