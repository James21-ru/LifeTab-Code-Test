#include "motor.h"

void motor_init(void) {
    gpio_reset_pin(MOTOR_GPIO);
    gpio_set_direction(MOTOR_GPIO, GPIO_MODE_OUTPUT);

    // Инициализация PWM (LEDC)
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .gpio_num = MOTOR_GPIO,
        .speed_mode = LEDC_MODE,
        .channel = LEDC_CHANNEL,
        .timer_sel = LEDC_TIMER,
        .duty = 0,
        .hpoint = 0
    };
    ledc_channel_config(&ledc_channel);
}

void motor_vibrate(int duty, int freq, int duration_ms) {
    ledc_set_freq(LEDC_MODE, LEDC_TIMER, freq);
    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, duty);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
    vTaskDelay(pdMS_TO_TICKS(duration_ms));

    // Выключаем мотор после задержки
    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, 0);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
}


void motor_on(void) {
    motor_vibrate(1023, 2000, 1000);  // Включаем вибрацию на 1 секунду
}

void motor_off(void) {
    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, 0);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
}

void ble_connect_vibro() {
    motor_vibrate(700, 5000000, 350);
    vTaskDelay(pdMS_TO_TICKS(180));
    motor_vibrate(1023, 5000000, 200);
}

void ble_disconnect_vibro() {
    motor_vibrate(1023, 3000000, 170);
    vTaskDelay(pdMS_TO_TICKS(230));
    motor_vibrate(600, 3000000, 330);
}

void notify_vibro() {
    for (int i = 0; i < 4; i++) {
        motor_vibrate(1023, 2000000, 900);
        vTaskDelay(pdMS_TO_TICKS(900));
    }
}

void notify_open_vibro() {
    for (int i = 0; i < 2; i++) {
        motor_vibrate(800, 2000000, 300);
        vTaskDelay(pdMS_TO_TICKS(150));
    }
}
