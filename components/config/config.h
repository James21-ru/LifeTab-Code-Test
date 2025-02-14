#pragma once

// для вибро 
#define LEDC_TIMER          LEDC_TIMER_0
#define LEDC_MODE           LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL        LEDC_CHANNEL_0
#define LEDC_DUTY_RES       LEDC_TIMER_10_BIT
#define LEDC_FREQUENCY      2000  // Стандартная частота


#define BIT_HALL_TRIGGERED (1 << 0)
#define BIT_WAKEUP         (1 << 1)
