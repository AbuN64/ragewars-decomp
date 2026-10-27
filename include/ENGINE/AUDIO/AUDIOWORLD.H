#ifndef ENGINE_AUDIO_AUDIOWORLD_H
#define ENGINE_AUDIO_AUDIOWORLD_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LISTNODE.H"
#include "AUDIO/80259280.H"

extern void func_802598B4_de(struct ChannelSet *arg0, s32 arg1);
extern void AudioWorld_StartSpatialVoice(ManagerRecAtD8V2 *manager, s32 index, s32 owner, CVector3 *position);
extern void func_8025966C_de(void *sentinel, s32 owner);
extern void *AudioWorld_UnlinkChannelNode(LinkPair *channelNode);
extern void func_80259988_de(void *channelOwner, s32 matchingKey);
extern void func_802599EC_de(OwnerRecAtD8 *listNode, s32 matchingValue);
#endif
