#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "config.h"
#include "esp_adc/adc_oneshot.h"

extern EventGroupHandle_t event_group;

// void init_adc(void);
