#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802AA1AC_CBF58[5] = {
    0x41F00000, 0x00000000, 0x3F800000, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C610C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C64BC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C647C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C61DC[1] = {
    0x00000000,
};
#endif
