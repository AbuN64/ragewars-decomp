#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/ALDELAY28.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/seqplayer_802B6BE4.h"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"

extern void func_802B3470_de(void *arg0, void *arg1, s16 arg2);

extern void func_802B3480_de(void *arg0, void *arg1, s16 arg2, s32 arg3);

extern s32 func_802B00D4_de(void *, s16 *, s32);

/* Voice events serialize the voice pointer in the first four payload bytes. */
static inline ALVoice_s *event_voice(ALEvent *event) {
    return (ALVoice_s *)event->msg.note.voice;
}

typedef void (*Callback802B6D04)(void *arg0);

extern s32 __alSeqNextDelta(void *arg0, s32 *arg1);

extern s32 alSeqGetTicks(void *arg0);

extern void alSeqSetLoc(void *arg0, void *arg1);

/** Store a new history slot (pointer + selected byte/word fields) into the ring buffer at arg0+0x60. */
void __setInstChanState(void *seqPlayer, void *selectedInstrument, s32 channelNumber) {
    s32 stride = channelNumber * 0x10;

    ((ALChanState *)(stride + (s32)((ALSeqPlayer *)seqPlayer)->chanState))->instrument = selectedInstrument;
    ((ALChanState *)((stride + (s32)((ALSeqPlayer *)seqPlayer)->chanState)))->pan = ((ALInstrument *)selectedInstrument)->pan;
    ((ALChanState *)((stride + (s32)((ALSeqPlayer *)seqPlayer)->chanState)))->vol = ((ALInstrument *)selectedInstrument)->volume;
    ((ALChanState *)((stride + (s32)((ALSeqPlayer *)seqPlayer)->chanState)))->priority = ((ALInstrument *)selectedInstrument)->priority;
    ((ALChanState *)((stride + (s32)((ALSeqPlayer *)seqPlayer)->chanState)))->bendRange = (u16)((ALInstrument *)selectedInstrument)->bendRange;
}

void __seqpReleaseVoice(void *seqPlayer, void *releasedVoice, s32 releaseDuration) {
    ALEventListItem *cur;
    ALEventListItem *next;
    ALVoiceState *object;
    s32 type6;
    Entry802B6BE4 entry;

    object = ((ALVoice_s *)releasedVoice)->clientPrivate;
    if (object->envPhase == 0) {
        cur = (ALEventListItem *)((ALSeqPlayer *)seqPlayer)->evtq.allocList.next;
        if (cur != 0) {
            type6 = 6;
            do {
                next = (ALEventListItem *)cur->node.next;
                if (cur->evt.type == type6 &&
                    event_voice(&cur->evt) == releasedVoice) {
                    if (next != 0) {
                        next->delta = next->delta +
                                            cur->delta;
                    }
                    alUnlink(cur);
                    alLink(cur, &((ALSeqPlayer *)seqPlayer)->evtq);
                }
                cur = next;
            } while (cur != 0);
        }
    }
    object->velocity = 0;
    object->envPhase = 3;
    object->envGain = 0;
    object->envEndTime = ((ALSeqPlayer *)seqPlayer)->curTime + releaseDuration;
    func_802B3470_de(((ALSeqPlayer *)seqPlayer)->drvr, releasedVoice, 0);
    func_802B3480_de(((ALSeqPlayer *)seqPlayer)->drvr, releasedVoice, 0, releaseDuration);
    entry.type = 5;
    entry.object = releasedVoice;
    func_802B00D4_de(&((ALSeqPlayer *)seqPlayer)->evtq, &entry, releaseDuration);
}

void __seqpStopOsc(void *seqPlayer, void *voiceState) {
    ALEventListItem *cur;
    ALEventListItem *next;
    u16 type;
    s32 type16;

    cur = (void *)((ALSeqPlayer *)seqPlayer)->evtq.allocList.next;
    if (cur != 0) {
        type16 = 0x16;
        do {
            type = cur->evt.type;
            next = (void *)cur->node.next;
            if ((type == 0x16 || type == 0x17) &&
                ((ALEvent *)&cur->evt)->msg.osc.vs == voiceState) {
                ((ALSeqPlayer *)seqPlayer)->stopOsc(
                    ((ALEvent *)&cur->evt)->msg.osc.oscState);
                alUnlink(cur);
                if (next != 0) {
                    next->delta = next->delta +
                                        cur->delta;
                }
                alLink(cur, &((ALSeqPlayer *)seqPlayer)->evtq.freeList.next);
                if ((short)type == type16) {
                    ((ALVoiceState *)voiceState)->flags &= 0xFE;
                } else {
                    ((ALVoiceState *)voiceState)->flags &= 0xFD;
                }
                if (((ALVoiceState *)voiceState)->flags == 0) {
                    break;
                }
            }
            cur = next;
        } while (cur != 0);
    }
}

void __postNextSeqEvent(void *seqPlayer) {
    ALEvent referenceEvent;
    s32 deltaTicks;
    s32 remainingLoops;
    void *sequence;

    sequence = ((ObjectLinks88 *)(seqPlayer))->unk_18;
    if ((((ObjectLinks88 *)(seqPlayer))->unk_2C == 1) && (sequence != 0) &&
        (__alSeqNextDelta(sequence, &deltaTicks) & 0xFF)) {
        if ((((ObjectLinks88 *)(seqPlayer))->unk_84 != 0) &&
            ((alSeqGetTicks(sequence) + deltaTicks) >=
             ((struct func_80254D70_S2 *) ((ObjectLinks88 *) seqPlayer)->unk_80)->unk8)) {
            alSeqSetLoc(sequence, ((ObjectLinks88 *)(seqPlayer))->unk_7C);
            remainingLoops = ((ObjectLinks88 *)(seqPlayer))->unk_84;
            if (remainingLoops != -1) {
                ((ObjectLinks88 *)(seqPlayer))->unk_84 = remainingLoops - 1;
            }
        }
        referenceEvent.type = 0;
        func_802B00D4_de(&((ObjectLinks88 *)(seqPlayer))->unk_48, &referenceEvent,
                      deltaTicks * ((ObjectLinks88 *)(seqPlayer))->unk_24);
    }
}

extern void func_802B1E50_de(void *arg0, f32 arg1);

void __handleMetaMsg(void *arg0, void *arg1) {
    u8 *p = (u8 *)arg1;
    int pad[4];

    (void)pad;
    if (p[8] == 0xFF && p[9] == 0x51) {
        func_802B1E50_de(arg0, (f32)((p[0xB] << 0x10) | (p[0xC] << 8) | p[0xD]));
    }
}
