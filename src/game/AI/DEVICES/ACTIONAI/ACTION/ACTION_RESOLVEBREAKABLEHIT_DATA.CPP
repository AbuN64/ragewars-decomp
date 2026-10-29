#include "include_asm.h"

/* ROM-grounded data: src/k_actionResolvebreakablehitDataFloatConstantWords_us_rev1.c */
const unsigned int k_actionResolvebreakablehitDataFloatConstantWords[1] = {
    0x3C010204,
};

#if defined(VERSION_EU_X)
unsigned int k_ActionResolvebreakablehitEncodedWordsBlock2[2] = {
    0x40490FDC, 0xBFC90FDC,
};
#endif

#if defined(VERSION_EU)
unsigned int k_ActionResolvebreakablehitEncodedWordsBlock1[2] = {
    0x3C021000, 0x8E030010,
};
#endif

#if defined(VERSION_DE)
unsigned int k_ActionResolvebreakablehitEncodedWords[2] = {
    0x0C0AC6AC, 0x02803021,
};
#endif
