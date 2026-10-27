#include "include_asm.h"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "TEXTURE/80256220.H"
#include "COMMON/LISTNODE.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "SYSTEM_3/80265370.H"
#include "RENDER_4/8028FD2C_6.H"
extern void func_802598B4_de(ChannelSet *arg0, s32 arg1);

/* Stops every voice playing a sound id while holding the manager's recursive lock at 0x110: tells
 * func_802598B4_de about the id, then for each of the 17 voice records whose sound matches it counts the voice
 * and either resets the spare record 16 or clears the voice's pending flag and stops its channel through
 * Audio_StopVoiceSlot when it has a handle; returns the number of voices found (0 for id -1). Lock handling
 * adapted from Audio_StopAudioBySecondaryValue; the voice records are addressed by offset from the manager.
 */





#include "COMMON/EXTERNS_11.H"

extern void Audio_StopVoiceSlot(void *, s16);






s32 func_80257A14_de(void *context, s32 id) {
    void *contextLock;
    void *channelSet;
    s32 lockClaimCount;
    u32 mask;
    u32 releaseInterruptMask;
    s32 found;
    s32 i;
    Voice *voice;

    found = 0;
    if (id == -1) {
        return found;
    }
    contextLock = &((ContextRecAt2BC0 *)(context))->lock;
    mask = __osDisableInt();
    lockClaimCount = ((MenuRules *)(contextLock))->locked + 1;
    ((MenuRules *)(contextLock))->locked = lockClaimCount;
    if (lockClaimCount != 1) {
        __osRestoreInt(mask);
        osRecvMesg(contextLock, 0, 1);
        channelSet = &((ContextRecAt2BC0 *)(context))->view[0];
    } else {
        __osRestoreInt(mask);
        channelSet = &((ContextRecAt2BC0 *)(context))->view[0];
    }
    func_802598B4_de(channelSet, id);
    for (i = 0; i < 17; i++) {
        if (((ContextRecAt2BC0 *)context)->voices[i].sound == id) {
            found++;
            voice = &((ContextRecAt2BC0 *)context)->voices[i];
            if (i == 16) {
                voice->sound = -1;
                voice->priority = 0;
                voice->channel = -1;
                voice->unkC = -1;
                voice->unk8 = -1;
            } else {
                if (voice->pending > 0) {
                    voice->pending = 0;
                    voice->flags &= ~0x10;
                }
                if ((&((ContextCode8025A3EC *)context)->slots)[0].ids[i] != -1) {
                    Audio_StopVoiceSlot(&((ContextRecAt2BC0 *)(context))->menu[0], i);
                }
            }
        }
    }
    contextLock = &((ContextRecAt2BC0 *)(context))->lock;
    releaseInterruptMask = __osDisableInt();
    lockClaimCount = ((MenuRules *)(contextLock))->locked - 1;
    ((MenuRules *)(contextLock))->locked = lockClaimCount;
    if (lockClaimCount != 0) {
        __osRestoreInt(releaseInterruptMask);
        osSendMesg(contextLock, 0, 1);
    } else {
        __osRestoreInt(releaseInterruptMask);
    }
    return found;
}

#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "ENGINE/AUDIO/AUDIOWORLD.H"

extern void *Sky_FindNearestCamera(MenuMatchGlobals *, CVector3 *);
extern s32 Audio_HasVoiceWithKey(void *, s32);
extern f32 Audio_ComputeDistanceAttenuation(CVector3 *, void *);
extern s32 Audio_FindVoiceByKeyPair(void *, s32, s32);
extern s32 func_80259260_de(void *, Item57BD4 *, CVector3 *, s32, s32);

extern void *Channel_StartNoteVoice(void *, Item57BD4 *, s32, s32);
extern void Audio_SetVoicePositionTracking(void *, CVector3 *, s32);

extern void Audio_InitializeVoiceParameters(void *, Item57BD4 *, s32);
extern void Audio_UpdateSoundSlot(void *, void *, s32, CVector3 *);








