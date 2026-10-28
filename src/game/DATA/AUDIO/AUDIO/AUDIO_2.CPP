#include "include_asm.h"

/* 802B63E4_4.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_802B6554_de_padding_B7154[12] = { 0x8F, 0xA2, 0x00, 0x00, 0x00, 0x02, 0x15, 0x83, 0x30, 0x42, 0x01, 0xFF };
#endif

/* save_3.c */
#if defined(VERSION_EU)
#define alSavePull func_802B661C_eu
#include "COMMON/EXTERNS_2.H"
#include "abi.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ALSEQUENCEPLAYER.H"
#include "COMMON/ALDELAY28.H"
#include "sdk/libultra/audio/save.H"
#include "TYPES.H"
#include "AUDIO/802BFD40.H"
Acmd *alSavePull(ALSave_u1 *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
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
