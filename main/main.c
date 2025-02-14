#include "main.h"

// static const char *TAG = "MAIN";  

// Глобальная переменная для группы событий
EventGroupHandle_t event_group;


// Главная функция
void app_main(void) {
    event_group = xEventGroupCreate(); // Создание группы событий
    
    motor_init();
    motor_off();
    
    status_led_init();
    hall_sensor_init();

    ble_connect_vibro();
    vTaskDelay(pdMS_TO_TICKS(2000));
    ble_disconnect_vibro();
    vTaskDelay(pdMS_TO_TICKS(2000));
    notify_vibro();
    vTaskDelay(pdMS_TO_TICKS(2000));
    notify_open_vibro();

    xTaskCreate(event_task, "event_task", 2048, NULL, 10, NULL);
}
