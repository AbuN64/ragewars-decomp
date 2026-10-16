#include "sdk/libgultra.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B2614.h"
#include "span_1000/code_802B7488.h"
#include "TYPES.H"

extern s32 func_802B00D4_de(void *, s16 *, s32);




void func_802B2D80_de(ALSndPlayer *arg0) {
    s32 base = (s32)arg0->sndState;

    if (((ALSoundState *) (base + (arg0->target * 0x30)))->state == 0) {
        ParamsRecAt8V1 p;
        p.f0 = 0;
        p.f4 = base + arg0->target * 0x30;
        func_802B00D4_de(&arg0->evtq, (s16 *)&p, 0);
    }
}

extern s32 func_802B00D4_de(void *, s16 *, s32);




void func_802B2DE0_de(ALSndPlayer *arg0, s8 arg1) {
    ParamsRecAt8V2 p;
    s32 acc;

    acc = (s32)arg0->sndState;
    p.f0 = 8;
    acc += arg0->target * 0x30;
    p.f8 = arg1;
    p.f4 = acc;
    func_802B00D4_de(&arg0->evtq, (s16 *)&p, 0);
}
