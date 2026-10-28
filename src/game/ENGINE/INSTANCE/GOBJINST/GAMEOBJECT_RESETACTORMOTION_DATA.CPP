#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80246184_C9514[2] = {
    0x3F800000, 0x3F4CCCCD,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C375C[1] = {
    0x63697479,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C3B1C[1] = {
    0x3F7FFF58,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C3ADC[1] = {
    0x00002821,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C382C[1] = {
    0x6E737461,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80246184_C9514_us_rev1.c */
const unsigned int D_blob_7cb729509528ee0305eb[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_8024643C_C9518_us_rev1.c */
const unsigned int D_blob_f37d5279a6b8bc3cae0a[1] = {
    0x3F4CCCCD,
};
#endif
