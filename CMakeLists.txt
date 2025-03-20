cmake_minimum_required(VERSION 3.5)

# Указываем пути к дополнительным компонентам, которые находятся не в корневой папке components
set(EXTRA_COMPONENT_DIRS "components/power_manager/battery_manager" "components/power_manager/charging_manager")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(lifeTab)
