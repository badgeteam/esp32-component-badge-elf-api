// SPDX-License-Identifier: MIT
// SPDX-CopyrightText: 2025 Julian Scheffers, Rene Schickbauer

#pragma once

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Check if network is available.
bool asp_net_is_connected(void);

// Perform HTTP GET request.
// Returns: HTTP status code on success, -1 on error.
int asp_http_get(const char* url, char* response, size_t max_len);

// Perform HTTP POST request.
// Returns: HTTP status code on success, -1 on error.
int asp_http_post(const char* url, const char* body, char* response, size_t max_len);

#ifdef __cplusplus
}
#endif
