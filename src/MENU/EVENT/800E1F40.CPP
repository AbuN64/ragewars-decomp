#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_constants_80437C28_us_rev1_E2B40_us_rev1.c */
const unsigned int D_blob_8953d58d3c35985f217c[1] = {
    0x3D888889,
};
#endif

#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", rodata_func_8043829C_de_800DDF14);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DDF17);
#endif
