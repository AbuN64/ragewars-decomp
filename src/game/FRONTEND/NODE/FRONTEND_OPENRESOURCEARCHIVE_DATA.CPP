#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800E10E0 */
const unsigned char D_blob_phase2_e6036f2dfb04ad707672[] = {
    0x72, 0x62, 0x00,
#if defined(VERSION_EU)
    0x4B,
#endif
#if defined(VERSION_US_REV1)
    0xC4,
#endif
};

#if defined(VERSION_US)
char rodata_unresolved_800DBD63[13] =
    "EL_INTRO_4equ";
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800E88F3[13] = {
    0xF4, 0x00, 0x43, 0xD5, 0x14, 0x00, 0x43, 0xD5, 0x04, 0x00, 0x43, 0xD5, 0x34,
};
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
char rodata_unresolved_800DD0B3[13] =
    "s : %d ]\012\000\000\000\000";
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif
