#include "DATA/REST_SOURCE_RECORDS.H"


/* 800E32A1_2.CPP */
/* Menu state seed block: seventeen zero words followed by a six-word tail. The zeros are the
   runtime's cleared fields; the tail words are cartridge settings — small numbers on eu, eu-x and
   us-rev1, and packed text or values on de, eu and us. */
#if defined(VERSION_DE)
extern char g_smpFrameAnim_DestroyControllerEntry[];
RestsmpControllerStateAndEventWordsLayout872 g_smpControllerStateAndEventWords = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0.38789132f, 0.3852987f },
    { 1, 30000 },
    (void *)(g_smpFrameAnim_DestroyControllerEntry),
    3592,
};
#elif defined(VERSION_EU)
RestsmpControllerStateAndEventWordsLayout873 g_smpControllerStateAndEventWords = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    0x257301E8,
    0x1580FFFC,
    1,
    4.758789f,
    0x03135820,
    0x018B6022,
};
#elif defined(VERSION_EU_X)
RestsmpControllerStateAndEventWordsLayout874 g_smpControllerStateAndEventWords = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 181, 200, 1, 198, 138, 130 },
};
#elif defined(VERSION_US)
RestsmpControllerStateAndEventWordsLayout875 g_smpControllerStateAndEventWords = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    "uR\000\000",
    0x98000000,
    { 1, 0 },
    0x1E475241,
    "PHIC",
};
#elif defined(VERSION_US_REV1)
RestsmpControllerStateAndEventWordsLayout876 g_smpControllerStateAndEventWords = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 177, 196, 1, 194, 134, 126 },
};
#endif

/* 800E3300.CPP */
#if defined(VERSION_US_REV1)
extern char addrLow_SmpFrameAnim_UpdateFrameSequence[];
extern char addrLow_SmpFrameAnim_DestroyController[];
RestsmpFrameControllerEventRecordsUsRev1Record877 g_smpFrameControllerEventRecordsUsRev1 = {
    3587,
    30000,
    (unsigned int)addrLow_SmpFrameAnim_DestroyController,
    3592,
    30000,
    (unsigned int)addrLow_SmpFrameAnim_UpdateFrameSequence,
    { 0x00000000, 0x00000000, 0x00000000 },
};
#endif

/* 800E3324.CPP */
#if defined(VERSION_US_REV1)
extern char addrLow_SmpFlicker_UpdateFlicker[];
extern char addrLow_SmpFlicker_DestroyController[];
extern char addrLow_Smp_UpdateFadeProgress[];
extern char addrLow_SmpSlider_DestroyController[];
extern char g_selection_HandleCharacterVariantCycleEntry[];
RestsmpControllerEventRecordTailsUsRev1Layout878 g_smpControllerEventRecordTailsUsRev1 = {
    { 199, 179, 181, 3587, 30000 },
    (void *)(addrLow_SmpFlicker_DestroyController),
    { 3592, 30000 },
    { (void *)(addrLow_SmpFlicker_UpdateFlicker), 0, 0, 0 },
    { 154, 158, 159, 3587, 30000 },
    (void *)(addrLow_SmpSlider_DestroyController),
    { 3592, 30000 },
    { (void *)(addrLow_Smp_UpdateFadeProgress), 0, 0, 0, (void *)(g_selection_HandleCharacterVariantCycleEntry) },
    { 3594, 7 },
};
#endif

/* 800E3324_2.CPP */
#if defined(VERSION_US_REV1)
extern char g_SmpSlider_DimSliderItemsAddress[];
extern char addrLow_SmpSlider_HighlightSliderItems[];
extern char addrLow_SmpList_ResetEntryCommands[];
extern char addrLow_SmpList_HandleIncrementInput[];
extern char addrLow_SmpList_HandleDecrementInput[];
extern char addrLow_SmpList_HandleStopEvent[];
extern char addrLow_SmpList_UpdateSliderMotion[];
extern char addrLow_SmpList_DestroyController[];
RestsmpSliderListEventRecordsUsRev1Record879 g_smpSliderListEventRecordsUsRev1 = {
    3591,
    30000,
    (unsigned int)g_SmpSlider_DimSliderItemsAddress,
    15,
    30000,
    (unsigned int)addrLow_SmpSlider_HighlightSliderItems,
    16,
    30000,
    (unsigned int)addrLow_SmpList_ResetEntryCommands,
    8,
    30000,
    (unsigned int)addrLow_SmpList_HandleIncrementInput,
    7,
    30000,
    (unsigned int)addrLow_SmpList_HandleDecrementInput,
    3587,
    30000,
    (unsigned int)addrLow_SmpList_DestroyController,
    11,
    30000,
    (unsigned int)addrLow_SmpList_HandleStopEvent,
    3592,
    30000,
    (unsigned int)addrLow_SmpList_UpdateSliderMotion,
    { 0x00000000, 0x00000000, 0x00000000 },
};
#endif

