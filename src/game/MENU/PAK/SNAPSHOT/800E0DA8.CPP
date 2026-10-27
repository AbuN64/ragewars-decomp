#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80408118_E19A8[1] = {
    0x20202000,
};
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
const unsigned int rodata_shared_800ED3FC[1] = {
    0x25316400,
};
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
const unsigned int rodata_func_8040A58C_de_800ED400[1] = {
    0x25326400,
};
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
const char rodata_func_8040A614_de_800ED404[14] =
    "%3d.%02d.%02d\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80408118_E19A8_us_rev1.c */
const unsigned char D_blob_4fb6fb10cdfd8ef7403a[4] = {
    0x20, 0x20, 0x20, 0x00,
};
#endif
