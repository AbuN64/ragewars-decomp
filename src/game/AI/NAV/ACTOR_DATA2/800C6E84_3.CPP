#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_EU_X)
#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C212C[1] = {
    0x00000000,
};
#endif
#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C212C[1] = {
    0x0022EC68,
};
#endif
#endif
