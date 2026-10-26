#ifndef COMMON_EXTERNS_10_H
#define COMMON_EXTERNS_10_H
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON.H"


struct Trigger;
extern void Link_DispatchTrigger(struct Trigger *);
#if defined(VERSION_EU)
#else
#endif
static inline f32 recordValue(s32 id) {
#if defined(VERSION_EU)
    return Menu_ExpandFloatHighWord(id);
#else
    return Menu_ExpandFloatHighWord(id);
#endif
}

#endif
