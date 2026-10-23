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
s32 Texture_PlaySoundAtPosition(void *context, s32 soundId, u32 positionXBits, u32 positionYBits, u32 positionZBits, s32 voiceParameter, s32 ownerId) {
    union { u32 word; f32 value; } xbits, ybits, zbits;
    CVector3 position;
    s32 firstSoundVariant;
    s32 lastSoundVariant;
    s32 firstInstrumentVariant;
    s32 lastInstrumentVariant;
    MenuRules *lock;
    MenuRules *unlock;
    s32 *soundWeightCursor;
    s32 *soundChoiceCursor;
    s32 *instrumentWeightCursor;
    s32 *instrumentChoiceCursor;
    s32 soundChoice;
    s32 instrumentChoice;
    s32 entryOffset;
    s32 soundWeight;
    s32 instrumentWeight;
    s32 lockCount;
    s32 remainingLocks;
    s32 i;
    s32 j;
    s32 soundWeightIndex;
    s32 instrumentWeightIndex;
    s32 soundVariant;
    s32 k;
    s32 instrumentVariant;
    s32 totalSoundWeight;
    s32 cumulativeSoundWeight;
    s32 totalInstrumentWeight;
    s32 cumulativeInstrumentWeight;
    s32 selectedVariant;
    s32 playId;
    s32 result;
    s32 repeatGuardBits;
    s32 isSound;
    s32 blocked;
    s8 *entries;
    u16 repeatGuard;
    u32 mask;
    u32 entryCount;
    u32 unlockMask;
    u32 l;
    void *voiceCursor;

    xbits.word = positionXBits; ybits.word = positionYBits; zbits.word = positionZBits;
    position.x = xbits.value; position.y = ybits.value; position.z = zbits.value;

    if (((ContextRecAt2BC0 *)context)->selectedHandle != -1) {
        blocked = 1;
    } else {
        j = 0;
        if (soundId < 0x100) {
            i = 0;
            voiceCursor = context;
            do {
                if (((s32 *) voiceCursor)[7780 / sizeof(s32)] == soundId) {
                    j += 1;
                }
                i += 1;
                voiceCursor += 0xCC;
            } while (i < 0x11);
            blocked = 1;
            if (j < 6) {
                goto allowSound;
            }
        } else {
allowSound:
            blocked = 0;
        }
    }
    result = -1;
    if (blocked == 0) {
        if (soundId < 0x100) {
            repeatGuard = ((u16 *) context)[306 / sizeof(u16)];
            totalSoundWeight = 0;
            if ((((ContextRecAt2BC0 *)context)->instrumentCount != 0) && (func_80265550_de((u32 *)((ContextRecAt2BC0 *)context)->instrumentData, ((ContextRecAt2BC0 *)context)->instrumentCount, (u32) (s16) soundId, &firstSoundVariant, &lastSoundVariant) != 0)) {
                soundVariant = firstSoundVariant;
                if (soundVariant != lastSoundVariant) {
                    soundWeightIndex = soundVariant;
                    if (lastSoundVariant >= soundVariant) {
                        soundWeightCursor = (soundVariant * 4) + (s32)((ContextRecAt2BC0 *)context)->envelopeData;
                        do {
                            soundWeight = *soundWeightCursor;
                            soundWeightCursor += 4;
                            soundWeightIndex += 1;
                            totalSoundWeight += soundWeight * 0xA;
                        } while (lastSoundVariant >= soundWeightIndex);
                    }
                    soundChoice = func_802744D4_de() % totalSoundWeight;
                    k = firstSoundVariant;
                    cumulativeSoundWeight = 0;
                    if (k < lastSoundVariant) {
                        soundChoiceCursor = (k * 4) + (s32)((ContextRecAt2BC0 *)context)->envelopeData;
selectSoundVariant:
                        cumulativeSoundWeight += *soundChoiceCursor * 0xA;
                        repeatGuardBits = repeatGuard << 0x10;
                        if (cumulativeSoundWeight < soundChoice) {
                            k += 1;
                            soundChoiceCursor += 4;
                            if (k >= lastSoundVariant) {
                                goto finishSoundSelection;
                            }
                            goto selectSoundVariant;
                        }
                    } else {
finishSoundSelection:
                        repeatGuardBits = repeatGuard << 0x10;
                    }
                    selectedVariant = k;
                    if ((repeatGuardBits != 0) && (k == ((s32 *) context)[304 / sizeof(s32)])) {
                        if (k != lastSoundVariant) {
                            soundVariant = k + 1;
                        } else {
                            soundVariant = k - 1;
                        }
                        goto useAdjacentVariant;
                    }
                } else {
useAdjacentVariant:
                    selectedVariant = soundVariant;
                }
            } else {
                selectedVariant = -1;
            }
            ((ContextRecAt2BC0 *)context)->field2B94 = (s8) (s32) func_80274564_de(D_800C3EDC_de);
        } else {
            totalInstrumentWeight = 0;
            if (((ContextRecAt2BC0 *)context)->instrumentCount != 0) {
                selectedVariant = -1;
                if (func_80265550_de((u32 *)((ContextRecAt2BC0 *)context)->instrumentData, ((ContextRecAt2BC0 *)context)->instrumentCount, (u32) (s16) soundId, &firstInstrumentVariant, &lastInstrumentVariant) != 0) {
                    instrumentVariant = firstInstrumentVariant;
                    if (instrumentVariant != lastInstrumentVariant) {
                        instrumentWeightIndex = instrumentVariant;
                        if (lastInstrumentVariant >= instrumentVariant) {
                            instrumentWeightCursor = (instrumentVariant * 4) + (s32)((ContextRecAt2BC0 *)context)->envelopeData;
                            do {
                                instrumentWeight = *instrumentWeightCursor;
                                instrumentWeightCursor += 4;
                                instrumentWeightIndex += 1;
                                totalInstrumentWeight += instrumentWeight * 0xA;
                            } while (lastInstrumentVariant >= instrumentWeightIndex);
                        }
                        instrumentChoice = func_802744D4_de() % totalInstrumentWeight;
                        instrumentVariant = firstInstrumentVariant;
                        cumulativeInstrumentWeight = 0;
                        if (instrumentVariant < lastInstrumentVariant) {
                            instrumentChoiceCursor = (instrumentVariant * 4) + (s32)((ContextRecAt2BC0 *)context)->envelopeData;
selectInstrumentVariant:
                            cumulativeInstrumentWeight += *instrumentChoiceCursor * 0xA;
                            selectedVariant = instrumentVariant;
                            if (cumulativeInstrumentWeight < instrumentChoice) {
                                instrumentVariant += 1;
                                instrumentChoiceCursor += 4;
                                if (instrumentVariant >= lastInstrumentVariant) {
                                    goto finishInstrumentSelection;
                                }
                                goto selectInstrumentVariant;
                            }
                        } else {
                            goto finishInstrumentSelection;
                        }
                    } else {
finishInstrumentSelection:
                        selectedVariant = instrumentVariant;
                    }
                }
            } else {
                selectedVariant = -1;
            }
        }
        result = -1;
        if (selectedVariant != -1) {
            ((ContextRecAt2BC0 *)context)->field2B88 = func_8028FDB4_de(func_8028FDB4_de(((ContextRecAt2BC0 *)context)->instrumentIndex, (s32) (s16) selectedVariant), 0);
            ((ContextRecAt2BC0 *)context)->field2B8C = (s16) soundId;
            ((ContextRecAt2BC0 *)context)->field2B90 = ownerId;
            entries = func_8028FDB4_de(func_8028FDB4_de(((ContextRecAt2BC0 *)context)->instrumentIndex, (s32) (s16) selectedVariant), 1);
            entryCount = ((u32 *) entries)[4 / sizeof(u32)];
            playId = -1;
            if (entryCount != 0) {
                lock = &((ContextRecAt2BC0 *)context)->lock;
                mask = func_802BCF30_de();
                lockCount = lock->locked + 1;
                lock->locked = lockCount;
                if (lockCount != 1) {
                    __osRestoreInt(mask);
                    func_802BB2A0_de((OSMesgQueue *)lock, NULL, 1);
                } else {
                    __osRestoreInt(mask);
                }
                unlock = &((ContextRecAt2BC0 *)context)->lock;
                playId = ((s32 *) context)[268 / sizeof(s32)] + 1;
                ((s32 *) context)[268 / sizeof(s32)] = playId;
                unlockMask = func_802BCF30_de();
                remainingLocks = unlock->locked - 1;
                unlock->locked = remainingLocks;
                if (remainingLocks != 0) {
                    __osRestoreInt(unlockMask);
                    func_802BB420_de((OSMesgQueue *)unlock, 0, 1);
                    isSound = soundId < 0x100;
                } else {
                    __osRestoreInt(unlockMask);
                    isSound = soundId < 0x100;
                }
                if (isSound != 0) {
                    ((s32 *) context)[304 / sizeof(s32)] = selectedVariant;
                    goto startEntries;
                }
                l = 0;
            } else {
startEntries:
                l = 0;
            }
            if (entryCount != 0) {
                do {
                    entryOffset = l * ((s32 *) entries)[0 / sizeof(s32)];
                    l += 1;
                    func_80257BB4_de(context, (void *)(entries + entryOffset + 8), &position, selectedVariant, playId, 0, voiceParameter);
                } while (l < entryCount);
            }
            ((ContextRecAt2BC0 *)context)->field2B90 = -1;
            result = playId;
        }
    }
    return result;
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
