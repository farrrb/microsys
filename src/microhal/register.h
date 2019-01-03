////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// \brief Register access (read, write) interface (public)
////////////////////////////////////////////////////////////////////////////////

#ifndef REGISTER_H__
#define REGISTER_H__

#include "microhal.h"

MICROHAL_INLINE void register_write(uint32_t addr, uint32_t val)
{
  *((volatile uint32_t *)addr) = val;
}

MICROHAL_INLINE uint32_t register_read(uint32_t addr)
{
  return *((volatile uint32_t *)addr);
}

#endif
