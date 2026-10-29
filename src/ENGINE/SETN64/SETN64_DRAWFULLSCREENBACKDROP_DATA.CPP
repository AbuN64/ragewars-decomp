#include "include_asm.h"

/* 800C5670.CPP */
#if defined(VERSION_EU)
const unsigned int g_Setn64DrawfullscreenbackdropWords1[4] = {
    0x437F0000, 0x3E32B8C4, 0x3ECCCCCD, 0x3F333333,
};
#endif

/* 800CA4B0.CPP */
#if defined(VERSION_DE) || defined(VERSION_US_REV1)
const unsigned int g_Setn64DrawfullscreenbackdropWords4[4] = {
    0x437F0000, 0x3E32B8C4, 0x3ECCCCCD, 0x3F333333,
};
#endif

/* 80290990.CPP */
#if defined(VERSION_US)
/** Perform no operation. */
void SetN64_EmptyBackdropHookUs(void) {
}
#endif

/* 802909E0_15.CPP */
#if defined(VERSION_EU_X)
const unsigned int g_Setn64DrawfullscreenbackdropWords2[4] = {
    0x437F0000, 0x3E32B8C4, 0x3ECCCCCD, 0x3F333333,
};
#endif

/* SETN64_DRAWFULLSCREENBACKDROP_WORDS_US.CPP */
#if defined(VERSION_US)
const unsigned int g_Setn64DrawfullscreenbackdropWords5[4] = {
    0x437F0000, 0x3E32B8C4, 0x3ECCCCCD, 0x3F333333,
};
char g_Setn64LoadingbackdropLeadText[8] = {'r', 'c', 'e', '\\', 'U', 'I', '\\', 'T'};
#endif
