#pragma once

#include "hall_sensor.h"
#include "status_led.h"
#include "sleep_manager.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "motor.h"

void event_task(void *arg);
