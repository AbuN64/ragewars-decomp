#include "include_asm.h"

#define L_udivdi3
#include "libgcc2.inc.c"

#if defined(VERSION_US)
unsigned int rodata_unresolved_802C1254[3] = {
    0x00660000, 0x00040000, 0x00000009,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_802C1604[3] = {
    0x40400000, 0x40400000, 0x41B80000,
};
#endif
