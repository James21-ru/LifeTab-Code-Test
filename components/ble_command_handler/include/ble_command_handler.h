#pragma once 

#include <stdio.h>
#include <string.h>
#include "motor.h"
#include "status_led.h"
#include "sleep_manager.h"
#include "esp_log.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/event_groups.h"
// #include "freertos/task.h"

void bluetooth_command_handle(const char *command);