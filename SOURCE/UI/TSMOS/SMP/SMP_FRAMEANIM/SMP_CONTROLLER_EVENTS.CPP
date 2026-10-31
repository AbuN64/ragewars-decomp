#include "DATA/REST_SOURCE_RECORDS.H"
extern char addrLow_SmpFlicker_DestroyController[];
extern char addrLow_SmpFlicker_UpdateFlicker[];
extern char addrLow_SmpSlider_DestroyController[];
extern char addrLow_Smp_UpdateFadeProgress[];
extern char g_selection_HandleCharacterVariantCycleEntry[];
#if defined(VERSION_US_REV1)
/* 800E3300.CPP */
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
/* 800E3324.CPP */
extern char addrLow_SmpFlicker_UpdateFlicker[];
extern char addrLow_SmpFlicker_DestroyController[];
extern char addrLow_Smp_UpdateFadeProgress[];
extern char addrLow_SmpSlider_DestroyController[];
extern char g_selection_HandleCharacterVariantCycleEntry[];
RestsmpControllerEventRecordTailsUsRev1Layout878 g_smpControllerEventRecordTailsUsRev1 = {
    { 199, 179, 181, 3587, 30000 },
    (void *)&addrLow_SmpFlicker_DestroyController,
    { 3592, 30000 },
    { (void *)&addrLow_SmpFlicker_UpdateFlicker, 0, 0, 0 },
    { 154, 158, 159, 3587, 30000 },
    (void *)&addrLow_SmpSlider_DestroyController,
    { 3592, 30000 },
    { (void *)&addrLow_Smp_UpdateFadeProgress, 0, 0, 0, (void *)&g_selection_HandleCharacterVariantCycleEntry },
    { 3594, 7 },
};
#endif
