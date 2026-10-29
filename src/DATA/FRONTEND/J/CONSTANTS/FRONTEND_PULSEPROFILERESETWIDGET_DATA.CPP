#include "include_asm.h"
#include "DATA/OVL1_J/FRONTEND_PULSEPROFILERESETWIDGET_DATA.H"

/* g_FrontendPulseprofileresetwidgetWords1_FrontendPulseprofileresetwidgetData.CPP */
/* ROM-grounded data: rodata/writable/800E5950 */
unsigned int g_FrontendPulseprofileresetwidgetWords1[1] = {
    0x00000000,
};

/* g_FrontendPulseprofileresetwidgetPointerWords1_FrontendPulseprofileresetwidgetData.CPP */
#if defined(VERSION_DE) || defined(VERSION_EU_X)
#if defined(VERSION_DE)
extern char g_Menu_DispatchSoundSliderEventAddress[];
extern char Frontend_HandleProfileResetConfirm_Address[];
extern char g_Frontend_DispatchProfileResetEventAddress[];
unsigned int D_src_9d8a2047[35] = {
    0xe08, 24, (unsigned int)(g_Menu_DispatchSoundSliderEventAddress + 476), 0xe06,
    24, (unsigned int)(g_Menu_DispatchSoundSliderEventAddress + 148), 0xe03, 24,
    (unsigned int)(g_Menu_DispatchSoundSliderEventAddress + 428), 1, 24, (unsigned int)(Frontend_HandleProfileResetConfirm_Address + 96),
    2, 24, (unsigned int)(Frontend_HandleProfileResetConfirm_Address + 64), 10,
    24, (unsigned int)Frontend_HandleProfileResetConfirm_Address, 0, 0,
    0, (unsigned int)(g_Frontend_DispatchProfileResetEventAddress + 1432), 2, 0xe06,
    33, (unsigned int)(g_Frontend_DispatchProfileResetEventAddress + 1496), 2, 33,
    (unsigned int)(g_Frontend_DispatchProfileResetEventAddress + 1708), 1, 33, (unsigned int)(g_Frontend_DispatchProfileResetEventAddress + 1536),
    0, 0, 0,
};
#endif
#if defined(VERSION_EU_X)
unsigned int D_src_9d8a2047[35] = {
    0x00000E08, 0x00000018, 0x0043A628, 0x00000E06, 0x00000018, 0x0043A4E0, 0x00000E03, 0x00000018,
    0x0043A5F8, 0x00000001, 0x00000018, 0x0043A750, 0x00000002, 0x00000018, 0x0043A730, 0x0000000A,
    0x00000018, 0x0043A6F0, 0x00000000, 0x00000000, 0x00000000, 0xACC200B8, 0xACC4000C, 0x00000E06,
    0x00000021, 0x0043AD30, 0x00000002, 0x00000021, 0x0043AE04, 0x00000001, 0x00000021, 0x0043AD58,
    0x00000000, 0x00000000, 0x00000000,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_FrontendPulseprofileresetwidgetPointerWords1[21] = {
    0x00000E08, 0x00000018, (unsigned int)g_Frontend_PulseProfileResetWidgetPackedAddress24_FrontendPulseprofileresetwidgetData, 0x00000E06, 0x00000018, (unsigned int)g_Frontend_CreateProfileResetScreenUsPackedAddress24, 0x00000E03, 0x00000018,
    (unsigned int)g_Frontend_FreeProfileResetScreenPackedAddress24_FrontendPulseprofileresetwidgetData, 0x00000001, 0x00000018, (unsigned int)g_ProfileReset_ReturnUnhandledEventPackedAddress24, 0x00000002, 0x00000018, (unsigned int)g_Frontend_AcknowledgeProfileResetEventPackedAddress24_FrontendPulseprofileresetwidgetData, 0x0000000A,
    0x00000018, (unsigned int)g_Frontend_HandleProfileResetConfirmPackedAddress24_FrontendPulseprofileresetwidgetData, 0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
unsigned int g_FrontendPulseprofileresetwidgetPointerWordsTailUs[14] = {
    0x1CE20028, 0x433A5C50, 0x00000E06, 0x00000021, 0x00439F10, 0x00000002, 0x00000021, 0x00439FE4,
    0x00000001, 0x00000021, 0x00439F38, 0x00000000, 0x00000000, 0x00000000,
};
#endif
