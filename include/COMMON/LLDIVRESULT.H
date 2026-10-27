#ifndef COMMON_LLDIVRESULT_H
#define COMMON_LLDIVRESULT_H
#include "TYPES.H"

typedef struct LldivResult LldivResult;

struct LldivResult {
    s64 quot;
    s64 rem;
};

struct LldivResult;

extern s64 Libc_SignedDivide(s64, s64) __attribute__((const));

extern s64 Libc_SignedRemainder(s64, s64) __attribute__((const));

#include "acmd.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
extern Acmd *alRaw16Pull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p);







extern char D_002BE514;
extern char D_002BE898;

#include "sdk/AUDIO/802C3EA4_2.H"
#endif
