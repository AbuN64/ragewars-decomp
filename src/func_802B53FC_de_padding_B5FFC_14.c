#include "types.h"
#include "abi.h"
#include "audio_callbacks.h"
#include "shared/func_802B0A90_de_closed.h"
#include "span_1000/code_802B53FC.h"




Acmd *func_802B6658_eu_x(ALSave_u1 *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    ALFilter_u1 *source = filter->filter.source;

    if (!source) {
        func_802BAC50_de(D_800C8DB0_eu_x, D_800C8DB4_eu_x, 0x22);
    }
    ptr = source->handler(source, outp, outCount, sampleOffset, ptr);
    aSetBuffer(ptr++, 0, 0, 0, outCount << 1);
    aInterleave(ptr++, 0x440, 0x580);
    aSetBuffer(ptr++, 0, 0, 0, outCount << 2);
    aSaveBuffer(ptr++, filter->dramout);
    return ptr;
}
