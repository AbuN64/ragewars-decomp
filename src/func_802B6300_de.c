#include "span_1000/code_802B53FC.h"
#include "types.h"
/* _doModFunc, drafted from ultralib src/audio/reverb.c: advance the chorus sawtooth by rsinc per
   sample, wrap it from +RANGE, fold it into a triangle and return it scaled by rsgain. The library
   evaluates RANGE in single precision against the cartridge's 2.0, 4.0 and 1.0 constants. */
extern const float D_800C77D8_de; /* RANGE, followed by RANGE*2 */
extern const float D_800C77E0_de; /* RANGE/2 */
f32 func_802B6300_de(ALDelay *d, s32 count)
{
    f32 val;
    d->rsval += d->rsinc * count;
    d->rsval = (d->rsval > D_800C77D8_de) ? d->rsval - (*(&D_800C77D8_de + 1)) : d->rsval;
    val = d->rsval;
    val = (val < 0) ? -val : val;
    val -= D_800C77E0_de;
    return d->rsgain * val;
}
