#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char g_threadLabelWordsGerman[];
unsigned int k_CurveDecodethreebitsamplesEncodedWords[20] = {
    0x00000000, 0x0000F000, 0x0001E800, 0x0001CC00, 0x00000000, 0x00000000, 0xFFFF1000, 0xFFFF3000,
    (unsigned int)g_threadLabelWordsGerman + 0x5C, (unsigned int)g_threadLabelWordsGerman + 0x54, (unsigned int)g_threadLabelWordsGerman + 0x4C, (unsigned int)g_threadLabelWordsGerman + 0x3C, (unsigned int)g_threadLabelWordsGerman + 0x34, (unsigned int)g_threadLabelWordsGerman + 0x2C, (unsigned int)g_threadLabelWordsGerman + 0x20, (unsigned int)g_threadLabelWordsGerman + 0x14,
    (unsigned int)g_threadLabelWordsGerman + 0xC, 0x00000000, 0xFFFFFFFF, 0x00002821,
};
#endif
#if defined(VERSION_EU)
extern char g_threadLabelWordsEuropean[];
unsigned int k_CurveDecodethreebitsamplesEncodedWords[20] = {
    0x00000000, 0x0000F000, 0x0001E800, 0x0001CC00, 0x00000000, 0x00000000, 0xFFFF1000, 0xFFFF3000,
    (unsigned int)g_threadLabelWordsEuropean + 0x5C, (unsigned int)g_threadLabelWordsEuropean + 0x54, (unsigned int)g_threadLabelWordsEuropean + 0x4C, (unsigned int)g_threadLabelWordsEuropean + 0x3C, (unsigned int)g_threadLabelWordsEuropean + 0x34, (unsigned int)g_threadLabelWordsEuropean + 0x2C, (unsigned int)g_threadLabelWordsEuropean + 0x20, (unsigned int)g_threadLabelWordsEuropean + 0x14,
    (unsigned int)g_threadLabelWordsEuropean + 0xC, 0x00000000, 0xFFFFFFFF, 0x46414D49,
};
#endif
#if defined(VERSION_EU_X)
extern char g_threadLabelWordsEuropeanX[];
unsigned int k_CurveDecodethreebitsamplesEncodedWords[20] = {
    0x00000000, 0x0000F000, 0x0001E800, 0x0001CC00, 0x00000000, 0x00000000, 0xFFFF1000, 0xFFFF3000,
    (unsigned int)g_threadLabelWordsEuropeanX + 0x5C, (unsigned int)g_threadLabelWordsEuropeanX + 0x54, (unsigned int)g_threadLabelWordsEuropeanX + 0x4C, (unsigned int)g_threadLabelWordsEuropeanX + 0x3C, (unsigned int)g_threadLabelWordsEuropeanX + 0x34, (unsigned int)g_threadLabelWordsEuropeanX + 0x2C, (unsigned int)g_threadLabelWordsEuropeanX + 0x20, (unsigned int)g_threadLabelWordsEuropeanX + 0x14,
    (unsigned int)g_threadLabelWordsEuropeanX + 0xC, 0x00000000, 0xFFFFFFFF, 0x3F801BC1,
};
#endif
#if defined(VERSION_US)
extern char g_threadLabelWordsUs[];
unsigned int k_CurveDecodethreebitsamplesEncodedWords[20] = {
    0x00000000, 0x0000F000, 0x0001E800, 0x0001CC00, 0x00000000, 0x00000000, 0xFFFF1000, 0xFFFF3000,
    (unsigned int)g_threadLabelWordsUs + 0x5C, (unsigned int)g_threadLabelWordsUs + 0x54, (unsigned int)g_threadLabelWordsUs + 0x4C, (unsigned int)g_threadLabelWordsUs + 0x3C, (unsigned int)g_threadLabelWordsUs + 0x34, (unsigned int)g_threadLabelWordsUs + 0x2C, (unsigned int)g_threadLabelWordsUs + 0x20, (unsigned int)g_threadLabelWordsUs + 0x14,
    (unsigned int)g_threadLabelWordsUs + 0xC, 0x00000000, 0xFFFFFFFF, 0x494E495F,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
unsigned int g_CurveDecodethreebitsamplesEncodedWords[19] = {
    0x00000000, 0x0000F000, 0x0001E800, 0x0001CC00, 0x00000000, 0x00000000, 0xFFFF1000, 0xFFFF3000,
    0x800C9470, 0x800C9468, 0x800C9460, 0x800C9450, 0x800C9448, 0x800C9440, 0x800C9434, 0x800C9428,
    0x800C9420, 0x00000000, 0xFFFFFFFF,
};
#endif
