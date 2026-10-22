#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80286AA8_CAE50);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5096);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5456);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5166);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80286AA8_CAE50_us_rev1.c */
const char D_blob_7b20c7c5cce5d400fe67[6] = "links";
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CA256);
#endif
