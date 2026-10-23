#ifndef SCHED_CODE_8023CBF8_H
#define SCHED_CODE_8023CBF8_H
#include "TYPES.H"
struct OwnerRecAt8V2 {
    s32 unk0;
    u32 handle;
    s32 queue;
};
struct RegionDesc {
    s32 pad0;
    s32 size;
    struct Region *region;
    void *mapping;
};
#endif