s32 Audio_StartSoundRecord(void *context, Item57BD4 *soundRecord, CVector3 *position, s32 playbackValue,
                  s32 voiceUserData, s32 arg5, s32 trackedPosition) {
    void *node;

    ((ContextRecAt2BC0 *)(context))->field2B98 = Sky_FindNearestCamera(&D_80145088, position);
    if (soundRecord->flags & 1) {
        if (Audio_HasVoiceWithKey(&((ContextRecAt2BC0 *)(context))->menu[0], ((ContextRecAt2BC0 *)(context))->selectedSound) != 0) {
            return -1;
        }
        if (Audio_ComputeDistanceAttenuation(position, (char *)((ContextRecAt2BC0 *)(context))->field2B98 + 0x128) == 0.0f) {
            return -1;
        }
    }
    if ((soundRecord->flags & 0x1000) && ((ContextRecAt2BC0 *)(context))->selectedOwner != -1) {
        if (Audio_FindVoiceByKeyPair(&((ContextRecAt2BC0 *)(context))->menu[0], ((ContextRecAt2BC0 *)(context))->selectedSound,
                         ((ContextRecAt2BC0 *)(context))->selectedOwner) != -1) {
            return -1;
        }
    }
    if (soundRecord->field2 != 0) {
        return func_80259260_de(&((ContextRecAt2BC0 *)(context))->view[0], soundRecord, position, playbackValue, arg5);
    }
    if (soundRecord->flags & 0x40) {
        Audio_ReleaseMatchingExclusiveVoice(&((ContextRecAt2BC0 *)(context))->menu[0], ((ContextRecAt2BC0 *)(context))->selectedSound, soundRecord->field0);
    }
    node = Channel_StartNoteVoice(&((ContextRecAt2BC0 *)(context))->menu[0], soundRecord, playbackValue, voiceUserData);
    if (node == 0) {
        return -1;
    }
    Audio_SetVoicePositionTracking(node, position, trackedPosition);
    Audio_SetVoiceTrackId(node, ((ContextRecAt2BC0 *)(context))->selectedSound);
    Audio_InitializeVoiceParameters(node, soundRecord, arg5);

    {
        char *queue = &((ContextRecAt2BC0 *)(context))->lock;
        u32 token = __osDisableInt();
        s32 count = ((MenuRules *)(queue))->locked + 1;
        ((MenuRules *)(queue))->locked = count;
        if (count != 1) {
            __osRestoreInt(token);
            osRecvMesg(queue, 0, 1);
        } else {
            __osRestoreInt(token);
        }
    }
    Audio_UpdateSoundSlot(context, ((Draw *)(node))->model, 0, position);
    {
        char *queue = &((ContextRecAt2BC0 *)(context))->lock;
        u32 token = __osDisableInt();
        s32 count = ((MenuRules *)(queue))->locked - 1;
        ((MenuRules *)(queue))->locked = count;
        if (count != 0) {
            __osRestoreInt(token);
            osSendMesg(queue, 0, 1);
        } else {
            __osRestoreInt(token);
        }
    }
    return 0;
}

