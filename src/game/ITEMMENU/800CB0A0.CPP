#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char g_systembootdoneText[15] =
    "systembootdone\000";
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C5E4F[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C61FF[1] = {
    0x20,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C61BF[1] = {
    0xFF,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800C5F1F[1] = {
    0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_802A71C0_CBCA0_us_rev1.c */
const unsigned char s_systembootdoneText[15] = {
    0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x62, 0x6F, 0x6F, 0x74, 0x64, 0x6F, 0x6E, 0x65, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800CB0AF[1] = {
    0x00,
};
#endif
