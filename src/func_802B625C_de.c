#include "span_1000/code_802B4730.h"
#include "acmd.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B53FC.h"
#include "types.h"

extern s32 func_802BBBC0_de(s32);








void *func_802B625C_de(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    AudioLowPassFilter *o = arg0;
    Awords *d = arg3;
    void *ret;
    s32 a1;

    a1 = arg1 & 0xFFFF;
    d[0].w0 = a1 | 0x08000000;
    d[0].w1 = (a1 << 0x10) | ((arg2 * 2) & 0xFFFF);
    d[1].w0 = 0x0B000020;
    d[1].w1 = func_802BBBC0_de((s32)&o->coefficients);
    {
        s32 c2 = 0x0E000000;
        s32 b2f = (u8)o->first;
        s32 h2 = (u16)o->gain;
        d[2].w0 = (b2f << 0x10) | (h2 | c2);
    }
    ret = d + 3;
    d[2].w1 = func_802BBBC0_de((s32)o->state);
    o->first = 0;
    return ret;
}
