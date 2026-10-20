#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80250624_C9B60);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3DAE);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C416E);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C412E);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3E7E);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80250624_C9B60_us_rev1.c */
const char D_blob_c06563bbfef28be84e19[14] = "static events";
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8F6E);
#endif