/* 804196C0.CPP */
#if defined(VERSION_EU_X)
RestsmpEventHandlerTablesLayout880 g_smpEventHandlerTables = {
    { 3587, 30000, 4300588, 3592, 30000, 4299552, 0, 0, 0, 203, 183, 185, 3587, 30000, 4301948, 3592, 30000, 4300624, 0, 0, 0, 158, 162, 163, 3587, 30000, 4303216, 3592, 30000, 4301984, 0, 0, 0, 4329512, 3594, 7, 3591, 30000, 4304256, 15, 30000, 4304312, 16, 30000, 4304368, 8, 30000, 4304464, 7, 30000, 4304576, 3587, 30000, 4304816, 11, 30000, 4304688, 3592, 30000, 4304732, 0, 0, 0, 0, 3591, 30000, 4305792, 15, 30000, 4305840, 16, 30000, 4305888, 8, 30000, 4305976, 7, 30000, 4306076, 3587, 30000, 4306176, 0, 0, 0, 3592, 27, 4333804, 3591, 30000, 4307268, 15, 30000, 4307316, 16, 30000, 4307364, 3587, 30000, 4307452, 0, 0, 0, 7, 3591, 30000, 4308852, 3587, 30000, 4309576, 3592, 30000, 4309608, 7, 30000, 4308860, 5, 30000, 4309008, 8, 30000, 4309156, 6, 30000, 4309304, 1, 30000, 4309452, 0, 0, 0, 4403020 },
};
#endif

