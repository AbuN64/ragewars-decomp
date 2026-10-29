#include "include_asm.h"
#include "DATA/OVL1_J/MENU_CREATESOUNDOPTIONSSCREEN_DATA.H"

/* g_MenuCreatesoundoptionsscreenWords1_MenuCreatesoundoptionsscreenData.CPP */
/* ROM-grounded data: rodata/writable/800E58A0 */
unsigned int g_MenuCreatesoundoptionsscreenWords1[2] = {
    0x00000000, 0x00000000,
};

/* g_MenuCreatesoundoptionsscreenPointerWords1_MenuCreatesoundoptionsscreenData.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char g_Achieve_DispatchResultsActorEventAddress[];
extern char g_Menu_DispatchSoundOptionsEventAddress[];
unsigned int D_src_3cb405cb[42] = {
    0xe07, 6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 404), 0xe08,
    6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 412), 0xe06, 6,
    (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 148), 0xe03, 6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 356),
    2, 6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 760), 1,
    6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 684), 0, 0,
    0, 0xe07, 13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 336),
    0xe08, 13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 344), 0xe06,
    13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 144), 0xe03, 13,
    (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 288), 2, 13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 596),
    1, 13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 504), 0,
    0, 0,
};
#endif
#if defined(VERSION_EU)
extern char g_Menu_SoundOptionsReturnZeroPackedAddress24[];
extern char g_Menu_UpdateSoundOptionsScreenPackedAddress24[];
extern char g_Menu_CreateSoundOptionsScreenPackedAddress24[];
extern char g_Menu_FreeSoundOptionsScreenPackedAddress24[];
extern char g_Menu_CancelSoundOptionsScreenPackedAddress24[];
extern char g_Menu_ConfirmSoundOptionsScreenPackedAddress24[];
extern char g_Menu_SoundSliderReturnZeroPackedAddress24[];
extern char g_Menu_ApplySoundSlidersPackedAddress24[];
extern char g_Menu_CreateSoundSlidersPackedAddress24[];
extern char g_Menu_FreeSoundSlidersPackedAddress24[];
extern char g_Menu_CancelSoundSliderPopupPackedAddress24[];
extern char g_Menu_ConfirmSoundSliderPopupPackedAddress24[];
unsigned int D_src_3cb405cb[42] = {
    0xe07, 6, (unsigned int)g_Menu_SoundOptionsReturnZeroPackedAddress24, 0xe08,
    6, (unsigned int)g_Menu_UpdateSoundOptionsScreenPackedAddress24, 0xe06, 6,
    (unsigned int)g_Menu_CreateSoundOptionsScreenPackedAddress24, 0xe03, 6, (unsigned int)g_Menu_FreeSoundOptionsScreenPackedAddress24,
    2, 6, (unsigned int)g_Menu_CancelSoundOptionsScreenPackedAddress24, 1,
    6, (unsigned int)g_Menu_ConfirmSoundOptionsScreenPackedAddress24, 0, 0,
    0, 0xe07, 13, (unsigned int)g_Menu_SoundSliderReturnZeroPackedAddress24,
    0xe08, 13, (unsigned int)g_Menu_ApplySoundSlidersPackedAddress24, 0xe06,
    13, (unsigned int)g_Menu_CreateSoundSlidersPackedAddress24, 0xe03, 13,
    (unsigned int)g_Menu_FreeSoundSlidersPackedAddress24, 2, 13, (unsigned int)g_Menu_CancelSoundSliderPopupPackedAddress24,
    1, 13, (unsigned int)g_Menu_ConfirmSoundSliderPopupPackedAddress24, 0,
    0, 0,
};
#endif
#if defined(VERSION_EU_X)
extern char g_Achieve_DispatchResultsActorEventAddress[];
extern char g_Menu_DispatchSoundOptionsEventAddress[];
unsigned int D_src_3cb405cb[42] = {
    0xe07, 6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 400), 0xe08,
    6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 408), 0xe06, 6,
    (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 144), 0xe03, 6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 352),
    2, 6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 756), 1,
    6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 680), 0, 0,
    0, 0xe07, 13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 336),
    0xe08, 13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 344), 0xe06,
    13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 144), 0xe03, 13,
    (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 288), 2, 13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 596),
    1, 13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 504), 0,
    0, 0,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
unsigned int g_MenuCreatesoundoptionsscreenPointerWords1[6] = {
    0x00000E07, 0x00000006, (unsigned int)g_Menu_SoundOptionsReturnZeroPackedAddress24_MenuCreatesoundoptionsscreenData, 0x00000E08, 0x00000006, (unsigned int)g_Menu_UpdateSoundOptionsScreenPackedAddress24_MenuCreatesoundoptionsscreenData,
};
#endif

#if defined(VERSION_US)
extern char g_Achieve_DispatchResultsActorEventAddress[];
extern char g_Menu_UpdateSoundOptionsScreenPackedAddress24_MenuCreatesoundoptionsscreenData[];
extern char g_Menu_DispatchSoundOptionsEventAddress[];
unsigned int g_MenuCreatesoundoptionsscreenPointerWordsTailUs[36] = {
    0xe06, 6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 148), 0xe03,
    6, (unsigned int)(g_Achieve_DispatchResultsActorEventAddress + 356), 2, 6,
    (unsigned int)(g_Menu_UpdateSoundOptionsScreenPackedAddress24_MenuCreatesoundoptionsscreenData + 348), 1, 6, (unsigned int)(g_Menu_UpdateSoundOptionsScreenPackedAddress24_MenuCreatesoundoptionsscreenData + 272),
    0, 0, 0, 0xe07,
    13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 336), 0xe08, 13,
    (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 344), 0xe06, 13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 144),
    0xe03, 13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 288), 2,
    13, (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 596), 1, 13,
    (unsigned int)(g_Menu_DispatchSoundOptionsEventAddress + 504), 0, 0, 0,
};
#endif
