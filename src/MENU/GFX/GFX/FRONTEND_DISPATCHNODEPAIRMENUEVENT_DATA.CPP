#include "DATA/OVL1_J/FRONTEND_DISPATCHNODEPAIRMENUEVENT_DATA.H"
#include "DATA/UI/EVENT_HANDLER_RECORD.H"

/* 80408CB0_15.CPP */
#if defined(VERSION_EU)
unsigned char g_FrontendDispatchnodepairmenueventTrailingBytes[8] = { 0x00, 0x80, 0x88, 0x21, 0xAF, 0xB0, 0x00, 0x70 };
#endif

/* frontendDispatchnodepairmenueventEncodedWordsData.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E5954_unclaimed_E65A8 */
unsigned int g_FrontendDispatchnodepairmenueventEncodedWords[2] = {
    0x000B0000, 0x00000011,
};

EventHandlerRecord g_menuEventHandlers4_us_rev1[4] = {
    { 3590, 33, (void *)0x00439F10 },
    { 2, 33, g_frontend_CancelNodePairMenuEntry },
    { 1, 33, g_frontend_UpdateTimedTransitionEntry },
    { 0, 0, 0 },
};
#endif
