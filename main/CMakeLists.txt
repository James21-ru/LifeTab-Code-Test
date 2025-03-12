idf_component_register(SRCS "main.c"
                       INCLUDE_DIRS "."
                       REQUIRES motor status_led hall_sensor sleep_manager bt event_handler nvs_flash)
