#include "include_asm.h"

/* 800E444C_2.CPP */
/* ROM-grounded data: rodata/writable/800E4450 */
unsigned int k_MenuCreatesixchoicemenuZeroWords[1] = {
    0x00000000,
};

/* 800E4454.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char g_Menu_DispatchExtraOptionsEventAddress[];
extern char g_Menu_DispatchSixChoiceEventAddress[];
unsigned int D_src_3fb7e4b3[19] = {
    0xe08, 27, (unsigned int)(g_Menu_DispatchExtraOptionsEventAddress + 404), 0xe06,
    27, (unsigned int)(g_Menu_DispatchExtraOptionsEventAddress + 152), 0xe03, 27,
    (unsigned int)(g_Menu_DispatchExtraOptionsEventAddress + 356), 2, 27, (unsigned int)(g_Menu_DispatchExtraOptionsEventAddress + 828),
    1, 27, (unsigned int)(g_Menu_DispatchExtraOptionsEventAddress + 656), 0,
    0, 0, (unsigned int)(g_Menu_DispatchSixChoiceEventAddress + 1056),
};
#endif
#if defined(VERSION_EU)
unsigned int D_src_3fb7e4b3[19] = {
    0x00000E08, 0x0000001B, 0x004220EC, 0x00000E06, 0x0000001B, 0x00421FF0, 0x00000E03, 0x0000001B,
    0x004220BC, 0x00000002, 0x0000001B, 0x00422294, 0x00000001, 0x0000001B, 0x004221E8, 0x00000000,
    0x00000000, 0x00000000, 0x40013000,
};
#endif
#if defined(VERSION_EU_X)
extern char g_Menu_DispatchExtraOptionsEventAddress[];
unsigned int D_src_3fb7e4b3[19] = {
    0xe08, 27, (unsigned int)(g_Menu_DispatchExtraOptionsEventAddress + 404), 0xe06,
    27, (unsigned int)(g_Menu_DispatchExtraOptionsEventAddress + 152), 0xe03, 27,
    (unsigned int)(g_Menu_DispatchExtraOptionsEventAddress + 356), 2, 27, (unsigned int)(g_Menu_DispatchExtraOptionsEventAddress + 828),
    1, 27, (unsigned int)(g_Menu_DispatchExtraOptionsEventAddress + 656), 0,
    0, 0, 7,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char g_menu_CreateSixChoiceMenuEntry[];
extern char g_menu_DestroySixChoiceMenuEntry[];
extern char g_Menu_UpdateSixChoiceMenuAddress[];
extern char g_menu_ChooseSixChoiceOptionEntry[];
extern char g_menu_CancelSixChoiceMenuEntry[];
unsigned int g_MenuCreatesixchoicemenuEncodedWords[18] = {
    0x00000E08, 0x0000001B, (unsigned int)g_Menu_UpdateSixChoiceMenuAddress, 0x00000E06, 0x0000001B, (unsigned int)g_menu_CreateSixChoiceMenuEntry, 0x00000E03, 0x0000001B,
    (unsigned int)g_menu_DestroySixChoiceMenuEntry, 0x00000002, 0x0000001B, (unsigned int)g_menu_CancelSixChoiceMenuEntry, 0x00000001, 0x0000001B, (unsigned int)g_menu_ChooseSixChoiceOptionEntry, 0x00000000,
    0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
unsigned int k_MenuCreatesixchoicemenuTailWords[1] = {
    0x0000002B,
};
#endif
