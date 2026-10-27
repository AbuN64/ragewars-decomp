#include "include_asm.h"

/* ROM-grounded data: rodata/writable/800E28A0 */
unsigned int D_blob_phase2_5a247187d2e6747d8707[1] = {
    0x00000002,
};

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800EA084[3] = {
    0x00002C00, 0x00000200, 0x00000001,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EEEC4[3] = {
    0x00002C00, 0x00000200, 0x002BB820,
};
#endif
