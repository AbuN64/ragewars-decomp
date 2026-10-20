#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

/* ROM-grounded data: rodata/unresolved/800CC810 */
const unsigned int D_blob_0feeefc3e0e713f741ec[1] = {
    0x3A83126F,
};

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8B84);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C81B4);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C75C4);
#endif
