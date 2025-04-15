#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "led_strip.h"
#include "pin_config.h"
#include "esp_log.h"


void status_led_init();

void set_status_led_color(uint32_t red, uint32_t green, uint32_t blue);

void clear_status_led();

void delete_status_led();

void status_led_on();

void status_led_off();

void status_led_blink();

void charge_mode(const char* color);

void ble_connect_led();

void ble_disconnect_led();

void notify_led();

void notify_open_led();