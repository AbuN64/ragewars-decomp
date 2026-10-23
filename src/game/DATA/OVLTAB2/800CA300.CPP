#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800CA300 */
const unsigned char D_blob_phase2_fb6b6c6f9eb91dd0e313[] = {
    0x67, 0x72, 0x69, 0x64, 0x20, 0x73, 0x65, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x00,
#if defined(VERSION_DE)
    0x00, 0x00, 0x00,
#endif
};

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C514D[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C550D[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C54CD[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800CA30D[3] = {
    0x00, 0x00, 0x00,
};
#endif
