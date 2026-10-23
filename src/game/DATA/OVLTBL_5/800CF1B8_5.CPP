#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8021EEFC_CFDB8[1] = {
    0xC2EC0000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C9E8C[3] = {
    0x42940000, 0x42940000, 0xC2EC0000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800CB52C[3] = {
    0x42940000, 0x42940000, 0xC2EC0000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800CAB5C[3] = {
    0x42940000, 0x42940000, 0xC2EC0000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C9F78[3] = {
    0x42940000, 0x42940000, 0xC2EC0000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8021EEFC_CFDB8_us_rev1.c */
const unsigned int D_blob_9d33f2f29912959783e4[1] = {
    0xC2EC0000,
};
#endif
