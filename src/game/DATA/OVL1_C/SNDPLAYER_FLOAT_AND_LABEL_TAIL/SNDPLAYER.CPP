#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const unsigned char g_SndplayerBytes1[7] = {
    0x38, 0xD1, 0xB7, 0x17, 0x45, 0x58, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/g_SndplayerWords1_Sndplayer.c */
const unsigned int g_SndplayerWords1[1] = {
    0x38D1B717,
};

/* ROM-grounded data: src/g_SndplayerBytes2_Sndplayer.c */
const unsigned char g_SndplayerBytes2[3] = {
    0x45, 0x58, 0x00,
};
#endif
