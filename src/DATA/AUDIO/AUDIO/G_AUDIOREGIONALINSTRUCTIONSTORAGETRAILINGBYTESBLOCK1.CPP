#include "include_asm.h"

/* 802BFD80_18.CPP */
#if defined(VERSION_EU)
unsigned char g_AudioRegionalInstructionStorageTrailingBytesBlock1[4] = { 0x02, 0xA0, 0x20, 0x21 };
#endif

/* AudioRegionalInstructionStoragePaddingWords.CPP */
#if defined(VERSION_US)
unsigned int func_802B6DEC_de_padding_BCABC[1] = {
    0x73520000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_802B6DEC_de_padding_BCABC */
unsigned int g_AudioAudioAudio34CppRetainedWords1[1] = {
    0x54430001,
};
#endif
