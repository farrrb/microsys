################################################################################
# Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
# See provided LICENSE file for more information
################################################################################

add_library(rtos STATIC heap_1.c list.c queue.c tasks.c timers.c port/port.c)

target_include_directories(rtos PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/port ${CMAKE_CURRENT_SOURCE_DIR}/include)
