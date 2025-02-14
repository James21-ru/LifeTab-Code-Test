#include "status_led.h"

static const char *TAG = "STATUS_LED";

void status_led_init(void) {
    ESP_LOGI(TAG, "Инициализация статусного светодиода");
    gpio_reset_pin(STATUS_LED_GPIO);
    gpio_set_direction(STATUS_LED_GPIO, GPIO_MODE_OUTPUT);
}

void status_led_on(void) {
    gpio_set_level(STATUS_LED_GPIO, 0);
}

void status_led_off(void) {
    gpio_set_level(STATUS_LED_GPIO, 1);
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