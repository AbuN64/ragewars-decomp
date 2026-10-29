#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"

#if !(defined(VERSION_US_REV1))
const unsigned int g_Menu_DrawScreenStackConstantWords_de_eu_eu_x_us[2] = {
    0x408F4000, 0x00000000,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int g_Stream_SetFloatPairToNegativeOneConstantWords_de_eu_eu_x_us[1] = {
    0xBF800000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_MenuDrawscreenstackEncodedWordsBlock1[1] = {
    0x20455854,
};
#endif

#if defined(VERSION_DE)
unsigned int k_MenuDrawscreenstackEncodedWords[1] = {
    0x0029A164,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/g_Menu_DrawScreenStackConstantWords_us_rev1_MenuDrawscreenstackData.c */
const unsigned int g_Menu_DrawScreenStackConstantWords_us_rev1[2] = {
    0x408F4000, 0x00000000,
};

/* ROM-grounded data: src/g_Stream_SetFloatPairToNegativeOneConstantWords_us_rev1_MenuDrawscreenstackData.c */
const unsigned int g_Stream_SetFloatPairToNegativeOneConstantWords_us_rev1[1] = {
    0xBF800000,
};
#endif
