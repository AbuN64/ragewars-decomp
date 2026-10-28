#ifndef ENGINE_AUDIO_AUDIOWORLD_H
#define ENGINE_AUDIO_AUDIOWORLD_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LISTNODE.H"
#include "AUDIO/LIST_AND_CHANNEL_VIEWS.H"

extern void AudioWorld_RecyclePendingSoundsByIdentifier(struct ChannelSet *channelSet, s32 soundId);
extern void AudioWorld_StartSpatialVoice(ManagerRecAtD8V2 *manager, s32 index, s32 owner, CVector3 *position);
extern void AudioWorld_InitializeVoiceListSentinel(void *sentinel, s32 owner);
extern void *AudioWorld_UnlinkChannelNode(LinkPair *channelNode);
extern void AudioWorld_RecyclePendingSoundsByKey(void *channelOwner, s32 matchingKey);
extern void AudioWorld_RecyclePendingSoundsByTrack(OwnerRecAtD8 *listNode, s32 matchingValue);
#endif
