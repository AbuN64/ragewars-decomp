#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/SHAREDRECV4.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"

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

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", func_802B2F10_de_padding_B3A8C);
#endif
