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

void uart_send_hex(uint32_t number)
{
  uart_send_char('0');
  uart_send_char('x');

  for(int i = 0; i < 8; i++)
  {
    char ch = number >> 28;

    if (ch <= 9)
    {
      ch += '0';
    }
    else
    {
      ch += 'A' - 10;
    }

    uart_send_char(ch);

    number <<= 4;
  }

}

void uart_send_dec(int32_t number)
{
  uint32_t  num, rem;
  char      str[11];
  uint32_t  cnt = 0;

  if (number < 0)
  {
    num = -number;
    uart_send_char('-');
  }
  else
  {
    num = number;
  }

  str[10] = '\0';

  for (int i = 9; i >= 0; i--)
  {
    rem = num % 10;
    num = num / 10;
    str[i] = '0' + rem;
    cnt++;

    if (num == 0)
    {
      break;
    }
  }

  uart_send_string(&str[10 - cnt]);
}
