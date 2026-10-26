#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/S1.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/STATERECAT34.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_6.H"
#include "SYSTEM/80255C40_3.H"

void func_802B25D0_de(void *sound, short sample);

static inline short slot_id(Slots *slots, int index) {
    return slots->ids[index];
}

extern s32 SoundElement_PlaySoundAtPosition(s16 arg0, CVector3 position, s32 arg4, s32 arg5);


int func_8025C824_de(RecordRecAt4V4 *pool, short index) {
    SlotRecAtB4V2 *entry;
    ContextCode8025A3EC *context;
    Slots *slots;
    void *owner;

    entry = &pool->slots[index + 1];
    entry--;
    owner = entry->owner;
    context = owner;
    slots = &context->slots;
    func_802B25D0_de(entry->owner->sound, slot_id(slots, entry->index));
    slots->ids[entry->index] = -1;
    entry->priority = 0;
    entry->fieldC = -1;
    entry->used = -1;
    entry->value = -1;
    entry->channel = -1;
    entry->fieldB4 = -1;
    return 0;
}

/** Initialize the two object words at offsets 8 and 12 to negative one. */
void func_8025C8C0_de(void *cLoopingSoundData) {
    CLoopingSoundData *voice = cLoopingSoundData;
    voice->state = -1;
    voice->value = -1;
}

void func_8025C8D0_de(void) {
}

void func_8025C8D8_de(void *soundVoicePool, CLoopingSoundData *availableNodes, s32 nodeCount) {
    s32 i;

    func_80255CA0_de(soundVoicePool, 0, 4);
    func_80255CA0_de(&((SoundVoicePool *)soundVoicePool)->playing, 0, 4);
    i = 0;
    if (nodeCount > 0) {
        do {
            func_80255D14_de(soundVoicePool, availableNodes);
            i += 1;
            availableNodes = availableNodes + 1;
        } while (i < nodeCount);
    }
    ((SoundVoicePool *)soundVoicePool)->state = 0;
}

void *func_8025C95C_de(void *voicePool, s32 soundId, CVector3 *soundPosition, void *position, s32 fallback) {
    CLoopingSoundData *node;
    s32 result;

    node = ((SoundVoicePool *)voicePool)->available.head;
    if (node != 0) {
        func_80255ED8_de(voicePool, node);
        func_80255D14_de(&((SoundVoicePool *)voicePool)->playing, node);
        node->state = -1;
        node->value = -1;
        result = SoundElement_PlaySoundAtPosition((s16)soundId, *soundPosition,
                                (s32)position, fallback);
        node->value = result;
        D_800CBB10 = result;
        node->state = soundId;
        node->m_vSoundPos = *soundPosition;
        node->m_vSoundPosPtr = position;
    }
    return node;
}

s32 func_8025CA24_de(void *work, void *wantedNode) {
    void *playingNode;

    if (wantedNode == 0) {
        return 0;
    }

    playingNode = ((SoundVoicePool *)work)->playing.head;
    if (playingNode != 0) {
        do {
            if (playingNode == wantedNode) {
                func_8025E174_de(((CLoopingSoundData *)playingNode)->value);
                D_800CBB14 = ((CLoopingSoundData *)playingNode)->value;
                func_80255ED8_de(&((SoundVoicePool *)work)->playing, playingNode);
                func_80255D14_de(work, playingNode);
                return 1;
            }
            playingNode = ((CLoopingSoundData *)playingNode)->next;
        } while (playingNode != 0);
    }
    return 0;
}

void func_8025CAB0_de(void *voicePool) {
    s32 value;
    SoundVoicePool *pool = voicePool;
    CLoopingSoundData *playingNode;

    playingNode = pool->playing.head;
    if (playingNode != 0) {
        do {
            func_8025E174_de(playingNode->value);
            value = playingNode->value;
            playingNode = playingNode->next;
            D_800CBB18 = value;
        } while (playingNode != 0);
    }
    pool->state = 1;
}

void func_8025CB0C_de(SoundVoicePool *soundVoicePool) {
    s32 playbackHandle;
    CLoopingSoundData *playingNode;

    playingNode = soundVoicePool->playing.head;
    if (playingNode != 0) {
        do {
            playbackHandle = SoundElement_PlaySoundAtPosition((s16)playingNode->state,
                                     playingNode->m_vSoundPos,
                                     (s32)playingNode->m_vSoundPosPtr,
                                     -1);
            playingNode->value = playbackHandle;
            playingNode = playingNode->next;
            D_800CBB1C = playbackHandle;
        } while (playingNode != 0);
    }
    soundVoicePool->state = 0;
}

void func_8025CB88_de(void *soundVoicePool) {
    SoundVoicePool *pool = soundVoicePool;
    CLoopingSoundData *playingNode;

    if (pool->state == 0) {
        playingNode = pool->playing.head;
        if (playingNode != 0) {
            do {
                if (func_8025E0F4_de(playingNode->value) == 0) {
                    playingNode->state = -1;
                    playingNode->value = -1;
                }
                playingNode = playingNode->next;
            } while (playingNode != 0);
        }
    }
}

void func_8025CBEC_de(void *soundVoicePool) {
    CLoopingSoundData *cur;
    CLoopingSoundData *next;
    s32 value;
    SoundVoicePool *pool = soundVoicePool;

    cur = pool->playing.head;
    if (cur != 0) {
        do {
            value = cur->value;
            next = cur->next;
            func_8025E174_de(value);
            cur->state = -1;
            cur->value = -1;
            func_80255ED8_de(&pool->playing, cur);
            func_80255D14_de(&pool->available, cur);
            cur = next;
        } while (cur != 0);
    }
}
