#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800CA374 */
const unsigned char g_levelNameText[] = {
    0x6C, 0x65, 0x76, 0x65, 0x6C, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x00,
#if defined(VERSION_US)
    0x00,
#endif
};

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C557F[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C553F[1] = {
    0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800C528F[1] = {
    0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800CA37F[1] = {
    0x00,
};
#endif
