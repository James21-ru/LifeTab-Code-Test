#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "led_strip.h"
#include "pin_config.h"
#include "esp_log.h"


void status_led_init(void);
// Установка цвета для определенного пикселя
void set_status_led_color(uint32_t red, uint32_t green, uint32_t blue);

// Очистка светодиодной ленты
void clear_status_led();

// Удаление ресурсов светодиодной ленты
void delete_status_led();

void status_led_on(void);

void status_led_off(void);

void status_led_blink(void);