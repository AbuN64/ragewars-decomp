#include "MENU/MENU_BOX.H"

/* 80408CB0_18.CPP */
#if defined(VERSION_EU)
unsigned char g_GMenuboxcornersTrailingBytes[12] = { 0x86, 0x02, 0x00, 0x0E, 0x18, 0x40, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00 };
#endif

/* DATA_800E5F70.CPP */
#if defined(VERSION_US_REV1)
MenuBoxCorner g_menuBoxCorners[8] = {
    { -1, -1, 0, 0, 0, 0 },
    { 1, -1, 0, 0, 0, 0 },
    { 1, 1, 0, 0, 0, 0 },
    { -1, 1, 0, 0, 0, 0 },
    { -1, -1, -2, 0, 0, 0 },
    { 1, -1, -2, 0, 0, 0 },
    { 1, 1, -2, 0, 0, 0 },
    { -1, 1, -2, 0, 0, 0 },
};
unsigned int k_GMenuboxcornersEncodedWords[3] = {
    0x00000000, 0x00000000, 0xC4098000,
};
#endif

/* DATA_800E603C.CPP */
#if defined(VERSION_US_REV1)
char g_residentStrings3_us_rev1[28] = "_SMEartsend mode  :    on";
#endif

/* DATA_800E6058.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E5E74_unclaimed_E6C58 */
unsigned int g_residentStrings4_us_rev1[1] = {
    0x800E6040,
};

char s_artsendModeOffText[24] = "artsend mode  :   off";
#endif
