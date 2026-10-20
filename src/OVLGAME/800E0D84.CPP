#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char D_804058B0_E1984[11] = "audio heap";
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DBA0F);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E859F);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800ED3DF);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCD5F);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804058B0_E1984_us_rev1.c */
const char D_blob_43b0ba6b1ac402bbd480[11] = "audio heap";
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E0D8F);
#endif
