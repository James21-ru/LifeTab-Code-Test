#include "ble_command_handler.h"

static const char *TAG = "BLE_COMMAND_HANDLER";

void bluetooth_command_handle(const char *command) {
    ESP_LOGI(TAG, "Получена команда: %s", command);

<<<<<<< HEAD
    if (strncmp(command, "select:", 7) == 0) {
        int cell_number = command[7] - '0'; 
        select_cell(cell_number);
    } else if (strncmp(command, "clear:", 6) == 0) {
        int cell_number = command[6] - '0'; 
        clear_cell(cell_number);
    }

    
}

void select_cell(int cell_number) {
    switch (cell_number) {
        case 0:
            xEventGroupSetBits(event_group, ZERO_CELL_LED_ON);
            ESP_LOGI(TAG, "Включаем светодиод 0 ячейки!");
            break;
        case 1:
            xEventGroupSetBits(event_group, FIRST_CELL_LED_ON);
            ESP_LOGI(TAG, "Включаем светодиод 1 ячейки!");
            break;
        case 2:
            xEventGroupSetBits(event_group, SECOND_CELL_LED_ON);
            ESP_LOGI(TAG, "Включаем светодиод 2 ячейки!");
            break;
        case 3:
            xEventGroupSetBits(event_group, THIRD_CELL_LED_ON);
            ESP_LOGI(TAG, "Включаем светодиод 3 ячейки!");
            break;
        default:
            ESP_LOGW(TAG, "Неизвестный номер ячейки: %d", cell_number);
            break;
    }
    
    
}

void clear_cell(int cell_number) {
    switch (cell_number) {
        case 0:
            xEventGroupSetBits(event_group, ZERO_CELL_LED_OFF);
            ESP_LOGI(TAG, "Выключаем светодиод 0 ячейки!");
            break;
        case 1:
            xEventGroupSetBits(event_group, FIRST_CELL_LED_OFF);        
            ESP_LOGI(TAG, "Выключаем светодиод 1 ячейки!");
            break;
        case 2:
            xEventGroupSetBits(event_group, SECOND_CELL_LED_OFF);
            ESP_LOGI(TAG, "Выключаем светодиод 2 ячейки!");
            break;
        case 3:
            xEventGroupSetBits(event_group, THIRD_CELL_LED_OFF);
            ESP_LOGI(TAG, "Выключаем светодиод 3 ячейки!");
            break;
        default:
            ESP_LOGW(TAG, "Неизвестный номер ячейки: %d", cell_number);
            break;
=======
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
>>>>>>> d0536ee (реализована обработка команд select и clear)
    }
}