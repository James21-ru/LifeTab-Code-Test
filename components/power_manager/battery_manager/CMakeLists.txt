idf_component_register(SRCS "src/battery_manager.c"
                       INCLUDE_DIRS "include" "${CMAKE_SOURCE_DIR}/components/config"
                       REQUIRES driver esp_adc)
