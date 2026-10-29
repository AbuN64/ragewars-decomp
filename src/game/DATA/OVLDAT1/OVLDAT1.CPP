#include "include_asm.h"

/* 800C1CF4.CPP */
#if defined(VERSION_EU)
unsigned int k_Ovldat1EncodedWords[6] = {
    0x00000000, 0x0020421C, 0x00204224, 0x0020422C, 0x00204234, 0x0020423C,
};
#endif

/* 800C1E68.CPP */
#if defined(VERSION_US)
char s_OvldatELoaderRText[8] =
    "eLoaderR";
#endif

#if defined(NON_MATCHING) && defined(VERSION_US)
unsigned int k_Ovldat1EncodedWordsBlock1[6] = {
    0x654C6F61, 0x64657252, 0x42C80000, 0x00000800, 0x11000000, 0x0000086D,
};
#endif

/* 800C209C.CPP */
#if defined(VERSION_EU_X)
/* ROM-grounded data for eu-x; supplied-list member has no us-rev1 placement. */
unsigned int g_Ovldat1EncodedWords[1] = {
    0x40F00000,
};
#endif
