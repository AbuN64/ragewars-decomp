#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
INCLUDE_RODATA("data_800C", D_8041BE90_E2080);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DC103);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DC104);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD453);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800DD454);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_8041BE90_E2080_us_rev1.c */
const unsigned char D_blob_0e6a08a28b1a47b980d4[3] = {
    0x25, 0x64, 0x00,
};
#endif
