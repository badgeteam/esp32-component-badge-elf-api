
// SPDX-License-Identiefier: MIT
// SPDX-CopyRightText: 2025 Badge.Team

#include "asp/audio.h"
#include <stdlib.h>
#include "asp/err.h"
#include "bsp/audio.h"
#include "driver/i2s_common.h"
#include "driver/i2s_types.h"
#include "err.h"

// Set audio sampling rate.
asp_err_t asp_audio_set_rate(uint32_t rate_hz) {
    return asp_esp_err_conv(bsp_audio_set_rate(rate_hz));
}

// Get current volume.
asp_err_t asp_audio_get_volume(float* out_percentage) {
    return asp_esp_err_conv(bsp_audio_get_volume(out_percentage));
}

// Set audio volume.
asp_err_t asp_audio_set_volume(float percentage) {
    return asp_esp_err_conv(bsp_audio_set_volume(percentage));
}

// Enable/disable the audio amplifier.
asp_err_t asp_audio_set_amplifier(bool enabled) {
    return asp_esp_err_conv(bsp_audio_set_amplifier(enabled));
}

// Stop the audio stream.
asp_err_t asp_audio_stop() {
    i2s_chan_handle_t handle;
    ASP_RETURN_ON_ERR(asp_esp_err_conv(bsp_audio_get_i2s_handle(&handle)));
    if (!handle) {
        return ASP_ERR_FAIL;
    }
    return i2s_channel_disable(handle);
}

// Start the audio stream.
asp_err_t asp_audio_start() {
    i2s_chan_handle_t handle;
    ASP_RETURN_ON_ERR(asp_esp_err_conv(bsp_audio_get_i2s_handle(&handle)));
    if (!handle) {
        return ASP_ERR_FAIL;
    }
    return i2s_channel_enable(handle);
}

// Write audio samples.
asp_err_t asp_audio_write(void* samples, size_t samples_size, int64_t timeout_ms) {
    i2s_chan_handle_t handle;
    ASP_RETURN_ON_ERR(asp_esp_err_conv(bsp_audio_get_i2s_handle(&handle)));
    if (!handle) {
        return ASP_ERR_FAIL;
    }
    return asp_esp_err_conv(i2s_channel_write(handle, samples, samples_size, NULL, timeout_ms));
}
