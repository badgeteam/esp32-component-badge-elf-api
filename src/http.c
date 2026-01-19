// SPDX-License-Identifier: MIT
// SPDX-CopyrightText: 2025 Julian Scheffers, Rene Schickbauer

#include "asp/http.h"
#include <string.h>
#include "esp_http_client.h"
#include "esp_netif.h"

bool asp_net_is_connected(void) {
    // Check if any network interface is up and has an IP
    esp_netif_t* netif = esp_netif_get_handle_from_ifkey("WIFI_STA_DEF");
    if (netif && esp_netif_is_netif_up(netif)) {
        esp_netif_ip_info_t ip_info;
        if (esp_netif_get_ip_info(netif, &ip_info) == ESP_OK) {
            return ip_info.ip.addr != 0;
        }
    }
    return false;
}

int asp_http_get(const char* url, char* response, size_t max_len) {
    esp_http_client_config_t config = {
        .url = url,
        .timeout_ms = 10000,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    if (!client) {
        return -1;
    }

    esp_err_t err = esp_http_client_open(client, 0);
    if (err != ESP_OK) {
        esp_http_client_cleanup(client);
        return -1;
    }

    int content_length = esp_http_client_fetch_headers(client);
    int status_code = esp_http_client_get_status_code(client);

    if (response && max_len > 0 && content_length > 0) {
        size_t read_len = (size_t)content_length < max_len - 1 ? (size_t)content_length : max_len - 1;
        int actual = esp_http_client_read(client, response, read_len);
        if (actual >= 0) {
            response[actual] = '\0';
        }
    }

    esp_http_client_close(client);
    esp_http_client_cleanup(client);

    return status_code;
}

int asp_http_post(const char* url, const char* body, char* response, size_t max_len) {
    esp_http_client_config_t config = {
        .url = url,
        .method = HTTP_METHOD_POST,
        .timeout_ms = 10000,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    if (!client) {
        return -1;
    }

    esp_http_client_set_header(client, "Content-Type", "application/json");

    int body_len = body ? strlen(body) : 0;
    esp_err_t err = esp_http_client_open(client, body_len);
    if (err != ESP_OK) {
        esp_http_client_cleanup(client);
        return -1;
    }

    if (body && body_len > 0) {
        esp_http_client_write(client, body, body_len);
    }

    int content_length = esp_http_client_fetch_headers(client);
    int status_code = esp_http_client_get_status_code(client);

    if (response && max_len > 0 && content_length > 0) {
        size_t read_len = (size_t)content_length < max_len - 1 ? (size_t)content_length : max_len - 1;
        int actual = esp_http_client_read(client, response, read_len);
        if (actual >= 0) {
            response[actual] = '\0';
        }
    }

    esp_http_client_close(client);
    esp_http_client_cleanup(client);

    return status_code;
}
