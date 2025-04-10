idf_component_register(SRCS "src/cell_led.c"
                       INCLUDE_DIRS "include" "${CMAKE_SOURCE_DIR}/components/config"
                       REQUIRES driver led_strip)
