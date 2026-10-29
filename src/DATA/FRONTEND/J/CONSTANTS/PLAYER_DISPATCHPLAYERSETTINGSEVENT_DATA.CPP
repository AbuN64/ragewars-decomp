#include "include_asm.h"
#include "DATA/OVL1_J/PLAYER_DISPATCHPLAYERSETTINGSEVENT_DATA.H"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char g_Frontend_DispatchResidentActorEventAddress[];
extern char Player_FreeAlternatePlayerSettingsScreen_Address[];
extern char g_Player_DispatchPlayerSettingsEventAddress[];
unsigned int D_src_638b7747[58] = {
    0xe07, 5, (unsigned int)(g_Frontend_DispatchResidentActorEventAddress + 1812), 0xe08,
    5, (unsigned int)(g_Frontend_DispatchResidentActorEventAddress + 1820), 0xe06, 5,
    (unsigned int)(g_Frontend_DispatchResidentActorEventAddress + 156), 0xe03, 5, (unsigned int)(g_Frontend_DispatchResidentActorEventAddress + 1764),
    10, 5, (unsigned int)(g_Frontend_DispatchResidentActorEventAddress + 1944), 2,
    5, (unsigned int)(g_Frontend_DispatchResidentActorEventAddress + 2052), 1, 5,
    (unsigned int)(g_Frontend_DispatchResidentActorEventAddress + 1952), 8, 92, (unsigned int)(g_Frontend_DispatchResidentActorEventAddress + 2112),
    7, 92, (unsigned int)(g_Frontend_DispatchResidentActorEventAddress + 2296), 0,
    0, 0, 0xe07, 12,
    (unsigned int)(Player_FreeAlternatePlayerSettingsScreen_Address + 48), 0xe08, 12, (unsigned int)(Player_FreeAlternatePlayerSettingsScreen_Address + 56),
    0xe06, 12, (unsigned int)(g_Player_DispatchPlayerSettingsEventAddress + 144), 0xe03,
    12, (unsigned int)Player_FreeAlternatePlayerSettingsScreen_Address, 2, 12,
    (unsigned int)(Player_FreeAlternatePlayerSettingsScreen_Address + 176), 1, 12, (unsigned int)(Player_FreeAlternatePlayerSettingsScreen_Address + 64),
    8, 450, (unsigned int)(Player_FreeAlternatePlayerSettingsScreen_Address + 248), 7,
    450, (unsigned int)(Player_FreeAlternatePlayerSettingsScreen_Address + 424), 0, 0,
    0, 9,
};
#endif
#if defined(VERSION_EU)
extern char g_Player_PlayerSettingsEvent0E07HandlerPackedAddress24[];
extern char g_Player_UpdatePlayerSettingsExitPackedAddress24[];
extern char g_Player_InitPlayerSettingsScreenPackedAddress24[];
extern char g_Player_FreePlayerSettingsScreenPackedAddress24[];
extern char g_Player_PlayerSettingsEvent0AHandlerPackedAddress24[];
extern char g_Player_CancelPlayerSettingsEntryPackedAddress24[];
extern char g_Player_ConfirmPlayerSettingsEntryPackedAddress24[];
extern char g_Player_SelectNextPlayerSettingsEntryPackedAddress24[];
extern char g_Player_SelectPreviousPlayerSettingsEntryPackedAddress24[];
extern char g_Player_AlternatePlayerSettingsEvent0E07HandlerPackedAddress24[];
extern char g_Player_AlternatePlayerSettingsEvent0E08HandlerPackedAddress24[];
extern char g_Player_OpenAlternatePlayerSettingsScreenPackedAddress24[];
extern char g_Player_FreeAlternatePlayerSettingsScreenPackedAddress24[];
extern char g_Player_CancelAlternatePlayerSettingsEntryPackedAddress24[];
extern char g_Player_ConfirmAlternatePlayerSettingsEntryPackedAddress24[];
extern char g_Player_SelectNextAlternatePlayerSettingsEntryPackedAddress24[];
extern char g_Player_SelectPreviousAlternatePlayerSettingsEntryPackedAddress24[];
unsigned int D_src_638b7747[58] = {
    0xe07, 5, (unsigned int)g_Player_PlayerSettingsEvent0E07HandlerPackedAddress24, 0xe08,
    5, (unsigned int)g_Player_UpdatePlayerSettingsExitPackedAddress24, 0xe06, 5,
    (unsigned int)g_Player_InitPlayerSettingsScreenPackedAddress24, 0xe03, 5, (unsigned int)g_Player_FreePlayerSettingsScreenPackedAddress24,
    10, 5, (unsigned int)g_Player_PlayerSettingsEvent0AHandlerPackedAddress24, 2,
    5, (unsigned int)g_Player_CancelPlayerSettingsEntryPackedAddress24, 1, 5,
    (unsigned int)g_Player_ConfirmPlayerSettingsEntryPackedAddress24, 8, 94, (unsigned int)g_Player_SelectNextPlayerSettingsEntryPackedAddress24,
    7, 94, (unsigned int)g_Player_SelectPreviousPlayerSettingsEntryPackedAddress24, 0,
    0, 0, 0xe07, 12,
    (unsigned int)g_Player_AlternatePlayerSettingsEvent0E07HandlerPackedAddress24, 0xe08, 12, (unsigned int)g_Player_AlternatePlayerSettingsEvent0E08HandlerPackedAddress24,
    0xe06, 12, (unsigned int)g_Player_OpenAlternatePlayerSettingsScreenPackedAddress24, 0xe03,
    12, (unsigned int)g_Player_FreeAlternatePlayerSettingsScreenPackedAddress24, 2, 12,
    (unsigned int)g_Player_CancelAlternatePlayerSettingsEntryPackedAddress24, 1, 12, (unsigned int)g_Player_ConfirmAlternatePlayerSettingsEntryPackedAddress24,
    8, 454, (unsigned int)g_Player_SelectNextAlternatePlayerSettingsEntryPackedAddress24, 7,
    454, (unsigned int)g_Player_SelectPreviousAlternatePlayerSettingsEntryPackedAddress24, 0, 0,
    0, 0,
};
#endif
#if defined(VERSION_EU_X)
unsigned int D_src_638b7747[58] = {
    0x00000E07, 0x00000005, 0x00437C18, 0x00000E08, 0x00000005, 0x00437C20, 0x00000E06, 0x00000005,
    0x00437350, 0x00000E03, 0x00000005, 0x00437BE8, 0x0000000A, 0x00000005, 0x00437C9C, 0x00000002,
    0x00000005, 0x00437D08, 0x00000001, 0x00000005, 0x00437CA4, 0x00000008, 0x00000062, 0x00437D44,
    0x00000007, 0x00000062, 0x00437E0C, 0x00000000, 0x00000000, 0x00000000, 0x00000E07, 0x0000000C,
    0x00437F94, 0x00000E08, 0x0000000C, 0x00437F9C, 0x00000E06, 0x0000000C, 0x004377BC, 0x00000E03,
    0x0000000C, 0x00437F64, 0x00000002, 0x0000000C, 0x00438014, 0x00000001, 0x0000000C, 0x00437FA4,
    0x00000008, 0x000001CA, 0x0043805C, 0x00000007, 0x000001CA, 0x0043811C, 0x00000000, 0x00000000,
    0x00000000, 0x45030001,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_PlayerDispatchplayersettingseventPointerWords1[6] = {
    0x00000E07, 0x00000005, (unsigned int)addrLow_Player_EmptySettingsEntryHook, 0x00000E08, 0x00000005, (unsigned int)addrLow_Player_UpdatePlayerSettingsExit,
};
#endif

#if defined(VERSION_US)
unsigned int g_playerSettingsEventHandlersUs[96] = {
    0x00000E06, 0x00000005, 0x004366D0, 0x00000E03, 0x00000005, 0x00436D18, 0x0000000A, 0x00000005,
    0x00436DCC, 0x00000002, 0x00000005, 0x00436E38, 0x00000001, 0x00000005, 0x00436DD4, 0x00000008,
    0x0000005E, 0x00436E74, 0x00000007, 0x0000005E, 0x00436F2C, 0x00000000, 0x00000000, 0x00000000,
    0x00000E07, 0x0000000C, 0x0043722C, 0x00000E08, 0x0000000C, 0x00437234, 0x00000E06, 0x0000000C,
    0x00437074, 0x00000E03, 0x0000000C, 0x004371FC, 0x00000002, 0x0000000C, 0x004372AC, 0x00000001,
    0x0000000C, 0x0043723C, 0x00000008, 0x000001C6, 0x004372F4, 0x00000007, 0x000001C6, 0x004373A4,
    0x00000000, 0x00000000, 0x00000000, 0x2E481CEE, 0x00000000, 0x00000000, 0x00000E08, 0x00000009,
    0x00437624, 0x00000E06, 0x00000009, 0x004374F0, 0x00000E07, 0x00000009, 0x004375F4, 0x00000E03,
    0x00000009, 0x004375C4, 0x00000001, 0x00000009, 0x00437790, 0x00000002, 0x00000009, 0x00437754,
    0x00000000, 0x00000000, 0x00000000, 0x00000E08, 0x0000001E, 0x004379F0, 0x00000E06, 0x0000001E,
    0x004378F8, 0x00000E07, 0x0000001E, 0x004379C8, 0x00000E03, 0x0000001E, 0x00437998, 0x00000001,
    0x0000001E, 0x00437B10, 0x00000002, 0x0000001E, 0x00437AD4, 0x00000000, 0x00000000, 0x00000000,
};
#endif
