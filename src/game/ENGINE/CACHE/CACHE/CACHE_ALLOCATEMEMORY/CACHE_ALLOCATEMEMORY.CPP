#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned short g_allocText[3] = {
    0x616C, 0x6C6F, 0x6300,
};
#endif
#if defined(VERSION_EU)
const char g_allocText[8] =
    "alloc\000\000\000";
#endif
#endif

#if defined(VERSION_US)
unsigned short k_CacheAllocatememoryEncodedHalfwords[1] = {
    0x0008,
};
#endif

#if defined(VERSION_EU_X)
unsigned short k_CacheAllocatememoryEncodedHalfwordsBlock1[1] = {
    0xCBEC,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/alloc_text_us_rev1.c */
const char s_allocText[6] = "alloc";
#endif
