
// SPDX-License-Identiefier: MIT
// SPDX-CopyRightText: 2025 Badge.Team

#include "err.h"
#include <stddef.h>
#include "esp_err.h"

static char const* const asp_err_id_table[] = {
    [ASP_OK] = "ASP_OK",
#define ASP_ERR_DEF(id, no, desc) [ASP_ERR_##id] = #id,
#include "asp/err.inc"
};

static char const* const asp_err_desc_table[] = {
    [ASP_OK] = "Ok",
#define ASP_ERR_DEF(id, no, desc) [ASP_ERR_##id] = desc,
#include "asp/err.inc"
};

// Get string ID of an `asp_err_t`.
char const* asp_err_id(asp_err_t ec) {
    if (ec < 0 || ec > sizeof(asp_err_id_table) / sizeof(char const* const)) {
        return NULL;
    } else {
        return asp_err_id_table[ec];
    }
}

// Get strinf description of an `asp_err_t`.
char const* asp_err_desc(asp_err_t ec) {
    if (ec < 0 || ec > sizeof(asp_err_desc_table) / sizeof(char const* const)) {
        return NULL;
    } else {
        return asp_err_desc_table[ec];
    }
}

// Convert an `esp_err_t` to an `asp_err_t`.
asp_err_t asp_esp_err_conv(esp_err_t esp_err) {
    switch (esp_err) {
        case ESP_OK:
            return ASP_OK;
        default:
            return ASP_ERR_FAIL;
        case ESP_ERR_NO_MEM:
            return ASP_ERR_NOMEM;
        case ESP_ERR_INVALID_ARG:
            return ASP_ERR_PARAM;
        case ESP_ERR_NOT_SUPPORTED:
            return ASP_ERR_UNSUPPORTED;
        case ESP_ERR_NOT_FOUND:
            return ASP_ERR_NOT_FOUND;
    }
}
