#include "span_1000/code_802B53FC.h"
#include "abi.h"
#include "acmd.h"
#include "audio_callbacks.h"
#include "code_802BAC64.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "types.h"

/* alResamplePull, drafted from ultralib src/audio/resample.c: at unity pitch pull the source and
   move its output; otherwise clip and quantise the pitch ratio, pull the input sample count it
   needs and append a resample command. The ratio limit, unity pitch and its reciprocal are the
   cartridge floats D_800C7740_de, the one after it, and D_800C7748_de. */

extern unsigned int func_802BBBC0_de(void *);

/* alFxPull, drafted from ultralib src/audio/reverb.c: pull the effect's source, mix the aux left
   and right outputs into the delay line input, run each delay section (load, feed-forward and
   feedback mixes, low-pass, save, gain into the output), advance the delay line input modulo its
   length and move the result into the aux left output. */

typedef struct ALLowPass_s ALLowPass;

#if defined(VERSION_DE)
extern const float D_800C7780;
#elif defined(VERSION_EU)
extern const float D_800C8370;
#elif defined(VERSION_EU_X)
extern char D_800C8D40[];
#elif defined(VERSION_US)
extern const float D_800C76A0;
#else
extern char D_800CC9D0[];
#endif

extern char D_800C7784_de[];

 /* "audio/reverb.c" */
extern void func_802BAC50_de(char *, char *, s32);

 /* __assert */
extern Acmd *func_802B5D70_de(struct ALFx *, ALDelay28 *, s32, s32, Acmd *);

 /* _loadOutputBuffer */
extern Acmd *func_802B60EC_de(struct ALFx *, s16 *, s32, s32, Acmd *);

 /* _loadBuffer */
extern Acmd *func_802B5F68_de(struct ALFx *, s16 *, s32, s32, Acmd *);

s32 func_802B5540_de(Obj_func_802B3EDC_de *arg0, s32 arg1, s32 arg2) {
    int new_var;
    s32 *base;
    s32 count;

    base = arg0->base;
    if (arg1 == 2) {
        new_var = arg0->count;
        count = new_var;
        base[count] = arg2;
        new_var = count + 1;
        arg0->count = new_var;
    }
    return 0;
}

 /* osVirtualToPhysical */

 /* MAX_RATIO, followed by UNITY_PITCH */

    /* 1 / UNITY_PITCH */

Acmd *func_802B5570_de(ALResampler_s *filter, s16 *outp, s32 outCnt, s32 sampleOffset, Acmd *p)
{
    ALResampler_s *f = filter;
    Acmd *ptr = p;
    s16 inp;
    s32 inCount;
    ALFilter_s14_2 *source = f->filter.source;
    s32 incr;
    f32 finCount;
    f32 ratio;
    f32 unity;

    inp = 320; /* AL_DECODER_OUT */

    if (!outCnt)
        return ptr;

    if (f->upitch) {

        ptr = (*source->handler)(source, &inp, outCnt, sampleOffset, p);
        aDMEMMove(ptr++, inp, *outp, outCnt << 1);

    } else {

        if (f->ratio > D_800C7740_de) f->ratio = D_800C7740_de;

        ratio = f->ratio;
        unity = D_800C7744_de;
        f->ratio = (f32)(s32)(ratio * unity) * D_800C7748_de;

        finCount = f->delta + (f->ratio * (f32)outCnt);
        inCount = (s32)finCount;
        f->delta = finCount - (f32)inCount;

        ptr = (*source->handler)(source, &inp, inCount, sampleOffset, p);

        incr = (s32)(f->ratio * unity);
        aSetBuffer(ptr++, 0, inp, *outp, outCnt << 1);
        aResample(ptr++, f->first, incr, func_802BBBC0_de(f->state));
        f->first = 0;
    }

    return ptr;
}

