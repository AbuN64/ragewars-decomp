#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8025305C_C9B98);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3DDE);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C419E);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3EAE);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8025305C_C9B98_us_rev1.c */
const char D_blob_66a6a2bbfb831a34114b[6] = "alloc";
#endif
