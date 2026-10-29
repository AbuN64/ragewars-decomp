#include "DATA/OVL1_J/DATA_800E58C0.H"
#include "DATA/OVL1_J/DATA_800E58FC.H"

/* 80408CB0_14.CPP */
/* 80408CB0_14.CPP */
#if defined(VERSION_EU)
unsigned char g_FrontendUpdateslidergeometryTrailingBytes[12] = { 0x10, 0x40, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x09, 0x4E, 0x32 };
#endif

/* DATA_800E58C0.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E58A8_unclaimed_E64C0 */
unsigned int g_FrontendUpdateslidergeometryEncodedWords[3] = {
    0x00000E06, 0x00000006, (unsigned int)addrLow_Menu_CreateSoundOptionsScreen,
};

unsigned int g_frontendSliderEventHandlerWords[12] = {
    0x00000E03, 0x00000006, (unsigned int)addrLow_Menu_FreeSoundOptionsScreen, 0x00000002, 0x00000006, (unsigned int)addrLow_Menu_CancelSoundOptionsScreen, 0x00000001, 0x00000006,
    (unsigned int)addrLow_Menu_ConfirmSoundOptionsScreen, 0x00000000, 0x00000000, 0x00000000,
};
#endif

/* DATA_800E58FC.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_frontendSliderTransitionHandlerWords[21] = {
    0x00000E07, 0x0000000D, (unsigned int)D_004394E0, 0x00000E08, 0x0000000D, (unsigned int)addrLow_Menu_ApplySoundSliders, 0x00000E06, 0x0000000D,
    (unsigned int)addrLow_Menu_CreateSoundSliders, 0x00000E03, 0x0000000D, (unsigned int)addrLow_Menu_FreeSoundSliders, 0x00000002, 0x0000000D, (unsigned int)addrLow_Menu_CancelSoundSliderPopup, 0x00000001,
    0x0000000D, (unsigned int)addrLow_Menu_ConfirmSoundSliderPopup, 0x00000000, 0x00000000, 0x00000000,
};
#endif

/* 8040B45C_10.CPP */
#if defined(VERSION_EU_X)
unsigned char g_FrontendUpdateslidergeometryTrailingBytesBlock1[12] = { 0x0C, 0x0A, 0x7F, 0xE2, 0x24, 0x06, 0x00, 0x18, 0x3C, 0x02, 0x80, 0x15 };
#endif
