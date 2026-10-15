#include "sdk/libgultra.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B2614.h"
#include "span_1000/code_802B2EF8.h"
#include "span_1000/code_802B7488.h"
#include "types.h"

void func_802B2F00_de(ALSndPlayer *arg0, s16 arg1) {
    arg0->target = (s32) arg1;
}

extern s32 func_802B00D4_de(void *, s16 *, s32);




void func_802B2F10_de(ALSndPlayer *arg0, s16 arg1) {
    ParamsRecAt8V1 p;
    s32 acc;

    acc = (s32)arg0->sndState;
    p.f0 = 3;
    acc += arg0->target * 0x30;
    p.f8 = arg1;
    p.f4 = acc;
    func_802B00D4_de(&arg0->evtq, (s16 *)&p, 0);
}
