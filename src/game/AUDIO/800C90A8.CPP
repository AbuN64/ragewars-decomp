#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8025D350_C9CA8[3] = {
    0x41F00000, 0x00000000, 0x3C23D70A,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C4274[3] = {
    0x8E740020, 0x186000DD, 0x02A08821,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C3FC4[3] = {
    0x3C23D70A, 0x46FFFE00, 0x3C23D70A,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8025D350_C9CA8_us_rev1.c */
const unsigned int D_blob_a274f83a44ed3e23c66c[3] = {
    0x41F00000, 0x00000000, 0x3C23D70A,
};
#endif
