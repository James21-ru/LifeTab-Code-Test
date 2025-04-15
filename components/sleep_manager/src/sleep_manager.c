#include "sleep_manager.h"

static const char *TAG = "SLEEP_MANAGER";

void enter_light_sleep(void) {
    esp_sleep_enable_gpio_wakeup();
    esp_light_sleep_start();

    xEventGroupSetBits(event_group, BIT_WAKEUP);  
}