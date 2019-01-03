/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// Timer Interface

#ifndef TIMER_H__
#define TIMER_H__

#include "microhal.h"

typedef struct
{
  volatile uint32_t START;                    ///< (Offset: 0x000) Start Timer.
  volatile uint32_t STOP;                     ///< (Offset: 0x004) Stop Timer.
  volatile uint32_t COUNT;                    ///< (Offset: 0x008) Increment Timer (In counter mode).
  volatile uint32_t CLEAR;                    ///< (Offset: 0x00C) Clear timer.
  volatile uint32_t SHUTDOWN;                 ///< (Offset: 0x010) Shutdown timer.
  volatile uint32_t RESERVED0[11];            ///< (Offset: 0x014) Reserved space.
  volatile uint32_t CAPTURE[4];               ///< (Offset: 0x040) Capture Timer value to CC[n] registers.
  volatile uint32_t RESERVED1[60];            ///< (Offset: 0x044) Reserved space.
  volatile uint32_t COMPARE[4];               ///< (Offset: 0x140) Compare event on CC[n] match.
  volatile uint32_t RESERVED2[44];            ///< (Offset: 0x150) Reserved space.
  volatile uint32_t SHORTS;                   ///< (Offset: 0x200) Shortcuts for Timer.
  volatile uint32_t RESERVED3[64];            ///< (Offset: 0x204) Reserved space.
  volatile uint32_t INTENSET;                 ///< (Offset: 0x304) Interrupt enable set register.
  volatile uint32_t INTENCLR;                 ///< (Offset: 0x308) Interrupt enable clear register.
  volatile uint32_t RESERVED4[126];           ///< (Offset: 0x30C) Reserved space.
  volatile uint32_t MODE;                     ///< (Offset: 0x504) Timer Mode selection.
  volatile uint32_t BITMODE;                  ///< (Offset: 0x508) Sets timer behaviour.
  volatile uint32_t RESERVED5;                ///< (Offset: 0x50C) Reserved space.
  volatile uint32_t PRESCALER;                ///< (Offset: 0x510) 4-bit prescaler to source clock frequency
  volatile uint32_t RESERVED6[11];            ///< (Offset: 0x514) Reserved space.
  volatile uint32_t CC[4];                    ///< (Offset: 0x540) Capture/compare registers.
  volatile uint32_t RESERVED7[683];           ///< (Offset: 0x550) Reserved space.
  volatile uint32_t POWER;                    ///< (Offset: 0xFFC) Peripheral power control.
} TimerModule_t;

#define TIMER_BASE_0            (0x40008000)  ///< TIMER TIMER0 Timer/Counter
#define TIMER_BASE_1            (0x40009000)  ///< TIMER TIMER1 Timer/Counter
#define TIMER_BASE_2            (0x4000A000)  ///< TIMER TIMER2 Timer/Counter

#define TIMER_MODULE_0          ((volatile TimerModule_t *)TIMER_BASE_0)
#define TIMER_MODULE_1          ((volatile TimerModule_t *)TIMER_BASE_1)
#define TIMER_MODULE_2          ((volatile TimerModule_t *)TIMER_BASE_2)

#define TIMER_FREQUENCY         ((uint32_t)16000000) ///< Timer frequency in [MHz]

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
