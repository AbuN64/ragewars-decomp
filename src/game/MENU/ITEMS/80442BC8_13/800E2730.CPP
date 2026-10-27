#include "include_asm.h"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* ROM-grounded data: rodata/shared/800E2730 */
const unsigned char g_fmtDec4Pad[] = {
    0x25, 0x30, 0x34, 0x64, 0x00,
#if defined(VERSION_US)
    0x00, 0x00, 0x00,
#endif
};
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DE705[3] = {
    0x00, 0x00, 0x00,
};
#endif
