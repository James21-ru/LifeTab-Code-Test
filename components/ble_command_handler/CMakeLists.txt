idf_component_register(SRCS "src/ble_command_handler.c"
                    INCLUDE_DIRS "include"
                    REQUIRES motor status_led sleep_manager)
