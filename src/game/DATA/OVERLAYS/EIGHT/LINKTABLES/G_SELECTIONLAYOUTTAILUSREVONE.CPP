
#if defined(VERSION_US_REV1)
/* Widget IDs occupy the second halfword; kind and event fields remain words. */
struct {
    unsigned short firstRowWidgets[8][2];
    struct {
        unsigned int kind;
        unsigned short widgets[8][2];
    } rows[3];
} g_selectionLayoutTailUsRevOne = {
    { { 0, 0x007F }, { 0, 0x00C6 }, { 0, 0x00AD }, { 0, 0x00AF }, { 0, 0x00B1 }, { 0, 0x00C4 }, { 0, 0x00C3 }, { 0, 0x00C2 } },
    {
        { 0x00000086, { { 0, 0x007E }, { 0, 0x00A9 }, { 0, 0x0094 }, { 0, 0x0096 }, { 0, 0x0098 }, { 0, 0x00A8 }, { 0, 0x00A7 }, { 0, 0x00A6 } } },
        { 0x0000008D, { { 0, 0x007C }, { 0, 0x00C7 }, { 0, 0x00B3 }, { 0, 0x00B5 }, { 0, 0x00B7 }, { 0, 0x00B9 }, { 0, 0x00BA }, { 0, 0x00BB } } },
        { 0x0000008C, { { 0, 0x007D }, { 0, 0x00AA }, { 0, 0x009C }, { 0, 0x009B }, { 0, 0x009A }, { 0, 0x009E }, { 0, 0x009F }, { 0, 0x009D } } },
    },
};

extern char g_cCharacterSelection_OpenCharacterSelectionScreenEntry[];
extern char g_character_UpdateCharacterPreviewEntry[];
extern char g_menu_RenderPlayerCharacterPreviewsEntry[];
extern char D_00420B80[];
extern char g_selection_ActivateCharacterSelectionModeEntry[];
extern char g_selection_HandleCharacterVariantCycleEntry[];
extern char g_selection_ReturnCharacterEventZeroAEntry[];
extern char g_selection_ReturnCharacterEventZeroBEntry[];
extern char g_selection_ReturnCharacterEventZeroCEntry[];
extern char g_selection_ReturnCharacterEventZeroDEntry[];
extern char g_selection_CancelCharacterConfirmationEntry[];
extern char g_selection_ReadSelectionSlotEntry[];
unsigned int g_eventHandlers_us_rev1[39] = {
    0x00000E07, 0x00000007, (unsigned int)g_selection_ActivateCharacterSelectionModeEntry, 0x00000E08, 0x00000007, (unsigned int)g_character_UpdateCharacterPreviewEntry, 0x0000000A, 0x00000007,
    (unsigned int)g_selection_HandleCharacterVariantCycleEntry, 0x00000E0A, 0x00000007, (unsigned int)g_menu_RenderPlayerCharacterPreviewsEntry, 0x00000E06, 0x00000007, (unsigned int)g_cCharacterSelection_OpenCharacterSelectionScreenEntry, 0x00000E03,
    0x00000007, (unsigned int)D_00420B80, 0x00000002, 0x00000007, (unsigned int)g_selection_CancelCharacterConfirmationEntry, 0x00000001, 0x00000007, (unsigned int)g_selection_ReadSelectionSlotEntry,
    0x00000008, 0x00000007, (unsigned int)g_selection_ReturnCharacterEventZeroAEntry, 0x00000007, 0x00000007, (unsigned int)g_selection_ReturnCharacterEventZeroBEntry, 0x00000005, 0x00000007,
    (unsigned int)g_selection_ReturnCharacterEventZeroCEntry, 0x00000006, 0x00000007, (unsigned int)g_selection_ReturnCharacterEventZeroDEntry, 0x00000000, 0x00000000, 0x00000000,
};
#endif
