////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// \brief Timer interface (public)
///
////////////////////////////////////////////////////////////////////////////////

#ifndef TIMER_H__
#define TIMER_H__

#include "microhal.h"

typedef enum
{
  TIMER_CH_0 = 0,
  TIMER_CH_1 = 1,
  TIMER_CH_2 = 2
} TimerChannel_t;

void Timer_init(TimerChannel_t channel);
void Timer_start(TimerChannel_t channel);
void Timer_stop(TimerChannel_t channel);
void Timer_clear(TimerChannel_t channel);
uint32_t Timer_capture(TimerChannel_t channel);

uint32_t Timer_convertTicksToMicroseconds(uint32_t ticks);

#endif
