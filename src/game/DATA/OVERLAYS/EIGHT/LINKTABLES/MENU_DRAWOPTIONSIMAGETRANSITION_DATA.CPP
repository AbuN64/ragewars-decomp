#include "include_asm.h"
#include "DATA/OVLTBL/MENU_DRAWOPTIONSIMAGETRANSITION_DATA.H"

/* 800E449C_2.CPP */
/* ROM-grounded data: rodata/writable/800E44A0 */
unsigned int k_MenuDrawoptionsimagetransitionZeroWords[1] = {
    0x00000000,
};

/* 800E44A4.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
unsigned int D_src_d9561b8a[27] = {
    0x00000E06, 0x00000019, 0x00422230, 0x00000E03, 0x00000019, 0x00422278, 0x00000002, 0x00000019,
    0x0042242C, 0x00000001, 0x00000019, 0x00422414, 0x00000E0A, 0x00000019, 0x004222A8, 0x00000E08,
    0x00000019, 0x00422340, 0x0000000A, 0x00000019, 0x004223CC, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000E08,
};
#endif
#if defined(VERSION_EU)
unsigned int D_src_d9561b8a[27] = {
    0x00000E06, 0x00000019, 0x00422730, 0x00000E03, 0x00000019, 0x00422778, 0x00000002, 0x00000019,
    0x0042292C, 0x00000001, 0x00000019, 0x00422914, 0x00000E0A, 0x00000019, 0x004227A8, 0x00000E08,
    0x00000019, 0x00422840, 0x0000000A, 0x00000019, 0x004228CC, 0x00000000, 0x00000000, 0x00000000,
    0xA702000C, 0x001A1402, 0x30410008,
};
#endif
#if defined(VERSION_EU_X)
unsigned int D_src_d9561b8a[27] = {
    0x00000E06, 0x00000019, 0x00422730, 0x00000E03, 0x00000019, 0x00422778, 0x00000002, 0x00000019,
    0x0042292C, 0x00000001, 0x00000019, 0x00422914, 0x00000E0A, 0x00000019, 0x004227A8, 0x00000E08,
    0x00000019, 0x00422840, 0x0000000A, 0x00000019, 0x004228CC, 0x00000000, 0x00000000, 0x00000000,
    0x00000002, 0x00000013, 0x00432F4C,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_MenuDrawoptionsimagetransitionEncodedWords[24] = {
    0x00000E06, 0x00000019, (unsigned int)g_menu_CreateOptionsImageTransitionEntry, 0x00000E03, 0x00000019, (unsigned int)g_menu_DestroyOptionsImageTransitionEntry, 0x00000002, 0x00000019,
    (unsigned int)g_menu_ConsumeOptionsTransitionEventEntry, 0x00000001, 0x00000019, (unsigned int)g_menu_RequestOptionsImageTransitionEntry, 0x00000E0A, 0x00000019, (unsigned int)g_menu_DrawOptionsImageTransitionEntry, 0x00000E08,
    0x00000019, (unsigned int)g_menu_StartOptionsImageTransitionEntry, 0x0000000A, 0x00000019, (unsigned int)g_menu_HandleOptionsTransitionRequestEntry, 0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
char g_MenuDrawoptionsimagetransitionTrailingBytes[12] =
    "IFLEequ\004.eos";
#endif