/* 804196C0_2.CPP */
#if defined(VERSION_EU)
extern char g_SmpFrameAnim_UpdateFrameSequencePackedAddress24[];
extern char g_SmpFrameAnim_DestroyControllerPackedAddress24[];
extern char g_SmpFlicker_UpdateFlickerPackedAddress24[];
extern char g_SmpFlicker_DestroyControllerPackedAddress24[];
extern char g_Smp_UpdateFadeProgressPackedAddress24[];
extern char g_SmpSlider_DestroyControllerPackedAddress24[];
extern char g_SmpSlider_DimSliderItemsPackedAddress24[];
extern char g_SmpSlider_HighlightSliderItemsPackedAddress24[];
extern char g_SmpList_ResetEntryCommandsPackedAddress24[];
extern char g_SmpList_HandleIncrementInputPackedAddress24[];
extern char g_SmpList_HandleDecrementInputPackedAddress24[];
extern char g_SmpList_HandleStopEventPackedAddress24[];
extern char g_SmpList_UpdateSliderMotionPackedAddress24[];
extern char g_SmpList_DestroyControllerPackedAddress24[];
extern char g_SmpButton_DimListItemsPackedAddress24[];
extern char g_SmpButton_HighlightListItemsPackedAddress24[];
extern char g_SmpButton_DimListItemsWithSoundPackedAddress24[];
extern char g_SmpButton_SelectNextListEntryPackedAddress24[];
extern char g_SmpButton_SelectPreviousListEntryPackedAddress24[];
extern char g_SmpButton_DestroyListControllerPackedAddress24[];
extern char g_SmpButton_DimButtonItemsPackedAddress24[];
extern char g_SmpButton_HighlightButtonItemsPackedAddress24[];
extern char g_SmpButton_DimButtonItemsWithSoundPackedAddress24[];
extern char g_SmpButton_DestroyButtonControllerPackedAddress24[];
extern char g_SmpOverlay_ReturnUnhandledEventPackedAddress24[];
extern char g_SmpOverlay_FollowSlotTarget34PackedAddress24[];
extern char g_SmpOverlay_FollowSlotTarget2cPackedAddress24[];
extern char g_SmpOverlay_FollowSlotTarget38PackedAddress24[];
extern char g_SmpOverlay_FollowSlotTarget30PackedAddress24[];
extern char g_SmpOverlay_ForwardSlotEventPackedAddress24[];
extern char g_SmpOverlay_FreeEventObjectPackedAddress24[];
extern char g_SmpOverlay_SetListWidgetFlag40PackedAddress24[];
RestsmpEventHandlerTablesLayout881 g_smpEventHandlerTables = {
    { 3587, 30000 },
    (void *)(g_SmpFrameAnim_DestroyControllerPackedAddress24),
    { 3592, 30000 },
    { (void *)(g_SmpFrameAnim_UpdateFrameSequencePackedAddress24), 0, 0, 0 },
    2.1767578f,
    0x01785822,
    0x19600002,
    { 3587, 30000 },
    (void *)(g_SmpFlicker_DestroyControllerPackedAddress24),
    { 3592, 30000 },
    { (void *)(g_SmpFlicker_UpdateFlickerPackedAddress24), 0, 0, 0, 0 },
    0x97340380,
    0x0C000489,
    { 3587, 30000 },
    (void *)(g_SmpSlider_DestroyControllerPackedAddress24),
    { 3592, 30000 },
    { (void *)(g_Smp_UpdateFadeProgressPackedAddress24), 0, 0, 0 },
    0x900801D9,
    0x30A70001,
    0x15000006,
    { 3591, 30000 },
    (void *)(g_SmpSlider_DimSliderItemsPackedAddress24),
    { 15, 30000 },
    (void *)(g_SmpSlider_HighlightSliderItemsPackedAddress24),
    { 16, 30000 },
    (void *)(g_SmpList_ResetEntryCommandsPackedAddress24),
    { 8, 30000 },
    (void *)(g_SmpList_HandleIncrementInputPackedAddress24),
    { 7, 30000 },
    (void *)(g_SmpList_HandleDecrementInputPackedAddress24),
    { 3587, 30000 },
    (void *)(g_SmpList_DestroyControllerPackedAddress24),
    { 11, 30000 },
    (void *)(g_SmpList_HandleStopEventPackedAddress24),
    { 3592, 30000 },
    { (void *)(g_SmpList_UpdateSliderMotionPackedAddress24), 0, 0, 0 },
    8486726.0f,
    { 3591, 30000 },
    (void *)(g_SmpButton_DimListItemsPackedAddress24),
    { 15, 30000 },
    (void *)(g_SmpButton_HighlightListItemsPackedAddress24),
    { 16, 30000 },
    (void *)(g_SmpButton_DimListItemsWithSoundPackedAddress24),
    { 8, 30000 },
    (void *)(g_SmpButton_SelectNextListEntryPackedAddress24),
    { 7, 30000 },
    (void *)(g_SmpButton_SelectPreviousListEntryPackedAddress24),
    { 3587, 30000 },
    { (void *)(g_SmpButton_DestroyListControllerPackedAddress24), 0, 0, 0 },
    0xE9030E7A,
    23425932.0f,
    0xE919147C,
    { 3591, 30000 },
    (void *)(g_SmpButton_DimButtonItemsPackedAddress24),
    { 15, 30000 },
    (void *)(g_SmpButton_HighlightButtonItemsPackedAddress24),
    { 16, 30000 },
    (void *)(g_SmpButton_DimButtonItemsWithSoundPackedAddress24),
    { 3587, 30000 },
    { (void *)(g_SmpButton_DestroyButtonControllerPackedAddress24), 0, 0, 0 },
    0x1260000D,
    { 3591, 30000 },
    (void *)(g_SmpOverlay_ReturnUnhandledEventPackedAddress24),
    { 3587, 30000 },
    (void *)(g_SmpOverlay_FreeEventObjectPackedAddress24),
    { 3592, 30000 },
    (void *)(g_SmpOverlay_SetListWidgetFlag40PackedAddress24),
    { 7, 30000 },
    (void *)(g_SmpOverlay_FollowSlotTarget34PackedAddress24),
    { 5, 30000 },
    (void *)(g_SmpOverlay_FollowSlotTarget2cPackedAddress24),
    { 8, 30000 },
    (void *)(g_SmpOverlay_FollowSlotTarget38PackedAddress24),
    { 6, 30000 },
    (void *)(g_SmpOverlay_FollowSlotTarget30PackedAddress24),
    { 1, 30000 },
    { (void *)(g_SmpOverlay_ForwardSlotEventPackedAddress24), 0, 0, 0 },
    0xE9171C7C,
};
#endif
