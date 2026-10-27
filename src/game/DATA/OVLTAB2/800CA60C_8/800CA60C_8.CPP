#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80298FE8_CB410[2] = {
    0x408F4000, 0x00000000,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int D_80299B60_CB418[1] = {
    0xBF800000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C596C[1] = {
    0x20455854,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C568C[1] = {
    0x0029A164,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80298FE8_CB410_us_rev1.c */
const unsigned int D_blob_d32df2e67fa061c0c007[2] = {
    0x408F4000, 0x00000000,
};

/* ROM-grounded data: src/rw_pool_80299B60_CB418_us_rev1.c */
const unsigned int D_blob_e981e0a9122de2ed8afc[1] = {
    0xBF800000,
};
#endif
