#include "include_asm.h"
#include "DATA/OVL1_J/MENU_DISPATCHSETTINGSTABLEEVENT_DATA.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
extern char g_Menu_UpdateScrollingChoiceScreenPackedAddress242[];
extern char g_Player_DispatchAlternatePlayerSettingsEventAddress[];
extern char g_Menu_WrapScrollingChoiceNodesPackedAddress242[];
extern char g_Menu_FreeScrollingChoiceScreenPackedAddress242[];
extern char g_Menu_HandleScrollingChoicePackedAddress242[];
extern char g_Menu_CancelScrollingChoiceScreenPackedAddress242[];
extern char g_Menu_UpdateTitleButtonScreenPackedAddress242[];
extern char g_Menu_CreateTitleButtonScreenPackedAddress242[];
extern char g_Menu_WrapTitleButtonScreenNodesPackedAddress24[];
extern char g_Menu_FreeTitleButtonScreenPackedAddress242[];
extern char g_Menu_HandleTitleButtonChoicePackedAddress242[];
extern char g_Menu_CancelTitleButtonScreenPackedAddress242[];
unsigned int D_src_846838ea[42] = {
    0xe08, 9, (unsigned int)g_Menu_UpdateScrollingChoiceScreenPackedAddress242, 0xe06,
    9, (unsigned int)(g_Player_DispatchAlternatePlayerSettingsEventAddress + 148), 0xe07, 9,
    (unsigned int)g_Menu_WrapScrollingChoiceNodesPackedAddress242, 0xe03, 9, (unsigned int)g_Menu_FreeScrollingChoiceScreenPackedAddress242,
    1, 9, (unsigned int)g_Menu_HandleScrollingChoicePackedAddress242, 2,
    9, (unsigned int)g_Menu_CancelScrollingChoiceScreenPackedAddress242, 0, 0,
    0, 0xe08, 30, (unsigned int)g_Menu_UpdateTitleButtonScreenPackedAddress242,
    0xe06, 30, (unsigned int)g_Menu_CreateTitleButtonScreenPackedAddress242, 0xe07,
    30, (unsigned int)g_Menu_WrapTitleButtonScreenNodesPackedAddress24, 0xe03, 30,
    (unsigned int)g_Menu_FreeTitleButtonScreenPackedAddress242, 1, 30, (unsigned int)g_Menu_HandleTitleButtonChoicePackedAddress242,
    2, 30, (unsigned int)g_Menu_CancelTitleButtonScreenPackedAddress242, 0,
    0, 0,
};
#endif
#if defined(VERSION_EU_X)
extern char g_Player_DispatchAlternatePlayerSettingsEventAddress[];
extern char g_Menu_DispatchScrollingChoiceEventAddress[];
unsigned int D_src_846838ea[42] = {
    0xe08, 9, (unsigned int)(g_Player_DispatchAlternatePlayerSettingsEventAddress + 456), 0xe06,
    9, (unsigned int)(g_Player_DispatchAlternatePlayerSettingsEventAddress + 148), 0xe07, 9,
    (unsigned int)(g_Player_DispatchAlternatePlayerSettingsEventAddress + 408), 0xe03, 9, (unsigned int)(g_Player_DispatchAlternatePlayerSettingsEventAddress + 360),
    1, 9, (unsigned int)(g_Player_DispatchAlternatePlayerSettingsEventAddress + 820), 2,
    9, (unsigned int)(g_Player_DispatchAlternatePlayerSettingsEventAddress + 760), 0, 0,
    0, 0xe08, 30, (unsigned int)(g_Menu_DispatchScrollingChoiceEventAddress + 392),
    0xe06, 30, (unsigned int)(g_Menu_DispatchScrollingChoiceEventAddress + 144), 0xe07,
    30, (unsigned int)(g_Menu_DispatchScrollingChoiceEventAddress + 352), 0xe03, 30,
    (unsigned int)(g_Menu_DispatchScrollingChoiceEventAddress + 304), 1, 30, (unsigned int)(g_Menu_DispatchScrollingChoiceEventAddress + 680),
    2, 30, (unsigned int)(g_Menu_DispatchScrollingChoiceEventAddress + 620), 0,
    0, 0,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_MenuDispatchsettingstableeventPointerWords1[21] = {
    0x00000E08, 0x00000009, (unsigned int)g_Menu_SettingsTableEvent0E08HandlerPackedAddress24, 0x00000E06, 0x00000009, (unsigned int)g_Menu_SettingsTableEvent0E06HandlerPackedAddress24, 0x00000E07, 0x00000009,
    (unsigned int)g_Menu_SettingsTableEvent0E07HandlerPackedAddress24, 0x00000E03, 0x00000009, (unsigned int)g_Menu_SettingsTableEvent0E03HandlerPackedAddress24, 0x00000001, 0x00000009, (unsigned int)g_Menu_SettingsTableEvent01HandlerPackedAddress24, 0x00000002,
    0x00000009, (unsigned int)g_Menu_SettingsTableEvent02HandlerPackedAddress24, 0x00000000, 0x00000000, 0x00000000,
};
#endif
