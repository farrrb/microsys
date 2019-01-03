################################################################################
# Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
# See provided LICENSE file for more information
################################################################################

add_library(microhal STATIC clock.c delay.c timer.c uart.c)

target_include_directories(microhal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
