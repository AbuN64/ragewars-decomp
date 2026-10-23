#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802B2CF0_CD3B0[2] = {
    0x41DFFFFF, 0xFFC00000,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_800C7488[8] =
    "t\011m_Opti";
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C8B28[2] = {
    0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C8158[2] = {
    0x00230180, 0x00230180,
};
#endif

#if defined(VERSION_DE)
char rodata_unresolved_800C7568[8] =
    "o/synthe";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802B2CF0_CD3B0_us_rev1.c */
const unsigned int D_blob_898e22e4f52e3e0e52d7[2] = {
    0x41DFFFFF, 0xFFC00000,
};
#endif
