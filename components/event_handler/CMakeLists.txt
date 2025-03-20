idf_component_register(SRCS "src/event_handler.c"
                       INCLUDE_DIRS "include" "${CMAKE_SOURCE_DIR}/components/config"
                       REQUIRES freertos hall_sensor status_led sleep_manager motor charging_manager)
