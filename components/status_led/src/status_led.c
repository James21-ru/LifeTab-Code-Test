#include "status_led.h"
#include "esp_log.h"
#include "led_strip.h"

static const char *TAG = "STATUS_LED";

static led_strip_handle_t status_led;
static led_strip_config_t status_led_config;
static led_strip_rmt_config_t rmt_config;

void status_led_init(void) {
    status_led = NULL; // Глобальная переменная для статусного светодиода

    status_led_config.strip_gpio_num = STATUS_LED_GPIO;  // GPIO для подключения статусного светодиода
    status_led_config.max_leds = 1; // Количество светодиодов

    rmt_config.resolution_hz = 10 * 1000 * 1000; // 10MHz

    esp_err_t err = led_strip_new_rmt_device(&status_led_config, &rmt_config, &status_led);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Ошибка инициализации статусного светодиода: %s", esp_err_to_name(err));
        return;
    }
    ESP_LOGI(TAG, "Статусный светодиод успешно инициализирован");
}




// Установка цвета для определенного пикселя
void set_status_led_color(uint32_t red, uint32_t green, uint32_t blue) {
    led_strip_set_pixel(status_led, 0, red, green, blue);
    led_strip_refresh(status_led);
}

// Очистка светодиодной ленты
void clear_status_led() {
    led_strip_clear(status_led);
    led_strip_refresh(status_led);
}

// Удаление ресурсов светодиодной ленты
void delete_status_led() {
    led_strip_del(status_led);
}


void status_led_on() {
    set_status_led_color(255, 255, 255);
}

void status_led_off() {
    set_status_led_color(0, 0, 0);
}

void status_led_blink(void) {
    ESP_LOGI(TAG, "Мигаем");
    status_led_on();
    vTaskDelay(100 / portTICK_PERIOD_MS);
    
    status_led_off();
    vTaskDelay(100 / portTICK_PERIOD_MS);
    
    status_led_on();
    vTaskDelay(100 / portTICK_PERIOD_MS);
    
    status_led_off();
    vTaskDelay(100 / portTICK_PERIOD_MS);
    
    status_led_on();
    vTaskDelay(100 / portTICK_PERIOD_MS);
    
    status_led_off();
}
