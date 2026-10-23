#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
const unsigned char D_8040B444_E19CC[5] = {
    0x25, 0x31, 0x64, 0x2E, 0x00,
};
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800DBA51[7] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DCDA1[7] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8040B444_E19CC_us_rev1.c */
const unsigned char D_blob_d03d5379f8c440c18cae[5] = {
    0x25, 0x31, 0x64, 0x2E, 0x00,
};
#endif
