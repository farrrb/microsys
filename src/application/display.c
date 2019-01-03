////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
////////////////////////////////////////////////////////////////////////////////

#include "display.h"

#include "delay.h"
#include "gpio.h"

#define ROW_TO_INDEX(row) ((row) >> (13+1)) // First pin is number 13.
#define ROW1  (GPIO_PIN_13)
#define ROW2  (GPIO_PIN_14)
#define ROW3  (GPIO_PIN_15)

#define COL1  (GPIO_PIN_04)
#define COL2  (GPIO_PIN_05)
#define COL3  (GPIO_PIN_06)
#define COL4  (GPIO_PIN_07)
#define COL5  (GPIO_PIN_08)
#define COL6  (GPIO_PIN_09)
#define COL7  (GPIO_PIN_10)
#define COL8  (GPIO_PIN_11)
#define COL9  (GPIO_PIN_12)

#define ROWS  (ROW1 | ROW2 | ROW3)
#define COLS  (COL1 | COL2 | COL3 | COL4 | COL5 | COL6 | COL7 | COL8 | COL9)

typedef struct
{
  uint32_t row;
  uint32_t col;
} DisplayMatrix_t;

static const DisplayMatrix_t Display_lookup_table[5][5]=
{
  {{ROW1, COL1}, {ROW2, COL4}, {ROW1, COL2}, {ROW2, COL5}, {ROW1, COL3}},
  {{ROW3, COL4}, {ROW3, COL5}, {ROW3, COL6}, {ROW3, COL7}, {ROW3, COL8}},
  {{ROW2, COL2}, {ROW1, COL9}, {ROW2, COL3}, {ROW3, COL9}, {ROW2, COL1}},
  {{ROW1, COL8}, {ROW1, COL7}, {ROW1, COL6}, {ROW1, COL5}, {ROW1, COL4}},
  {{ROW3, COL3}, {ROW2, COL7}, {ROW3, COL1}, {ROW2, COL6}, {ROW3, COL2}}
};

static uint32_t Display_led_matrix[3] = {0};

void Display_init(void)
{
  // Configure outputs
  // set directions to output on all rows & columns
  Gpio_initPins((ROWS | COLS), true);

  // clear screen
  Display_clrScreen();
}

void Display_clrScreen(void)
{
  uint8_t row;

  // reset internal data
  for (row = 0; row < 3; row++)
  {
    Display_led_matrix[row] = 0;
  }

  // Set all rows low
  // Set all cols high
  Gpio_clrPins(ROWS);
  Gpio_setPins(COLS);
}

void Display_update(uint32_t delay_ticks)
{
  // ROW1
  Gpio_clrPins(ROWS);
  Gpio_setPins(COLS);

  Gpio_clrPins(Display_led_matrix[0]);
  Gpio_setPins(ROW1);
  Delay_ticks(delay_ticks);

  // ROW2
  Gpio_clrPins(ROWS);
  Gpio_setPins(COLS);

  Gpio_clrPins(Display_led_matrix[1]);
  Gpio_setPins(ROW2);
  Delay_ticks(delay_ticks);

  // ROW3
  Gpio_clrPins(ROWS);
  Gpio_setPins(COLS);

  Gpio_clrPins(Display_led_matrix[2]);
  Gpio_setPins(ROW3);
  Delay_ticks(delay_ticks);
}

void Display_setPixel(uint8_t x, uint8_t y)
{
  Display_led_matrix[ROW_TO_INDEX(Display_lookup_table[x][y].row)] |= Display_lookup_table[x][y].col;
}

void Display_clrPixel(uint8_t x, uint8_t y)
{
  Display_led_matrix[ROW_TO_INDEX(Display_lookup_table[x][y].row)] &= ~Display_lookup_table[x][y].col;
}
