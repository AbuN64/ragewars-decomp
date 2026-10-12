#ifndef FUNC_8028C568_DE_CLOSED_H
#define FUNC_8028C568_DE_CLOSED_H
#include "types.h"
#include "common/unused.h"
#include "packed_float.h"


extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);
extern void func_80278C10_de(void *);
#if defined(VERSION_EU)
#else
#endif
static inline f32 recordValue(s32 id) {
#if defined(VERSION_EU)
    return func_802AD520_eu(id);
#else
    return func_802B2350(id);
#endif
}

struct func_8028C544_S2;
struct func_8028C544_S3;


#endif
