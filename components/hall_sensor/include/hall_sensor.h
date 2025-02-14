#pragma once

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "pin_config.h"
#include "config.h"
#include "freertos/event_groups.h"

extern EventGroupHandle_t event_group;

void hall_sensor_init(void);