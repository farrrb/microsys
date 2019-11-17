////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

#include "clock.h"
#include "display.h"

// the FreeRTOS heap
uint8_t ucHeap[configTOTAL_HEAP_SIZE];

static void drawHeart(void)
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

static void heartbeatTask(void *parameters)
{
  (void)parameters;
  // initialize display
  Display_init();

  while (1)
  {
    vTaskDelay(500);
    drawHeart();
    vTaskDelay(500);
    Display_clrScreen();
  }
}


void vApplicationIdleHook(void)
{
  Display_update(10);
}

void vAssertCalled(const char *file, int line)
{
  (void)file;
  (void)line;
  __asm("bkpt 1");
}

int main(void)
{
  // Initialize clock
  Clock_init();

  xTaskCreate(heartbeatTask, "heartbeat",
              configMINIMAL_STACK_SIZE,
              NULL,
              (tskIDLE_PRIORITY + 1),
              NULL);

  vTaskStartScheduler();

  configASSERT(0);

  return 0;
}
