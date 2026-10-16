#ifndef MAIN_802BD1A8_H
#define MAIN_802BD1A8_H

#include "TYPES.H"

typedef struct LldivResult LldivResult;

struct LldivResult {
    s64 quot;
    s64 rem;
};

struct LldivResult;

extern s64 func_802C0230_de(s64, s64) __attribute__((const));

extern s64 func_802C0820_de(s64, s64) __attribute__((const));

#include "acmd.h"
#include "audio_callbacks.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
extern Acmd *func_802BE514_de(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p);

extern u16 func_802BEDB0_de(u16 *, u16, s32, s32, void *);

extern void func_802BF514_de();

extern u32 func_802BFE3C_de(void);

extern void func_802C021C_de();

extern void func_802BFAAC_de(void *arg0, void *arg1);

extern char D_002BE514;
extern char D_002BE898;

extern void func_802BF928_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

#endif
