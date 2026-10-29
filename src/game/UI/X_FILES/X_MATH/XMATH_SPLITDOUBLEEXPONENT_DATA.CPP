#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"

#if !(defined(VERSION_US_REV1))
const unsigned int k_xmathSplitdoubleexponentDataFloatConstantWords[25] = {
    0x00000000, 0x00000000, 0x3FC90FDB, 0x3FC90FDB, 0x3F800000, 0xBB84D7E7, 0x3CB31652, 0x3D6501C4,
    0x3DC577DF, 0x3E0E6C63, 0x3E4C40A6, 0x3EAAA61C, 0x3F7FFFF5, 0x3F490FDB, 0x3F800000, 0xBF800000,
    0xBC3F5FAF, 0x3CFD10F8, 0x3D4D8392, 0x3DB63A9E, 0x3E5BBFCA, 0x3FC90FDA, 0x3FC90FDB, 0x3F800000,
    0xBF800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8029DCB0_CB958_us_rev1.c */
const unsigned int k_xmathSplitdoubleexponentDataZeroWords[2] = {
    0x00000000, 0x00000000,
};

/* ROM-grounded data: src/rw_pool_8029DD18_CB960_us_rev1.c */
const unsigned int k_XmathSplitdoubleexponentHalfPiWords[1] = {
    0x3FC90FDB,
};

/* ROM-grounded data: src/rw_pool_8029DD3C_CB964_us_rev1.c */
const unsigned int k_XmathSplitdoubleexponentHalfPiWordsVariant1[1] = {
    0x3FC90FDB,
};

const unsigned int k_xmathSplitdoubleexponentDataFloatConstantWordsBlock1[10] = {
    0x3F800000, 0xBB84D7E7, 0x3CB31652, 0x3D6501C4, 0x3DC577DF, 0x3E0E6C63, 0x3E4C40A6, 0x3EAAA61C,
    0x3F7FFFF5, 0x3F490FDB,
};

const unsigned int k_xmathSplitdoubleexponentDataFloatConstantWordsBlock2[9] = {
    0x3F800000, 0xBF800000, 0xBC3F5FAF, 0x3CFD10F8, 0x3D4D8392, 0x3DB63A9E, 0x3E5BBFCA, 0x3FC90FDA,
    0x3FC90FDB,
};

/* ROM-grounded data: src/rw_pool_8029DF48_CB9B4_us_rev1.c */
const unsigned int k_xmathSplitdoubleexponentDataFloatConstantWordsBlock3[2] = {
    0x3F800000, 0xBF800000,
};
#endif
