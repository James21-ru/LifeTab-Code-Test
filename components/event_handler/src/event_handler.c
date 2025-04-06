#include "event_handler.h"

static const char *TAG = "EVENT_HANDLER";

void event_task(void *arg) {
    while (1) {
        EventBits_t events = xEventGroupWaitBits(
            event_group,
            BIT_HALL_TRIGGERED | BIT_WAKEUP | BIT_MOTOR_ON | BIT_MOTOR_OFF | BIT_LED_ON | BIT_LED_OFF | BIT_SLEEP | ZERO_CELL_LED_ON | FIRST_CELL_LED_ON | SECOND_CELL_LED_ON | THIRD_CELL_LED_ON, 
            pdTRUE,  // Сбрасывать биты после обработки
            pdFALSE, // Ждать любое событие
            portMAX_DELAY
        );

        if (events & BIT_HALL_TRIGGERED) {
            ESP_LOGI(TAG, "Сработал датчик Хола!");
            status_led_blink();
            notify_open_vibro();
        }

        if (events & BIT_WAKEUP) {
            ESP_LOGI(TAG, "ESP32 проснулся!");
            status_led_blink();
        }

        if (events & BIT_MOTOR_ON) {
            ESP_LOGI(TAG, "Включаем мотор!");
            motor_on();
        }

        if (events & BIT_MOTOR_OFF) {
            ESP_LOGI(TAG, "Выключаем мотор!");
            motor_off();
        }

        if (events & BIT_LED_ON) {
            ESP_LOGI(TAG, "Включаем светодиод!");
            status_led_on();
        }

        if (events & BIT_LED_OFF) {
            ESP_LOGI(TAG, "Выключаем светодиод!");
            status_led_off();
        }

        if (events & ZERO_CELL_LED_ON) {
            ESP_LOGI(TAG, "Включаем светодиод 0 ячейки!");
            status_led_on();
            // xEventGroupClearBits(event_group, ZERO_CELL_LED_ON);
        }   

        if (events & FIRST_CELL_LED_ON) {
            ESP_LOGI(TAG, "Включаем светодиод 1 ячейки!");
            status_led_on();
            // xEventGroupClearBits(event_group, FIRST_CELL_LED_ON);
        }   

        if (events & SECOND_CELL_LED_ON) {
            ESP_LOGI(TAG, "Включаем светодиод 2 ячейки!");
            status_led_on();
            // xEventGroupClearBits(event_group, SECOND_CELL_LED_ON);
        }      

        if (events & THIRD_CELL_LED_ON) {
            ESP_LOGI(TAG, "Включаем светодиод 3 ячейки!");
            status_led_on();
            // xEventGroupClearBits(event_group, THIRD_CELL_LED_ON);
        }   

        if (events & ZERO_CELL_LED_OFF) {
            ESP_LOGI(TAG, "Выключаем светодиод 0 ячейки!"); 
            status_led_off();
            // xEventGroupClearBits(event_group, ZERO_CELL_LED_OFF);
        }      

        if (events & FIRST_CELL_LED_OFF) {
            ESP_LOGI(TAG, "Выключаем светодиод 1 ячейки!");
            status_led_off();
            // xEventGroupClearBits(event_group, FIRST_CELL_LED_OFF);
        }      

        if (events & SECOND_CELL_LED_OFF) {
            ESP_LOGI(TAG, "Выключаем светодиод 2 ячейки!");
            status_led_off();
            // xEventGroupClearBits(event_group, SECOND_CELL_LED_OFF);
        }         

        if (events & THIRD_CELL_LED_OFF) {
            ESP_LOGI(TAG, "Выключаем светодиод 3 ячейки!");
            status_led_off();
            // xEventGroupClearBits(event_group, THIRD_CELL_LED_OFF);
        }           
    }
}
