#include "include_asm.h"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
#define func_802B6658_eu_x func_802B661C_eu
#include "COMMON/EXTERNS_2.H"
#include "abi.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ALSEQUENCEPLAYER.H"
#include "COMMON/ALDELAY28.H"
#include "AUDIO_3/802B6380.H"
#include "TYPES.H"
#include "AUDIO_3/802BFD40.H"
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
#else
INCLUDE_ASM("span_1000", func_802B661C_eu);
#endif
#endif
