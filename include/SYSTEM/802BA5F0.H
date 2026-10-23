#ifndef SYSTEM_802BA5F0_H
#define SYSTEM_802BA5F0_H
#include "TYPES.H"
#include "COMMON/UNUSED.H"
struct RecCode802BA23C {
    char pad0[2];
    s16 f2;
    char pad4[0xC];
    s32 f10;
    s32 f14;
};
struct __OSViContext {
    u16 state;
    u16 retraceCount;
    void *framep;
    void *modep;
    u32 control;
    Opaque_OSMesgQueue *msgq;
    void * msg;
};
#endif
