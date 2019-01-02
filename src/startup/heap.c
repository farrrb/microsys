/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// Heap Storage

#include <stdint.h>

#include "startup_config.h"

// Reserve Heap Space
static uint8_t __heap_storage[HEAP_SIZE] __attribute__((aligned(8), used, section(".heap")));
