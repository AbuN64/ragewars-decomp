#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
INCLUDE_RODATA("data_800C", D_8028A948_CAFD4);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5217);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C52E7);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_8028A948_CAFD4_us_rev1.c */
const unsigned char D_blob_7af543284835d222fd61[3] = {
    0x25, 0x73, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CA3D7);
#endif
