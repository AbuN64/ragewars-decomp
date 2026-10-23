#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
const unsigned int rodata_func_80278C10_de_800C4DE0[1] = {
    0x40800000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C4E24[3] = {
    0x00000000, 0x43300000, 0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C4DE4[3] = {
    0xC4400000, 0x24A20001, 0x00402821,
};
#endif
