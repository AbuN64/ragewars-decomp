#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8020CA10_C7A7C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8020CA10_C7A7C_us_rev1.c */
const unsigned int D_blob_8d7cc47a80dd77f04129[2] = {
    0xBF800000, 0x41700000,
};
#endif
