#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8024E2FC_C9A5C);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3CA8);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4068);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4028);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3D78);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_tail_8024E2FC_C9A5C_us_rev1.c */
const unsigned int D_blob_c4dbe4674d0baa5e48fa[3] = {
    0x43800000, 0x42A3D70A, 0x4275C28F,
};
#endif
