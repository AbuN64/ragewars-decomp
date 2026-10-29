

/* 800E32A1_2.CPP */
/* Menu state seed block: seventeen zero words followed by a six-word tail. The zeros are the
   runtime's cleared fields; the tail words are cartridge settings — small numbers on eu, eu-x and
   us-rev1, and packed text or values on de, eu and us. */
#if defined(VERSION_DE)
extern char g_smpFrameAnim_DestroyControllerEntry[];
unsigned int g_smpControllerStateAndEventWords[23] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x3EC699B1, 0x3EC545DF, 0x00000001, 0x00007530, (unsigned int)g_smpFrameAnim_DestroyControllerEntry, 0x00000E08,
};
#elif defined(VERSION_EU)
unsigned int g_smpControllerStateAndEventWords[23] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x257301E8, 0x1580FFFC, 0x00000001, 0x40984800, 0x03135820, 0x018B6022,
};
#elif defined(VERSION_EU_X)
unsigned int g_smpControllerStateAndEventWords[23] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x000000B5, 0x000000C8, 0x00000001, 0x000000C6, 0x0000008A, 0x00000082,
};
#elif defined(VERSION_US)
unsigned int g_smpControllerStateAndEventWords[23] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x75520000, 0x98000000, 0x00000001, 0x00000000, 0x1E475241, 0x50484943,
};
#elif defined(VERSION_US_REV1)
unsigned int g_smpControllerStateAndEventWords[23] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x000000B1, 0x000000C4, 0x00000001, 0x000000C2, 0x00000086, 0x0000007E,
};
#endif

/* 800E3300.CPP */
#if defined(VERSION_US_REV1)
extern char addrLow_SmpFrameAnim_UpdateFrameSequence[];
extern char addrLow_SmpFrameAnim_DestroyController[];
unsigned int g_smpFrameControllerEventRecordsUsRev1[9] = {
    0x00000E03, 0x00007530, (unsigned int)addrLow_SmpFrameAnim_DestroyController, 0x00000E08, 0x00007530, (unsigned int)addrLow_SmpFrameAnim_UpdateFrameSequence, 0x00000000, 0x00000000,
    0x00000000,
};
#endif

