#include "DATA/OVLTBL/800E4530.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E451C_unclaimed_E5128_unclaimed_E5130 */
unsigned int g_MenuEventHandlers3UsRev1EncodedWords[1] = {
    (unsigned int)g_options_CreateOptionsPageEntry,
};

unsigned int g_menuEventHandlers3_us_rev1[12] = {
    0x00000E03, 0x00000004, (unsigned int)g_menu_DestroyOptionsPageEntry, 0x00000002, 0x00000004, (unsigned int)g_frontend_CloseOptionsPageEntry, 0x00000001, 0x00000004,
    (unsigned int)g_frontend_HandleOptionsPageShortcutEntry, 0x00000000, 0x00000000, 0x00000000,
};
#endif
