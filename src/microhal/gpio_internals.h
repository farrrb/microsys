/// Copyright (c) 2018 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// \brief  Internal implementation of the GPIO module. Do not include this file
///         use gpio.h instead for the public interface.
///         The whole purpose of this file is to do information hiding.
///         (private)

#ifndef GPIO_INTERNALS_H__
#define GPIO_INTERNALS_H__

/// \brief GPIO register file description
typedef struct
{
  volatile uint32_t RESERVED0[321];                   ///< (Offset: 0x000) Reserved space
  volatile uint32_t OUT;                              ///< (Offset: 0x504) Write GPIO port.
  volatile uint32_t OUTSET;                           ///< (Offset: 0x508) Set individual bits in GPIO port.
  volatile uint32_t OUTCLR;                           ///< (Offset: 0x50C) Clear individual bits in GPIO port.
  volatile uint32_t IN;                               ///< (Offset: 0x510) Read GPIO port.
  volatile uint32_t DIR;                              ///< (Offset: 0x514) Direction of GPIO pins.
  volatile uint32_t DIRSET;                           ///< (Offset: 0x518) DIR set register.
  volatile uint32_t DIRCLR;                           ///< (Offset: 0x51C) DIR clear register.
  volatile uint32_t RESERVED1[120];                   ///< (Offset: 0x520) Reserved space
  volatile uint32_t PIN_CNF[32];                      ///< (Offset: 0x700) Configuration of GPIO pins.
} GpioModule_t;

#define GPIO_BASE     (0x50000000)                            ///< GPIO port base address
#define GPIO_MODULE   ((volatile GpioModule_t *)GPIO_BASE)    ///< Pointer to GPIO module instance

typedef enum
{
  GPIO_PIN_00 = 0x00000001,
  GPIO_PIN_01 = 0x00000002,
  GPIO_PIN_02 = 0x00000004,
  GPIO_PIN_03 = 0x00000008,
  GPIO_PIN_04 = 0x00000010,
  GPIO_PIN_05 = 0x00000020,
  GPIO_PIN_06 = 0x00000040,
  GPIO_PIN_07 = 0x00000080,
  GPIO_PIN_08 = 0x00000100,
  GPIO_PIN_09 = 0x00000200,
  GPIO_PIN_10 = 0x00000400,
  GPIO_PIN_11 = 0x00000800,
  GPIO_PIN_12 = 0x00001000,
  GPIO_PIN_13 = 0x00002000,
  GPIO_PIN_14 = 0x00004000,
  GPIO_PIN_15 = 0x00008000,
  GPIO_PIN_16 = 0x00010000,
  GPIO_PIN_17 = 0x00020000,
  GPIO_PIN_18 = 0x00040000,
  GPIO_PIN_19 = 0x00080000,
  GPIO_PIN_20 = 0x00100000,
  GPIO_PIN_21 = 0x00200000,
  GPIO_PIN_22 = 0x00400000,
  GPIO_PIN_23 = 0x00800000,
  GPIO_PIN_24 = 0x01000000,
  GPIO_PIN_25 = 0x02000000,
  GPIO_PIN_26 = 0x04000000,
  GPIO_PIN_27 = 0x08000000,
  GPIO_PIN_28 = 0x10000000,
  GPIO_PIN_29 = 0x20000000,
  GPIO_PIN_30 = 0x40000000,
  GPIO_PIN_31 = 0x80000000
} GpioPin_t;

MICROHAL_INLINE void Gpio_initPins(GpioPin_t pins, bool output)
{
  if (output == true)
  {
    GPIO_MODULE->DIRSET = (uint32_t)pins;
  }
  else
  {
    GPIO_MODULE->DIRCLR = (uint32_t)pins;
  }
}

MICROHAL_INLINE void Gpio_setPins(GpioPin_t pins)
{
  GPIO_MODULE->OUTSET = (uint32_t)pins;
}

MICROHAL_INLINE void Gpio_clrPins(GpioPin_t pins)
{
  GPIO_MODULE->OUTCLR = (uint32_t)pins;
}

#endif
