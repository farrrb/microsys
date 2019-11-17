////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2019 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// \brief NVIC control
///
////////////////////////////////////////////////////////////////////////////////

#ifndef NVIC_H__
#define NVIC_H__

#include "microhal.h"

typedef enum
{
    NVIC_TIMER0 = 8,

} NvicIrqNr_t;

void Nvic_enable(NvicIrqNr_t irq_nr);

#endif
