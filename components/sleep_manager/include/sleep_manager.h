#pragma once

#include "esp_sleep.h"
#include "freertos/FreeRTOS.h"
#include "config.h"
#include "freertos/event_groups.h"

extern EventGroupHandle_t event_group;

void enter_light_sleep(void);