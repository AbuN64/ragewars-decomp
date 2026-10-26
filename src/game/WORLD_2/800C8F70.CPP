#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_statModelsIndexText[18] =
    "stat models index\000";
#endif

#if defined(VERSION_US)
unsigned short rodata_unresolved_800C3DC2[1] = {
    0x0000,
};
#endif

#if defined(VERSION_EU_X)
unsigned short rodata_unresolved_800C4182[1] = {
    0x0000,
};
#endif

#if defined(VERSION_EU)
unsigned short rodata_unresolved_800C4142[1] = {
    0x0000,
};
#endif

#if defined(VERSION_DE)
unsigned short rodata_unresolved_800C3E92[1] = {
    0x0000,
};
#endif

#if defined(VERSION_US_REV1)
const char D_auto_src_rw_text_802507AC_C9B70_us_rev1[] = "stat models index"
#if defined(VERSION_US_REV1)
    "\000\000"
#endif
;
#endif
