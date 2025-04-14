#include "status_led.h"
#include "esp_log.h"
#include "led_strip.h"
#include <string.h>

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

void status_led_blink() {
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

void charge_mode(const char* color) {
    if (strcmp(color, "green") == 0) {
        for (int i = 0; i < 255; i += 2) {
            set_status_led_color(0, i, 0);
            vTaskDelay(20 / portTICK_PERIOD_MS);
        }
        vTaskDelay(60 / portTICK_PERIOD_MS);
        for (int i = 255; i > 0; i -= 3) {
            set_status_led_color(0, i, 0);
            vTaskDelay(20 / portTICK_PERIOD_MS);
        }
        set_status_led_color(0, 0, 0);
    } else if (strcmp(color, "yellow") == 0) {
        for (int i = 0; i < 255; i += 2) {
            set_status_led_color(i, i, 0);
            vTaskDelay(20 / portTICK_PERIOD_MS);
        }
        vTaskDelay(60 / portTICK_PERIOD_MS);
        for (int i = 255; i > 0; i -= 3) {
            set_status_led_color(i, i, 0);
            vTaskDelay(20 / portTICK_PERIOD_MS);
        }
        set_status_led_color(0, 0, 0);
    } else if (strcmp(color, "red") == 0) {
        for (int i = 0; i < 255; i += 2) {
            set_status_led_color(i, 0, 0);
            vTaskDelay(20 / portTICK_PERIOD_MS);
        }
        vTaskDelay(60 / portTICK_PERIOD_MS);
        for (int i = 255; i > 0; i -= 3) {
            set_status_led_color(i, 0, 0);
            vTaskDelay(20 / portTICK_PERIOD_MS);
        }
        set_status_led_color(0, 0, 0);
    }
}

void ble_connect_led() {
    ESP_LOGI(TAG, "BLE подключение: мигание зелёным");
    for (int count = 0; count < 2; count++) {
        set_status_led_color(0, 200, 0);
        vTaskDelay(400 / portTICK_PERIOD_MS);
        set_status_led_color(0, 0, 0);
        vTaskDelay(600 / portTICK_PERIOD_MS);
    }
}

void ble_disconnect_led() {
    ESP_LOGI(TAG, "BLE отключение: мигание красным");
    for (int count = 0; count < 2; count++) {
        set_status_led_color(200, 0, 0);
        vTaskDelay(400 / portTICK_PERIOD_MS);
        set_status_led_color(0, 0, 0);
        vTaskDelay(600 / portTICK_PERIOD_MS);
    }
}

void notify_led() {
    ESP_LOGI(TAG, "Уведомление: мигание жёлтым");
    for (int i = 0; i < 4; i++) {
        set_status_led_color(255, 255, 0);
        vTaskDelay(450 / portTICK_PERIOD_MS);
        set_status_led_color(0, 0, 0);
        vTaskDelay(450 / portTICK_PERIOD_MS);
    }
}

void notify_open_led() {
    ESP_LOGI(TAG, "Открытое уведомление: мигание синим");
    for (int i = 0; i < 2; i++) {
        set_status_led_color(0, 0, 255);
        vTaskDelay(450 / portTICK_PERIOD_MS);
        set_status_led_color(0, 0, 0);
        vTaskDelay(450 / portTICK_PERIOD_MS);
    }
}
