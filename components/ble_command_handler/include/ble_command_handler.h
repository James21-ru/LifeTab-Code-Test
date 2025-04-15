#pragma once 

#include <stdio.h>
#include <string.h>
#include "motor.h"
#include "status_led.h"
#include "sleep_manager.h"
#include "esp_log.h"


// void select_cell(int cell_number);
// void clear_cell(int cell_number);
void bluetooth_command_handle(const char *command);
void append_json_data(const char* json_data);