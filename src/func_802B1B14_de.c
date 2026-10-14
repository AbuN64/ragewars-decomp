#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B0388.h"
#include "types.h"



extern void func_802B2450_de(void *arg0);
extern void func_802B2480_de(void *arg0, void **arg1);
extern void func_802B3470_de(void *arg0, void *arg1, s16 arg2);
extern void func_802B3480_de(void *arg0, void *arg1, s16 arg2, s32 arg3);
extern s32 func_802B00D4_de(void *, s16 *, s32);












/* Voice events serialize the voice pointer in the first four payload bytes. */
static inline ALVoice_s *event_voice(Message_func_802AF150_de *event) {
    ALVoice_s *voice;
    __builtin_memcpy(&voice, &event->pad[2], sizeof(voice));
    return voice;
}

void func_802B1B14_de(void *arg0, void *arg1, s32 arg2) {
    ALEventListItem *cur;
    ALEventListItem *next;
    ALVoiceState_s *object;
    s32 type6;
    Entry802B6BE4 entry;

    object = ((ALVoice_s *)arg1)->clientPrivate;
    if (object->envPhase == 0) {
        cur = (ALEventListItem *)((ALSeqPlayer *)arg0)->events.allocList.next;
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
                    func_802B2480_de(cur, &((ALSeqPlayer *)arg0)->events);
                }
                cur = next;
            } while (cur != 0);
        }
    }
    object->velocity = 0;
    object->envPhase = 3;
    object->envGain = 0;
    object->envEndTime = ((ALSeqPlayer *)arg0)->currentTime + arg2;
    func_802B3470_de(((ALSeqPlayer *)arg0)->synth, arg1, 0);
    func_802B3480_de(((ALSeqPlayer *)arg0)->synth, arg1, 0, arg2);
    entry.type = 5;
    entry.object = arg1;
    func_802B00D4_de(&((ALSeqPlayer *)arg0)->events, &entry, arg2);
}
