////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
/// See provided LICENSE file for more information
///
/// \brief Symbols defined by the linker script
///
////////////////////////////////////////////////////////////////////////////////


#ifndef LINKER_SCRIPT_H__
#define LINKER_SCRIPT_H__

extern uint32_t __stack_top;
extern uint32_t __stack_end__;

extern uint32_t __bss_start__;
extern uint32_t __bss_end__;

extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __data_load__;

extern uint32_t __heap_start__;
extern uint32_t __heap_end__;

extern void (*__preinit_array_start__ []) (void);
extern void (*__preinit_array_end__ []) (void);
extern void (*__init_array_start__ []) (void);
extern void (*__init_array_end__ []) (void);
extern void (*__fini_array_start__ []) (void);
extern void (*__fini_array_end__ []) (void);

#endif
