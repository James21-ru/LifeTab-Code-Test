idf_component_register(SRCS "src/ble_uart.c"
                    INCLUDE_DIRS "include" "${CMAKE_SOURCE_DIR}/components/config"
                    REQUIRES bt event_handler nvs_flash ble_command_handler)
