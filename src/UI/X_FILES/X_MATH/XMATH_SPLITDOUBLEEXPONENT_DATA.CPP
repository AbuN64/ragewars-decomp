#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"

#if !(defined(VERSION_US_REV1))
const float k_xmathSplitdoubleexponentDataFloatConstantWords[25] = {
    0.0f, 0.0f, 1.5707964f, 1.5707964f, 1.0f, -0.004054058f,
    0.02186123f, 0.055909887f, 0.09642004f, 0.13908534f, 0.19946536f, 0.33329856f,
    0.99999934f, 0.7853982f, 1.0f, -1.0f, -0.011680528f, 0.03089188f,
    0.050174303f, 0.08897899f, 0.2145988f, 1.5707963f, 1.5707964f, 1.0f,
    -1.0f,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_xmathSplitdoubleexponentDataZeroWords_XmathSplitdoubleexponentData.c */
const unsigned int k_xmathSplitdoubleexponentDataZeroWords[2] = {
    0x00000000, 0x00000000,
};

/* ROM-grounded data: src/k_XmathSplitdoubleexponentHalfPiWords_XmathSplitdoubleexponentData.c */
const float k_XmathSplitdoubleexponentHalfPiWords[1] = {
    1.5707964f,
};

/* ROM-grounded data: src/k_XmathSplitdoubleexponentHalfPiWordsVariant1_XmathSplitdoubleexponentData.c */
const float k_XmathSplitdoubleexponentHalfPiWordsVariant1[1] = {
    1.5707964f,
};

const unsigned int k_xmathSplitdoubleexponentDataFloatConstantWordsBlock1[10] = {
    0x3F800000, 0xBB84D7E7, 0x3CB31652, 0x3D6501C4, 0x3DC577DF, 0x3E0E6C63, 0x3E4C40A6, 0x3EAAA61C,
    0x3F7FFFF5, 0x3F490FDB,
};

const unsigned int k_xmathSplitdoubleexponentDataFloatConstantWordsBlock2[9] = {
    0x3F800000, 0xBF800000, 0xBC3F5FAF, 0x3CFD10F8, 0x3D4D8392, 0x3DB63A9E, 0x3E5BBFCA, 0x3FC90FDA,
    0x3FC90FDB,
};

/* ROM-grounded data: src/k_xmathSplitdoubleexponentDataFloatConstantWordsBlock3_XmathSplitdoubleexponentData.c */
const float k_xmathSplitdoubleexponentDataFloatConstantWordsBlock3[2] = {
    1.0f, -1.0f,
};
#endif
