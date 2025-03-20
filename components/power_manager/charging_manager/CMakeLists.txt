idf_component_register(SRCS "src/charging_manager.c"
                       INCLUDE_DIRS "include" "${CMAKE_SOURCE_DIR}/components/config"
                       REQUIRES driver )
