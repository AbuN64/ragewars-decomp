#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/shared/800E27E0 */
const unsigned short D_blob_phase2_ceab36489678f9aeb2a6[3] = {
    0x2020, 0x2532, 0x6400,
};
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE7A6);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E27E6);
#endif
