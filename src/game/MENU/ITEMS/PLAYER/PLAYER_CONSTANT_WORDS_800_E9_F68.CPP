#include "include_asm.h"

#if defined(VERSION_EU_X)
const unsigned int k_playerConstantWords[7] = {
    0x00444718, 0x00444738, 0x00444758, 0x00444778, 0x00444798, 0x004447B8, 0x004447D8,
};
#endif

#if defined(VERSION_EU_X)
const unsigned int k_PlayerConstantWordsEFHalfWords[1] = {
    0x3F000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_PlayerConstantWordsE9F68EncodedWords[2] = {
    0x0000005F, 0x0000002A,
};
#endif
