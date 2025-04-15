#pragma once

#include "driver/gpio.h"
#include "pin_config.h"  
#include "config.h" 
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"

void motor_init(void);

void motor_on(void);

void motor_off(void);

void ble_connect_vibro(void);

void ble_disconnect_vibro(void);

void notify_vibro(void);

void notify_open_vibro(void);