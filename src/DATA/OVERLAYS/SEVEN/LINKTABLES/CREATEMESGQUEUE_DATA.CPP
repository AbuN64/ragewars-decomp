#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X)
unsigned int D_src_f0222606[2] = {
    0x00000000, 0xFFFFFFFF,
};
#endif
#if defined(VERSION_US)
unsigned int D_src_f0222606[3] = {
    0x00000000, 0xFFFFFFFF, (unsigned int)D_src_f0222606,
};
#endif
#endif

#if defined(VERSION_US)
#if defined(VERSION_US)
unsigned int __osActiveQueue_CreatemesgqueueData[1] = {
    (unsigned int)D_src_f0222606,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_createmesgqueueDataConstantWords[4] = {
    0x00000000, 0xFFFFFFFF, 0x800D9290, 0x800D9290,
};
#endif
