/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information

#include "uart.h"

/// \brief UART register file description
typedef struct
{
  volatile uint32_t STARTRX;            ///< (Offset: 0x000) Start UART receiver.
  volatile uint32_t STOPRX;             ///< (Offset: 0x004) Stop UART receiver.
  volatile uint32_t STARTTX;            ///< (Offset: 0x008) Start UART transmitter.
  volatile uint32_t STOPTX;             ///< (Offset: 0x00C) Stop UART transmitter.
  volatile uint32_t RESERVED0[3];       ///< (Offset: 0x010) Reserved space
  volatile uint32_t SUSPEND;            ///< (Offset: 0x01C) Suspend UART.
  volatile uint32_t RESERVED1[56];      ///< (Offset: 0x020) Reserved space
  volatile uint32_t CTS;                ///< (Offset: 0x100) CTS activated.
  volatile uint32_t NCTS;               ///< (Offset: 0x104) CTS deactivated.
  volatile uint32_t RXDRDY;             ///< (Offset: 0x108) Data received in RXD.
  volatile uint32_t RESERVED2[4];       ///< (Offset: 0x10C) Reserved space
  volatile uint32_t TXDRDY;             ///< (Offset: 0x11C) Data sent from TXD.
  volatile uint32_t RESERVED3;          ///< (Offset: 0x120) Reserved space.
  volatile uint32_t ERROR;              ///< (Offset: 0x124) Error detected.
  volatile uint32_t RESERVED4[7];       ///< (Offset: 0x128) Reserved space.
  volatile uint32_t RXTO;               ///< (Offset: 0x144) Receiver timeout.
  volatile uint32_t RESERVED5[46];      ///< (Offset: 0x148) Reserved space.
  volatile uint32_t SHORTS;             ///< (Offset: 0x200) Shortcuts for UART.
  volatile uint32_t RESERVED6[64];      ///< (Offset: 0x204) Reserved space.
  volatile uint32_t INTENSET;           ///< (Offset: 0x304) Interrupt enable set register.
  volatile uint32_t INTENCLR;           ///< (Offset: 0x308) Interrupt enable clear register.
  volatile uint32_t RESERVED7[93];      ///< (Offset: 0x30C) Reserved space.
  volatile uint32_t ERRORSRC;           ///< (Offset: 0x480) Error source.
  volatile uint32_t RESERVED8[31];      ///< (Offset: 0x484) Reserved space.
  volatile uint32_t ENABLE;             ///< (Offset: 0x500) Enable UART and acquire IOs.
  volatile uint32_t RESERVED9;          ///< (Offset: 0x504) Reserved space.
  volatile uint32_t PSELRTS;            ///< (Offset: 0x508) Pin select for RTS.
  volatile uint32_t PSELTXD;            ///< (Offset: 0x50C) Pin select for TXD.
  volatile uint32_t PSELCTS;            ///< (Offset: 0x510) Pin select for CTS.
  volatile uint32_t PSELRXD;            ///< (Offset: 0x514) Pin select for RXD.
  volatile uint32_t RXD;                ///< (Offset: 0x518) RXD register.
  volatile uint32_t TXD;                ///< (Offset: 0x51C) TXD register.
  volatile uint32_t RESERVED10;         ///< (Offset: 0x520) Reserved space
  volatile uint32_t BAUDRATE;           ///< (Offset: 0x524) UART Baudrate.
  volatile uint32_t RESERVED11[17];     ///< (Offset: 0x528) Reserved space.
  volatile uint32_t CONFIG;             ///< (Offset: 0x56C) Configuration of parity and hardware flow control register.
  volatile uint32_t RESERVED12[675];    ///< (Offset: 0x570) Reserved space.
  volatile uint32_t POWER;              ///< (Offset: 0xFFC) Peripheral power control.
} UartModule_t;

#define UART_BASE     (0x40002000)                          ///< UART UART0 Universal Asynchronous Receiver/Transmitter
#define UART_MODULE   ((volatile UartModule_t *)UART_BASE)  ///< Pointer to UART module instance

#define UART_PIN_TX   (24)
#define UART_PIN_RX   (25)

void Uart_init(UartBaudrate_t baudrate)
{
  // UART configuration
  UART_MODULE->PSELTXD   = UART_PIN_TX;         // set output pin
  UART_MODULE->BAUDRATE  = (uint32_t)baudrate; // set baud rate
  UART_MODULE->ENABLE    = 4;                  // enable
  UART_MODULE->STARTTX   = 1;                  // start transmission
}

void Uart_sendChar(const char chr)
{
  // write char to transmit register
  UART_MODULE->TXD = chr;

  // poll ready bit
  while(UART_MODULE->TXDRDY == (uint32_t)0)
  {
    // do nothing
  }
  // clear ready bit
  UART_MODULE->TXDRDY = 0;
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
