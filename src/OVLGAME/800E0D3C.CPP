#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char D_804058B0_E193C[15] = "Display Buffer";
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DB9CB);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E855B);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800ED39B);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCD1B);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804058B0_E193C_us_rev1.c */
const char D_blob_ef98aa1baca74b3c10f7[15] = "Display Buffer";
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E0D4B);
#endif
