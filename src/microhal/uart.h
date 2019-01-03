/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// UART Interface

#ifndef UART_H__
#define UART_H__

#include "microhal.h"

#define UART_BASE             0x40002000    ///< UART UART0 Universal Asynchronous Receiver/Transmitter

#define UART_OFFSET_STARTRX   0x000         ///< Start UART receiver
#define UART_OFFSET_STOPRX    0x004         ///< Stop UART receiver
#define UART_OFFSET_STARTTX   0x008         ///< Start UART transmitter
#define UART_OFFSET_STOPTX    0x00C         ///< Stop UART transmitter
#define UART_OFFSET_SUSPEND   0x01C         ///< Suspend UART
// Events
#define UART_OFFSET_CTS       0x100         ///< CTS is activated (set low). Clear To Send.
#define UART_OFFSET_NCTS      0x104         ///< CTS is deactivated (set high). Not Clear To Send.
#define UART_OFFSET_RXDRDY    0x108         ///< Data received in RXD
#define UART_OFFSET_TXDRDY    0x11C         ///< Data sent from TXD
#define UART_OFFSET_ERROR     0x124         ///< Error detected
#define UART_OFFSET_RXTO      0x144         ///< Receiver timeout
// Registers
#define UART_OFFSET_INTEN     0x300         ///< Enable or disable interrupt
#define UART_OFFSET_INTENSET  0x304         ///< Enable interrupt
#define UART_OFFSET_INTENCLR  0x308         ///< Disable interrupt
#define UART_OFFSET_ERRORSRC  0x480         ///< Error source
#define UART_OFFSET_ENABLE    0x500         ///< Enable UART
#define UART_OFFSET_PSELRTS   0x508         ///< Pin select for RTS
#define UART_OFFSET_PSELTXD   0x50C         ///< Pin select for TXD
#define UART_OFFSET_PSELCTS   0x510         ///< Pin select for CTS
#define UART_OFFSET_PSELRXD   0x514         ///< Pin select for RXD
#define UART_OFFSET_RXD       0x518         ///< RXD register
#define UART_OFFSET_TXD       0x51C         ///< TXD register
#define UART_OFFSET_BAUDRATE  0x524         ///< Baud rate
#define UART_OFFSET_CONFIG    0x56C         ///< Configuration of parity and hardware flow control

// Register abbreviations
#define UART_REG_STARTTX      (UART_BASE + UART_OFFSET_STARTTX)
#define UART_REG_TXDRDY       (UART_BASE + UART_OFFSET_TXDRDY)
#define UART_REG_ENABLE       (UART_BASE + UART_OFFSET_ENABLE)
#define UART_REG_PSELTXD      (UART_BASE + UART_OFFSET_PSELTXD)
#define UART_REG_TXD          (UART_BASE + UART_OFFSET_TXD)
#define UART_REG_BAUDRATE     (UART_BASE + UART_OFFSET_BAUDRATE)

// Baud rate values
#define UART_BAUDRATE_1200    0x0004F000    ///< 1200   baud (actual rate: 1205)
#define UART_BAUDRATE_2400    0x0009D000    ///< 2400   baud (actual rate: 2396)
#define UART_BAUDRATE_4800    0x0013B000    ///< 4800   baud (actual rate: 4808)
#define UART_BAUDRATE_9600    0x00275000    ///< 9600   baud (actual rate: 9598)
#define UART_BAUDRATE_14400   0x003B0000    ///< 14400  baud (actual rate: 14414)
#define UART_BAUDRATE_19200   0x004EA000    ///< 19200  baud (actual rate: 19208)
#define UART_BAUDRATE_28800   0x0075F000    ///< 28800  baud (actual rate: 28829)
#define UART_BAUDRATE_31250   0x00800000    ///< 31250  baud
#define UART_BAUDRATE_38400   0x009D5000    ///< 38400  baud (actual rate: 38462)
#define UART_BAUDRATE_56000   0x00E50000    ///< 56000  baud (actual rate: 55944)
#define UART_BAUDRATE_57600   0x00EBF000    ///< 57600  baud (actual rate: 57602)
#define UART_BAUDRATE_76800   0x013A9000    ///< 76800  baud (actual rate: 76797)
#define UART_BAUDRATE_115200  0x01D7E000    ///< 115200 baud (actual rate: 115204)
#define UART_BAUDRATE_230400  0x03AFB000    ///< 230400 baud (actual rate: 230393)
#define UART_BAUDRATE_250000  0x04000000    ///< 250000 baud
#define UART_BAUDRATE_460800  0x075F7000    ///< 460800 baud
#define UART_BAUDRATE_921600  0x0EBEDFA4    ///< 921600 baud (actual rate: 921585)
#define UART_BAUDRATE_1M      0x10000000    ///< 1Mega  baud

void Uart_init(uint32_t baudrate);
void Uart_sendChar(const char ch);
void Uart_sendString(const char *str);
void Uart_sendNumberHex(uint32_t number);
void Uart_sendNumberDec(int32_t number);

#endif
