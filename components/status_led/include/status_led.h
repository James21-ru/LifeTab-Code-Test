#pragma once 

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "pin_config.h"  
#include "esp_log.h"

void status_led_init(void);

void status_led_on(void);

void status_led_off(void);

void status_led_blink(void);


