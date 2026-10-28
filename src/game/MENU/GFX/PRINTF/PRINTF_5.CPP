#include "include_asm.h"

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800E1220[2] = {
    0x00000000, 0x00000000,
};
#endif
#if !(defined(VERSION_DE))
const unsigned int rodata_unresolved_800E1220[2] = {
    0x00000000, 0x00000000,
};
#endif
