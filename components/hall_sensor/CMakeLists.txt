idf_component_register(SRCS "src/hall_sensor.c"
                       INCLUDE_DIRS "include" "${CMAKE_SOURCE_DIR}/components/config"
                       REQUIRES driver )
