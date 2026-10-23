#include "include_asm.h"

const unsigned int D_auto_rodata_shared_800C6AB0[10] = {
    0x00201650, 0x002015B4, 0x002015BC, 0x002015E4, 0x002015F0, 0x002015FC, 0x00201604, 0x00201628,
    0x00201638, 0x00201648,
};

#if defined(VERSION_US)
const char rodata_unresolved_800C1918[20] =
    "RGBR\000\000\000\000\000\000\000\000\077\200\000\000\000\000\000\000";
#endif

#if defined(VERSION_EU)
const unsigned int rodata_unresolved_800C1C88[5] = {
    0x8E02000C, 0x3C060500, 0x00000000, 0x3F800000, 0x00000000,
};
#endif
