

/* g_listButtonEventHandlerRecordsUsRev1_SmpbuttonDispatchlisteventData.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E3300_unclaimed_E3FFC */
unsigned int g_listButtonEventTablePrefixUsRev1[1] = {
    0x00000000,
};

extern char g_SmpButton_DimListItemsAddress[];
extern char g_SmpButton_HighlightListItemsAddress[];
extern char g_SmpButton_DimListItemsWithSoundAddress[];
extern char g_SmpButton_SelectNextListEntryAddress[];
extern char g_SmpButton_SelectPreviousListEntryAddress[];
extern char g_SmpButton_DestroyListControllerAddress[];
unsigned int g_listButtonEventHandlerRecordsUsRev1[21] = {
    0x00000E07, 0x00007530, (unsigned int)g_SmpButton_DimListItemsAddress, 0x0000000F, 0x00007530, (unsigned int)g_SmpButton_HighlightListItemsAddress, 0x00000010, 0x00007530,
    (unsigned int)g_SmpButton_DimListItemsWithSoundAddress, 0x00000008, 0x00007530, (unsigned int)g_SmpButton_SelectNextListEntryAddress, 0x00000007, 0x00007530, (unsigned int)g_SmpButton_SelectPreviousListEntryAddress, 0x00000E03,
    0x00007530, (unsigned int)g_SmpButton_DestroyListControllerAddress, 0x00000000, 0x00000000, 0x00000000,
};
#endif

/* g_buttonEventHandlerRecordsUsRev1_SmpbuttonDispatchlisteventData.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E3300_unclaimed_E4054 */
extern char g_Menu_UpdateSixChoiceMenuAddress[];
unsigned int g_sixChoiceMenuUpdateEventRecordUsRev1[3] = {
    0x00000E08, 0x0000001B, (unsigned int)g_Menu_UpdateSixChoiceMenuAddress,
};

extern char g_SmpButton_DimButtonItemsAddress[];
extern char g_SmpButton_HighlightButtonItemsAddress[];
extern char g_SmpButton_DimButtonItemsWithSoundAddress[];
extern char g_SmpButton_DestroyButtonControllerAddress[];
unsigned int g_buttonEventHandlerRecordsUsRev1[15] = {
    0x00000E07, 0x00007530, (unsigned int)g_SmpButton_DimButtonItemsAddress, 0x0000000F, 0x00007530, (unsigned int)g_SmpButton_HighlightButtonItemsAddress, 0x00000010, 0x00007530,
    (unsigned int)g_SmpButton_DimButtonItemsWithSoundAddress, 0x00000E03, 0x00007530, (unsigned int)g_SmpButton_DestroyButtonControllerAddress, 0x00000000, 0x00000000, 0x00000000,
};
#endif

/* g_buttonWidgetHandlerTailUsRev1_SmpbuttonDispatchlisteventData.CPP */
#if defined(VERSION_US_REV1)
extern char g_SmpOverlay_ReturnUnhandledEventAddress[];
extern char g_SmpOverlay_FollowSlotTarget34Address[];
extern char g_SmpOverlay_FollowSlotTarget2cAddress[];
extern char g_SmpOverlay_FollowSlotTarget38Address[];
extern char g_SmpOverlay_FollowSlotTarget30Address[];
extern char g_SmpOverlay_ForwardSlotEventAddress[];
extern char g_SmpOverlay_FreeEventObjectAddress[];
extern char g_SmpOverlay_SetListWidgetFlag40Address[];
extern char g_Frontend_UpdatePlayerCountScreenAddress[];
unsigned int g_buttonWidgetHandlerTailUsRev1[29] = {
    (unsigned int)g_Frontend_UpdatePlayerCountScreenAddress, 0x00000E07, 0x00007530, (unsigned int)g_SmpOverlay_ReturnUnhandledEventAddress, 0x00000E03, 0x00007530, (unsigned int)g_SmpOverlay_FreeEventObjectAddress, 0x00000E08,
    0x00007530, (unsigned int)g_SmpOverlay_SetListWidgetFlag40Address, 0x00000007, 0x00007530, (unsigned int)g_SmpOverlay_FollowSlotTarget34Address, 0x00000005, 0x00007530, (unsigned int)g_SmpOverlay_FollowSlotTarget2cAddress,
    0x00000008, 0x00007530, (unsigned int)g_SmpOverlay_FollowSlotTarget38Address, 0x00000006, 0x00007530, (unsigned int)g_SmpOverlay_FollowSlotTarget30Address, 0x00000001, 0x00007530,
    (unsigned int)g_SmpOverlay_ForwardSlotEventAddress, 0x00000000, 0x00000000, 0x00000000, 0x00000013,
};
#endif
