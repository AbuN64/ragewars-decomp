#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802AA1AC_CBF50);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C60F4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C64A4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C6464);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C61C4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802AA1AC_CBF50_us_rev1.c */
const unsigned int D_blob_608004a4c20165c340f6[1] = {
    0x3F800000,
};
#endif
