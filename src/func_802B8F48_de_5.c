#include "span_C76B0/data.h"
#include "common/unused.h"
#include "span_1000/code_802B4730.h"
#include "span_1000/code_802B53FC.h"
#include "types.h"
#include "span_1000/code_802B369C.h"
/* alFxNew, drafted from ultralib src/audio/drvrnew.c: initialise the effect filter, pick the
   parameter table for the configured effect type, allocate the delay line and its sections, and
   give each section its optional resampler and low-pass filter. init_lpfilter's body is written
   out where the library's -O3 inlined it, against this function's own cartridge constants (a
   static inline helper kept 16384.0 in the inner loop instead of hoisting it into f20); the
   parameter tables are the cartridge's D_800D4080..D_800D41E8 and the unsigned length
   conversion is written out in GCC's order. */

extern void func_802B53E0_de(void *f, int h, int s, int type);        /* alFilterNew */
extern s32 func_802B0340_de(s32 file, s32 line, void *hp, s32 num, s32 size); /* alHeapDBAlloc */

extern char D_002B60D8; /* alFxParam */
extern char D_002B57F0; /* alFxPull */
extern char D_002B5B94; /* alFxParamHdl */

extern s32 D_800D4080[]; /* SMALLROOM_PARAMS */
extern s32 D_800D40E8[]; /* BIGROOM_PARAMS */
extern s32 D_800D4170_de[]; /* ECHO_PARAMS */
extern s32 D_800D4198[]; /* CHORUS_PARAMS */
extern s32 D_800D41C0[]; /* FLANGE_PARAMS */
extern s32 D_800D41E8[]; /* NULL_PARAMS */

 /* 16384.0 */
extern const f32 D_800CC810; /* 1 / 1000 */

 /* 2^32 */
extern const f32 D_800CC820; /* 1 / 173123.404906676 */

 /* 1.0f */

 /* 1.0 / 16384 */

void func_802B3F10_de(ALFx *r, ALSynConfig *c, ALHeap *hp)
{
    u16 i, j, k;
    s32 *param = 0;
    ALFilter_s14 *f = &r->filter;
    ALDelay28 *d;

    func_802B53E0_de(f, 0, (s32)&D_002B60D8, 5);
    f->handler = &D_002B57F0;
    r->paramHdl = &D_002B5B94;

    switch (c->fxType) {
      case 1: param = D_800D4080; break;
      case 2: param = D_800D40E8; break;
      case 5: param = D_800D4170_de; break;
      case 3: param = D_800D4198; break;
      case 4: param = D_800D41C0; break;
      case 6: param = c->params; break;
      default: param = D_800D41E8; break;
    }

    j = 0;

    r->section_count = param[j++];
    r->length = param[j++];

    r->delay = (void *)func_802B0340_de(0, 0, hp, r->section_count, sizeof(ALDelay28));
    r->base = (void *)func_802B0340_de(0, 0, hp, r->length, sizeof(s16));
    r->input = r->base;

    for (k = 0; k < r->length; k++)
        r->base[k] = 0;

    for (i = 0; i < r->section_count; i++) {
        d = &r->delay[i];
        d->input = param[j++];
        d->output = param[j++];
        d->fbcoef = param[j++];
        d->ffcoef = param[j++];
        d->gain = param[j++];

        if (param[j]) {
            s32 length;
            f64 flength;
            f32 rsinc;
            f32 depth;

            rsinc = (f32)param[j++] * D_800CC810;
            d->rsinc = (rsinc + rsinc) / c->outputRate;

            depth = (f32)param[j++];
            length = d->output - d->input;
            flength = length;
            if (length < 0)
                flength += D_800C75C8_de;
            d->rsgain = depth * ((f32)flength * D_800CC820);
            d->rsval = D_800C75D4;
            d->rsdelta = 0;
            d->rs = (void *)func_802B0340_de(0, 0, hp, 1, sizeof(struct ALResampler_s));
            ((struct ALResampler_s *)d->rs)->state = (void *)func_802B0340_de(0, 0, hp, 1, 32);
            ((struct ALResampler_s *)d->rs)->delta = 0;
            ((struct ALResampler_s *)d->rs)->first = 1;
        } else {
            d->rs = 0;
            j++;
            j++;
        }

        if (param[j]) {
            d->lp = (void *)func_802B0340_de(0, 0, hp, 1, sizeof(struct AudioLowPassFilter));
            ((struct AudioLowPassFilter *)d->lp)->state = (void *)func_802B0340_de(0, 0, hp, 1, sizeof(AudioPoleFilterState));
            ((struct AudioLowPassFilter *)d->lp)->cutoff = param[j++];
            {
                struct AudioLowPassFilter *lp = d->lp;
                s32 n, temp;
                s16 fc;
                f64 ffc, fcoef;

                temp = lp->cutoff * 16384;
                fc = temp >> 15;
                lp->gain = 16384 - fc;

                lp->first = 1;
                for (n = 0; n < 8; n++)
                    lp->coefficients.taps[n] = 0;

                lp->coefficients.taps[n++] = fc;
                fcoef = ffc = (f64)fc * D_800C75D8_de;

                for (; n < 16; n++) {
                    fcoef *= ffc;
                    lp->coefficients.taps[n] = (s16)(fcoef * 16384.0);
                }
            }
        } else {
            d->lp = 0;
            j++;
        }
    }
}
