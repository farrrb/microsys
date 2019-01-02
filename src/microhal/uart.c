/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information

#include "uart.h"

#include "gpio.h"
#include "register.h"

#define UART_PIN_TX   (24)
#define UART_PIN_RX   (25)

void uart_init(uint32_t baudrate)
{
  // pin setup
  register_write(GPIO_REG_OUTSET,  (1 << UART_PIN_TX));
  register_write(UART_REG_PSELTXD, UART_PIN_TX);

  // UART configuration
  register_write(UART_REG_BAUDRATE, baudrate);
  register_write(UART_REG_ENABLE,   4);
  register_write(UART_REG_STARTTX,  1);
}

void uart_send_char(const char ch)
{
  // write char to transmit register
  register_write(UART_REG_TXD, ch);

  // poll ready bit
  while(register_read(UART_REG_TXDRDY) == 0)
  {
    // do nothing
  }
  // clear ready bit
  register_write(UART_REG_TXDRDY, 0);
}

void uart_send_string(const char *str)
{
  while (*str != '\0')
  {
    uart_send_char(*str);
    str++;
  }
}
