#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_804142AC_E1D00);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E8918);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800ED758);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD0D8);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804142AC_E1D00_us_rev1.c */
const char D_blob_4b08887938ba46bf6f70[8] = "UNKNOWN";
#endif
