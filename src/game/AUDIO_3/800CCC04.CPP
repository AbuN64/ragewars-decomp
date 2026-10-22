#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B9FD0_CD804);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C78E2);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800C78E4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C85B2);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800C85B4);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C79C2);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800C79C4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_802B9FD0_CD804_us_rev1.c */
const char D_blob_f285d2215453b80d0441[14] = "io/sprawdma.c";
#endif
