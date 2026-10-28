#include "include_asm.h"
#include "COMMON/MANAGER.H"
#include "SCENE/802508E0.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/S1.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "SCENE/802508E0_2.H"
#include "sdk/os.h"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_3.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "RESMGR/802A0888.H"

/* One declaration per symbol for the whole unit; the functions below used to redeclare them locally with
 * conflicting types, which only the MIPS compiler accepted. */
extern struct Shape_func_8021A2D4_de_2 D_80105180;
extern OSMesgQueue D_80101140;
extern CMemEntry **D_80100564;
extern s32 func_80255B2C_de(void *, s32);
extern s32 D_801051A0[3];
extern char D_80100570;
extern CMemEntry *D_80100568;
#include "COMMON/EXTERNS_11.H"

#include "COMMON/ENTRYRECAT18V3.H"
/* The resource manager record at D_80100560: node array, free-slot stack, link records, lists and its lock queue.
 * count (0xBDC) and stamp (0xC20) are the Pool fields used by Cache_AcquirePendingResourceEntry. */
struct ResLink {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 owner;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
};
struct ResMgr {
    struct CMemEntry *nodes;
    struct CMemEntry **slots;
    s32 unk8;
    struct ResLink *links;
    IntrusiveList entries;
    IntrusiveList recent;
    s32 enabled0;
    s32 enabled1;
    s32 unk40;
    s32 unk44;
    s32 selected;
    char pad4C[0xB98 - 0x4C];
    IntrusiveList freeLinks;
    IntrusiveList listBAC;
    IntrusiveList listBC0;
    s32 unkBD4;
    s32 unkBD8;
    s32 count;
    char padBE0[0xC00 - 0xBE0];
    OSMesgQueue lock;
    OSMesg lockSlot[1];
    s32 unkC1C;
    s32 stamp;
};
extern s32 func_80255920_de(void *, s32);
extern s32 func_802567A4_de(OSMesgQueue *);
extern u32 Defs_GetMemorySize(void);
extern s32 osCreateThread(void *, s32, void *, s32, void *, s32);
extern s32 osStartThread(void *);
extern void func_802552E0_de(s32);
extern s32 D_002524B0;
extern s32 D_800CD8BC;
extern s32 D_801008F8;
extern int D_800CB6E0;
extern Manager D_801047E0;
extern struct ResMgr D_80100560;

