// SPDX-License-Identifier: MIT
// SPDX-CopyrightText: 2026 Rene Schickbauer

#include "asp/log.h"
#include <stdarg.h>
#include "esp_log.h"

void asp_log_info(const char* tag, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    esp_log_writev(ESP_LOG_INFO, tag, fmt, args);
    va_end(args);
}

void asp_log_warn(const char* tag, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    esp_log_writev(ESP_LOG_WARN, tag, fmt, args);
    va_end(args);
}

void asp_log_error(const char* tag, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    esp_log_writev(ESP_LOG_ERROR, tag, fmt, args);
    va_end(args);
}
