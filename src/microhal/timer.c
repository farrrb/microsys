/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information

#include "timer.h"

static volatile TimerModule_t *Timer_modules[3] =
{
  TIMER_MODULE_0,
  TIMER_MODULE_1,
  TIMER_MODULE_2
};

void Timer_init(TimerChannel_t channel)
{
  (void)channel;

  Timer_modules[channel]->MODE      = 0; // Timer mode
  Timer_modules[channel]->BITMODE   = 3; // 32-bit
  Timer_modules[channel]->PRESCALER = 0; // 16 MHz timer clock
}

void Timer_start(TimerChannel_t channel)
{
  (void)channel;

  Timer_modules[channel]->START = 1;
}

void Timer_stop(TimerChannel_t channel)
{
  (void)channel;

  Timer_modules[channel]->STOP = 1;
}

void Timer_clear(TimerChannel_t channel)
{
  (void)channel;

  Timer_modules[channel]->CLEAR = 1;
}

uint32_t Timer_capture(TimerChannel_t channel)
{
  (void)channel;

  Timer_modules[channel]->CAPTURE[0] = 1;

  return Timer_modules[channel]->CC[0];
}

uint32_t Timer_convertTicksToMicroseconds(uint32_t ticks)
{
  return ticks >> 4;
}
