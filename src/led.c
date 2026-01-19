// SPDX-License-Identifier: MIT
// SPDX-CopyrightText: 2025 Julian Scheffers, Rene Schickbauer

#include "asp/led.h"
#include "bsp/led.h"
#include "esp_err.h"

bool asp_led_set_brightness(uint8_t percentage) {
    return bsp_led_set_brightness(percentage) == ESP_OK;
}

bool asp_led_get_brightness(uint8_t* out_percentage) {
    if (!out_percentage) return false;
    return bsp_led_get_brightness(out_percentage) == ESP_OK;
}

bool asp_led_set_mode(bool automatic) {
    return bsp_led_set_mode(automatic) == ESP_OK;
}

bool asp_led_get_mode(bool* out_automatic) {
    if (!out_automatic) return false;
    return bsp_led_get_mode(out_automatic) == ESP_OK;
}

bool asp_led_set_pixel(uint32_t index, uint32_t color) {
    if (index >= ASP_LED_COUNT) return false;
    uint8_t red   = (color >> 16) & 0xFF;
    uint8_t green = (color >> 8) & 0xFF;
    uint8_t blue  = color & 0xFF;
    return asp_led_set_pixel_rgb(index, red, green, blue);
}

bool asp_led_set_pixel_rgb(uint32_t index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index >= ASP_LED_COUNT) return false;
    return bsp_led_set_pixel_rgb(index, red, green, blue) == ESP_OK;
}

bool asp_led_set_pixel_hsv(uint32_t index, uint16_t hue, uint8_t saturation, uint8_t value) {
    if (index >= ASP_LED_COUNT) return false;
    return bsp_led_set_pixel_hsv(index, hue, saturation, value) == ESP_OK;
}

bool asp_led_send(void) {
    return bsp_led_send() == ESP_OK;
}

bool asp_led_clear(void) {
    for (uint32_t i = 0; i < ASP_LED_COUNT; i++) {
        bsp_led_set_pixel_rgb(i, 0, 0, 0);
    }
    return bsp_led_send() == ESP_OK;
}
