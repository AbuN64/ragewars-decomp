#include "DATA/OVL1_J/g_FrontendUpdateslidergeometryEncodedWords_FrontendUpdateslidergeometry.H"
#include "DATA/OVL1_J/g_frontendSliderTransitionHandlerWords_FrontendUpdateslidergeometry.H"
#include "DATA/UI/EVENT_HANDLER_RECORD.H"

/* 80408CB0_14.CPP */
/* 80408CB0_14.CPP */
#if defined(VERSION_EU)
unsigned char g_FrontendUpdateslidergeometryTrailingBytes[12] = { 0x10, 0x40, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x09, 0x4E, 0x32 };
#endif

/* g_FrontendUpdateslidergeometryEncodedWords_FrontendUpdateslidergeometry.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E58A8_unclaimed_E64C0 */
EventHandlerRecord g_FrontendUpdateslidergeometryEncodedWords[1] = {
    { 3590, 6, addrLow_Menu_CreateSoundOptionsScreen },
};

EventHandlerRecord g_frontendSliderEventHandlerWords[4] = {
    { 3587, 6, addrLow_Menu_FreeSoundOptionsScreen },
    { 2, 6, addrLow_Menu_CancelSoundOptionsScreen },
    { 1, 6, addrLow_Menu_ConfirmSoundOptionsScreen },
    { 0, 0, 0 },
};
#endif

/* g_frontendSliderTransitionHandlerWords_FrontendUpdateslidergeometry.CPP */
#if defined(VERSION_US_REV1)
EventHandlerRecord g_frontendSliderTransitionHandlerWords[7] = {
    { 3591, 13, addrLow_Menu_SoundSliderReturnZero },
    { 3592, 13, addrLow_Menu_ApplySoundSliders },
    { 3590, 13, addrLow_Menu_CreateSoundSliders },
    { 3587, 13, addrLow_Menu_FreeSoundSliders },
    { 2, 13, addrLow_Menu_CancelSoundSliderPopup },
    { 1, 13, addrLow_Menu_ConfirmSoundSliderPopup },
    { 0, 0, 0 },
};
#endif

/* 8040B45C_10.CPP */
#if defined(VERSION_EU_X)
unsigned char g_FrontendUpdateslidergeometryTrailingBytesBlock1[12] = { 0x0C, 0x0A, 0x7F, 0xE2, 0x24, 0x06, 0x00, 0x18, 0x3C, 0x02, 0x80, 0x15 };
#endif
