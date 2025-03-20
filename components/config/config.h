#pragma once

// для вибро 
#define LEDC_TIMER          LEDC_TIMER_0
#define LEDC_MODE           LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL        LEDC_CHANNEL_0
#define LEDC_DUTY_RES       LEDC_TIMER_10_BIT
#define LEDC_FREQUENCY      2000  // Стандартная частота


#define CHARGING_THRESHOLD 1500
#define BATT_FULL 2290
#define BATT_EMPTY 2100

//for event_group
// #define BIT_HALL_TRIGGERED (1 << 0)
// #define BIT_WAKEUP         (1 << 1)
#define BIT_HALL_TRIGGERED  (1 << 0)
#define BIT_WAKEUP          (1 << 1)
#define BIT_MOTOR_ON        (1 << 2)
#define BIT_MOTOR_OFF       (1 << 3)
#define BIT_LED_ON          (1 << 4)
#define BIT_LED_OFF         (1 << 5)
#define BIT_SLEEP           (1 << 6)

//for charging_event_group
#define CHARGING_EVENT (1 << 7)
#define SLEEP_EVENT (1 << 8)
#define CHARGING_STATUS_BIT (1 << 9)
