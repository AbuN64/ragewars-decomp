#ifndef COMMON_EXTERNS_H
#define COMMON_EXTERNS_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"



#include "COMMON/SHAREDPLAYER.H"
extern void Audio_ResolveInstrumentSectionZero(void *arg0, s16 index);

#include "COMMON/LISTNODE.H"
extern int Audio_IsSoundInstanceLimitReached(ObjRecAt1E64 *obj, int id);

#include "COMMON/RESIDENT_EVENT_HANDLER.H"




extern void AudioWorld_RecyclePendingSoundsByKey(void *channelOwner, s32 matchingKey);
extern void AudioWorld_RecyclePendingSoundsByTrack(struct OwnerRecAtD8 *, s32);

extern void alSndpSetPriority(char *, s32, s32);
extern void alSndpSetFXMix(char *, s32);

#include "COMMON/VECTOR4F.H"

extern s32 D_800CBB50_de;
extern s32 D_800CBB54;
extern f32 D_800C3FD0_de;
extern f32 D_800C3FD8_de;
extern f32 D_800C3FE0_de;
extern f32 D_800C3FE4;
extern f32 D_800C3FE8_de;
extern f32 D_800C3FEC_de;
extern f32 D_800C3FF0_de;
#endif
