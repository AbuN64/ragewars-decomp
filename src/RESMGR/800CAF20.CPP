#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802A1B24_CBB20);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5CC3);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800C5CC4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C6073);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800C6074);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C6033);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800C6034);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_802A1B24_CBB20_us_rev1.c */
const unsigned char D_blob_66a5e2efda41fe7042e8[3] = {
    0x25, 0x64, 0x00,
};
#endif
