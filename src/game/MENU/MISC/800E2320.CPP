#include "include_asm.h"
#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", D_auto_rodata_func_8043D1DC_de_800DCF94);
#endif
#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", D_auto_rodata_func_8043D1DC_de_800DE2E4);
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
INCLUDE_RODATA("data_800C", D_8043E2D8_E2F20);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCFA5);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE2F5);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8043E2D8_E2F20_us_rev1.c */
const unsigned char D_blob_0ba9a74234414ef5c6c4[5] = {
    0x25, 0x30, 0x32, 0x64, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E2325);
#endif
