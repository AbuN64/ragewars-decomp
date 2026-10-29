#ifndef COMMON_CACHE_ALLOCATERESOURCE_H
#define COMMON_CACHE_ALLOCATERESOURCE_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"

struct CacheResourceBlockView *Cache_AllocateResource(s32, s32, u32, void *);
extern s32 g_pakPakStateNoteName;

extern s32 g_controllerPakNoteLists;
#endif
