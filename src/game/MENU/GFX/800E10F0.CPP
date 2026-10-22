#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_804142AC_E1CF0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DBD7D);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E890D);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800ED74D);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD0CD);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804142AC_E1CF0_us_rev1.c */
const unsigned char D_blob_e943468e2786e751deb0[13] = {
    0x5B, 0x20, 0x25, 0x73, 0x20, 0x3A, 0x20, 0x25, 0x64, 0x20, 0x5D, 0x0A, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E10FD);
#endif
