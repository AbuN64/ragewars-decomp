#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char g_sirawdmaText[14] =
    "io/sirawdma.c\000";
#endif

#if defined(VERSION_US)
char s_SirawdmaSMHUDEXPANDText[14] =
    "\000\015SMHUD_EXPAND";
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
unsigned short k_SirawdmaEncodedHalfwords[7] = {
    0xED70, 0x0020, 0xEB00, 0x0021, 0x0250, 0x0020, 0xF6E0,
};
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
char s_SirawdmaTextsText[14] =
    " Texts\000\000\000\000\077\200\000\000";
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
char s_SirawdmaIoSprawdmaText[14] =
    "\000\000io/sprawdma.";
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/SirawdmaTextSource.c */
const char s_sirawdmaText[14] = "io/sirawdma.c";
#endif
