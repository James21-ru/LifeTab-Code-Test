#include "ble_uart.h"

static uint8_t ble_addr_type;

char *TAG = "BLE-Server";

const struct ble_gatt_svc_def gatt_svcs[] = {
    {.type = BLE_GATT_SVC_TYPE_PRIMARY,
     .uuid = BLE_UUID128_DECLARE(0x9E, 0xCA, 0xDC, 0x24, 0x0E, 0xE5, 0xA9, 0xE0, 
                                0x93, 0xF3, 0xA3, 0xB5, 0x01, 0x00, 0x40, 0x6E),  // UUID NUS
     .characteristics = (struct ble_gatt_chr_def[]){
         {.uuid = BLE_UUID128_DECLARE(0x9E, 0xCA, 0xDC, 0x24, 0x0E, 0xE5, 0xA9, 0xE0,
                                    0x93, 0xF3, 0xA3, 0xB5, 0x03, 0x00, 0x40, 0x6E),  // UUID TX
          .flags = BLE_GATT_CHR_F_NOTIFY,
          .access_cb = device_read},
         {.uuid = BLE_UUID128_DECLARE(0x9E, 0xCA, 0xDC, 0x24, 0x0E, 0xE5, 0xA9, 0xE0,
                                    0x93, 0xF3, 0xA3, 0xB5, 0x02, 0x00, 0x40, 0x6E),  // UUID RX
          .flags = BLE_GATT_CHR_F_WRITE,
          .access_cb = device_write},
         {0}}},
    {0}};

    
// Write data to ESP32 defined as server
int device_write(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt *ctxt, void *arg)
{
    char command[ctxt->om->om_len + 1];
    memcpy(command, ctxt->om->om_data, ctxt->om->om_len);
    command[ctxt->om->om_len] = '\0'; // Добавляем null-терминатор

    ESP_LOGI(TAG, "Получена команда по BLE: %s", command);
    bluetooth_command_handle(command);

    // Пример обработки команды
    if (strcmp(command, "ping") == 0)
    {
        ESP_LOGI(TAG, "Отправка ответа на ping");
        // Отправка ответа
        os_mbuf_append(ctxt->om, "received ping", strlen("received ping"));
    }

    return 0;
}

// Read data from ESP32 defined as server
int device_read(uint16_t con_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt *ctxt, void *arg)
{
    os_mbuf_append(ctxt->om, "Data from the server", strlen("Data from the server"));
    return 0;
}

// BLE event handling
int ble_gap_event(struct ble_gap_event *event, void *arg)
{
    switch (event->type)
    {
    case BLE_GAP_EVENT_CONNECT:
        ESP_LOGI("GAP", "BLE GAP EVENT CONNECT %s", event->connect.status == 0 ? "OK!" : "FAILED!");
        if (event->connect.status == 0)
        {
            // Обработка успешного подключения
            // powersaving_ble_connect();
            // ble_connect_vibro();
            // ble_connect_led();
        }
        else
        {
            ble_app_advertise();
        }
        break;
    case BLE_GAP_EVENT_DISCONNECT:
        ESP_LOGI("GAP", "BLE GAP EVENT DISCONNECT");
        // Обработка отключения
        // powersaving_ble_disconnect();
        // ble_disconnect_vibro();
        // ble_disconnect_led();
        ble_app_advertise();
        break;
    case BLE_GAP_EVENT_ADV_COMPLETE:
        ESP_LOGI("GAP", "BLE GAP EVENT ADV COMPLETE");
        ble_app_advertise();
        break;
    default:
        break;
    }
    return 0;
}

// Define the BLE connection
void ble_app_advertise(void)
{
    // GAP - device name definition
    struct ble_hs_adv_fields fields;
    const char *device_name;
    memset(&fields, 0, sizeof(fields));
    
    // Добавляем UUID сервиса в рекламные данные
    ble_uuid128_t service_uuid = BLE_UUID128_INIT(0x6E, 0x40, 0x00, 0x01, 0xB5, 0xA3, 0xF3, 0x93, 
                                                 0xE0, 0xA9, 0xE5, 0x0E, 0x24, 0xDC, 0xCA, 0x9E);
    fields.uuids128 = &service_uuid;
    fields.num_uuids128 = 1;
    fields.uuids128_is_complete = 1;
    
    // Имя устройства
    device_name = ble_svc_gap_device_name();
    fields.name = (uint8_t *)device_name;
    fields.name_len = strlen(device_name);
    fields.name_is_complete = 1;
    
    ble_gap_adv_set_fields(&fields);

    // GAP - device connectivity definition
    struct ble_gap_adv_params adv_params;
    memset(&adv_params, 0, sizeof(adv_params));
    adv_params.conn_mode = BLE_GAP_CONN_MODE_UND; 
    adv_params.disc_mode = BLE_GAP_DISC_MODE_GEN; 
    ble_gap_adv_start(ble_addr_type, NULL, BLE_HS_FOREVER, &adv_params, ble_gap_event, NULL);
}


void ble_app_on_sync(void)
{
    ble_hs_id_infer_auto(0, &ble_addr_type); 
    ble_app_advertise();                     
}


void host_task(void *param)
{
    nimble_port_run(); 
}