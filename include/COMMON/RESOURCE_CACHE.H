#ifndef COMMON_RESOURCE_CACHE_H
#define COMMON_RESOURCE_CACHE_H
#include "COMMON/MANAGER.H"
#include "os.h"
struct ResLink {
    s32 reservedWord0;
    s32 reservedWord4;
    s32 reservedWord8;
    s32 reservedWordC;
    s32 owner;
    s32 reservedWord14;
    s32 reservedWord18;
    s32 reservedWord1C;
    s32 reservedWord20;
    s32 nextLink;
    s32 prevLink;
};
struct ResMgr {
    struct CMemEntry *nodes;
    struct CMemEntry **slots;
    s32 reservedWord8;
    struct ResLink *links;
    IntrusiveList entries;
    IntrusiveList recent;
    s32 enabled0;
    s32 enabled1;
    s32 reservedWord40;
    s32 reservedWord44;
    s32 selected;
    char pad4C[0xB98 - 0x4C];
    IntrusiveList freeLinks;
    IntrusiveList listBAC;
    IntrusiveList listBC0;
    s32 reservedWordBD4;
    s32 reservedWordBD8;
    s32 count;
    OSMesgQueue heapLockQueue; /* 0xBE0: g_resourceHeapLockQueue */
    OSMesg heapLockMessage;
    s32 heapLockUsers;
    OSMesgQueue lock;
    OSMesg lockSlot[1];
    s32 reservedWordC1C;
    s32 stamp;
};
#endif
