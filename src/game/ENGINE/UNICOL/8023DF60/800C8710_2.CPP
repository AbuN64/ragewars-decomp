#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C398C[1] = {
    0x26310008,
};
#endif
#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C398C[1] = {
    0x00000000,
};
#endif
#endif
