#include "include_asm.h"

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C77B4[8] = {
    0x0B000010, 0x000B0000, 0x00000010, 0x3C8EFA35, 0x3F000000, 0xBF800000, 0x40000000, 0x48000000,
};
#endif

#if defined(NON_MATCHING) && defined(VERSION_US)
unsigned int D_auto_rodata_unresolved_800C77B4[9] = {
    0x0B000010, 0x000B0000, 0x00000010, 0x3C8EFA35, 0x3F000000, 0xBF800000, 0x40000000, 0x48000000,
    0x4F000000,
};
#endif
