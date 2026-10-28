#include "include_asm.h"

#if defined(VERSION_EU_X) || defined(VERSION_US)
#if defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
const unsigned int rodata_unresolved_800C3F6C[2] = {
    0x42F5C28F, 0x3FB5C28F,
};
#endif
#if defined(VERSION_US)
const unsigned int rodata_unresolved_800C3F6C[1] = {
    0x784C6973,
};
#endif
#endif
#if defined(VERSION_US)
#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C3F6C[2] = {
    0x42F5C28F, 0x3FB5C28F,
};
#endif
#if defined(VERSION_US)
unsigned int rodata_unresolved_800C3F6C[1] = {
    0x784C6973,
};
#endif
#endif
#endif
