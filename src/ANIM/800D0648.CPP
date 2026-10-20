#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800D0648 */
const unsigned int D_blob_phase2_261792c552ab891181a5[1] = {
    0x3DCCCCCD,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800CB31C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800CC9BC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800CBFEC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800CB40C);
#endif
