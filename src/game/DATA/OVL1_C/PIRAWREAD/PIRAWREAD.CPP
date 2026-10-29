#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char g_pirawreadText[15] =
    "io/pirawread.c\000";
#endif

#if defined(VERSION_US)
unsigned char k_PirawreadEncodedBytes[13] = {
    0x0F, 0x00, 0x0A, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x2E, 0x31, 0x37, 0x35,
};
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
unsigned char k_PirawreadEncodedBytesBlock1[13] = {
    0x00, 0x4F, 0x00, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
char s_PirawreadIoSirawdmaText[13] =
    "\000io/sirawdma.";
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/s_pirawreadText_Pirawread.c */
const unsigned char s_pirawreadText[15] = {
    0x69, 0x6F, 0x2F, 0x70, 0x69, 0x72, 0x61, 0x77, 0x72, 0x65, 0x61, 0x64, 0x2E, 0x63, 0x00,
};
#endif
