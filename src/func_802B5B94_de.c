#include "span_1000/code_802B53FC.h"
#include "span_1000/code_802B53FC.h"
#include "span_C76B0/data.h"
#include "types.h"
#include "common/unused.h"
#include "abi.h"

extern ALGlobals_func_802B5B94_de *D_800D4070; /* alGlobals */

       /* 1/1000 */
extern const double D_800C77C0_de; /* 2^32 */
extern const float D_800C77C8_de; /* 1/CONVERT */

s32 func_802B5B94_de(void *filter, s32 paramID, void *param)
{
    ALFx_func_802B5B94_de *f = (ALFx_func_802B5B94_de *)filter;
    s32 p = (paramID - 2) % 8;
    s32 s = (paramID - 2) / 8;
    s32 val = *(s32 *)param;

    switch (p) {
        case 0:
            f->delay[s].input = (u32)val & 0xFFFFFFF8;
            break;
        case 1:
            f->delay[s].output = (u32)val & 0xFFFFFFF8;
            break;
        case 3:
            f->delay[s].ffcoef = (s16)val;
            break;
        case 2:
            f->delay[s].fbcoef = (s16)val;
            break;
        case 4:
            f->delay[s].gain = (s16)val;
            break;
        case 5:
            f->delay[s].rsinc = (((f32)val * D_800C77B8_de) * 2.0f) / D_800D4070->drvr.unk44;
            break;
        case 6: {
            f32 fval = (f32)val;
            s32 length = (f->delay[s].output - f->delay[s].input);
            double flength = length;

            if (length < 0)
                flength += D_800C77C0_de;
            f->delay[s].rsgain = fval * ((f32)flength * D_800C77C8_de);
            break;
        }
        case 7:
            if (f->delay[s].lp) {
                f->delay[s].lp->mode = (s16)val;
                func_802B468C_de(f->delay[s].lp);
            }
            break;
    }
    return 0;
}

extern const f32 D_800C77CC_de;
extern const f32 D_800C77D0_de;
extern const f32 D_800C77D4_de;
extern Acmd *func_802B60EC_de(ALFx *, s16 *, s32, s32, Acmd *);
extern s32 func_802BBBC0_de(s32);

/* Load a delay section, optionally applying chorus modulation and resampling.
 * ALDelay28 is the existing resampler-bearing view of the delay record. */
Acmd *func_802B5D70_de(ALFx *r, ALDelay28 *d, s32 buff, s32 incount, Acmd *p)
{
    Acmd *ptr = p;
    s32 ratio, count, rbuff = 640;
    s16 *out_ptr;
    f32 fincount, fratio, delta;
    s32 ramalign = 0, length;
    f32 unity;

    if (d->rs) {
        length = d->output - d->input;
        delta = func_802B6300_de((ALDelay *)d, incount);
        delta /= length;
        unity = D_800C77CC_de;
        delta = (s32)(delta * unity);
        delta = delta * D_800C77D0_de;
        fratio = D_800C77D4_de - delta;

        fincount = d->rs->delta + (fratio * (f32)incount);
        count = (s32)fincount;
        d->rs->delta = fincount - (f32)count;

        out_ptr = &r->input[-(d->output - d->rsdelta)];
        ramalign = ((s32)out_ptr & 0x7) >> 1;

        ptr = func_802B60EC_de(r, out_ptr - ramalign, rbuff, count + ramalign, ptr);

        ratio = (s32)(fratio * unity);
        aSetBuffer(ptr++, 0, rbuff + (ramalign << 1), buff, incount << 1);
        aResample(ptr++, d->rs->first, ratio, func_802BBBC0_de((s32)d->rs->state));

        d->rs->first = 0;
        d->rsdelta += count - incount;
    } else {
        out_ptr = &r->input[-d->output];
        ptr = func_802B60EC_de(r, out_ptr, buff, incount, ptr);
    }

    return ptr;
}
