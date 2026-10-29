#include "include_asm.h"

/* 800E2774.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_constants_80443734_E3374_us_rev1.c */
const unsigned int g_Player_DrawPulsingMenuSpriteConstantWords_us_rev1[1] = {
    0x3F000000,
};
#endif

/* 80442BC8_5.CPP */
#if defined(VERSION_US)
/* ROM-grounded data: rodata/Player_FormatPlayerPartnerStatus/800E2738 (US: shared with the next table) */
#ifdef VERSION_US
const unsigned int k_AmmoEncodedWords[15] = {
    0x004436B0, 0x004436C8, 0x004436E0, 0x004436F8, 0x00443710, 0x00443728, 0x00443740, 0x00000000,
    0x00443784, 0x00443794, 0x004437A4, 0x004437B4, 0x004437C4, 0x004437D4, 0x004437E4,
};
#endif
#endif

#if defined(VERSION_US)
const unsigned int g_Player_DrawPulsingMenuSpriteConstantWords_us[1] = {
    0x3F000000,
};
#endif

#if defined(VERSION_US)
unsigned int k_AmmoEncodedWordsBlock1[2] = {
    0x000A0004, 0x00000014,
};
#endif

/* DATA_800E2778.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E2778 */
unsigned int g_AmmoEncodedWordsBlock1[2] = {
    0x00000001, 0x00000010,
};
#endif

/* DATA_800EEDE0.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
const char s_ammoCountFormat[8] =
    " %03d\000\000\000";
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif
