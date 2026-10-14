#include "span_1000/code_802B53FC.h"
#include "abi.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "span_1000/code_802B53FC.h"
#include "types.h"
#include "abi.h"
#include "acmd.h"

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

/* alResamplePull, drafted from ultralib src/audio/resample.c: at unity pitch pull the source and
   move its output; otherwise clip and quantise the pitch ratio, pull the input sample count it
   needs and append a resample command. The ratio limit, unity pitch and its reciprocal are the
   cartridge floats D_800C7740_de, the one after it, and D_800C7748_de. */

extern unsigned int func_802BBBC0_de(void *); /* osVirtualToPhysical */

 /* MAX_RATIO, followed by UNITY_PITCH */

    /* 1 / UNITY_PITCH */

Acmd *func_802B5570_de(void *filter, s16 *outp, s32 outCnt, s32 sampleOffset, Acmd *p)
{
    ALResampler_s *f = (ALResampler_s *)filter;
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
