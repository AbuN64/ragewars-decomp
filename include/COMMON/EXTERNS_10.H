#ifndef COMMON_EXTERNS_10_H
#define COMMON_EXTERNS_10_H
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON.H"


struct Trigger;
extern void Actors_DispatchTrigger(struct Trigger *);
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
