
// SPDX-License-Identiefier: MIT
// SPDX-CopyRightText: 2025 Badge.Team

#pragma once

#include "asp/err.h"
#include "esp_err.h"

// Convert an `esp_err_t` to an `asp_err_t`.
asp_err_t asp_esp_err_conv(esp_err_t esp_err);
