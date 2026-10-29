#include "include_asm.h"

/* g_EventsDelivercontacteffectWords2_EventsDelivercontacteffectData.CPP */
#if defined(VERSION_US)
#if defined(VERSION_US)
unsigned short D_src_a9295539[68] = {
    0xE300, 0x1001, 0x0000, 0x0000, 0xD7FF, 0x0002, 0x8000, 0x8000, 0xD9F9, 0xFBFF, 0x0000, 0x0000,
    0xD9FF, 0xFFFF, 0x0021, 0x0004, 0xFCFF, 0x97FF, 0xFFFF, 0xFE38, 0xE200, 0x001C, 0xC810, 0x4E50,
    0xDB04, 0x0004, 0x0000, 0x0001, 0xDB04, 0x000C, 0x0000, 0x0001, 0xDB04, 0x0014, 0x0000, 0xFFFF,
    0xDB04, 0x001C, 0x0000, 0xFFFF, 0x0100, 0x4008, 0x8014, 0x08E0, 0x0600, 0x0204, 0x0004, 0x0600,
    0xDB04, 0x0004, 0x0000, 0x0005, 0xDB04, 0x000C, 0x0000, 0x0005, 0xDB04, 0x0014, 0x0000, 0xFFFB,
    0xDB04, 0x001C, 0x0000, 0xFFFB, 0xDF00, 0x0000, 0x0000, 0x0000,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_EventsDelivercontacteffectWords2[34] = {
    0xE3001001, 0x00000000, 0xD7FF0002, 0x80008000, 0xD9F9FBFF, 0x00000000, 0xD9FFFFFF, 0x00210004,
    0xFCFF97FF, 0xFFFFFE38, 0xE200001C, 0xC8104E50, 0xDB040004, 0x00000001, 0xDB04000C, 0x00000001,
    0xDB040014, 0x0000FFFF, 0xDB04001C, 0x0000FFFF, 0x01004008, 0x801469A0, 0x06000204, 0x00040600,
    0xDB040004, 0x00000005, 0xDB04000C, 0x00000005, 0xDB040014, 0x0000FFFB, 0xDB04001C, 0x0000FFFB,
    0xDF000000, 0x00000000,
};
#endif

/* g_EventsDelivercontacteffectWords1_EventsDelivercontacteffectData.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800D0F00_unclaimed_D1BA0_unclaimed_D1E68_unclaimed_D1F78 */
unsigned int g_EventsDelivercontacteffectWords1[2] = {
    0x3F169CFB, 0x3F162965,
};

extern char g_Events_PlayClipEventPackedAddress24[];
extern char g_Events_StopClipEventPackedAddress24[];
extern char g_Events_SpawnActorEffectPackedAddress24[];
extern char g_Events_ApplyDirectDamagePackedAddress24_us_rev1[];
extern char g_Events_ApplyRadialDamagePackedAddress24[];
extern char g_Events_ApplyRadialDamageWithKnockbackPackedAddress24_us_rev1[];
extern char g_Events_PreserveEventArgumentPackedAddress24[];
extern char g_Events_RunFirstNodeOperationPackedAddress24[];
extern char g_Events_RunSecondNodeOperationPackedAddress24_us_rev1[];
extern char g_Events_StartCameraFadeAtPointPackedAddress24[];
extern char g_Events_ConsumeEventArgumentPackedAddress24[];
extern char g_Events_RequestActorPositionPackedAddress24[];
extern char g_Events_StartEnabledCameraEmitterPackedAddress24[];
extern char g_Events_StartDisabledCameraEmitterPackedAddress24[];
extern char g_Events_PostGameplayMessagePackedAddress24[];
extern char g_Events_ApplyFlag100RadialDamagePackedAddress24[];
extern char g_Events_ApplyFlag100RadialKnockbackPackedAddress24[];
extern char g_Events_ApplyFlag200RadialDamagePackedAddress24[];
extern char g_Events_ApplyFlag200RadialKnockbackPackedAddress24[];
extern char g_Events_ApplyFlag400RadialDamagePackedAddress24[];
extern char g_Events_ApplyFlag400RadialKnockbackPackedAddress24[];
extern char g_Events_StartActorEmitterPackedAddress24[];
extern char g_Events_IgnoreEventPackedAddress24[];
extern char g_Events_PlayTeamClipPackedAddress24[];
extern char g_Events_SpawnFilteredActorEffectPackedAddress24[];
extern char g_Events_FireWithinHeightRangePackedAddress24[];
extern char g_Events_SetActorEventBitPackedAddress24[];
extern char g_Events_ClearActorEventBitPackedAddress24[];
extern char g_Events_SpawnAttachedEffectPackedAddress24[];
extern char g_Events_SpawnPositionedEffectPackedAddress24[];
extern char g_Events_PlayTeamEffectPackedAddress24[];
extern char g_Events_SetActorLoopingSoundPackedAddress24_us_rev1[];
extern char g_Events_StopActorLoopingSoundPackedAddress24[];
extern char g_Events_IncrementNearbyPlayerCounterPackedAddress24[];
extern char g_Events_SetActorEffectModePackedAddress24[];
extern char g_Events_DeactivateActorPackedAddress24[];
unsigned int g_effectCallbackFlags[74] = {
    (unsigned int)g_Events_PlayClipEventPackedAddress24, 0x00000000, (unsigned int)g_Events_SpawnActorEffectPackedAddress24, 0x00000000, (unsigned int)g_Events_ApplyDirectDamagePackedAddress24_us_rev1, 0x00000004, (unsigned int)g_Events_ApplyRadialDamagePackedAddress24, 0x00000006,
    (unsigned int)g_Events_ApplyRadialDamageWithKnockbackPackedAddress24_us_rev1, 0x00000006, (unsigned int)g_Events_PreserveEventArgumentPackedAddress24, 0x0000000A, (unsigned int)g_Events_RunFirstNodeOperationPackedAddress24, 0x00000010, (unsigned int)g_Events_RunSecondNodeOperationPackedAddress24_us_rev1, 0x00000010,
    (unsigned int)g_Events_SpawnActorEffectPackedAddress24, 0x00000000, (unsigned int)g_Events_StartCameraFadeAtPointPackedAddress24, 0x00000000, (unsigned int)g_Events_ConsumeEventArgumentPackedAddress24, 0x00000000, (unsigned int)g_Events_RequestActorPositionPackedAddress24, 0x00000000,
    (unsigned int)g_Events_StartEnabledCameraEmitterPackedAddress24, 0x00000000, (unsigned int)g_Events_StartDisabledCameraEmitterPackedAddress24, 0x00000000, (unsigned int)g_Events_PostGameplayMessagePackedAddress24, 0x00000000, (unsigned int)g_Events_ApplyFlag100RadialDamagePackedAddress24, 0x00000006,
    (unsigned int)g_Events_ApplyFlag100RadialKnockbackPackedAddress24, 0x00000006, (unsigned int)g_Events_ApplyFlag200RadialDamagePackedAddress24, 0x00000007, (unsigned int)g_Events_ApplyFlag200RadialKnockbackPackedAddress24, 0x00000007, (unsigned int)g_Events_ApplyFlag400RadialDamagePackedAddress24, 0x00000006,
    (unsigned int)g_Events_ApplyFlag400RadialKnockbackPackedAddress24, 0x00000006, (unsigned int)g_Events_StartActorEmitterPackedAddress24, 0x00000000, (unsigned int)g_Events_IgnoreEventPackedAddress24, 0x00000000, (unsigned int)g_Events_PlayTeamClipPackedAddress24, 0x00000000,
    (unsigned int)g_Events_SpawnFilteredActorEffectPackedAddress24, 0x00000000, (unsigned int)g_Events_FireWithinHeightRangePackedAddress24, 0x00000007, (unsigned int)g_Events_SetActorEventBitPackedAddress24, 0x00000000, (unsigned int)g_Events_ClearActorEventBitPackedAddress24, 0x00000000,
    (unsigned int)g_Events_SpawnAttachedEffectPackedAddress24, 0x00000000, (unsigned int)g_Events_PlayTeamEffectPackedAddress24, 0x00000000, (unsigned int)g_Events_StopClipEventPackedAddress24, 0x00000000, (unsigned int)g_Events_SetActorLoopingSoundPackedAddress24_us_rev1, 0x00000000,
    (unsigned int)g_Events_StopActorLoopingSoundPackedAddress24, 0x00000000, (unsigned int)g_Events_IncrementNearbyPlayerCounterPackedAddress24, 0x00000002, (unsigned int)g_Events_SpawnPositionedEffectPackedAddress24, 0x00000000, (unsigned int)g_Events_SetActorEffectModePackedAddress24, 0x00000000,
    (unsigned int)g_Events_DeactivateActorPackedAddress24, 0x00000000,
};
#endif

/* g_EventsDelivercontacteffectWords3_EventsDelivercontacteffectData.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800D0F00_unclaimed_D1BA0_unclaimed_D1E68_unclaimed_D1F78_unclaimed_D20A8 */
unsigned int g_EventsDelivercontacteffectWords3[2] = {
    0x3EDF9547, 0x3EDE6595,
};
#endif
