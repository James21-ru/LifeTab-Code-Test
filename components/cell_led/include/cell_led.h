#ifndef CELL_LED_H
#define CELL_LED_H

#include "led_strip.h"

// Инициализация светодиодной ленты
led_strip_handle_t led_strip_init(uint32_t num_leds);

// Установка цвета для определенного пикселя
void set_pixel_color(led_strip_handle_t strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue);

// Очистка светодиодной ленты
void clear_strip(led_strip_handle_t strip);

// Удаление ресурсов светодиодной ленты
void delete_strip(led_strip_handle_t strip);

#endif // CELL_LED_H 