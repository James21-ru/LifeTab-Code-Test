#pragma once 

#include <stdio.h>
#include <string.h>
#include "motor.h"
#include "status_led.h"
#include "sleep_manager.h"
#include "esp_log.h"

void bluetooth_command_handle(const char *command);