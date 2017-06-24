cmake_minimum_required(VERSION 3.7)
project(DBUSTutorial)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig REQUIRED)

# if not installed:
# apt install libdbus-glib-1-dev
pkg_search_module(DBUS REQUIRED dbus-1)

# Show all the warnings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")


add_executable(DBUS_Connection_Name src/dbus_connection_name.cpp)
target_link_libraries(DBUS_Connection_Name ${DBUS_LIBRARIES})
target_include_directories(DBUS_Connection_Name PUBLIC ${DBUS_INCLUDE_DIRS})
target_compile_options(DBUS_Connection_Name PUBLIC ${DBUS_CFLAGS_OTHER})


add_executable(DBUS_Read_UPower_GetCriticalAction src/dbus_read_UPower_GetCriticalAction.cpp)
target_link_libraries(DBUS_Read_UPower_GetCriticalAction ${DBUS_LIBRARIES})
target_include_directories(DBUS_Read_UPower_GetCriticalAction PUBLIC ${DBUS_INCLUDE_DIRS})
target_compile_options(DBUS_Read_UPower_GetCriticalAction PUBLIC ${DBUS_CFLAGS_OTHER})


add_executable(DBUS_Read_UPOWER_devies_battery_BAT1 src/dbus_read_UPOWER_devies_battery_BAT1.cpp)
target_link_libraries(DBUS_Read_UPOWER_devies_battery_BAT1 ${DBUS_LIBRARIES})
target_include_directories(DBUS_Read_UPOWER_devies_battery_BAT1 PUBLIC ${DBUS_INCLUDE_DIRS})
target_compile_options(DBUS_Read_UPOWER_devies_battery_BAT1 PUBLIC ${DBUS_CFLAGS_OTHER})