void Cache_InitializeResourceCache(s32 unused, s32 count) {
    u32 mask;
    u32 unlockMask;
    u32 i;
    void *thread;
    func_802567A4_de(&D_80101140);
    mask = __osDisableInt();
    D_8010515C += 1;
    if (D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    D_800CB6E0 = 0x400;
    if (Defs_GetMemorySize() > 0x400000) {
        D_800CB6E0 *= 2;
    }
    D_80100560.nodes = (struct CMemEntry *)func_80255920_de(&D_801051A0, D_800CB6E0 * sizeof(struct CMemEntry));
    D_80100560.slots = (struct CMemEntry **)func_80255920_de(&D_801051A0, D_800CB6E0 * sizeof(void *));
    D_80100560.links = (struct ResLink *)func_80255920_de(&D_801051A0, D_800CB6E0 * 0x2C);
    osCreateMesgQueue(&D_80100560.lock, D_80100560.lockSlot, 1);
    D_80100560.unk44 = 0;
    D_80100560.unk40 = 0;
    func_80255CA0_de(&D_80100560.entries, 0x18, 0x1C);
    func_80255CA0_de(&D_80100560.recent, 0x20, 0x24);
    D_80100560.count = 0;
    for (i = 0; i < D_800CB6E0; i++) {
        struct CMemEntry *node = &D_80100560.nodes[i];
        node->flags = 0;
        D_80100560.slots[i] = node;
        D_80100560.count += 1;
    }
    D_80100560.enabled0 = D_80100560.enabled1 = 1;
    D_80100560.selected = -1;
    D_80100560.unkBD4 = 0;
    D_80100560.unkBD8 = 0;
    D_80100560.unk8 = 0;
#if defined(VERSION_US)
    D_80100560.unkC1C = 0;
#else
    D_80100560.unkC1C = 1;
#endif
    D_80100560.stamp = 0;
    func_80255CA0_de(&D_80100560.freeLinks, 0x28, 0x24);
    func_80255CA0_de(&D_80100560.listBAC, 0x28, 0x24);
    func_80255CA0_de(&D_80100560.listBC0, 0x28, 0x24);
    for (i = 0; i < D_800CB6E0; i++) {
        struct ResLink *link = &D_80100560.links[i];
        link->owner = 0;
        func_80255D14_de(&D_80100560.freeLinks, link);
    }
    func_802552E0_de(D_800CB6E0);
    osCreateMesgQueue((OSMesgQueue *)D_801047E0.queue, (OSMesg *)(D_801047E0.queue + 0x18), 0x40);
    unlockMask = __osDisableInt();
    D_8010515C -= 1;
    if (D_8010515C != 0) {
        __osRestoreInt(unlockMask);
        osSendMesg((OSMesgQueue *)D_801047E0.lock, 0, 1);
    } else {
        __osRestoreInt(unlockMask);
    }
    /* thread block D_801008F8 - 0x348 followed by its 0x800-byte stack at D_801008F8 */
    XPlus_FillMemory(&D_801008F8, count, 0x800);
    thread = (char *)&D_801008F8 - 0x348;
    osCreateThread(thread, count, &D_002524B0, 0, (char *)&D_801008F8 + 0x800, D_800CD8BC);
    osStartThread(thread);
}





/* Reclaims one pool node: finds the first unlocked node (none of flags 0x702) in the D_80104574 list that
 * was last used five or more frames ago, falling back unless keep_recent is set to the first unlocked node
 * even if recent; the node's resource is released through Cache_DetachResourceRequest and func_80255B2C_de, it is unlinked
 * from its lists, cleared, and pushed back on the free stack, returning func_80255B2C_de's result (0 when no
 * node could be reclaimed). */




extern void Cache_DetachResourceRequest(void *, CMemEntry *);

static inline CMemEntry *find_stale(CMemEntry **recent) {
    CMemEntry *node;

    for (node = D_80104574; node != 0; node = node->next) {
        if (!(node->flags & 0x702)) {
            if ((u32)(D_80105180.field_0 - node->lastUsed) >= 5) {
                return node;
            }
            *recent = node;
            break;
        }
    }
    for (; node != 0; node = node->next) {
        if (!(node->flags & 0x702) && (u32)(D_80105180.field_0 - node->lastUsed) >= 5) {
            return node;
        }
    }
    return 0;
}

/* Allocates a node from the free pool D_8010513C (as Cache_AcquirePendingResourceEntry does: pops it, resets its fields,
 * stamps the current frame and links it through func_80255CB8_de with the caller's 0xC flags); when the pool
 * is empty it runs the collector Cache_EvictResource (keeping the 0x10-flagged kind) and retries once, returning
 * 0 when nothing could be freed. Adapted by inlining Cache_AcquirePendingResourceEntry as a static helper. */






static inline void *pool_alloc(s32 arg1) {
    struct CMemEntry *cacheEntry;

    if (((struct Pool *)&D_8010513C)->count == 0) {
        return 0;
    }
    ((struct Pool *)&D_8010513C)->count -= 1;
    cacheEntry = D_80100564[((struct Pool *)&D_8010513C)->count];
    cacheEntry->flags = 0x800;
    cacheEntry->references = 0;
    cacheEntry->resource = 0;
    cacheEntry->callback = 0;
    cacheEntry->pending = 0;
    cacheEntry->owner = 0;
    cacheEntry->lastUsed = ((struct Pool *)&D_8010513C)->field44;
    func_80255CB8_de((char *)&D_8010513C - 0xBCC, cacheEntry);
    cacheEntry->flags |= (arg1 & 0xC);
    return cacheEntry;
}


extern void Defs_MoveMemory(u32, u32, s32);

extern void func_80255D70_de(void *, s32, s32);

/* Looks up a key in the hash table under the queue lock and, if found, bumps the object's reference count, flags it, stamps it and passes it to func_80255FB8_de, returning the object. Adapted from Cache_TouchResourceByKey, with the count/flag updates added and the object returned. */







extern struct Shape_func_8021A2D4_de_2 D_80101190;


extern void func_80255FB8_de(void *, s32);

void Cache_WaitForResourceSlotRelease(void) {
    s32 lockReleaseCount;
    s32 lockClaimCount;
    s32 slotCursor;
    s32 i;
    s32 pendingReleaseCount;
    u32 reacquireInterruptMask;
    u32 mask;

    pendingReleaseCount = 0;
    slotCursor = 0;
    do {
        if (D_80101134[slotCursor] != 0) {
            if (D_801005A8 != slotCursor) {
                pendingReleaseCount += 1;
                D_801005A0[slotCursor] = 1;
                goto block_7;
            }
            D_80100598[slotCursor] = 0;
            Cache_ClearResourceSlotProtection(0, slotCursor);
            slotCursor += 1;
        } else {
block_7:
            slotCursor += 1;
        }
    } while (slotCursor < 2);
    if (pendingReleaseCount != 0) {
        mask = __osDisableInt();
        lockReleaseCount = D_8010515C - 1;
        D_8010515C = lockReleaseCount;
        if (lockReleaseCount != 0) {
            __osRestoreInt(mask);
            osSendMesg(&D_80101140, 0, 1);
            i = 0;
        } else {
            __osRestoreInt(mask);
            i = 0;
        }
        if (pendingReleaseCount > 0) {
            do {
                osRecvMesg(&D_80101160, 0, 1);
                i += 1;
            } while (i < pendingReleaseCount);
        }
        reacquireInterruptMask = __osDisableInt();
        lockClaimCount = D_8010515C + 1;
        D_8010515C = lockClaimCount;
        if (lockClaimCount != 1) {
            __osRestoreInt(reacquireInterruptMask);
            osRecvMesg(&D_80101140, 0, 1);
            return;
        }
        __osRestoreInt(reacquireInterruptMask);
    }
}

s32 Cache_EvictResource(s32 unused0, s32 unused1, s32 keep_recent) {
    CMemEntry *recent;
    CMemEntry *node;
    s32 result;

    recent = 0;
    node = find_stale(&recent);
    if (node == 0) {
        if (keep_recent == 0) {
            node = recent;
        }
    }
    if (node != 0) {
        Cache_DetachResourceRequest(0, node);
        result = func_80255B2C_de(&D_801051A0, node->resource);
        func_80255ED8_de(&D_80100570, node);
        if (node->flags & 0x1000) {
            func_80255ED8_de(&D_80100584, node);
        }
        if (D_80100568 == node) {
            D_80100568 = 0;
            node->flags = 0;
        } else {
            node->flags = 0;
        }
        *(CMemEntry **)(D_8010513C * 4 + (char *)D_80100564) = node;
        D_8010513C++;
        return result;
    }
    return 0;
}

void *Cache_AcquireResourceNodeWithEviction(s32 unused0, s32 flags) {
    void *node;

    node = pool_alloc(flags);
    if (node == 0) {
        s32 keep = flags & 0x10;

        if (Cache_EvictResource(0, 2, keep == 0) != 0) {
            node = pool_alloc(flags);
        }
    }
    return node;
}

void Cache_CompactResourceHeap(s32 unused, s32 compactAll) {
    IntrusiveList queue;
    Node80254C10 *node;
    Node80254C10 *next;
    Node80254C10 *scan;
    u32 split;
    s32 *arena_end;
    s32 *arena;
    s32 *pool;

    func_80255CA0_de(&queue, 0x20, 0x24);
    if (compactAll != 0 || ((s32 *)&D_80100568)[0] == 0) {
        ((s32 *)&D_80100568)[0] = ((s32 *)&D_80100568)[7];
        if (((s32 *)&D_80100568)[7] == 0) {
            goto drain;
        }
    }

    pool = (s32 *)&D_80100568;
    arena_end = &D_801051A0[2];
    arena = arena_end - 2;
    do {
        node = (Node80254C10 *)pool[0];
        pool[0] = *(s32 *)&node->next;
        if (!(*(s32 *)&node->flags & 0x701) && (u32)(*arena_end + 0x20) < node->start) {
            func_80255B2C_de(arena, node->start);
            split = func_80255920_de(arena, node->end);
            if (split < node->start) {
                Defs_MoveMemory(split, node->start, node->end);
                node->start = split;
                func_80255ED8_de(&pool[7], node);
                func_80255D14_de(&queue, node);
            }
            if (compactAll == 0) {
                break;
            }
        }
    } while (((s32 *)&D_80100568)[0] != 0);

drain:
    node = queue.head;
    while (node != 0) {
        next = node->next;
        func_80255F70_de(&queue);
        scan = D_80100584.head;
        while (scan != 0) {
            if (scan->start > node->start) {
                func_80255D70_de(&D_80100584, (s32)scan, (s32)node);
                break;
            }
            scan = scan->next;
        }
        if (scan == 0) {
            func_80255D14_de(&D_80100584, node);
        }
        node->flags |= 0x1000;
        node = next;
    }
}

void *Cache_RetainResourceByKey(s32 arg0, s32 resourceKey) {
    s32 lockClaimCount;
    s32 lockReleaseCount;
    u32 mask;
    u32 releaseInterruptMask;
    HashNode *node;
    void *value;
    void **out;
    struct IntrusiveList *object;

    mask = __osDisableInt();
    lockClaimCount = D_8010515C + 1;
    D_8010515C = lockClaimCount;
    if (lockClaimCount != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }

    out = &value;
    node = (HashNode *)((s32)D_80101194 +
        ((((resourceKey << 5) ^ ((u32)resourceKey >> 1) ^ ((u32)resourceKey >> 9) ^
           ((u32)resourceKey >> 17)) & D_80101190.field_0) * 0x10));
    if (node->key != resourceKey) {
        goto not_initial;
    }
    value = node->value;
    goto found;
loop_found:
    *out = node->value;
    goto found;
not_initial:
    value = 0;
    if (node == 0) {
        goto found;
    }
loop:
    if (node->key == resourceKey) {
        goto loop_found;
    }
    node = node->next;
    if (node != 0) {
        goto loop;
    }
found:

    object = 0;
    if (value != 0) {
        object = *(void **)value;
        object->prevOffset += 1;
        object->nextOffset |= 0x100;
        object->count = D_80105180.field_0;
        func_80255FB8_de(&D_80100570, object);
    }

    releaseInterruptMask = __osDisableInt();
    lockReleaseCount = D_8010515C - 1;
    D_8010515C = lockReleaseCount;
    if (lockReleaseCount != 0) {
        __osRestoreInt(releaseInterruptMask);
        osSendMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(releaseInterruptMask);
    }
    return object;
}
