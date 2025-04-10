#pragma once

// для вибро 
#define LEDC_TIMER          LEDC_TIMER_0
#define LEDC_MODE           LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL        LEDC_CHANNEL_0
#define LEDC_DUTY_RES       LEDC_TIMER_10_BIT
#define LEDC_FREQUENCY      2000  // Стандартная частота


<<<<<<< HEAD
#define BIT_HALL_TRIGGERED  (1 << 0)
#define BIT_WAKEUP          (1 << 1)
#define BIT_MOTOR_ON        (1 << 2)
#define BIT_MOTOR_OFF       (1 << 3)
#define BIT_LED_ON          (1 << 4)
#define BIT_LED_OFF         (1 << 5)
#define BIT_SLEEP           (1 << 6)

#define ZERO_CELL_LED_ON   (1 << 7)
#define ZERO_CELL_LED_OFF  (1 << 8)
#define FIRST_CELL_LED_ON  (1 << 9)
#define FIRST_CELL_LED_OFF (1 << 10)
#define SECOND_CELL_LED_ON  (1 << 11)
#define SECOND_CELL_LED_OFF (1 << 12)
#define THIRD_CELL_LED_ON  (1 << 13)
#define THIRD_CELL_LED_OFF (1 << 14)
=======
#define BIT_HALL_TRIGGERED (1 << 0)
#define BIT_WAKEUP         (1 << 1)
#define BIT_MOTOR_ON       (1 << 2)
#define BIT_MOTOR_OFF      (1 << 3)
#define BIT_LED_ON         (1 << 4)
#define BIT_LED_OFF        (1 << 5)
#define BIT_SLEEP          (1 << 6)

#define BIT_SELECT_CELL0   (1 << 7)
#define BIT_SELECT_CELL1   (1 << 8)
#define BIT_SELECT_CELL2   (1 << 9)
#define BIT_SELECT_CELL3   (1 << 10)

#define BIT_CLEAR_CELL0    (1 << 11)
#define BIT_CLEAR_CELL1    (1 << 12)
#define BIT_CLEAR_CELL2    (1 << 13)
#define BIT_CLEAR_CELL3    (1 << 14)
>>>>>>> d0536ee (реализована обработка команд select и clear)

