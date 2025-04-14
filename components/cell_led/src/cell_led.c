#include "cell_led.h"
// Инициализация светодиодной ленты
led_strip_handle_t led_strip_init(uint32_t num_leds) {
    led_strip_handle_t strip = NULL;
    led_strip_config_t strip_config = {
        .strip_gpio_num = LED_STRIP_GPIO,  // GPIO для подключения светодиодной ленты
        .max_leds = num_leds, // Количество светодиодов
    };
    
    led_strip_rmt_config_t rmt_config = {
        .resolution_hz = 10 * 1000 * 1000, // 10MHz
    };
    
    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &strip));
    return strip;
}

// Установка цвета для определенного пикселя
void set_pixel_color(led_strip_handle_t strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue) {
    led_strip_set_pixel(strip, index, red, green, blue);
    led_strip_refresh(strip);
}

// Очистка светодиодной ленты
void clear_strip(led_strip_handle_t strip) {
    led_strip_clear(strip);
    led_strip_refresh(strip);
}

// Удаление ресурсов светодиодной ленты
void delete_strip(led_strip_handle_t strip) {
    led_strip_del(strip);
}