static inline void soundAcquireLock(MenuRules *lock) {
    u32 mask = __osDisableInt();
    s32 held = lock->locked + 1;
    lock->locked = held;
    if (held != 1) {
        __osRestoreInt(mask);
        osRecvMesg((OSMesgQueue *)lock, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
}

static inline void soundReleaseLock(MenuRules *lock) {
    u32 mask = __osDisableInt();
    s32 held = lock->locked - 1;
    lock->locked = held;
    if (held != 0) {
        __osRestoreInt(mask);
        osSendMesg((OSMesgQueue *)lock, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
}

typedef struct SoundVoiceGroup {
    s32 stride;
    u32 count;
} SoundVoiceGroup;

#include "COMMON/SELF.H"
/* The definition range is inclusive; weights are signed 32-bit entries. */
static inline s32 selectSoundVariant(ContextRecAt2BC0 *context, s32 sound, s16 avoidPrevious) {
    s32 first;
    s32 last;
    s32 total;
    s32 index;
    s32 i;
    s32 threshold;
    total = 0;
    if (context->instrumentCount != 0) {
        if (!func_80265550_de((u32 *)context->instrumentData, context->instrumentCount, (s16)sound, &first, &last)) {
            return -1;
        }
        index = first;
        if (index != last) {
            for (i = first; i <= last; i++) {
                total += context->envelopeData[i] * 10;
            }
            threshold = GraphU64_NextRandom() % total;
            total = 0;
            for (index = first; index < last; index++) {
                total += context->envelopeData[index] * 10;
                if (total >= threshold) {
                    break;
                }
            }
            if (avoidPrevious && index == context->lastInstrument) {
                if (index == last) {
                    index--;
                } else {
                    index++;
                }
            }
        }
        return index;
    }
    return -1;
}
static inline s32 soundVoiceLimitReached(ContextRecAt2BC0 *context, s32 sound) {
    s32 count;
    s32 i;
    if (context->selectedHandle != -1) {
        return 1;
    }
    count = 0;
    if (sound < 0x100) {
        for (i = 0; i < 17; i++) {
            if (context->voices[i].soundId == sound) {
                count++;
            }
        }
        if (count >= 6) {
            return 1;
        }
    }
    return 0;
}

/* Plays sound-bank entry `sound` at `position`: refuses while a handle is selected or when six voices
 * already play the same sound effect, picks a weighted random variant of the entry (sound effects below
 * 0x100 avoid repeating the previous variant and get a random pan), records the entry, sound and owner as
 * the current selection, hands out a play id under the recursive lock and starts every voice record of the
 * variant; returns the play id, or -1 when nothing was started. */
s32 Audio_PlaySoundAtPosition(ContextRecAt2BC0 *context, s32 sound, CVector3 position, s32 spatialMode, s32 owner) {
    SoundVoiceGroup *group;
    u32 count;
    u32 i;
    s32 index;
    s32 playId;

    if (soundVoiceLimitReached(context, sound)) {
        return -1;
    }
    if (sound < 0x100) {
        index = selectSoundVariant(context, sound, context->lastInstrument);
        context->randomPan = (s32)GraphU64_RandomFloat(127.0f);
    } else {
        index = selectSoundVariant(context, sound, 0);
    }
    if (index != -1) {
        context->selectedEntry = SetN64_GetPackSection(SetN64_GetPackSection(context->instrumentIndex, (s16)index), 0);
        context->selectedSound = sound;
        context->selectedOwner = owner;
        group = SetN64_GetPackSection(SetN64_GetPackSection(context->instrumentIndex, (s16)index), 1);
        count = group->count;
        if (count != 0) {
            soundAcquireLock(&context->lock);
            playId = ++context->playIdCounter;
            soundReleaseLock(&context->lock);
            if (sound < 0x100) {
                context->lastInstrument = index;
            }
        } else {
            playId = -1;
        }
        for (i = 0; i < count; i++) {
            Audio_StartSoundRecord(context, (Item57BD4 *)((u8 *)(group + 1) + i * group->stride), &position, index,
                                     playId, 0, spatialMode);
        }
        context->selectedOwner = -1;
        return playId;
    }
    return -1;
}

/* Starts a sound-bank entry: looks up the entry's record in the bank table at 0x2B4C, resets the current
 * selection (0x2B88/0x2B8C/0x2B90), takes the recursive lock at 0x110 to hand out a new play id (counter
 * at 0x10C), then starts every voice record of the entry through Audio_StartSoundRecord at the given position;
 * returns the play id, or -1 for an out-of-range index or an empty entry. */
s32 Audio_PlayInstrumentAtPosition(ContextRecAt2BC0 *self, s32 index, CVector3 position, s32 voiceParameter) {
    SoundVoiceGroup *group;
    u32 count;
    u32 i;
    s32 playId;
    if (index >= self->instrumentCount) {
        return -1;
    }
    self->selectedEntry = SetN64_GetPackSection(SetN64_GetPackSection(self->instrumentIndex, (s16)index), 0);
    self->selectedSound = 0x100;
    self->selectedOwner = -1;
    group = SetN64_GetPackSection(SetN64_GetPackSection(self->instrumentIndex, (s16)index), 1);
    count = group->count;
    if (count != 0) {
        soundAcquireLock(&self->lock);
        playId = ++self->playIdCounter;
        soundReleaseLock(&self->lock);
    } else {
        playId = -1;
    }
    for (i = 0; i < count; i++) {
        Audio_StartSoundRecord(self, (Item57BD4 *)((u8 *)(group + 1) + i * group->stride), &position, index, playId, 0, voiceParameter);
    }
    return playId;
}
