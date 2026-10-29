#ifndef ENGINE_VIRTUAL_VIRTUAL_REGION_OWNER_STATE_H
#define ENGINE_VIRTUAL_VIRTUAL_REGION_OWNER_STATE_H
#include "TYPES.H"
struct VirtualRegionOwnerState {
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
