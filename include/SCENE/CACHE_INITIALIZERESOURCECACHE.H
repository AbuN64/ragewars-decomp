#ifndef SCENE_CACHE_INITIALIZERESOURCECACHE_H
#define SCENE_CACHE_INITIALIZERESOURCECACHE_H
#include "COMMON/MANAGER.H"
extern void *Cache_RetainResourceByKey(s32 cache, s32 resourceKey);
extern void Cache_CompactResourceHeap(s32, s32);
#endif
