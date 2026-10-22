#include "include_asm.h"

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1EE8);
#endif

#if defined(NON_MATCHING) && defined(VERSION_DE)
unsigned int D_auto_rodata_unresolved_800C1EE8[10] = {
    0x0020F01C, 0x0020F028, 0x0020EFC8, 0x0020F00C, 0x0020F01C, 0x0020F028, 0x0020F034, 0x0020F068,
    0x0020F078, 0x0020F088,
};
#endif
