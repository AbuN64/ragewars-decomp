#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800C8EC4 */
const unsigned char g_simpModelText[11] = {
    0x73, 0x69, 0x6D, 0x70, 0x20, 0x6D, 0x6F, 0x64, 0x65, 0x6C, 0x00,
};

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C3D0F[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C40CF[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C408F[1] = {
    0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800C3DDF[1] = {
    0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800C8ECF[1] = {
    0x00,
};
#endif
