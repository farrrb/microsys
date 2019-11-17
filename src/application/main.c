////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

#include "clock.h"
#include "delay.h"
#include "nvic.h"
#include "timer.h"
#include "uart.h"

#include "display.h"

//#define MEASURE_MAIN_LOOP

#define BLINK_TICKS (32768)
#define DELAY_TICKS (10)

#define CLEAR_SCREEN "\x1b[2J\x1b[H"

// Test Variables
const uint32_t const_data         = 0xADDE; // -> .rodata (FLASH)
uint32_t       initialized_data   = 0xFECA; // -> .data   (RAM)
uint32_t       zero_data          = 0;      // -> .bss    (RAM)
uint32_t       uninitialized_data;          // -> COMMON  (RAM)

uint32_t Timer_value = 0;

void drawHeart(void)
{
  Display_setPixel(0, 1);
  Display_setPixel(0, 3);

  Display_setPixel(1, 0);
  Display_setPixel(1, 2);
  Display_setPixel(1, 4);

  Display_setPixel(2, 0);
  Display_setPixel(2, 4);

  Display_setPixel(3, 1);
  Display_setPixel(3, 3);

  Display_setPixel(4, 2);
}

uint32_t __debug_ctr = 0;

void TIMER0_IRQHandler(void)
{
  Timer_clearCompareEvent(TIMER_CH_0);

  __debug_ctr++;
}

int main(void)
{
  uint32_t ctr = 0;

  // Initialize clock
  Clock_init();

  // initialize timer
  Timer_init(TIMER_CH_0);
  Timer_setCompareValue(TIMER_CH_0, Timer_convertMicrosecondsToTicks(1000));
  Timer_setCompareClear(TIMER_CH_0);
  Timer_enableInterrupt(TIMER_CH_0);
  Timer_start(TIMER_CH_0);

  // enable interrupts
  Nvic_enable(NVIC_TIMER0);

  // initialize UART
  Uart_init(UART_BAUDRATE_115200);
  Uart_sendString(CLEAR_SCREEN);
  Uart_sendString("Booting MicroSys...\r\n");

  // initialize display
  Display_init();
  drawHeart();

  while (1)
  {
    // update the display
    Display_update(DELAY_TICKS);

#if BLINK_TICKS > 0
    // blink
    ctr++;
    if (ctr == (BLINK_TICKS / 2))
    {
      Uart_sendChar('.');
      Display_clrScreen();
    }
    if (ctr == (BLINK_TICKS))
    {
      drawHeart();
      ctr = 0;
    }
#endif

#ifdef MEASURE_MAIN_LOOP
    Timer_value = Timer_convertTicksToMicroseconds(Timer_capture(TIMER_CH_0));
    Uart_sendString("\r\n");
    Uart_sendNumberDec(Timer_value);
    Timer_clear(TIMER_CH_0);
#endif

  }

  return 0;
}
