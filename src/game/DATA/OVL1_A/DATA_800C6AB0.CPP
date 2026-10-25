#include "include_asm.h"


#if defined(VERSION_US)
const char rodata_unresolved_800C1918[20] =
    "RGBR\000\000\000\000\000\000\000\000\077\200\000\000\000\000\000\000";
#endif

#if defined(VERSION_EU)
const unsigned int rodata_unresolved_800C1C88[5] = {
    0x8E02000C, 0x3C060500, 0x00000000, 0x3F800000, 0x00000000,
};
#endif
