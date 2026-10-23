#include "include_asm.h"

#if defined(VERSION_EU_X)
const unsigned int rodata_func_80256880_de_800C41A0[3] = {
    0x41F00000, 0x00000000, 0x3C888889,
};
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C41AC[1] = {
    0x000213C3,
};
#endif
#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C41AC[1] = {
    0x00000000,
};
#endif
#endif
