#include "span_1000/code_802B53FC.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B0388.h"
#include "types.h"

extern void func_802B2450_de(void *arg0);

extern void func_802B2480_de(void *arg0, void **arg1);

s32 func_802B15D0_de(void *arg0, s32 arg1, s32 arg2) {
    s32 amount;
    s32 total;
    s32 result;
    char *next;
    char *cur;

    total = 0;
    cur = ((ALSeqPlayer *)arg0)->evtq.allocList.next;
    result = 1;
    if (cur != 0) {
        do {
            amount = ((ALEventListItem *)cur)->delta;
            next = ((ALEventListItem *)cur)->node.next;
            total += amount;
            if (((ALEventListItem *)cur)->evt.type == 5 && (s32)((ALEvent *)&((ALEventListItem *)cur)->evt)->msg.note.voice == arg1) {
                if (arg2 < total) {
                    if (next != 0) {
                        ((ALEventListItem *)next)->delta = ((ALEventListItem *)next)->delta + amount;
                    }
                    func_802B2450_de(cur);
                    func_802B2480_de(cur, &((ALSeqPlayer *)arg0)->evtq.freeList.next);
                    goto done;
                }
                result = 0;
                goto done;
            }
            cur = next;
        } while (cur != 0);
    }
done:
    return result;
}

/* __lookupVoice, drafted from ultralib src/audio/seqplayer.c: walk the sequence player's allocated
   voice list for the voice playing a key on a channel that is not being released. */









ALVoiceState *func_802B1680_de(ALSeqPlayer *seqp, u8 key, u8 channel)
{
    ALVoiceState *vs;

    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if ((vs->key == key) && (vs->channel == channel) &&
            (vs->phase != 3) && (vs->phase != 4))
            return vs;
    }
    return 0;
}
