/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information

#include "delay.h"

static uint32_t delay_ticks = 0;

void delay(uint32_t ticks)
{
  for(uint32_t i = 0; i < ticks; i++)
  {
    delay_ticks++;
  }
}
