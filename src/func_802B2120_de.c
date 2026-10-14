#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B243C.h"
#include "types.h"
/* alSeqSecToTicks, drafted from ultralib src/audio/seq.c: convert seconds to ticks at the given
   tempo. The library evaluates it in single precision as sec * (division * 1e6f), so the product is
   spelled in that order against the cartridge constant after D_800CC740; GCC's u32-to-float and
   float-to-u32 expansions are written out against D_800CC748 and D_800CC750. */
extern const float D_800CC740; /* followed by 1000000.0f */
extern const double D_800CC748; /* 4294967296.0 */
extern const float D_800CC750; /* 2147483648.0f */
u32 func_802B2120_de(ObjRecAt18V1 *seq, f32 sec, u32 tempo)
{
    f32 ticks;
    f64 t;
    f32 q;
    u32 result;
    ticks = sec * ((f32)seq->field18 * (*(&D_800CC740 + 1)));
    t = (f64)(s32)tempo;
    if ((s32)tempo < 0) {
        t = t + D_800CC748;
    }
    q = ticks / (f32)t;
    if (!(q >= D_800CC750)) {
        result = (s32)q;
    } else {
        q = q - D_800CC750;
        result = (s32)q;
        result |= 0x80000000;
    }
    return result;
}
