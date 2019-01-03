////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// \brief GPIO interface (public)
///
////////////////////////////////////////////////////////////////////////////////

#ifndef GPIO_H__
#define GPIO_H__

#include "microhal.h"
#include "gpio_internals.h"

MICROHAL_INLINE void Gpio_initPins(GpioPin_t pins, bool output);

MICROHAL_INLINE void Gpio_setPins(GpioPin_t pins);

MICROHAL_INLINE void Gpio_clrPins(GpioPin_t pins);

#endif
