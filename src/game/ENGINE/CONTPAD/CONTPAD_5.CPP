#include "include_asm.h"
#include "TYPES.H"

#if defined(VERSION_DE) || defined(VERSION_EU)
#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C42EC[1] = {
    0xC2FE0000,
};
#endif
#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C42EC[1] = {
    0x00542821,
};
#endif
#endif
