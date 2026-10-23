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
 * func_8025BA9C_de when it has a handle; returns the number of voices found (0 for id -1). Lock handling
 * adapted from func_802588D4_de; the voice records are addressed by offset from the manager.
 */





extern u32 func_802BCF30_de(void);

extern void func_8025BA9C_de(void *, s16);






s32 func_80257A14_de(void *arg0, s32 id) {
    void *temp_s0;
    void *var_a0;
    s32 temp_v1;
    u32 mask;
    u32 temp_v0;
    s32 found;
    s32 i;
    Voice *voice;

    found = 0;
    if (id == -1) {
        return found;
    }
    temp_s0 = &((ContextRecAt2BC0 *)(arg0))->lock;
    mask = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(mask);
        func_802BB2A0_de(temp_s0, 0, 1);
        var_a0 = &((ContextRecAt2BC0 *)(arg0))->view[0];
    } else {
        __osRestoreInt(mask);
        var_a0 = &((ContextRecAt2BC0 *)(arg0))->view[0];
    }
    func_802598B4_de(var_a0, id);
    for (i = 0; i < 17; i++) {
        if (((ContextRecAt2BC0 *)arg0)->voices[i].sound == id) {
            found++;
            voice = &((ContextRecAt2BC0 *)arg0)->voices[i];
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
                if ((&((ContextCode8025A3EC *)arg0)->slots)[0].ids[i] != -1) {
                    func_8025BA9C_de(&((ContextRecAt2BC0 *)(arg0))->menu[0], i);
                }
            }
        }
    }
    temp_s0 = &((ContextRecAt2BC0 *)(arg0))->lock;
    temp_v0 = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 0) {
        __osRestoreInt(temp_v0);
        func_802BB420_de(temp_s0, 0, 1);
    } else {
        __osRestoreInt(temp_v0);
    }
    return found;
}

#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "AUDIO/80259280_5.H"

extern void *func_802395A4_de(MenuMatchGlobals *, CVector3 *);
extern s32 func_8025BA4C_de(void *, s32);
extern f32 func_8025C10C_de(CVector3 *, void *);
extern s32 func_8025BDAC_de(void *, s32, s32);
extern s32 func_80259260_de(void *, Item57BD4 *, CVector3 *, s32, s32);

extern void *Audio_StartNoteVoice(void *, Item57BD4 *, s32, s32);
extern void func_8025BB5C_de(void *, CVector3 *, s32);

extern void func_8025BB84_de(void *, Item57BD4 *, s32);
extern void Texture_UpdateSoundSlot(void *, void *, s32, CVector3 *);
extern u32 func_802BCF30_de(void);








