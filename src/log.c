// SPDX-License-Identifier: MIT
// SPDX-CopyrightText: 2026 Rene Schickbauer

#include "asp/log.h"
#include <stdarg.h>
#include <stdio.h>
#include "esp_log.h"

// esp_log_writev writes raw bytes only — no timestamp, level prefix or
// trailing newline. ESP_LOGx macros add all of that, but they also expand
// `format` at compile time. To get proper formatting with a runtime `tag`
// and `fmt`, format the user's message into a buffer first and then hand
// it off to the macro as a single `%s` argument.

#define ASP_LOG_BUF_SIZE 256

void asp_log_info(const char* tag, const char* fmt, ...) {
    char    buf[ASP_LOG_BUF_SIZE];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    ESP_LOGI(tag, "%s", buf);
}

void asp_log_warn(const char* tag, const char* fmt, ...) {
    char    buf[ASP_LOG_BUF_SIZE];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    ESP_LOGW(tag, "%s", buf);
}

void asp_log_error(const char* tag, const char* fmt, ...) {
    char    buf[ASP_LOG_BUF_SIZE];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    ESP_LOGE(tag, "%s", buf);
}
