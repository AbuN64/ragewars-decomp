#include "include_asm.h"

#if defined(VERSION_EU)
#define func_802B6658_eu_x func_802B661C_eu
#include "COMMON/EXTERNS_2.H"
#include "abi.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ALSEQUENCEPLAYER.H"
#include "COMMON/ALDELAY28.H"
#include "sdk/libultra/audio/save.H"
#include "TYPES.H"
#include "AUDIO_3/802BFD40.H"
Acmd *func_802B6658_eu_x(ALSave_u1 *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    ALFilter_u1 *source = filter->filter.source;

    if (!source) {
        Audio_Assert(D_800C8DB0_eu_x, g_audioSaveText, 0x22);
    }
    ptr = source->handler(source, outp, outCount, sampleOffset, ptr);
    aSetBuffer(ptr++, 0, 0, 0, outCount << 1);
    aInterleave(ptr++, 0x440, 0x580);
    aSetBuffer(ptr++, 0, 0, 0, outCount << 2);
    aSaveBuffer(ptr++, filter->dramout);
    return ptr;
}
#endif
