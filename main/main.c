#include "main.h"
#include "cell_led.h"

static const char *TAG = "MAIN";  

EventGroupHandle_t event_group;

extern const struct ble_gatt_svc_def gatt_svcs[];

void app_main() {
    event_group = xEventGroupCreate(); // Создание группы событий
    nvs_flash_init();
    esp_nimble_hci_init();  // Инициализация HCI 
    nimble_port_init();
    ble_svc_gap_device_name_set("LTab-01P");
    ble_svc_gap_init();
    ble_gatts_count_cfg(gatt_svcs);
    ble_gatts_add_svcs(gatt_svcs);
    ble_svc_gatt_init();
    ble_hs_cfg.sync_cb = ble_app_on_sync;
    nimble_port_freertos_init(host_task);

    motor_init();
    motor_off();
    
    // status_led_init();
    hall_sensor_init();

    status_led_init();
    status_led_blink(); 
    status_led_on();

    ble_connect_led();
    ble_disconnect_led();
    notify_led();
    notify_open_led();

    led_strip_handle_t led_strip = led_strip_init(4); // Инициализация ленты с 4 светодиодами
    for (int i = 0; i < 4; i++) {
        set_pixel_color(led_strip, i, 255, 255, 255);
    }

    xTaskCreate(event_task, "event_task", 2048, NULL, 10, NULL);
    led_strip_refresh(led_strip); // Обновление ленты

    xTaskCreate(event_task, "event_task", 2048, NULL, 10, NULL);
}

// // Главная функция
// void app_main(void) {
//     event_group = xEventGroupCreate(); // Создание группы событий
    
//     motor_init();
//     motor_off();
    
//     status_led_init();
//     hall_sensor_init();

//     ble_connect_vibro();
//     vTaskDelay(pdMS_TO_TICKS(2000));
//     ble_disconnect_vibro();
//     vTaskDelay(pdMS_TO_TICKS(2000));
//     notify_vibro();
//     vTaskDelay(pdMS_TO_TICKS(2000));
//     notify_open_vibro();

//     xTaskCreate(event_task, "event_task", 2048, NULL, 10, NULL);
// }