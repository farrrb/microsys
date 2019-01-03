////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
////////////////////////////////////////////////////////////////////////////////

#include "clock.h"

typedef struct
{
  volatile uint32_t HFCLKSTART;      ///< (Offset: 0x000) Start HFCLK clock source.
  volatile uint32_t HFCLKSTOP;       ///< (Offset: 0x004) Stop HFCLK clock source.
  volatile uint32_t LFCLKSTART;      ///< (Offset: 0x008) Start LFCLK clock source.
  volatile uint32_t LFCLKSTOP;       ///< (Offset: 0x00C) Stop LFCLK clock source.
  volatile uint32_t CAL;             ///< (Offset: 0x010) Start calibration of LFCLK RC oscillator.
  volatile uint32_t CTSTART;         ///< (Offset: 0x014) Start calibration timer.
  volatile uint32_t CTSTOP;          ///< (Offset: 0x018) Stop calibration timer.
  volatile uint32_t RESERVED0[57];   ///< (Offset: 0x01C) Reserved space.
  volatile uint32_t HFCLKSTARTED;    ///< (Offset: 0x100) HFCLK oscillator started.
  volatile uint32_t LFCLKSTARTED;    ///< (Offset: 0x104) LFCLK oscillator started.
  volatile uint32_t RESERVED1;       ///< (Offset: 0x108) Reserved space.
  volatile uint32_t DONE;            ///< (Offset: 0x10C) Calibration of LFCLK RC oscillator completed.
  volatile uint32_t CTTO;            ///< (Offset: 0x110) Calibration timer timeout.
  volatile uint32_t RESERVED2[124];  ///< (Offset: 0x114) Reserved space.
  volatile uint32_t INTENSET;        ///< (Offset: 0x304) Interrupt enable set register.
  volatile uint32_t INTENCLR;        ///< (Offset: 0x308) Interrupt enable clear register.
  volatile uint32_t RESERVED3[63];   ///< (Offset: 0x30C) Reserved space.
  volatile uint32_t HFCLKRUN;        ///< (Offset: 0x408) Task HFCLKSTART trigger status.
  volatile uint32_t HFCLKSTAT;       ///< (Offset: 0x40C) High frequency clock status.
  volatile uint32_t RESERVED4;       ///< (Offset: 0x410) Reserved space.
  volatile uint32_t LFCLKRUN;        ///< (Offset: 0x414) Task LFCLKSTART triggered status.
  volatile uint32_t LFCLKSTAT;       ///< (Offset: 0x418) Low frequency clock status.
  volatile uint32_t LFCLKSRCCOPY;    ///< (Offset: 0x41C) Clock source for the LFCLK clock, set when task LKCLKSTART is triggered.
  volatile uint32_t RESERVED5[62];   ///< (Offset: 0x420) Reserved space.
  volatile uint32_t LFCLKSRC;        ///< (Offset: 0x518) Clock source for the LFCLK clock.
  volatile uint32_t RESERVED6[7];    ///< (Offset: 0x51C) Reserved space.
  volatile uint32_t CTIV;            ///< (Offset: 0x538) Calibration timer interval.
  volatile uint32_t RESERVED7[5];    ///< (Offset: 0x53C) Reserved space.
  volatile uint32_t XTALFREQ;        ///< (Offset: 0x550) Crystal frequency.
} ClockModule_t;

#define CLOCK_BASE      (0x40000000)                            ///< Clock system base address
#define CLOCK_MODULE    ((volatile ClockModule_t *)CLOCK_BASE)  ///< Pointer to CLOCK module instance

void Clock_init(void)
{
  // The system gets the HFCLK from the internal RC oscillator by default at startup.
  // Due to the frequency tolerance of the internal RC oscillator up to +/- 5%
  // the frequency varies up to +/- 800 kHz.
  // To avoid this we will no set up the external crystal oscillator (16 MHz quartz),
  // which gives us a frequency tolerance band of +/- 50 ppm.

  // Setup external crystal oscillator
  CLOCK_MODULE->XTALFREQ     = 0xFF; // Set external crystal frequency to 16 MHz
  CLOCK_MODULE->HFCLKSTARTED = 0;    // reset event
  CLOCK_MODULE->HFCLKSTART   = 1;    // start HFCLK task

  // Wait until the clock started successfully (steady state)
  while (CLOCK_MODULE->HFCLKSTARTED == 0)
  {
    // do nothing
  }
}
