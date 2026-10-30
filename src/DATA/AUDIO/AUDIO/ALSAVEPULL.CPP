#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* 802B63E4_4.CPP */
#if defined(VERSION_DE)
RestLinkerAlignmentFill12 g_AlsavepullLinkerAlignmentFill83 = {
    { 143, 162, 0, 0, 0, 2, 21, 131, 48, 66, 1, 255 },
};
#endif

/* save_3.c */
#if defined(VERSION_EU)
#include "COMMON/ALFXPARAM.H"
#include "abi.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ALSEQUENCEPLAYER.H"
#include "COMMON/ALDELAY28.H"
#include "libultra/audio/save.H"
#include "TYPES.H"
#include "libultra/debug/assert.h"
Acmd *alSavePull(ALSave_u1 *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    ALFilter_u1 *source = filter->filter.source;

    if (!source) {
        __assert(g_audioSaveAssertConditionText, g_audioSaveText, 0x22);
    }
    ptr = source->handler(source, outp, outCount, sampleOffset, ptr);
    aSetBuffer(ptr++, 0, 0, 0, outCount << 1);
    aInterleave(ptr++, 0x440, 0x580);
    aSetBuffer(ptr++, 0, 0, 0, outCount << 2);
    aSaveBuffer(ptr++, filter->dramout);
    return ptr;
}
#endif
