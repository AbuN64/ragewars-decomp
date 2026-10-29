
#if defined(VERSION_US_REV1)
extern char g_Frontend_CreatePakProfileScreenPackedAddress24[];
/* ROM-grounded data: rodata/unresolved/800E54A8_unclaimed_E60CC */
unsigned int g_OverlaysNineResourcesRetainedPointerWords1[3] = {
    0x00000E06, 0x00000013, (unsigned int)g_Frontend_CreatePakProfileScreenPackedAddress24,
};

extern char g_frontend_HandlePakProfileInputEntry[];
extern char g_PAKInterface_MoveNameCursorForwardPackedAddress242[];
extern char g_PAKInterface_MoveNameCursorBackwardPackedAddress242[];
extern char g_PAKInterface_HandleNextPanelSelectionPackedAddress242[];
extern char g_PAKInterface_HandlePakMenuConfirmPackedAddress242[];
extern char g_PAKInterface_ActivatePlayerPanelActionPackedAddress242[];
extern char g_PAKInterface_HandlePlayerPanelBackPackedAddress242[];
extern char g_Frontend_DestroyPakProfileScreenPackedAddress242[];
extern char g_Frontend_ResetNameRepeatOnEventPackedAddress242[];
unsigned int g_MenuEventHandlersPointerWords6[30] = {
    0x00000E03, 0x00000013, (unsigned int)g_Frontend_DestroyPakProfileScreenPackedAddress242, 0x00000002, 0x00000013, (unsigned int)g_PAKInterface_HandlePlayerPanelBackPackedAddress242, 0x00000001, 0x00000013,
    (unsigned int)g_PAKInterface_ActivatePlayerPanelActionPackedAddress242, 0x0000000A, 0x00000013, (unsigned int)g_frontend_HandlePakProfileInputEntry, 0x0000000B, 0x00000013, (unsigned int)g_Frontend_ResetNameRepeatOnEventPackedAddress242, 0x00000005,
    0x00000013, (unsigned int)g_PAKInterface_HandlePakMenuConfirmPackedAddress242, 0x00000006, 0x00000013, (unsigned int)g_PAKInterface_HandleNextPanelSelectionPackedAddress242, 0x00000008, 0x00000013, (unsigned int)g_PAKInterface_MoveNameCursorForwardPackedAddress242,
    0x00000007, 0x00000013, (unsigned int)g_PAKInterface_MoveNameCursorBackwardPackedAddress242, 0x00000000, 0x00000000, 0x00000000,
};
#endif
