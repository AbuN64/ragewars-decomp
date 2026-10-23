#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char D_804142AC_E1D00[8] =
    "UNKNOWN\000";
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E8918[4] = {
    0x0000001E, 0x00000001, 0x496E6600, 0x4E614E00,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800ED758[4] = {
    0x0800FFD5, 0x0800FFD6, 0x496E6600, 0x4E614E00,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD0D8[4] = {
    0x00000000, 0x00000000, 0x496E6600, 0x4E614E00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804142AC_E1D00_us_rev1.c */
const char D_blob_4b08887938ba46bf6f70[8] = "UNKNOWN";
#endif
