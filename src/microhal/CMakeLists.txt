add_library(microhal STATIC delay.c timer.c uart.c)

target_include_directories(microhal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
