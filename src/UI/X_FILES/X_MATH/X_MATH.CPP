#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"

#if !(defined(VERSION_US_REV1))
const unsigned int k_xMathFloatConstantWords[5] = {
    0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int k_XMathOneWords[1] = {
    0x3F800000,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int k_xMathFloatConstantWordsBlock1[10] = {
    0x3F800000, 0xBF800000, 0xBC3F5FAF, 0x3CFD10F8, 0x3D4D8392, 0x3DB63A9E, 0x3E5BBFCA, 0x3FC90FDA,
    0x3FC90FDB, 0x38D1B717,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int k_xMathFloatConstantWordsBlock2[9] = {
    0x3F800000, 0xBF800000, 0xBC3F5FAF, 0x3CFD10F8, 0x3D4D8392, 0x3DB63A9E, 0x3E5BBFCA, 0x3FC90FDA,
    0x3FC90FDB,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int k_xMathFloatConstantWordsBlock3[2] = {
    0x3F800000, 0x3F800000,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int k_xMathFloatConstantWordsBlock4[2] = {
    0x38D1B717, 0x3F800000,
};
#endif


#if defined(VERSION_US_REV1)
const unsigned int k_xMathFloatConstantWordsBlock6[5] = {
    0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000,
};

/* ROM-grounded data: src/k_XMathOneWordsVariant1_XMath.c */
const unsigned int k_XMathOneWordsVariant1[1] = {
    0x3F800000,
};

const unsigned int k_xMathFloatConstantWordsBlock7[10] = {
    0x3F800000, 0xBF800000, 0xBC3F5FAF, 0x3CFD10F8, 0x3D4D8392, 0x3DB63A9E, 0x3E5BBFCA, 0x3FC90FDA,
    0x3FC90FDB, 0x38D1B717,
};

const unsigned int k_xMathFloatConstantWordsBlock8[9] = {
    0x3F800000, 0xBF800000, 0xBC3F5FAF, 0x3CFD10F8, 0x3D4D8392, 0x3DB63A9E, 0x3E5BBFCA, 0x3FC90FDA,
    0x3FC90FDB,
};

/* ROM-grounded data: src/k_xMathFloatConstantWordsBlock9_XMath.c */
const unsigned int k_xMathFloatConstantWordsBlock9[2] = {
    0x3F800000, 0x3F800000,
};

/* ROM-grounded data: src/k_xMathFloatConstantWordsBlock10_XMath.c */
const unsigned int k_xMathFloatConstantWordsBlock10[2] = {
    0x38D1B717, 0x3F800000,
};


#endif
