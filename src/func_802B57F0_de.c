#include "span_1000/code_802B53FC.h"
#include "span_1000/code_802B53FC.h"
#include "abi.h"
#include "audio_callbacks.h"
#include "common/unused.h"
#include "types.h"

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
extern char D_800C7784_de[]; /* "audio/reverb.c" */
extern void func_802BAC50_de(char *, char *, s32); /* __assert */
extern Acmd *func_802B5D70_de(struct ALFx *, ALDelay28 *, s32, s32, Acmd *); /* _loadOutputBuffer */
extern Acmd *func_802B60EC_de(struct ALFx *, s16 *, s32, s32, Acmd *); /* _loadBuffer */
extern Acmd *func_802B5F68_de(struct ALFx *, s16 *, s32, s32, Acmd *); /* _saveBuffer */
Acmd *func_802B57F0_de(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    struct ALFx *r = (struct ALFx *)filter;
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
