#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800D0648 */
const unsigned int D_blob_phase2_261792c552ab891181a5[1] = {
    0x3DCCCCCD,
};

#if defined(VERSION_US)
unsigned int rodata_unresolved_800CB31C[1] = {
    0x0000000F,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800CC9BC[1] = {
    0x3FC78F78,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800CBFEC[1] = {
    0x44415649,
};
#endif
