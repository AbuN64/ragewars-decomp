#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B0388.h"
#include "types.h"

typedef void (*Callback802B6D04)(void *arg0);

extern void func_802B2450_de(void *arg0);
extern void func_802B2480_de(void *arg0, void **arg1);










void func_802B1C34_de(void *arg0, void *arg1) {
    ALEventListItem *cur;
    ALEventListItem *next;
    u16 type;
    s32 type16;

    cur = (void *)((ALSeqPlayer_func_802B0C94_de *)arg0)->evtq.allocList.next;
    if (cur != 0) {
        type16 = 0x16;
        do {
            type = cur->evt.type;
            next = (void *)cur->node.next;
            if ((type == 0x16 || type == 0x17) &&
                ((ALEvent10 *)&cur->evt)->msg.osc.vs == arg1) {
                ((ALSeqPlayer_func_802B0C94_de *)arg0)->stopOsc(
                    ((ALEvent10 *)&cur->evt)->msg.osc.oscState);
                func_802B2450_de(cur);
                if (next != 0) {
                    next->delta = next->delta +
                                        cur->delta;
                }
                func_802B2480_de(cur, &((ALSeqPlayer_func_802B0C94_de *)arg0)->evtq.freeList.next);
                if ((short)type == type16) {
                    ((ALVoiceState_s38 *)arg1)->flags &= 0xFE;
                } else {
                    ((ALVoiceState_s38 *)arg1)->flags &= 0xFD;
                }
                if (((ALVoiceState_s38 *)arg1)->flags == 0) {
                    break;
                }
            }
            cur = next;
        } while (cur != 0);
    }
}
