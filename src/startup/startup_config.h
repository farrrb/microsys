////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// \brief Startup configuration
///
////////////////////////////////////////////////////////////////////////////////


#ifndef STARTUP_CONFIG_H__
#define STARTUP_CONFIG_H__

#define HEAP_SIZE   (1024)        ///< [Byte]
#define STACK_SIZE  (1024)        ///< [Byte]

#define HEAP_MAGIC  (0xDEADBEEF)  ///< A magic word to examine heap usage
#define STACK_MAGIC (0xFEEDC0DE)  ///< A magic word to examine stack usage

#endif
