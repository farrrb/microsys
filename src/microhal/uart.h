/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// \brief UART interface (public)

#ifndef UART_H__
#define UART_H__

#include "microhal.h"

typedef enum
{
  UART_BAUDRATE_1200   = 0x0004F000,    ///< 1200   baud (actual rate: 1205)
  UART_BAUDRATE_2400   = 0x0009D000,    ///< 2400   baud (actual rate: 2396)
  UART_BAUDRATE_4800   = 0x0013B000,    ///< 4800   baud (actual rate: 4808)
  UART_BAUDRATE_9600   = 0x00275000,    ///< 9600   baud (actual rate: 9598)
  UART_BAUDRATE_14400  = 0x003B0000,    ///< 14400  baud (actual rate: 14414)
  UART_BAUDRATE_19200  = 0x004EA000,    ///< 19200  baud (actual rate: 19208)
  UART_BAUDRATE_28800  = 0x0075F000,    ///< 28800  baud (actual rate: 28829)
  UART_BAUDRATE_31250  = 0x00800000,    ///< 31250  baud
  UART_BAUDRATE_38400  = 0x009D5000,    ///< 38400  baud (actual rate: 38462)
  UART_BAUDRATE_56000  = 0x00E50000,    ///< 56000  baud (actual rate: 55944)
  UART_BAUDRATE_57600  = 0x00EBF000,    ///< 57600  baud (actual rate: 57602)
  UART_BAUDRATE_76800  = 0x013A9000,    ///< 76800  baud (actual rate: 76797)
  UART_BAUDRATE_115200 = 0x01D7E000,    ///< 115200 baud (actual rate: 115204)
  UART_BAUDRATE_230400 = 0x03AFB000,    ///< 230400 baud (actual rate: 230393)
  UART_BAUDRATE_250000 = 0x04000000,    ///< 250000 baud
  UART_BAUDRATE_460800 = 0x075F7000,    ///< 460800 baud
  UART_BAUDRATE_921600 = 0x0EBEDFA4,    ///< 921600 baud (actual rate: 921585)
  UART_BAUDRATE_1M     = 0x10000000     ///< 1Mega  baud
} UartBaudrate_t;

void Uart_init(UartBaudrate_t baudrate);
void Uart_sendChar(const char chr);
void Uart_sendString(const char *str);
void Uart_sendNumberHex(uint32_t number);
void Uart_sendNumberDec(int32_t number);

#endif