/** Apply a control message to this node and forward handled messages. */
s32 func_802B5730_de(void *arg0, s32 arg1, s32 arg2) {
    void *node = arg0;
    void *target;
    void (*callback)(void *, s32, s32);

    {
        s32 sw_message_value = arg1;
        sw_message_value -= (1);
        if ((unsigned int)sw_message_value > 8) {
            goto sw_message_default;
        }
        switch (sw_message_value) {
        case 0: goto sw_message_1;
        case 1: goto sw_message_default;
        case 2: goto sw_message_default;
        case 3: goto sw_message_4;
        case 4: goto sw_message_default;
        case 5: goto sw_message_default;
        case 6: goto sw_message_7;
        case 7: goto sw_message_8;
        case 8: goto sw_message_9;
        }
    }
    do {
    sw_message_1:
        *(s32 *)arg0 = arg2;
        break;
    sw_message_4:
        ((IntegerState34 *)(node))->unk_20 = 0;
        ((IntegerState34 *)(node))->unk_24 = 1;
        ((IntegerState34 *)(node))->unk_30 = 0;
        ((IntegerState34 *)(node))->unk_1C = 0;
        target = *(void **)arg0;
        if (target != 0) {
            callback = ((struct CallbackStateC *) ((char *) target))->callback;
            callback(target, 4, 0);
        }
        break;
    sw_message_9:
        ((IntegerState34 *)(node))->unk_30 = 1;
        target = *(void **)arg0;
        if (target != 0) {
            callback = ((struct CallbackStateC *) ((char *) target))->callback;
            callback(target, 9, 0);
        }
        break;
    sw_message_7:
        ((IntegerState34 *)(node))->unk_18 = arg2;
        break;
    sw_message_8:
        ((IntegerState34 *)(node))->unk_1C = 1;
        break;
    sw_message_default:
        target = *(void **)arg0;
        if (target != 0) {
            callback = ((struct CallbackStateC *) ((char *) target))->callback;
            callback(target, arg1, arg2);
        }
        break;

    } while (0);

    return 0;
}

 /* _saveBuffer */
Acmd *func_802B57F0_de(struct ALFx *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    struct ALFx *r = filter;
    ALFilter_s14_2 *source = (ALFilter_s14_2 *)r->filter.source;
    s16 i, buff1, buff2, input, output;
    s16 *in_ptr, *out_ptr, gain, *prev_out_ptr = 0;
    ALDelay28 *d, *pd;

    if (!source)
#if defined(VERSION_DE)
        func_802BAC50_de(&D_800C7780, D_800C7784_de, 75);
#elif defined(VERSION_EU)
        func_802BAC50_de(&D_800C8370, D_800C7784_de, 75);
#elif defined(VERSION_EU_X)
        func_802BAC50_de(D_800C8D40, D_800C7784_de, 75);
#elif defined(VERSION_US)
        func_802BAC50_de(&D_800C76A0, D_800C7784_de, 75);
#else
        func_802BAC50_de(D_800CC9D0, D_800C7784_de, 75);
#endif

    ptr = (*source->handler)(source, outp, outCount, sampleOffset, p);

    input = 1728;
    output = 2048;
    buff1 = 0;
    buff2 = 320;

    aSetBuffer(ptr++, 0, 0, 0, outCount << 1);
    aMix(ptr++, 0, 0xda83, 1728, input);
    aMix(ptr++, 0, 0x5a82, 2048, input);
    ptr = func_802B5F68_de(r, r->input, input, outCount, ptr);

    aClearBuffer(ptr++, output, outCount << 1);

    for (i = 0; i < r->section_count; i++) {
        d = &r->delay[i];
        in_ptr = &r->input[-d->input];
        out_ptr = &r->input[-d->output];

        if (in_ptr == prev_out_ptr) {
            { s16 t = buff2; buff2 = buff1; buff1 = t; };
        } else {
            ptr = func_802B60EC_de(r, in_ptr, buff1, outCount, ptr);
        }
        ptr = func_802B5D70_de(r, d, buff2, outCount, ptr);

        if (d->ffcoef) {
            aMix(ptr++, 0, (u16)d->ffcoef, buff1, buff2);
            if (!d->rs && !d->lp) {
                ptr = func_802B5F68_de(r, out_ptr, buff2, outCount, ptr);
            }
        }

        if (d->fbcoef) {
            aMix(ptr++, 0, (u16)d->fbcoef, buff2, buff1);
            ptr = func_802B5F68_de(r, in_ptr, buff1, outCount, ptr);
        }

        if (d->lp)
            ptr = func_802B625C_de(d->lp, buff2, outCount, ptr);

        if (!d->rs)
            ptr = func_802B5F68_de(r, out_ptr, buff2, outCount, ptr);

        if (d->gain)
            aMix(ptr++, 0, (u16)d->gain, buff2, output);

        prev_out_ptr = &r->input[d->output];
    }

    r->input += outCount;
    if (r->input > &r->base[r->length])
        r->input -= r->length;

    aDMEMMove(ptr++, output, 1728, outCount << 1);

    return ptr;
}
