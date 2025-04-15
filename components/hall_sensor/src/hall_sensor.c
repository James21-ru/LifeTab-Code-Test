#include "hall_sensor.h"

static const char *TAG = "HALL_SENSOR";

// Прерывание датчика Хола
void IRAM_ATTR hall_sensor_isr_handler(void *arg) { 
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xEventGroupSetBitsFromISR(event_group, BIT_HALL_TRIGGERED, &xHigherPriorityTaskWoken);
    if (xHigherPriorityTaskWoken == pdTRUE) {  
        portYIELD_FROM_ISR();
    }
}

void hall_sensor_init(void) {
    gpio_reset_pin(HALL_SENSOR_GPIO);
    gpio_set_direction(HALL_SENSOR_GPIO, GPIO_MODE_INPUT);
    gpio_pullup_en(HALL_SENSOR_GPIO);
    gpio_set_intr_type(HALL_SENSOR_GPIO, GPIO_INTR_NEGEDGE);  // Срабатывание на спаде
    gpio_install_isr_service(0);
    gpio_isr_handler_add(HALL_SENSOR_GPIO, hall_sensor_isr_handler, NULL);
}

//hall_sensor_isr_handler — это обработчик прерывания, который срабатывает, когда состояние датчика Хола изменяется.
//IRAM_ATTR — атрибут, указывающий, что эта функция должна быть размещена в оперативной памяти (IRAM), так как обработчики прерываний должны быть быстрыми.
//xEventGroupSetBitsFromISR() — этот вызов устанавливает бит в группе событий из обработчика прерывания:
//&xHigherPriorityTaskWoken — указатель на флаг, который будет установлен, если прерывание привело к необходимости пробуждения более высокой приоритетной задачи.