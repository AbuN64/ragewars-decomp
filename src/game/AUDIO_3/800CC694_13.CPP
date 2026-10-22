#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

const char D_auto_src_ragewars_resident_strings_CD3C4_us_rev1[20] = "audio/synthesizer.c";

/* ROM-grounded data: src/rw_pool_802B3CD0_CD3D8_us_rev1.c */
const unsigned int D_blob_ba6b872948b26bb298a2[2] = {
    0x358637BD, 0x3F000000,
};

/* ROM-grounded data: src/rw_pool_802B3DB8_CD3E0_us_rev1.c */
const unsigned int D_blob_1a249f1d90e237f6ffb5[2] = {
    0x358637BD, 0x3F000000,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C74B8);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8B58);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8188);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7598);
#endif
