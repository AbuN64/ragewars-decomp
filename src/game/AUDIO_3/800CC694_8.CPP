#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802B2510_CD360[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C8AD4[3] = {
    0xFFFF0000, 0x06A503E8, 0x06A601F4,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C8104[3] = {
    0x0022EC3C, 0x0022EC80, 0x0022EC3C,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C7514[3] = {
    0x002B2908, 0x002B2978, 0x002B2A60,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802B2510_CD360_us_rev1.c */
const unsigned int D_blob_0ac61d632b03a4a1fa7b[1] = {
    0x3F800000,
};
#endif
