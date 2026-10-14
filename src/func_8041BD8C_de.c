#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_8041B020.h"
/* After func_8029973C_de, forwards an event for a channel to func_802995D4_de with the channel's handler id
   (short at 0xC of the handler at 0x4C) when the channel is not muted (word at 0x5C) and has a handler;
   returns 0. */




extern void func_8029973C_de(void);
extern void func_802995D4_de(int, int, int, int, int);

int func_8041BD8C_de(Mixer *mixer, int unused, int channel, int value, int extra) {
    ObjRecAtCV1 *h;

    func_8029973C_de();
    if (mixer->muted[(unsigned short)channel] != 0) {
        return 0;
    }
    h = mixer->handlers[(unsigned short)channel];
    if (h == 0) {
        return 0;
    }
    func_802995D4_de(h->unkC, 1, channel, value, extra);
    return 0;
}
