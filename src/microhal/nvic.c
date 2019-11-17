////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2019 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
////////////////////////////////////////////////////////////////////////////////

#include "nvic.h"

typedef struct
{
  volatile uint32_t ISER[16];
} NvicModule_t;

#define NVIC_BASE   (0xE000E100)

#define NVIC_MODULE ((volatile NvicModule_t*)(NVIC_BASE))

void Nvic_enable(NvicIrqNr_t irq_nr)
{
  NVIC_MODULE->ISER[irq_nr/32] |= (1 << (irq_nr % 32));
}
