#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
const unsigned int g_OvlgameInitializerenderdirectionWords1[1] = {
    0xBF2ADC4D,
};
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned int g_OvlgameInitializerenderdirectionWords1[3] = {
    0xBF2ADC4D, 0x3F741616, 0xBF1273B4,
};
#endif
#endif

#if defined(VERSION_EU_X)
unsigned int k_OvlgameInitializerenderdirectionEncodedWordsBlock2[1] = {
    0x4E2C2053,
};
#endif

#if defined(VERSION_EU)
unsigned int k_OvlgameInitializerenderdirectionEncodedWordsBlock1[1] = {
    0x080B02A1,
};
#endif

#if defined(VERSION_DE)
const unsigned int g_OvlgameInitializerenderdirectionWords3[2] = {
    0x3F741616, 0xBF1273B4,
};
#endif

#if defined(VERSION_DE)
unsigned int k_OvlgameInitializerenderdirectionEncodedWords[1] = {
    0x3F333333,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int g_OvlgameInitializerenderdirectionWords2[3] = {
    0xBF2ADC4D, 0x3F741616, 0xBF1273B4,
};
#endif
