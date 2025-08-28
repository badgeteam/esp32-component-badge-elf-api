
// SPDX-License-Identiefier: MIT
// SPDX-CopyRightText: 2025 Julian Scheffers

#include "asp/input.h"
#include <assert.h>
#include "asp/err.h"
#include "asp/input_types.h"
#include "bsp/input.h"
#include "err.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "portmacro.h"

// Check for an input event; sleep for at most `max_delay_ms` (0 is non-blocking).
bool asp_input_poll(asp_input_event_t* event_out, int64_t max_delay_ms) {
    static_assert(sizeof(asp_input_event_t) == sizeof(bsp_input_event_t),
                  "Mismatch in size of event type between ASP and BSP");
    QueueHandle_t queue;
    TickType_t    delay_ticks;
    if (max_delay_ms >= (int64_t)portMAX_DELAY * portTICK_PERIOD_MS * 1000) {
        delay_ticks = portMAX_DELAY;
    } else {
        delay_ticks = pdMS_TO_TICKS(max_delay_ms);
    }
    if (bsp_input_get_queue(&queue) == ESP_OK) {
        return xQueueReceive(queue, event_out, delay_ticks);
    } else {
        ESP_LOGE("badge-elf-api", "BSP doesn't support input queue");
        return false;
    }
}

// Get the current state of a navigation input.
asp_err_t asp_input_get_nav(asp_input_navigation_key_t nav_key, bool* state_out) {
    return asp_esp_err_conv(bsp_input_read_navigation_key(nav_key, state_out));
}

// Get the current state of an action input.
asp_err_t asp_input_get_action(asp_input_action_type_t action, bool* state_out) {
    return asp_esp_err_conv(bsp_input_read_action(action, state_out));
}

// Whether there is a need for an on-screen keyboard.
// TODO: Make a function to pop up the on-screen keyboard.
bool asp_input_needs_on_screen_keyboard() {
    return bsp_input_needs_on_screen_keyboard();
}

// Set the input (usually keyboard) backlight brightness.
asp_err_t asp_input_set_backlight(uint8_t percent) {
    return asp_esp_err_conv(bsp_input_set_backlight_brightness(percent));
}

// Get the input (usually keyboard) backlight brightness.
asp_err_t asp_input_get_backlight(uint8_t* percent_out) {
    return asp_esp_err_conv(bsp_input_get_backlight_brightness(percent_out));
}