s32 func_80257BB4_de(void *arg0, Item57BD4 *arg1, CVector3 *arg2, s32 arg3,
                  s32 arg4, s32 arg5, s32 arg6) {
    void *node;

    ((ContextRecAt2BC0 *)(arg0))->field2B98 = func_802395A4_de(&D_80145088, arg2);
    if (arg1->flags & 1) {
        if (func_8025BA4C_de(&((ContextRecAt2BC0 *)(arg0))->menu[0], ((ContextRecAt2BC0 *)(arg0))->field2B8C) != 0) {
            return -1;
        }
        if (func_8025C10C_de(arg2, (char *)((ContextRecAt2BC0 *)(arg0))->field2B98 + 0x128) == 0.0f) {
            return -1;
        }
    }
    if ((arg1->flags & 0x1000) && ((ContextRecAt2BC0 *)(arg0))->field2B90 != -1) {
        if (func_8025BDAC_de(&((ContextRecAt2BC0 *)(arg0))->menu[0], ((ContextRecAt2BC0 *)(arg0))->field2B8C,
                         ((ContextRecAt2BC0 *)(arg0))->field2B90) != -1) {
            return -1;
        }
    }
    if (arg1->field2 != 0) {
        return func_80259260_de(&((ContextRecAt2BC0 *)(arg0))->view[0], arg1, arg2, arg3, arg5);
    }
    if (arg1->flags & 0x40) {
        func_8025B920_de(&((ContextRecAt2BC0 *)(arg0))->menu[0], ((ContextRecAt2BC0 *)(arg0))->field2B8C, arg1->field0);
    }
    node = Audio_StartNoteVoice(&((ContextRecAt2BC0 *)(arg0))->menu[0], arg1, arg3, arg4);
    if (node == 0) {
        return -1;
    }
    func_8025BB5C_de(node, arg2, arg6);
    func_8025BB7C_de(node, ((ContextRecAt2BC0 *)(arg0))->field2B8C);
    func_8025BB84_de(node, arg1, arg5);

    {
        char *queue = &((ContextRecAt2BC0 *)(arg0))->lock;
        u32 token = func_802BCF30_de();
        s32 count = ((MenuRules *)(queue))->locked + 1;
        ((MenuRules *)(queue))->locked = count;
        if (count != 1) {
            __osRestoreInt(token);
            func_802BB2A0_de(queue, 0, 1);
        } else {
            __osRestoreInt(token);
        }
    }
    Texture_UpdateSoundSlot(arg0, ((Draw *)(node))->model, 0, arg2);
    {
        char *queue = &((ContextRecAt2BC0 *)(arg0))->lock;
        u32 token = func_802BCF30_de();
        s32 count = ((MenuRules *)(queue))->locked - 1;
        ((MenuRules *)(queue))->locked = count;
        if (count != 0) {
            __osRestoreInt(token);
            func_802BB420_de(queue, 0, 1);
        } else {
            __osRestoreInt(token);
        }
    }
    return 0;
}

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_11.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/SELF.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/TRIPLE.H"
#include "stddef.h"
#include "TYPES.H"
s32 func_80257BB4_de(void *arg0, Item57BD4 *arg1, CVector3 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
/* The definition range is inclusive; weights are signed 32-bit entries. */
static inline s32 selectSoundVariant(ContextRecAt2BC0 *context, s32 sound, u16 avoidPrevious) {
    s32 first;
    s32 last;
    s32 total = 0;
    s32 index;
    s32 threshold;
    s32 *weights;

    if (context->instrumentCount == 0 ||
        !func_80265550_de((u32 *)context->instrumentData, context->instrumentCount,
                         (u32)(s16)sound, &first, &last)) {
        return -1;
    }
    if (first == last) {
        return first;
    }
    if (first <= last) {
        weights = &context->envelopeData[first];
        for (index = first; index <= last; index++) total += *weights++ * 10;
    }
    threshold = func_802744D4_de() % total;
    total = 0;
    index = first;
    if (index < last) {
        weights = &context->envelopeData[index];
        for (; index < last; index++, weights++) {
            total += *weights * 10;
            if (total >= threshold) {
                break;
            }
        }
    }
    if ((s16)avoidPrevious && index == context->lastInstrument) {
        if (index != last) {
            index++;
        } else {
            index--;
        }
    }
    return index;
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

static inline void soundAcquireLock(MenuRules *lock) {
    u32 mask = func_802BCF30_de();
    s32 held = lock->locked + 1;
    lock->locked = held;
    if (held != 1) {
        __osRestoreInt(mask);
        func_802BB2A0_de((OSMesgQueue *)lock, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
}

static inline void soundReleaseLock(MenuRules *lock) {
    u32 mask = func_802BCF30_de();
    s32 held = lock->locked - 1;
    lock->locked = held;
    if (held != 0) {
        __osRestoreInt(mask);
        func_802BB420_de((OSMesgQueue *)lock, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
}

typedef struct SoundVoiceGroup {
    s32 stride;
    u32 count;
} SoundVoiceGroup;

/* 91/294 aligned edits remain in register allocation and selection branches. */
s32 Texture_PlaySoundAtPosition(void *memory, s32 sound, CVector3 position, s32 spatialMode, s32 owner) {
    ContextRecAt2BC0 *context = memory;
    SoundVoiceGroup *group;
    u32 count;
    u32 i;
    s32 index;
    s32 playId;

    if (soundVoiceLimitReached(context, sound)) {
        return -1;
    }
    {
        if (sound < 0x100) {
            index = selectSoundVariant(context, sound, (u16)context->lastInstrument);
            context->field2B94 = (s8)(s32)func_80274564_de(D_800C3EDC_de);
        } else {
            index = selectSoundVariant(context, sound, 0);
        }
        if (index != -1) {
            context->field2B88 = func_8028FDB4_de(func_8028FDB4_de(context->instrumentIndex, (s16)index), 0);
            context->field2B8C = sound;
            context->field2B90 = owner;
            group = func_8028FDB4_de(func_8028FDB4_de(context->instrumentIndex, (s16)index), 1);
            count = group->count;
            playId = -1;
            if (count != 0) {
                soundAcquireLock(&context->lock);
                playId = ++context->playIdCounter;
                soundReleaseLock(&context->lock);
                if (sound < 0x100) {
                    context->lastInstrument = index;
                }
            }
            for (i = 0; i < count; i++) {
                func_80257BB4_de(context, (Item57BD4 *)((u8 *)(group + 1) + i * group->stride),
                                &position, index, playId, 0, spatialMode);
            }
            context->field2B90 = -1;
            return playId;
        }
    }
    return -1;
}


#else
INCLUDE_ASM("span_1000", Texture_PlaySoundAtPosition);
#endif

#ifdef NON_MATCHING
/* Starts a sound-bank entry: looks up the entry's record in the bank table at 0x2B4C, resets the current
 * selection (0x2B88/0x2B8C/0x2B90), takes the recursive lock at 0x110 to hand out a new play id (counter
 * at 0x10C), then starts every voice record of the entry through func_80257BB4_de at the given position;
 * returns the play id, or -1 for an out-of-range index or an empty entry. */
s32 Texture_PlayInstrumentAtPosition(ContextRecAt2BC0 *self, s32 index, CVector3 position, s32 voiceParameter) {
    u32 *entry;
    u32 count;
    u32 i;
    s32 playId = -1;
    if (index >= self->instrumentCount) {
        return -1;
    }
    self->field2B88 = func_8028FDB4_de(func_8028FDB4_de(self->instrumentIndex, (s16)index), 0);
    self->field2B8C = 0x100;
    self->field2B90 = -1;
    entry = func_8028FDB4_de(func_8028FDB4_de(self->instrumentIndex, (s16)index), 1);
    count = entry[1];
    if (count != 0) {
        {
            char *queue = &self->lock;
            u32 token = func_802BCF30_de();
            s32 held = ((MenuRules *)(queue))->locked + 1;
            ((MenuRules *)(queue))->locked = held;
            if (held != 1) {
                __osRestoreInt(token);
                func_802BB2A0_de(queue, 0, 1);
            } else {
                __osRestoreInt(token);
            }
        }
        playId = *(s32 *)((char *)self + 0x10C) + 1;
        {
            char *queue = &self->lock;
            u32 token;
            s32 held;
            *(s32 *)((char *)self + 0x10C) = playId;
            token = func_802BCF30_de();
            held = ((MenuRules *)(queue))->locked - 1;
            ((MenuRules *)(queue))->locked = held;
            if (held != 0) {
                __osRestoreInt(token);
                func_802BB420_de(queue, 0, 1);
            } else {
                __osRestoreInt(token);
            }
        }
    }
    if (count != 0) {
        for (i = 0; i < count; i++) {
            func_80257BB4_de(self, (Item57BD4 *)((char *)entry + 8 + i * entry[0]), &position, index, playId, 0, voiceParameter);
        }
    }
    return playId;
}
#else
INCLUDE_ASM("span_1000", Texture_PlayInstrumentAtPosition);
#endif
