#include "main.h"

// static const char *TAG = "MAIN";  

// Глобальная переменная для группы событий
EventGroupHandle_t event_group;


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

// Array of pointers to other service definitions
// UUID - Universal Unique Identifier
static const struct ble_gatt_svc_def gatt_svcs[] = {
    {.type = BLE_GATT_SVC_TYPE_PRIMARY,
     .uuid = BLE_UUID16_DECLARE(0x180),                 // Define UUID for device type
     .characteristics = (struct ble_gatt_chr_def[]){
         {.uuid = BLE_UUID16_DECLARE(0xFEF4),           // Define UUID for reading
          .flags = BLE_GATT_CHR_F_READ,
          .access_cb = device_read},
         {.uuid = BLE_UUID16_DECLARE(0xDEAD),           // Define UUID for writing
          .flags = BLE_GATT_CHR_F_WRITE,
          .access_cb = device_write},
         {0}}},
    {0}};

void app_main() {
    nvs_flash_init();
    esp_nimble_hci_init();  // Инициализация HCI (исправлено)
    nimble_port_init();
    ble_svc_gap_device_name_set("BLE-Server");
    ble_svc_gap_init();
    ble_gatts_count_cfg(gatt_svcs);
    ble_gatts_add_svcs(gatt_svcs);
    ble_svc_gatt_init();
    ble_hs_cfg.sync_cb = ble_app_on_sync;
    nimble_port_freertos_init(host_task);
}
