#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80408118_E19A8);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_shared_800ED3FC);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_func_8040A58C_de_800ED400);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_func_8040A614_de_800ED404);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E85D2);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800ED412);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80408118_E19A8_us_rev1.c */
const unsigned int D_blob_4fb6fb10cdfd8ef7403a[1] = {
    0x20202000,
};
#endif
