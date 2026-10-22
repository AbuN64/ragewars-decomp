#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8021EEFC_C82EC);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C252F);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C28DF);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C289F);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C25FF);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_8021EEFC_C82EC_us_rev1.c */
const unsigned char D_blob_7002b97077c82a79bbdc[3] = {
    0x25, 0x73, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800C76EF);
#endif
