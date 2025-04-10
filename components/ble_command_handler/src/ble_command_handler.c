#include "ble_command_handler.h"

static const char *TAG = "BLE_COMMAND_HANDLER";

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

        
    } else {
        ESP_LOGW(TAG, "Неизвестная команда: %s", command);
    }
}