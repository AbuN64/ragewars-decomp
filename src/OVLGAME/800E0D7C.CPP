#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char D_804058B0_E197C[5] = "fifo";
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DBA01);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E8591);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800ED3D1);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCD51);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804058B0_E197C_us_rev1.c */
const char D_blob_dd23482635aa126a2066[5] = "fifo";
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E0D81);
#endif
