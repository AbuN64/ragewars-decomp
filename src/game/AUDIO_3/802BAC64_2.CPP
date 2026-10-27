#include "include_asm.h"
#include "AUDIO_3/ACMD.H"
#include "abi.h"
#include "acmd.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "sdk/libultra/audio/save_3.H"
#include "sdk/libgultra.h"
#include "COMMON/ALPARAM_S.H"
#include "COMMON/ALDELAY28.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "sdk/OSINT/802C0CB0.H"
#include "COMMON/ALAUXBUS_S.H"
#include "sdk/al_globals.h"

 /* alGlobals */

       /* 1/1000 */

 /* 2^32 */

/* _saveBuffer, drafted from ultralib src/audio/reverb.c: write count samples from the DMEM buffer
   buff back into the delay line at curr_ptr, wrapping the write back to r->base when it would run
   past the end of the line. The wrapped arm ends with its own set-buffer command, which the
   straight arm does not emit. */

/* _loadBuffer, drafted from ultralib src/audio/reverb.c: load count samples of the delay line at
   curr_ptr into the DMEM buffer buff, wrapping the read back to r->base when it would run past
   the end of the line. The wrapped arm emits its two loads as a pair of set-buffer and load-buffer
   commands against this function's own cartridge command words. */

/* _doModFunc, drafted from ultralib src/audio/reverb.c: advance the chorus sawtooth by rsinc per
   sample, wrap it from +RANGE, fold it into a triangle and return it scaled by rsgain. The library
   evaluates RANGE in single precision against the cartridge's 2.0, 4.0 and 1.0 constants. */

 /* RANGE, followed by RANGE*2 */

 /* 1/CONVERT */

s32 func_802B5B94_de(ALFxCode802BAC64 *filter, s32 paramID, void *param)
{
    ALFxCode802BAC64 *f = filter;
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
            f->delay[s].rsinc = (((f32)val * D_800C77B8_de) * 2.0f) / D_800D4070->drvr.outputRate;
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
                init_lpfilter(f->delay[s].lp);
            }
            break;
    }
    return 0;
}

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
        delta = func_802B6300_de(d, incount);
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

 /* osVirtualToPhysical */

Acmd *func_802B5F68_de(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p)
{
    Acmd *ptr = p;
    s32 after_end, before_end;
    s16 *updated_ptr, *delay_end;

    delay_end = &r->base[r->length];

    if (curr_ptr < r->base)
        curr_ptr += r->length;
    updated_ptr = curr_ptr + count;

    if (updated_ptr > delay_end) {
        after_end = updated_ptr - delay_end;
        before_end = delay_end - curr_ptr;

        aSetBuffer(ptr++, 0, 0, buff, before_end << 1);
        aSaveBuffer(ptr++, func_802BBBC0_de(curr_ptr));
        aSetBuffer(ptr++, 0, 0, buff + (before_end << 1), after_end << 1);
        aSaveBuffer(ptr++, func_802BBBC0_de(r->base));
        aSetBuffer(ptr++, 0, 0, 0, count << 1);
    } else {
        aSetBuffer(ptr++, 0, 0, buff, count << 1);
        aSaveBuffer(ptr++, func_802BBBC0_de(curr_ptr));
    }

    return ptr;
}

int alFxParam(int *filter, int paramId, int param) {
    if (paramId == 1) {
        *filter = param;
    }
    return 0;
}

 /* osVirtualToPhysical */

Acmd *func_802B60EC_de(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p)
{
    Acmd *ptr = p;
    s32 after_end, before_end;
    s16 *updated_ptr, *delay_end;

    delay_end = &r->base[r->length];

    if (curr_ptr < r->base)
        curr_ptr += r->length;
    updated_ptr = curr_ptr + count;

    if (updated_ptr > delay_end) {
        after_end = updated_ptr - delay_end;
        before_end = delay_end - curr_ptr;

        aSetBuffer(ptr++, 0, buff, 0, before_end << 1);
        aLoadBuffer(ptr++, func_802BBBC0_de(curr_ptr));
        aSetBuffer(ptr++, 0, buff + (before_end << 1), 0, after_end << 1);
        aLoadBuffer(ptr++, func_802BBBC0_de(r->base));
    } else {
        aSetBuffer(ptr++, 0, buff, 0, count << 1);
        aLoadBuffer(ptr++, func_802BBBC0_de(curr_ptr));
    }

    aSetBuffer(ptr++, 0, 0, 0, count << 1);

    return ptr;
}

void *func_802B625C_de(void *audioLowPassFilter, s32 dmemBuffer, s32 sampleCount, void *awords) {
    AudioLowPassFilter *o = audioLowPassFilter;
    Awords *d = awords;
    void *ret;
    s32 a1;

    a1 = dmemBuffer & 0xFFFF;
    d[0].w0 = a1 | 0x08000000;
    d[0].w1 = (a1 << 0x10) | ((sampleCount * 2) & 0xFFFF);
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

 /* RANGE/2 */
f32 func_802B6300_de(ALDelay28 *d, s32 count)
{
    f32 val;
    d->rsval += d->rsinc * count;
    d->rsval = (d->rsval > D_800C77D8_de) ? d->rsval - (*(&D_800C77D8_de + 1)) : d->rsval;
    val = d->rsval;
    val = (val < 0) ? -val : val;
    val -= D_800C77E0_de;
    return d->rsgain * val;
}

#if defined(VERSION_EU) || defined(VERSION_US)
unsigned int func_802B6300_de_padding_B6EA8[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int func_802B6378_de_padding_B6F78[2] = {
    0x0080A821, 0xAFB30024,
};
#endif
