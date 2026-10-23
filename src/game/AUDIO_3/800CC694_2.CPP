#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C7504[3] = {
    0x8FB70034, 0x8FB60030, 0x8FB5002C,
};
#endif
#if defined(VERSION_US)
unsigned int rodata_unresolved_800C7504[1] = {
    0x00000000,
};
#endif
#endif
