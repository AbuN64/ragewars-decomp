#include "include_asm.h"

unsigned short D_auto_src_rw_controller_pak_filename_alphabet_us_rev1[33] = {
    0x007E, 0x7E7E, 0x7E7E, 0x7E7E, 0x7E7E, 0x7E7E, 0x7E7E, 0x7E20, 0x3031, 0x3233, 0x3435, 0x3637,
    0x3839, 0x4142, 0x4344, 0x4546, 0x4748, 0x494A, 0x4B4C, 0x4D4E, 0x4F50, 0x5152, 0x5354, 0x5556,
    0x5758, 0x595A, 0x2122, 0x2327, 0x2A2B, 0x2C2D, 0x2E2F, 0x3A3D, 0x3F40,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DD4FE);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800EA07E);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800EEEBE);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800DE84E);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E285C_unclaimed_E349E);
#endif
