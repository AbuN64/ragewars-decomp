#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800E2788 */
const unsigned char D_blob_phase2_7f8705674e42ed0499e7[7] = {
    0x20, 0x20, 0x25, 0x30, 0x32, 0x64, 0x00,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD40F);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9F9F);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EEDDF);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE75F);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E278F);
#endif
