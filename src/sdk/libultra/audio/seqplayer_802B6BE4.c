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

extern s32 func_802B22F4_de(void *arg0, s32 *arg1);

extern s32 func_802B20C8_de(void *arg0);

extern void alSeqSetLoc(void *arg0, void *arg1);

/** Store a new history slot (pointer + selected byte/word fields) into the ring buffer at arg0+0x60. */
void __setInstChanState(void *arg0, void *arg1, s32 arg2) {
    s32 stride = arg2 * 0x10;

    ((ALChanState10 *)(stride + (s32)((ALSeqPlayer *)arg0)->chanState))->instrument = arg1;
    ((ALChanState10 *)((stride + (s32)((ALSeqPlayer *)arg0)->chanState)))->pan = ((ALInstrument *)arg1)->pan;
    ((ALChanState10 *)((stride + (s32)((ALSeqPlayer *)arg0)->chanState)))->vol = ((ALInstrument *)arg1)->volume;
    ((ALChanState10 *)((stride + (s32)((ALSeqPlayer *)arg0)->chanState)))->priority = ((ALInstrument *)arg1)->priority;
    ((ALChanState10 *)((stride + (s32)((ALSeqPlayer *)arg0)->chanState)))->bendRange = (u16)((ALInstrument *)arg1)->bendRange;
}

void func_802B1B14_de(void *arg0, void *arg1, s32 arg2) {
    ALEventListItem *cur;
    ALEventListItem *next;
    ALVoiceState *object;
    s32 type6;
    Entry802B6BE4 entry;

    object = ((ALVoice_s *)arg1)->clientPrivate;
    if (object->envPhase == 0) {
        cur = (ALEventListItem *)((ALSeqPlayer *)arg0)->evtq.allocList.next;
        if (cur != 0) {
            type6 = 6;
            do {
                next = (ALEventListItem *)cur->node.next;
                if (cur->evt.type == type6 &&
                    event_voice(&cur->evt) == arg1) {
                    if (next != 0) {
                        next->delta = next->delta +
                                            cur->delta;
                    }
                    func_802B2450_de(cur);
                    func_802B2480_de(cur, &((ALSeqPlayer *)arg0)->evtq);
                }
                cur = next;
            } while (cur != 0);
        }
    }
    object->velocity = 0;
    object->envPhase = 3;
    object->envGain = 0;
    object->envEndTime = ((ALSeqPlayer *)arg0)->curTime + arg2;
    func_802B3470_de(((ALSeqPlayer *)arg0)->drvr, arg1, 0);
    func_802B3480_de(((ALSeqPlayer *)arg0)->drvr, arg1, 0, arg2);
    entry.type = 5;
    entry.object = arg1;
    func_802B00D4_de(&((ALSeqPlayer *)arg0)->evtq, &entry, arg2);
}

void func_802B1C34_de(void *arg0, void *arg1) {
    ALEventListItem *cur;
    ALEventListItem *next;
    u16 type;
    s32 type16;

    cur = (void *)((ALSeqPlayer *)arg0)->evtq.allocList.next;
    if (cur != 0) {
        type16 = 0x16;
        do {
            type = cur->evt.type;
            next = (void *)cur->node.next;
            if ((type == 0x16 || type == 0x17) &&
                ((ALEvent *)&cur->evt)->msg.osc.vs == arg1) {
                ((ALSeqPlayer *)arg0)->stopOsc(
                    ((ALEvent *)&cur->evt)->msg.osc.oscState);
                func_802B2450_de(cur);
                if (next != 0) {
                    next->delta = next->delta +
                                        cur->delta;
                }
                func_802B2480_de(cur, &((ALSeqPlayer *)arg0)->evtq.freeList.next);
                if ((short)type == type16) {
                    ((ALVoiceState *)arg1)->flags &= 0xFE;
                } else {
                    ((ALVoiceState *)arg1)->flags &= 0xFD;
                }
                if (((ALVoiceState *)arg1)->flags == 0) {
                    break;
                }
            }
            cur = next;
        } while (cur != 0);
    }
}

void func_802B1D24_de(void *arg0) {
    ALEvent sp10;
    s32 sp20;
    s32 temp_v1;
    void *temp_s0;

    temp_s0 = ((ObjectLinks88 *)(arg0))->unk_18;
    if ((((ObjectLinks88 *)(arg0))->unk_2C == 1) && (temp_s0 != 0) &&
        (func_802B22F4_de(temp_s0, &sp20) & 0xFF)) {
        if ((((ObjectLinks88 *)(arg0))->unk_84 != 0) &&
            ((func_802B20C8_de(temp_s0) + sp20) >=
             ((struct func_80254D70_S2 *) ((ObjectLinks88 *) arg0)->unk_80)->unk8)) {
            alSeqSetLoc(temp_s0, ((ObjectLinks88 *)(arg0))->unk_7C);
            temp_v1 = ((ObjectLinks88 *)(arg0))->unk_84;
            if (temp_v1 != -1) {
                ((ObjectLinks88 *)(arg0))->unk_84 = temp_v1 - 1;
            }
        }
        sp10.type = 0;
        func_802B00D4_de(&((ObjectLinks88 *)(arg0))->unk_48, &sp10,
                      sp20 * ((ObjectLinks88 *)(arg0))->unk_24);
    }
}
