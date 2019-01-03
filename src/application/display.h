/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// Display Abstraction

#ifndef DISPLAY_H__
#define DISPLAY_H__

#include <stdint.h>

void Display_init(void);
void Display_clrScreen(void);

void Display_update(uint32_t delay_ticks);

void Display_setPixel(uint8_t x, uint8_t y);
void Display_clrPixel(uint8_t x, uint8_t y);

#endif
