#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8041A280_E2070[2] = {
    0x3EAAAAAB, 0x3D4CCCCD,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DC0F8[2] = {
    0x00000000, 0x00164D55,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E8C88[2] = {
    0x3DDD67C9, 0x3F000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EDAC8[2] = {
    0x0800FFE0, 0x01270134,
};
#endif

#if defined(VERSION_DE)
#if defined(VERSION_DE)
extern char D_800C8380_de[];
extern char D_800C8420_de[];
unsigned int rodata_unresolved_800DD448[2] = {
    (unsigned int)D_800C8380_de + 0x70, (unsigned int)D_800C8420_de + 0x90,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8041A280_E2070_us_rev1.c */
const unsigned int D_blob_1466e2b8289b860d4bb9[2] = {
    0x3EAAAAAB, 0x3D4CCCCD,
};
#endif
