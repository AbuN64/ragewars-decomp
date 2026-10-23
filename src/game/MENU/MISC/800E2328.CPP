#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8043E7AC_E2F28);
#endif

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800DCFAC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9B3C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE2FC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8043E7AC_E2F28_us_rev1.c */
const unsigned char D_blob_2b2bfc88c3a9266b27aa[4] = {
    0x25, 0x33, 0x64, 0x00,
};
#endif
