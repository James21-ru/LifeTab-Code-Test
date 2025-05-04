#include "ble_command_handler.h"
#include <stdio.h>
#include <string.h>

static const char *TAG = "BLE_COMMAND_HANDLER";
static char json_buffer[1024]; // Буфер для хранения JSON данных
static bool receiving_json = false; // Флаг для отслеживания состояния приема JSON

void bluetooth_command_handle(const char *command) {
    ESP_LOGI(TAG, "Получена команда: %s", command);

    if (strcmp(command, "MOTOR_ON") == 0) {
        xEventGroupSetBits(event_group, BIT_MOTOR_ON);

    } else if (strcmp(command, "MOTOR_OFF") == 0) {
        xEventGroupSetBits(event_group, BIT_MOTOR_OFF);

    } else if (strcmp(command, "LED_ON") == 0) {
        xEventGroupSetBits(event_group, BIT_LED_ON);

    } else if (strcmp(command, "LED_OFF") == 0) {
        xEventGroupSetBits(event_group, BIT_LED_OFF);

    } else if (strcmp(command, "select:0") == 0) {
        xEventGroupSetBits(event_group, BIT_SELECT_CELL0);

    } else if (strcmp(command, "clear:0") == 0) {
        xEventGroupSetBits(event_group, BIT_CLEAR_CELL0);

    } else if (strcmp(command, "select:1") == 0) {
        xEventGroupSetBits(event_group, BIT_SELECT_CELL1);

    } else if (strcmp(command, "clear:1") == 0) {
        xEventGroupSetBits(event_group, BIT_CLEAR_CELL1);

    } else if (strcmp(command, "select:2") == 0) {
        xEventGroupSetBits(event_group, BIT_SELECT_CELL2);
        
    } else if (strcmp(command, "clear:2") == 0) {
        xEventGroupSetBits(event_group, BIT_CLEAR_CELL2);

    } else if (strcmp(command, "select:3") == 0) {
        xEventGroupSetBits(event_group, BIT_SELECT_CELL3);
        
    } else if (strcmp(command, "clear:3") == 0) {
        xEventGroupSetBits(event_group, BIT_CLEAR_CELL3);

    } else if (strcmp(command, "start_trans") == 0) {
        json_buffer[0] = '\0'; // Очистка буфера перед началом новой транзакции
        receiving_json = true; // Начало приема JSON

    } else if (strcmp(command, "fin_trans") == 0) {
        ESP_LOGI(TAG, "Полученные JSON данные: %s", json_buffer); // Вывод данных на экран
        receiving_json = false; // Завершение приема JSON

    } else if (receiving_json) {
        append_json_data(command); // Добавление части JSON в буфер

    } else {
        ESP_LOGW(TAG, "Неизвестная команда: %s", command);
    }
}

void append_json_data(const char* json_data) {
    strncat(json_buffer, json_data, sizeof(json_buffer) - strlen(json_buffer) - 1);
    strncat(json_buffer, "\n", sizeof(json_buffer) - strlen(json_buffer) - 1); // Добавление новой строки после каждого пакета
}