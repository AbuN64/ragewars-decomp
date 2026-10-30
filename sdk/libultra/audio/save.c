#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"
#include "abi.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ALSEQUENCEPLAYER.H"
#include "COMMON/ALDELAY28.H"
#include "../../include/libultra/audio/save.H"
#include "TYPES.H"
#include "../../include/libultra/debug/assert.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALAUXBUS_S.H"

/* 802B63E4_3.CPP */
#if defined(VERSION_DE)
unsigned char g_SaveTrailingBytes[12] = { 0xAF, 0xB1, 0x00, 0x14, 0x00, 0x80, 0x88, 0x21, 0x00, 0x05, 0x14, 0x00 };
#endif

/* save.c */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1) || defined(VERSION_DE) || defined(VERSION_US)
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

/* save_2.c */
s32 alSaveParam(ALSave *saveFilter, s32 parameterId, ALFilter_s14 *parameterValue)
{
  switch (parameterId)
  {
    case 1:
      saveFilter->filter.source = parameterValue;
      goto ret0;

    case 6:
      saveFilter->dramout = parameterValue;

    default:
      ret0:
    return 0;

      return 0;

  }

}
