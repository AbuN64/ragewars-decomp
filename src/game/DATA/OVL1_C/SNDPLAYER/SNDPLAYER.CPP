#include "TYPES.H"

/* DATA_800CC764.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_SndplayerEncodedWords[3] = {
    0xFFFF0000, 0x06A503E8, 0x06A601F4,
};
#endif

/* DATA_800CC890.CPP */
#if defined(VERSION_EU)
extern char g_Events_PlayClipEventAddress[];
extern char D_002673A4[];
extern char g_Events_SpawnActorEffectAddress[];
extern char g_Events_ApplyDirectDamageAddress[];
extern char g_packedCodeAddress24_00267B78[];
extern char g_Events_ApplyRadialDamageWithKnockbackAddress[];
extern char g_Events_PreserveEventArgumentAddress[];
extern char g_packedCodeAddress24_00267C30[];
extern char g_Events_RunSecondNodeOperationAddress[];
extern char D_00267C94[];
extern char g_Events_ConsumeEventArgumentAddress[];
extern char g_Events_RequestActorPositionAddress[];
extern char g_Events_StartEnabledCameraEmitterAddress[];
extern char g_Events_StartDisabledCameraEmitterAddress[];
extern char g_Events_PostGameplayMessageAddress[];
extern char g_Events_ApplyFlag100RadialDamageAddress[];
extern char g_Events_ApplyFlag100RadialKnockbackAddress[];
extern char g_Events_ApplyFlag200RadialDamageAddress[];
extern char g_Events_ApplyFlag200RadialKnockbackAddress[];
extern char g_Events_ApplyFlag400RadialDamageAddress[];
extern char g_Events_ApplyFlag400RadialKnockbackAddress[];
extern char g_Events_StartActorEmitterAddress[];
extern char g_Events_IgnoreEventAddress[];
extern char g_Events_PlayTeamClipAddress[];
extern char g_Events_SpawnFilteredActorEffectAddress[];
extern char g_Events_FireWithinHeightRangeAddress[];
extern char g_Events_SetActorEventBitAddress[];
extern char D_002684B0[];
extern char g_Events_SpawnAttachedEffectAddress[];
extern char g_Events_SpawnPositionedEffectAddress[];
extern char g_Events_PlayTeamEffectAddress[];
extern char g_Events_SetActorLoopingSoundAddress[];
extern char g_packedCodeAddress24_00268864[];
extern char g_Events_IncrementNearbyPlayerCounterAddress[];
extern char g_Events_SetActorEffectModeAddress[];
extern char g_Events_DeactivateActorAddress[];
u32 data_unresolved_800CC890[428] = {
    0xFFFFFF00, 0xFFFFFF00, 0x00007F00, 0x00000000, 0xD9000000, 0x00000000,
    0xD9FFFFFF, 0x00000001, 0xDB020000, 0x00000018, 0xDC08060A, 0x800CC878,
    0xDC08090A, 0x800CC870, 0xDF000000, 0x00000000, 0xE3000A01, 0x00000000,
    0xE3000800, 0x00000000, 0xE3000F00, 0x00000000, 0xE3001001, 0x00000000,
    0xE3000D01, 0x00000000, 0xE3000C00, 0x00080000, 0xE3001201, 0x00002000,
    0xE3001402, 0x00000C00, 0xE3001700, 0x00000000, 0xE2001E01, 0x00000000,
    0xE7000000, 0x00000000, 0xDF000000, 0x00000000, 0xF5100000, 0x07000000,
    0xF3000000, 0x0755C000, 0xF5101000, 0x00014050, 0xF2000000, 0x0007C07C,
    0xF5100900, 0x01010441, 0xF2000000, 0x0103C03C, 0xF5100540, 0x0200C832,
    0xF2000000, 0x0201C01C, 0xF5100350, 0x03008C23, 0xF2000000, 0x0300C00C,
    0xF5100354, 0x04005014, 0xF2000000, 0x04004004, 0xF5100356, 0x05001405,
    0xF2000000, 0x05000000, 0xE3001001, 0x00000000, 0xDF000000, 0x00000000,
    0xF5100000, 0x07000000, 0xF3000000, 0x0755C000, 0xF5101000, 0x00054150,
    0xF2000000, 0x0007C07C, 0xF5100900, 0x01050541, 0xF2000000, 0x0103C03C,
    0xF5100540, 0x0204C932, 0xF2000000, 0x0201C01C, 0xF5100350, 0x03048D23,
    0xF2000000, 0x0300C00C, 0xF5100354, 0x04045114, 0xF2000000, 0x04004004,
    0xF5100356, 0x05041505, 0xF2000000, 0x05000000, 0xE3001001, 0x00000000,
    0xDF000000, 0x00000000, 0xF5100000, 0x07000000, 0xF3000000, 0x0755C000,
    0xF5101000, 0x00017C5F, 0xF2000000, 0x0007C07C, 0xF5101000, 0x01014050,
    0xF2000000, 0x0107C07C, 0xF5100900, 0x02010441, 0xF2000000, 0x0203C03C,
    0xF5100540, 0x0300C832, 0xF2000000, 0x0301C01C, 0xF5100350, 0x04008C23,
    0xF2000000, 0x0400C00C, 0xF5100354, 0x05005014, 0xF2000000, 0x05004004,
    0xF5100356, 0x06001405, 0xF2000000, 0x06000000, 0xE3000D01, 0x00040000,
    0xE3001001, 0x00000000, 0xDF000000, 0x00000000, 0xF5100000, 0x07000000,
    0xF3000000, 0x0755C000, 0xF5101000, 0x0001785E, 0xF2000000, 0x0007C07C,
    0xF5101000, 0x01014050, 0xF2000000, 0x0107C07C, 0xF5100900, 0x02010441,
    0xF2000000, 0x0203C03C, 0xF5100540, 0x0300C832, 0xF2000000, 0x0301C01C,
    0xF5100350, 0x04008C23, 0xF2000000, 0x0400C00C, 0xF5100354, 0x05005014,
    0xF2000000, 0x05004004, 0xF5100356, 0x06001405, 0xF2000000, 0x06000000,
    0xE3000D01, 0x00040000, 0xE3001001, 0x00000000, 0xDF000000, 0x00000000,
    0xF5900000, 0x07000000, 0xF3000000, 0x07580000, 0xF5800800, 0x00018060,
    0xF2000000, 0x000FC0FC, 0xF5800500, 0x01014451, 0xF2000000, 0x0107C07C,
    0xF5800340, 0x02010842, 0xF2000000, 0x0203C03C, 0xF5800350, 0x0300CC33,
    0xF2000000, 0x0301C01C, 0xF5800358, 0x04009024, 0xF2000000, 0x0400C00C,
    0xF580035C, 0x05005415, 0xF2000000, 0x05004004, 0xF580035E, 0x06001806,
    0xF2000000, 0x06000000, 0xE3000D01, 0x00000000, 0xE3001001, 0x00000000,
    0xDF000000, 0x00000000, 0xE3001001, 0x00000000, 0xD7000002, 0x80008000,
    0xD9F9FBFF, 0x00000000, 0xD9FFFFFF, 0x00210004, 0xFCFF97FF, 0xFFFFFE38,
    0xE200001C, 0xC8104B50, 0xDB040004, 0x00000001, 0xDB04000C, 0x00000001,
    0xDB040014, 0x0000FFFF, 0xDB04001C, 0x0000FFFF, 0x01004008, 0x801528E0,
    0x06000204, 0x00040600, 0xDB040004, 0x00000005, 0xDB04000C, 0x00000005,
    0xDB040014, 0x0000FFFB, 0xDB04001C, 0x0000FFFB, 0xDF000000, 0x00000000,
    0xE3001001, 0x00000000, 0xD7FF0002, 0x80008000, 0xD9F9FBFF, 0x00000000,
    0xD9FFFFFF, 0x00210004, 0xFCFF97FF, 0xFFFFFE38, 0xE200001C, 0xC8104E50,
    0xDB040004, 0x00000001, 0xDB04000C, 0x00000001, 0xDB040014, 0x0000FFFF,
    0xDB04001C, 0x0000FFFF, 0x01004008, 0x801528E0, 0x06000204, 0x00040600,
    0xDB040004, 0x00000005, 0xDB04000C, 0x00000005, 0xDB040014, 0x0000FFFB,
    0xDB04001C, 0x0000FFFB, 0xDF000000, 0x00000000, 0x524F4752, 0x414D4D41,
    (unsigned int)g_Events_PlayClipEventAddress, 0x00000000, (unsigned int)g_Events_SpawnActorEffectAddress, 0x00000000, (unsigned int)g_Events_ApplyDirectDamageAddress, 0x00000004,
    (unsigned int)g_packedCodeAddress24_00267B78, 0x00000006, (unsigned int)g_Events_ApplyRadialDamageWithKnockbackAddress, 0x00000006, (unsigned int)g_Events_PreserveEventArgumentAddress, 0x0000000A,
    (unsigned int)g_packedCodeAddress24_00267C30, 0x00000010, (unsigned int)g_Events_RunSecondNodeOperationAddress, 0x00000010, (unsigned int)g_Events_SpawnActorEffectAddress, 0x00000000,
    (unsigned int)D_00267C94, 0x00000000, (unsigned int)g_Events_ConsumeEventArgumentAddress, 0x00000000, (unsigned int)g_Events_RequestActorPositionAddress, 0x00000000,
    (unsigned int)g_Events_StartEnabledCameraEmitterAddress, 0x00000000, (unsigned int)g_Events_StartDisabledCameraEmitterAddress, 0x00000000, (unsigned int)g_Events_PostGameplayMessageAddress, 0x00000000,
    (unsigned int)g_Events_ApplyFlag100RadialDamageAddress, 0x00000006, (unsigned int)g_Events_ApplyFlag100RadialKnockbackAddress, 0x00000006, (unsigned int)g_Events_ApplyFlag200RadialDamageAddress, 0x00000007,
    (unsigned int)g_Events_ApplyFlag200RadialKnockbackAddress, 0x00000007, (unsigned int)g_Events_ApplyFlag400RadialDamageAddress, 0x00000006, (unsigned int)g_Events_ApplyFlag400RadialKnockbackAddress, 0x00000006,
    (unsigned int)g_Events_StartActorEmitterAddress, 0x00000000, (unsigned int)g_Events_IgnoreEventAddress, 0x00000000, (unsigned int)g_Events_PlayTeamClipAddress, 0x00000000,
    (unsigned int)g_Events_SpawnFilteredActorEffectAddress, 0x00000000, (unsigned int)g_Events_FireWithinHeightRangeAddress, 0x00000007, (unsigned int)g_Events_SetActorEventBitAddress, 0x00000000,
    (unsigned int)D_002684B0, 0x00000000, (unsigned int)g_Events_SpawnAttachedEffectAddress, 0x00000000, (unsigned int)g_Events_PlayTeamEffectAddress, 0x00000000,
    (unsigned int)D_002673A4, 0x00000000, (unsigned int)g_Events_SetActorLoopingSoundAddress, 0x00000000, (unsigned int)g_packedCodeAddress24_00268864, 0x00000000,
    (unsigned int)g_Events_IncrementNearbyPlayerCounterAddress, 0x00000002, (unsigned int)g_Events_SpawnPositionedEffectAddress, 0x00000000, (unsigned int)g_Events_SetActorEffectModeAddress, 0x00000000,
    (unsigned int)g_Events_DeactivateActorAddress, 0x00000000, 0x43544555, 0x52204445, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00071115, 0x15110700, 0x00000000,
    0x00000003, 0x1529363E, 0x3E362815, 0x03000000, 0x0000031C, 0x3550626E,
    0x6E625038, 0x1C010000, 0x00001738, 0x5879919F, 0x9E927959, 0x36170000,
    0x00082850, 0x799FBDCE, 0xCEBE9F79, 0x4E290800, 0x00113662, 0x91BEDFF2,
    0xF2E0BD92, 0x62361000, 0x00173E6E, 0x9FCEF2FF, 0xFFF3CE9F, 0x6D3E1500,
    0x00173D6E, 0xA1CDF2FF, 0xFFF3CE9F, 0x6D401700, 0x00103662, 0x92BEDFF3,
    0xF2E0BE92, 0x62361100, 0x00072850, 0x799FBDCF, 0xCEBE9F78, 0x4E290700,
    0x00001736, 0x597A92A1, 0x9F927958, 0x36150000, 0x0000031C, 0x3650646E,
    0x6E644E36, 0x1C010000, 0x00000003, 0x1528363E, 0x3D362815, 0x03000000,
    0x00000000, 0x00071015, 0x15110700, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000,
};
#endif

/* DATA_800CC9E8.CPP */
#if defined(VERSION_EU_X)
unsigned int k_SndplayerEncodedWords[17] = {
    0x3FC62F13, 0x3FC60F08, 0x00000000, 0x00000000, 0x800C9D40, 0x800C9B8C, 0x800C9810, 0x00000000,
    0x800C99C0, 0x800C9A80, 0x00000000, 0x800C9C10, 0x800C98D4, 0x00000000, 0x00000000, 0x00000000,
    0x00000000,
};
#endif
