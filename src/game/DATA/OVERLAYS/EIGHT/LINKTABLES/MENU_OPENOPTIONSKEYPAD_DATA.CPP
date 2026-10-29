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
unsigned int D_src_16391c30[19] = {
    0x00000E08, 0x0000001C, 0x00421884, 0x00000E06, 0x0000001C, 0x00420E20, 0x00000E03, 0x0000001C,
    0x00421854, 0x00000002, 0x0000001C, 0x004219E0, 0x00000001, 0x0000001C, 0x00421928, 0x00000000,
    0x00000000, 0x00000000, 0x00421BAC,
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
unsigned int D_src_16391c30[19] = {
    0x00000E08, 0x0000001C, 0x00421DCC, 0x00000E06, 0x0000001C, 0x004212D0, 0x00000E03, 0x0000001C,
    0x00421D9C, 0x00000002, 0x0000001C, 0x00421F00, 0x00000001, 0x0000001C, 0x00421E70, 0x00000000,
    0x00000000, 0x00000000, 0x00000000,
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
unsigned int data_unresolved_800DF0AC[1] = {
    0x75042E65,
};
#endif
