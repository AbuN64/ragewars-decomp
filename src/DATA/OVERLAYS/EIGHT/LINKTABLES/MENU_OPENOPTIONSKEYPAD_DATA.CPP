#include "include_asm.h"
#include "DATA/OVLTBL/MENU_OPENOPTIONSKEYPAD_DATA.H"

/* 800E4400.CPP */
/* ROM-grounded data: rodata/writable/800E4400 */
unsigned int k_MenuOpenoptionskeypadZeroWords[1] = {
    0x00000000,
};

/* 800E4404.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char Menu_UpdateExtraOptionsMenu_Address[];
extern char Menu_OpenRuleToggleScreen_Address[];
extern char Menu_DestroyExtraOptionsMenu_Address[];
extern char g_Menu_DispatchExtraOptionsEventAddress[];
unsigned int D_src_16391c30[19] = {
    0xe08, 28, (unsigned int)Menu_UpdateExtraOptionsMenu_Address, 0xe06,
    28, (unsigned int)Menu_OpenRuleToggleScreen_Address, 0xe03, 28,
    (unsigned int)Menu_DestroyExtraOptionsMenu_Address, 2, 28, (unsigned int)(Menu_UpdateExtraOptionsMenu_Address + 348),
    1, 28, (unsigned int)(Menu_UpdateExtraOptionsMenu_Address + 164), 0,
    0, 0, (unsigned int)(g_Menu_DispatchExtraOptionsEventAddress + 340),
};
#endif
#if defined(VERSION_EU)
unsigned int D_src_16391c30[19] = {
    0x00000E08, 0x0000001C, 0x00421DCC, 0x00000E06, 0x0000001C, 0x004212D0, 0x00000E03, 0x0000001C,
    0x00421D9C, 0x00000002, 0x0000001C, 0x00421F08, 0x00000001, 0x0000001C, 0x00421E70, 0x00000000,
    0x00000000, 0x00000000, 0x8C850320,
};
#endif
#if defined(VERSION_EU_X)
extern char g_Selection_DispatchCharacterSelectionEventAddress[];
unsigned int D_src_16391c30[19] = {
    0xe08, 28, (unsigned int)(g_Selection_DispatchCharacterSelectionEventAddress + 2956), 0xe06,
    28, (unsigned int)(g_Selection_DispatchCharacterSelectionEventAddress + 144), 0xe03, 28,
    (unsigned int)(g_Selection_DispatchCharacterSelectionEventAddress + 2908), 2, 28, (unsigned int)(g_Selection_DispatchCharacterSelectionEventAddress + 3264),
    1, 28, (unsigned int)(g_Selection_DispatchCharacterSelectionEventAddress + 3120), 0,
    0, 0, 0,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
unsigned int g_MenuOpenoptionskeypadEncodedWords[18] = {
    0x00000E08, 0x0000001C, (unsigned int)g_menu_UpdateExtraOptionsMenuEntry, 0x00000E06, 0x0000001C, (unsigned int)g_menu_OpenRuleToggleScreenEntry, 0x00000E03, 0x0000001C,
    (unsigned int)g_menu_DestroyExtraOptionsMenuEntry, 0x00000002, 0x0000001C, (unsigned int)g_menu_ConfirmExtraOptionsEntry, 0x00000001, 0x0000001C, (unsigned int)g_menu_HandleExtraOptionsChoiceEntry, 0x00000000,
    0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
unsigned int g_MenuOpenoptionskeypadTrailingWord[1] = {
    0x75042E65,
};
#endif
