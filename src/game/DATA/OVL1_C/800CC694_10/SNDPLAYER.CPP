#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const char s_audioSndplayerText[18] =
    "audio/sndplayer.c\000";
#endif

#if defined(VERSION_US_REV1)
const char g_audioSndplayerSourceText[18] = "audio/sndplayer.c";
#endif
