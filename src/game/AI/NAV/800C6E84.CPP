#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_US)
#if defined(VERSION_EU)
const unsigned int rodata_unresolved_800C205C[1] = {
    0x00000000,
};
#endif
#if defined(VERSION_US)
unsigned int rodata_unresolved_800C205C[1] = {
    0x00000000,
};
#endif
#endif
