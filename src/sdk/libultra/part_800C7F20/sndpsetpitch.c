#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"

extern s32 func_802B00D4_de(void *, s16 *, s32);




void alSndpSetPitch(struct ObjRecAt40V2 *arg0, s32 arg1) {
    ParamsRecAt8V3 p;
    s32 acc;

    acc = arg0->field40;
    p.f0 = 4;
    acc += arg0->field3C * 0x30;
    p.f8 = arg1;
    p.f4 = acc;
    func_802B00D4_de(&arg0->events, (s16 *)&p, 0);
}
