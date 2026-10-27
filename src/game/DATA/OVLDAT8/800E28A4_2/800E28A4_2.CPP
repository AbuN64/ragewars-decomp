#include "include_asm.h"

unsigned int D_auto_rodata_writable_800E28B0[8] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000,
};

#if defined(VERSION_US)
unsigned int data_unresolved_800DD530[3] = {
    0x00000140, 0x000000F0, 0xFFFFFFFF,
};
#endif

#if defined(VERSION_EU_X)
unsigned int data_unresolved_800EA0B0[3] = {
    0x00000140, 0x000000F0, 0xFFFFFFFF,
};
#endif

#if defined(VERSION_EU)
unsigned int data_unresolved_800EEEF0[3] = {
    0x00000140, 0x000000F0, 0xFFFFFFFF,
};
#endif

#if defined(VERSION_DE)
unsigned int data_unresolved_800DE880[3] = {
    0x00000140, 0x000000F0, 0xFFFFFFFF,
};
#endif

#if !(defined(VERSION_US_REV1))
/* bytes live in the preceding array */
#endif
