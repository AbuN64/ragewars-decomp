#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/func_804434E0_de/800E2758 */
#ifdef VERSION_DE
const unsigned int D_blob_phase2_5ad8b0872f8686d1dfd6[7] = {
    0x00443614, 0x00443624, 0x00443634, 0x00443644, 0x00443654, 0x00443664, 0x00443674,
};
#endif
#ifdef VERSION_US_REV1
const unsigned int D_blob_phase2_5ad8b0872f8686d1dfd6[7] = {
    0x00443784, 0x00443794, 0x004437A4, 0x004437B4, 0x004437C4, 0x004437D4, 0x004437E4,
};
#endif
#endif

#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", rodata_func_80443734_de_800DE744);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE748);
#endif
