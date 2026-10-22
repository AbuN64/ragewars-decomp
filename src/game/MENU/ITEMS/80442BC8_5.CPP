#include "include_asm.h"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* ROM-grounded data: rodata/func_804434E0_de/800E2738 */
#ifdef VERSION_DE
const unsigned int D_blob_phase2_b8084b071a881bbaccb0[7] = {
    0x00443540, 0x00443558, 0x00443570, 0x00443588, 0x004435A0, 0x004435B8, 0x004435D0,
};
#endif
#ifdef VERSION_US
const unsigned int D_blob_phase2_b8084b071a881bbaccb0[15] = {
    0x004436B0, 0x004436C8, 0x004436E0, 0x004436F8, 0x00443710, 0x00443728, 0x00443740, 0x00000000,
    0x00443784, 0x00443794, 0x004437A4, 0x004437B4, 0x004437C4, 0x004437D4, 0x004437E4,
};
#endif
#ifdef VERSION_US_REV1
const unsigned int D_blob_phase2_b8084b071a881bbaccb0[7] = {
    0x004436B0, 0x004436C8, 0x004436E0, 0x004436F8, 0x00443710, 0x00443728, 0x00443740,
};
#endif
#endif

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_func_80443734_de_800DD3F4);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD3F8);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE724);
#endif
