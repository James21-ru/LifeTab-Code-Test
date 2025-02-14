#include "event_handler.h"

static const char *TAG = "EVENT_HANDLER";

void event_task(void *arg) {
    while (1) {
        EventBits_t events = xEventGroupWaitBits(event_group, BIT_HALL_TRIGGERED | BIT_WAKEUP, pdTRUE, pdFALSE, portMAX_DELAY);

        if (events & BIT_HALL_TRIGGERED) {
            ESP_LOGI(TAG, "Сработал датчик Хола!");
            status_led_blink();
            notify_open_vibro();
        }

        if (events & BIT_WAKEUP) {
            ESP_LOGI(TAG, "ESP32 проснулся!");
            status_led_blink();
        }
    }
}
