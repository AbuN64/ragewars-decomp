#ifndef SDK_ACMD_H
#define SDK_ACMD_H
#include "TYPES.H"
#include "acmd.h"
#include "COMMON/ALLOADFILTER48_2.H"

extern u32 func_802570C0_de(void *book, s32 size); /* game ADPCM codebook cache */
extern Acmd *func_802BEC34_de(Acmd *ptr, ALLoadFilter48_2 *f, s32 tsam, s32 nbytes, s16 outp, s16 inp,
                           u32 flags); /* _decodeChunk */
#endif
