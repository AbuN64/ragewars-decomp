#include "span_1000/code_802B2EF8.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B2614.h"
#include "types.h"



extern s32 func_802B00D4_de(void *, s16 *, s32);




s32 func_802B2E30_de(struct Obj_func_802B2F60_de *arg0, s8 arg1) {
    Params_func_802B2DE0_de p;
    s32 acc;

    acc = arg0->field40;
    p.f0 = 2;
    p.f8 = arg1;
    acc += arg0->field3C * 0x30;
    p.f4 = acc;
    func_802B00D4_de(&arg0->events, (s16 *)&p, 0);
}
