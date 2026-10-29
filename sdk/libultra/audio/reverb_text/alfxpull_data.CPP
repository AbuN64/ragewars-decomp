#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const char s_audioReverbSourcePath[15] =
    "audio/reverb.c\000";
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/g_audioReverbText_AlfxpullData.c */
const unsigned char g_audioReverbText[15] = {
    0x61, 0x75, 0x64, 0x69, 0x6F, 0x2F, 0x72, 0x65, 0x76, 0x65, 0x72, 0x62, 0x2E, 0x63, 0x00,
};
#endif