/* 800E3324.CPP */
#if defined(VERSION_US_REV1)
extern char addrLow_SmpFlicker_UpdateFlicker[];
extern char addrLow_SmpFlicker_DestroyController[];
extern char addrLow_Smp_UpdateFadeProgress[];
extern char addrLow_SmpSlider_DestroyController[];
extern char g_selection_HandleCharacterVariantCycleEntry[];
unsigned int g_smpControllerEventRecordTailsUsRev1[27] = {
    0x000000C7, 0x000000B3, 0x000000B5, 0x00000E03, 0x00007530, (unsigned int)addrLow_SmpFlicker_DestroyController, 0x00000E08, 0x00007530,
    (unsigned int)addrLow_SmpFlicker_UpdateFlicker, 0x00000000, 0x00000000, 0x00000000, 0x0000009A, 0x0000009E, 0x0000009F, 0x00000E03,
    0x00007530, (unsigned int)addrLow_SmpSlider_DestroyController, 0x00000E08, 0x00007530, (unsigned int)addrLow_Smp_UpdateFadeProgress, 0x00000000, 0x00000000, 0x00000000,
    (unsigned int)g_selection_HandleCharacterVariantCycleEntry, 0x00000E0A, 0x00000007,
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
unsigned int g_smpSliderListEventRecordsUsRev1[27] = {
    0x00000E07, 0x00007530, (unsigned int)g_SmpSlider_DimSliderItemsAddress, 0x0000000F, 0x00007530, (unsigned int)addrLow_SmpSlider_HighlightSliderItems, 0x00000010, 0x00007530,
    (unsigned int)addrLow_SmpList_ResetEntryCommands, 0x00000008, 0x00007530, (unsigned int)addrLow_SmpList_HandleIncrementInput, 0x00000007, 0x00007530, (unsigned int)addrLow_SmpList_HandleDecrementInput, 0x00000E03,
    0x00007530, (unsigned int)addrLow_SmpList_DestroyController, 0x0000000B, 0x00007530, (unsigned int)addrLow_SmpList_HandleStopEvent, 0x00000E08, 0x00007530, (unsigned int)addrLow_SmpList_UpdateSliderMotion,
    0x00000000, 0x00000000, 0x00000000,
};
#endif

/* 804196C0.CPP */
#if defined(VERSION_EU_X)
unsigned int g_smpEventHandlerTables[] = {
    0x00000E03, 0x00007530, 0x00419F2C, 0x00000E08, 0x00007530, 0x00419B20, 0x00000000, 0x00000000,
    0x00000000, 0x000000CB, 0x000000B7, 0x000000B9, 0x00000E03, 0x00007530, 0x0041A47C, 0x00000E08,
    0x00007530, 0x00419F50, 0x00000000, 0x00000000, 0x00000000, 0x0000009E, 0x000000A2, 0x000000A3,
    0x00000E03, 0x00007530, 0x0041A970, 0x00000E08, 0x00007530, 0x0041A4A0, 0x00000000, 0x00000000,
    0x00000000, 0x00421028, 0x00000E0A, 0x00000007, 0x00000E07, 0x00007530, 0x0041AD80, 0x0000000F,
    0x00007530, 0x0041ADB8, 0x00000010, 0x00007530, 0x0041ADF0, 0x00000008, 0x00007530, 0x0041AE50,
    0x00000007, 0x00007530, 0x0041AEC0, 0x00000E03, 0x00007530, 0x0041AFB0, 0x0000000B, 0x00007530,
    0x0041AF30, 0x00000E08, 0x00007530, 0x0041AF5C, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000E07, 0x00007530, 0x0041B380, 0x0000000F, 0x00007530, 0x0041B3B0, 0x00000010, 0x00007530,
    0x0041B3E0, 0x00000008, 0x00007530, 0x0041B438, 0x00000007, 0x00007530, 0x0041B49C, 0x00000E03,
    0x00007530, 0x0041B500, 0x00000000, 0x00000000, 0x00000000, 0x00000E08, 0x0000001B, 0x004220EC,
    0x00000E07, 0x00007530, 0x0041B944, 0x0000000F, 0x00007530, 0x0041B974, 0x00000010, 0x00007530,
    0x0041B9A4, 0x00000E03, 0x00007530, 0x0041B9FC, 0x00000000, 0x00000000, 0x00000000, 0x00000007,
    0x00000E07, 0x00007530, 0x0041BF74, 0x00000E03, 0x00007530, 0x0041C248, 0x00000E08, 0x00007530,
    0x0041C268, 0x00000007, 0x00007530, 0x0041BF7C, 0x00000005, 0x00007530, 0x0041C010, 0x00000008,
    0x00007530, 0x0041C0A4, 0x00000006, 0x00007530, 0x0041C138, 0x00000001, 0x00007530, 0x0041C1CC,
    0x00000000, 0x00000000, 0x00000000, 0x00432F4C,
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
unsigned int g_smpEventHandlerTables[] = {
    0x00000E03, 0x00007530, (unsigned int)g_SmpFrameAnim_DestroyControllerPackedAddress24, 0x00000E08, 0x00007530, (unsigned int)g_SmpFrameAnim_UpdateFrameSequencePackedAddress24, 0x00000000, 0x00000000,
    0x00000000, 0x400B5000, 0x01785822, 0x19600002, 0x00000E03, 0x00007530, (unsigned int)g_SmpFlicker_DestroyControllerPackedAddress24, 0x00000E08,
    0x00007530, (unsigned int)g_SmpFlicker_UpdateFlickerPackedAddress24, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x97340380, 0x0C000489,
    0x00000E03, 0x00007530, (unsigned int)g_SmpSlider_DestroyControllerPackedAddress24, 0x00000E08, 0x00007530, (unsigned int)g_Smp_UpdateFadeProgressPackedAddress24, 0x00000000, 0x00000000,
    0x00000000, 0x900801D9, 0x30A70001, 0x15000006, 0x00000E07, 0x00007530, (unsigned int)g_SmpSlider_DimSliderItemsPackedAddress24, 0x0000000F,
    0x00007530, (unsigned int)g_SmpSlider_HighlightSliderItemsPackedAddress24, 0x00000010, 0x00007530, (unsigned int)g_SmpList_ResetEntryCommandsPackedAddress24, 0x00000008, 0x00007530, (unsigned int)g_SmpList_HandleIncrementInputPackedAddress24,
    0x00000007, 0x00007530, (unsigned int)g_SmpList_HandleDecrementInputPackedAddress24, 0x00000E03, 0x00007530, (unsigned int)g_SmpList_DestroyControllerPackedAddress24, 0x0000000B, 0x00007530,
    (unsigned int)g_SmpList_HandleStopEventPackedAddress24, 0x00000E08, 0x00007530, (unsigned int)g_SmpList_UpdateSliderMotionPackedAddress24, 0x00000000, 0x00000000, 0x00000000, 0x4B017F46,
    0x00000E07, 0x00007530, (unsigned int)g_SmpButton_DimListItemsPackedAddress24, 0x0000000F, 0x00007530, (unsigned int)g_SmpButton_HighlightListItemsPackedAddress24, 0x00000010, 0x00007530,
    (unsigned int)g_SmpButton_DimListItemsWithSoundPackedAddress24, 0x00000008, 0x00007530, (unsigned int)g_SmpButton_SelectNextListEntryPackedAddress24, 0x00000007, 0x00007530, (unsigned int)g_SmpButton_SelectPreviousListEntryPackedAddress24, 0x00000E03,
    0x00007530, (unsigned int)g_SmpButton_DestroyListControllerPackedAddress24, 0x00000000, 0x00000000, 0x00000000, 0xE9030E7A, 0x4BB2B9C6, 0xE919147C,
    0x00000E07, 0x00007530, (unsigned int)g_SmpButton_DimButtonItemsPackedAddress24, 0x0000000F, 0x00007530, (unsigned int)g_SmpButton_HighlightButtonItemsPackedAddress24, 0x00000010, 0x00007530,
    (unsigned int)g_SmpButton_DimButtonItemsWithSoundPackedAddress24, 0x00000E03, 0x00007530, (unsigned int)g_SmpButton_DestroyButtonControllerPackedAddress24, 0x00000000, 0x00000000, 0x00000000, 0x1260000D,
    0x00000E07, 0x00007530, (unsigned int)g_SmpOverlay_ReturnUnhandledEventPackedAddress24, 0x00000E03, 0x00007530, (unsigned int)g_SmpOverlay_FreeEventObjectPackedAddress24, 0x00000E08, 0x00007530,
    (unsigned int)g_SmpOverlay_SetListWidgetFlag40PackedAddress24, 0x00000007, 0x00007530, (unsigned int)g_SmpOverlay_FollowSlotTarget34PackedAddress24, 0x00000005, 0x00007530, (unsigned int)g_SmpOverlay_FollowSlotTarget2cPackedAddress24, 0x00000008,
    0x00007530, (unsigned int)g_SmpOverlay_FollowSlotTarget38PackedAddress24, 0x00000006, 0x00007530, (unsigned int)g_SmpOverlay_FollowSlotTarget30PackedAddress24, 0x00000001, 0x00007530, (unsigned int)g_SmpOverlay_ForwardSlotEventPackedAddress24,
    0x00000000, 0x00000000, 0x00000000, 0xE9171C7C,
};
#endif
