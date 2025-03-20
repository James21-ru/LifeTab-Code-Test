idf_component_register(SRCS "main.c"
                       INCLUDE_DIRS "."
                       REQUIRES motor status_led hall_sensor sleep_manager ble_uart charging_manager)
