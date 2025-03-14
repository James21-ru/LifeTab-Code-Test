#include "ble_command_handler.h"

static const char *TAG = "BLE_COMMAND_HANDLER";

// void bluetooth_command_handle(const char *command) {
//     ESP_LOGI(TAG, "Получена команда: %s", command);

//     if (strcmp(command, "MOTOR_ON") == 0) {
//         motor_on();
//     } else if (strcmp(command, "MOTOR_OFF") == 0) {
//         motor_off();
//     // } else if (strcmp(command, "LED_ON") == 0) {
//     //     status_led_on();
//     // } else if (strcmp(command, "LED_OFF") == 0) {
//     //     status_led_off();
//     // } else if (strcmp(command, "SLEEP") == 0) {
//     //     enter_sleep_mode();
//     } else {
//         ESP_LOGW(TAG, "Неизвестная команда: %s", command);
//     }
// }

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
    // } else if (strcmp(command, "SLEEP") == 0) {
    //     xEventGroupSetBits(event_group, BIT_SLEEP);
    } else {
        ESP_LOGW(TAG, "Неизвестная команда: %s", command);
    }
}