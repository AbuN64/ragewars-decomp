#include "DATA/REST_SOURCE_RECORDS.H"
extern char g_Frontend_UpdatePlayerCountScreenAddress[];
extern char g_SmpOverlay_FollowSlotTarget2cAddress[];
extern char g_SmpOverlay_FollowSlotTarget30Address[];
extern char g_SmpOverlay_FollowSlotTarget34Address[];
extern char g_SmpOverlay_FollowSlotTarget38Address[];
extern char g_SmpOverlay_ForwardSlotEventAddress[];
extern char g_SmpOverlay_FreeEventObjectAddress[];
extern char g_SmpOverlay_ReturnUnhandledEventAddress[];
extern char g_SmpOverlay_SetListWidgetFlag40Address[];


/* g_listButtonEventHandlerRecordsUsRev1_SmpbuttonDispatchlisteventData.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E3300_unclaimed_E3FFC */
RestLinkerAlignmentFill4 g_listButtonEventTablePrefixUsRev1LinkerAlignmentFill450 = {
    { 0, 0, 0, 0 },
};

extern char g_SmpButton_DimListItemsAddress[];
extern char g_SmpButton_HighlightListItemsAddress[];
extern char g_SmpButton_DimListItemsWithSoundAddress[];
extern char g_SmpButton_SelectNextListEntryAddress[];
extern char g_SmpButton_SelectPreviousListEntryAddress[];
extern char g_SmpButton_DestroyListControllerAddress[];
RestlistButtonEventHandlerRecordsUsRev1Record451 g_listButtonEventHandlerRecordsUsRev1 = {
    3591,
    30000,
    (unsigned int)g_SmpButton_DimListItemsAddress,
    15,
    30000,
    (unsigned int)g_SmpButton_HighlightListItemsAddress,
    16,
    30000,
    (unsigned int)g_SmpButton_DimListItemsWithSoundAddress,
    8,
    30000,
    (unsigned int)g_SmpButton_SelectNextListEntryAddress,
    7,
    30000,
    (unsigned int)g_SmpButton_SelectPreviousListEntryAddress,
    3587,
    30000,
    (unsigned int)g_SmpButton_DestroyListControllerAddress,
    { 0x00000000, 0x00000000, 0x00000000 },
};
#endif

/* g_buttonEventHandlerRecordsUsRev1_SmpbuttonDispatchlisteventData.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E3300_unclaimed_E4054 */
extern char g_Menu_UpdateSixChoiceMenuAddress[];
RestsixChoiceMenuUpdateEventRecordUsRev1Record452 g_sixChoiceMenuUpdateEventRecordUsRev1 = {
    3592,
    27,
    (unsigned int)g_Menu_UpdateSixChoiceMenuAddress,
};

extern char g_SmpButton_DimButtonItemsAddress[];
extern char g_SmpButton_HighlightButtonItemsAddress[];
extern char g_SmpButton_DimButtonItemsWithSoundAddress[];
extern char g_SmpButton_DestroyButtonControllerAddress[];
RestbuttonEventHandlerRecordsUsRev1Record453 g_buttonEventHandlerRecordsUsRev1 = {
    3591,
    30000,
    (unsigned int)g_SmpButton_DimButtonItemsAddress,
    15,
    30000,
    (unsigned int)g_SmpButton_HighlightButtonItemsAddress,
    16,
    30000,
    (unsigned int)g_SmpButton_DimButtonItemsWithSoundAddress,
    3587,
    30000,
    (unsigned int)g_SmpButton_DestroyButtonControllerAddress,
    { 0x00000000, 0x00000000, 0x00000000 },
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
RestbuttonWidgetHandlerTailUsRev1Layout454 g_buttonWidgetHandlerTailUsRev1 = {
    (void *)&g_Frontend_UpdatePlayerCountScreenAddress,
    { 3591, 30000 },
    (void *)&g_SmpOverlay_ReturnUnhandledEventAddress,
    { 3587, 30000 },
    (void *)&g_SmpOverlay_FreeEventObjectAddress,
    { 3592, 30000 },
    (void *)&g_SmpOverlay_SetListWidgetFlag40Address,
    { 7, 30000 },
    (void *)&g_SmpOverlay_FollowSlotTarget34Address,
    { 5, 30000 },
    (void *)&g_SmpOverlay_FollowSlotTarget2cAddress,
    { 8, 30000 },
    (void *)&g_SmpOverlay_FollowSlotTarget38Address,
    { 6, 30000 },
    (void *)&g_SmpOverlay_FollowSlotTarget30Address,
    { 1, 30000 },
    { (void *)&g_SmpOverlay_ForwardSlotEventAddress, 0, 0, 0 },
    19,
};
#endif
