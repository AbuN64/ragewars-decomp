#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned char D_src_80515f28[3] = {
    0x42, 0x20, 0x00,
};
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800DE6DF[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800EB25F[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800F009F[1] = {
    0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DFA2F[1] = {
    0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_e0eb683c6d4d4b28aff1[1] = {
    0x42200000,
};
#endif
