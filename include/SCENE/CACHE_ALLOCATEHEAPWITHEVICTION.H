#ifndef SCENE_CACHE_ALLOCATEHEAPWITHEVICTION_H
#define SCENE_CACHE_ALLOCATEHEAPWITHEVICTION_H
#include "COMMON/RESOURCELOCKSTATE.H"
extern void Cache_ClearCurrentResourceSlot(void);
extern void *Cache_AcquirePendingResourceEntry(s32 unused0, s32 requestFlags);
#endif
