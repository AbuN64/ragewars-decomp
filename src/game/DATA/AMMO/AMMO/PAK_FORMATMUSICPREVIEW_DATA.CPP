#include "include_asm.h"

#if defined(VERSION_DE)
const unsigned int g_musicPreviewTwoColumnFormatWords[1] = {
    0x25326400,
};
#endif

#if defined(VERSION_DE)
unsigned int k_PakFormatmusicpreviewEncodedWords[3] = {
    0x40C00000, 0x3B66C2B4, 0x42800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/g_musicPreviewTwoColumnFormat_PakFormatmusicpreviewData.c */
const unsigned char g_musicPreviewTwoColumnFormat[4] = {
    0x25, 0x32, 0x64, 0x00,
};
#endif
