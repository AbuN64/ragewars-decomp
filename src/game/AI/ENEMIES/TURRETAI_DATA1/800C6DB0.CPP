#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_EU_X)
#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C1CC8[2] = {
    0x00209EF4, 0x00209EF4,
};
#endif
#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C1CC8[5] = {
    0x41000000, 0x41B80000, 0x00000000, 0x3F800000, 0x00000000,
};
#endif
#endif
