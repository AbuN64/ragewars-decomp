#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80298FE8_CB408);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C55AC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C595C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C591C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C567C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80298FE8_CB408_us_rev1.c */
const unsigned int D_blob_95c14edb8bb0fb2af018[1] = {
    0x3F800000,
};
#endif
