#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
const char rodata_shared_800EED80[8] =
    "%04d\000\000\000\000";
#endif
#if defined(VERSION_EU_X)
const unsigned char rodata_shared_800EED80[5] = {
    0x25, 0x30, 0x34, 0x64, 0x00,
};
#endif
#endif
