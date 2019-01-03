/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information

#include "uart.h"

#include "gpio.h"
#include "register.h"

#define UART_PIN_TX   (24)
#define UART_PIN_RX   (25)

void Uart_init(uint32_t baudrate)
{
  // UART configuration
  register_write(UART_REG_PSELTXD,  UART_PIN_TX); // set output pin
  register_write(UART_REG_BAUDRATE, baudrate);    // set baud rate
  register_write(UART_REG_ENABLE,   4);           // enable
  register_write(UART_REG_STARTTX,  1);           // start transmission
}

void Uart_sendChar(const char ch)
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

void Uart_sendString(const char *str)
{
  while (*str != '\0')
  {
    Uart_sendChar(*str);
    str++;
  }
}

void Uart_sendNumberHex(uint32_t number)
{
  Uart_sendChar('0');
  Uart_sendChar('x');

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

    Uart_sendChar(ch);

    number <<= 4;
  }

}

void Uart_sendNumberDec(int32_t number)
{
  uint32_t  num, rem;
  char      str[11];
  uint32_t  cnt = 0;

  if (number < 0)
  {
    num = -number;
    Uart_sendChar('-');
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

  Uart_sendString(&str[10 - cnt]);
}
