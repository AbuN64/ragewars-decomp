#include "include_asm.h"

/* ROM-grounded data: rodata/writable/800E28A0 */
unsigned int D_blob_phase2_5a247187d2e6747d8707[1] = {
    0x00000002,
};

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800EA084);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EEEC4);
#endif
