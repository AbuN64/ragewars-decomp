#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80241BAC_C9448[3] = {
    0x3ED1B717, 0x3ED1B717, 0x3ED1B717,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_800C3694[12] =
    "\000\000\000\025m_dwChea";
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C3A54[3] = {
    0x4F000000, 0x47800000, 0x4F000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C3764[3] = {
    0x3F333333, 0x3F333333, 0x2490FFFF,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80241BAC_C9448_us_rev1.c */
const unsigned int D_blob_c6e20dcf8365ef7c5fa8[1] = {
    0x3ED1B717,
};

/* ROM-grounded data: src/rw_pool_80241F24_C944C_us_rev1.c */
const unsigned int D_blob_7f8e2984af5813a58f3c[1] = {
    0x3ED1B717,
};

/* ROM-grounded data: src/rw_pool_802426CC_C9450_us_rev1.c */
const unsigned int D_blob_3d3f4a16b9cf94ea04a2[1] = {
    0x3ED1B717,
};
#endif
