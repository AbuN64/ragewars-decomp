#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8024E2FC_C9A5C[3] = {
    0x43800000, 0x42A3D70A, 0x4275C28F,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_800C3CA8[8] =
    "alTimeT\000";
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C4068[2] = {
    0x43000000, 0x437F0000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C4028[2] = {
    0x8FB50024, 0x8FB40020,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C3D78[2] = {
    0x3EB33333, 0x3F000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_tail_8024E2FC_C9A5C_us_rev1.c */
const unsigned int D_blob_c4dbe4674d0baa5e48fa[3] = {
    0x43800000, 0x42A3D70A, 0x4275C28F,
};
#endif
