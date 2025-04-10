#include "event_handler.h"
#include "led_strip.h"
#include "cell_led.h"

static const char *TAG = "EVENT_HANDLER";

int cell_array[] = {
    [BIT_SELECT_CELL0] = 0,
    [BIT_SELECT_CELL1] = 1,
    [BIT_SELECT_CELL2] = 2,
    [BIT_SELECT_CELL3] = 3,
    [BIT_CLEAR_CELL0] = 0,
    [BIT_CLEAR_CELL1] = 1,
    [BIT_CLEAR_CELL2] = 2,
    [BIT_CLEAR_CELL3] = 3
};

void select_cell(led_strip_handle_t led_strip, int bit_mask){
    int index = cell_array[bit_mask];
    ESP_LOGI(TAG, "Выделили ячейку %d!", index);
    set_pixel_color(led_strip, index, 255, 255, 255); // Белый цвет
    motor_on();
}

void clear_cell(int bit_mask){
    int index = cell_array[bit_mask];
    ESP_LOGI(TAG, "Сняли выделение с ячейки %d!", index);
    status_led_off();
}

void event_task(void *arg) {
    led_strip_handle_t led_strip = led_strip_init(4); // Инициализация ленты с 4 светодиодами
    while (1) {
        EventBits_t events = xEventGroupWaitBits(
            event_group,
            BIT_HALL_TRIGGERED | BIT_WAKEUP | BIT_MOTOR_ON | BIT_MOTOR_OFF | 
            BIT_LED_ON | BIT_LED_OFF | BIT_SLEEP | 
            BIT_CLEAR_CELL0 | BIT_SELECT_CELL0 | 
            BIT_CLEAR_CELL1 | BIT_SELECT_CELL1 | 
            BIT_CLEAR_CELL2 | BIT_SELECT_CELL2 | 
            BIT_CLEAR_CELL3 | BIT_SELECT_CELL3, 
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

        if (events & BIT_SELECT_CELL0) {
            select_cell(led_strip, BIT_SELECT_CELL0);
        }
        if (events & BIT_CLEAR_CELL0) {
            clear_cell(BIT_CLEAR_CELL0);
        }
        if (events & BIT_SELECT_CELL1) {
            select_cell(led_strip, BIT_SELECT_CELL1);
        }
        if (events & BIT_CLEAR_CELL1) {
            clear_cell(BIT_CLEAR_CELL1);
        }
        if (events & BIT_SELECT_CELL2) {
            select_cell(led_strip, BIT_SELECT_CELL2);
        }
        if (events & BIT_CLEAR_CELL2) {
            clear_cell(BIT_CLEAR_CELL2);
        }
        if (events & BIT_SELECT_CELL3) {
            select_cell(led_strip, BIT_SELECT_CELL3);
        }
        if (events & BIT_CLEAR_CELL3) {
            clear_cell(BIT_CLEAR_CELL3);
        }
    }
}
    