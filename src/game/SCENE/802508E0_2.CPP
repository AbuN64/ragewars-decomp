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
#include "SYSTEM/80255C40_7.H"
#include "COMMON/ENTRYRECAT18V3.H"

/* One declaration per symbol for the whole unit; the functions below used to redeclare them locally with
 * conflicting types, which only the MIPS compiler accepted. */
extern struct Shape_func_8021A2D4_de_2 D_80105180;
extern OSMesgQueue D_80101140;
extern ResourceCacheEntry **D_80100564;
extern s32 func_80255B2C_de(void *, s32);
extern s32 D_801051A0[3];
extern char D_80100570;
extern ResourceCacheEntry *D_80100568;
extern u32 func_802BCF30_de(void);

#ifdef NON_MATCHING
#include "COMMON/ENTRYRECAT18V3.H"
/* The resource manager record at D_80100560: node array, free-slot stack, link records, lists and its lock queue.
 * count (0xBDC) and stamp (0xC20) are the Pool fields used by func_80254A28_de. */
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
    struct ResourceCacheEntry *nodes;
    struct ResourceCacheEntry **slots;
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
extern u32 func_80265350_de(void);
extern s32 func_802BAC90_de(void *, s32, void *, s32, void *, s32);
extern s32 func_802BB750_de(void *);
extern void func_80255CA0_de(IntrusiveList *, s32, s32);
extern s32 func_80255D14_de(IntrusiveList *, void *);
extern void func_802552E0_de(s32);
extern void *func_802A001C_de(void *, int, u32);
extern s32 D_002524B0;
extern s32 D_800CD8BC;
extern s32 D_801008F8;
extern int D_800CB6E0;
extern int D_8010515C;
extern Manager D_801047E0;

void func_80250E70_de(s32 arg0, s32 count) {
#define mgr ((struct ResMgr *)&D_80100560)
    u32 mask;
    u32 i;
    void *thread;
    func_802567A4_de(&D_80101140);
    mask = func_802BCF30_de();
    D_8010515C += 1;
    if (D_8010515C != 1) {
        __osRestoreInt(mask);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    D_800CB6E0 = 0x400;
    if (func_80265350_de() > 0x400000) {
        D_800CB6E0 *= 2;
    }
    mgr->nodes = (struct ResourceCacheEntry *)func_80255920_de(&D_801051A0, D_800CB6E0 * sizeof(struct ResourceCacheEntry));
    mgr->slots = (struct ResourceCacheEntry **)func_80255920_de(&D_801051A0, D_800CB6E0 * sizeof(void *));
    mgr->links = (struct ResLink *)func_80255920_de(&D_801051A0, D_800CB6E0 * 0x2C);
    osCreateMesgQueue(&mgr->lock, mgr->lockSlot, 1);
    mgr->unk40 = 0;
    mgr->unk44 = 0;
    func_80255CA0_de(&mgr->entries, 0x18, 0x1C);
    func_80255CA0_de(&mgr->recent, 0x20, 0x24);
    mgr->count = 0;
    for (i = 0; i < D_800CB6E0; i++) {
        struct ResourceCacheEntry *node = &mgr->nodes[i];
        node->flags = 0;
        mgr->slots[i] = node;
        mgr->count += 1;
    }
    mgr->enabled1 = 1;
    mgr->enabled0 = 1;
    mgr->selected = -1;
    mgr->unkBD4 = 0;
    mgr->unkBD8 = 0;
    mgr->unk8 = 0;
    mgr->unkC1C = 1;
    mgr->stamp = 0;
    func_80255CA0_de(&mgr->freeLinks, 0x28, 0x24);
    func_80255CA0_de(&mgr->listBAC, 0x28, 0x24);
    func_80255CA0_de(&mgr->listBC0, 0x28, 0x24);
    for (i = 0; i < D_800CB6E0; i++) {
        struct ResLink *link = &mgr->links[i];
        link->owner = 0;
        func_80255D14_de(&mgr->freeLinks, link);
    }
    func_802552E0_de(D_800CB6E0);
    osCreateMesgQueue((OSMesgQueue *)D_801047E0.queue, (OSMesg *)(D_801047E0.queue + 0x18), 0x40);
    mask = func_802BCF30_de();
    D_8010515C -= 1;
    if (D_8010515C != 0) {
        __osRestoreInt(mask);
        func_802BB420_de((OSMesgQueue *)D_801047E0.lock, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    /* thread block D_801008F8 - 0x348 followed by its 0x800-byte stack at D_801008F8 */
    thread = (char *)&D_801008F8 - 0x348;
    func_802A001C_de(&D_801008F8, count, 0x800);
    func_802BAC90_de(thread, count, &D_002524B0, 0, (char *)&D_801008F8 + 0x800, D_800CD8BC);
    func_802BB750_de(thread);
#undef mgr
}
#else
INCLUDE_ASM("span_1000", func_80250E70_de);
#endif

extern s32 D_80101134[];

extern s32 D_80101160;

extern u32 func_802BCF30_de(void);


/* Reclaims one pool node: finds the first unlocked node (none of flags 0x702) in the D_80104574 list that
 * was last used five or more frames ago, falling back unless keep_recent is set to the first unlocked node
 * even if recent; the node's resource is released through func_80254DD0_de and func_80255B2C_de, it is unlinked
 * from its lists, cleared, and pushed back on the free stack, returning func_80255B2C_de's result (0 when no
 * node could be reclaimed). */



extern ResourceCacheEntry *D_80104574;

extern void func_80254DD0_de(void *, ResourceCacheEntry *);

static inline ResourceCacheEntry *find_stale(ResourceCacheEntry **recent) {
    ResourceCacheEntry *node;

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

/* Allocates a node from the free pool D_8010513C (as func_80254A28_de does: pops it, resets its fields,
 * stamps the current frame and links it through func_80255CB8_de with the caller's 0xC flags); when the pool
 * is empty it runs the collector func_80251328_de (keeping the 0x10-flagged kind) and retries once, returning
 * 0 when nothing could be freed. Adapted by inlining func_80254A28_de as a static helper. */






static inline void *pool_alloc(s32 arg1) {
    struct ResourceCacheEntry *cacheEntry;

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

extern s32 func_80255920_de(void *, s32);

extern void func_80265378_de(u32, u32, s32);

extern void func_80255D70_de(void *, s32, s32);

/* Looks up a key in the hash table under the queue lock and, if found, bumps the object's reference count, flags it, stamps it and passes it to func_80255FB8_de, returning the object. Adapted from func_80253F8C_de, with the count/flag updates added and the object returned. */







extern struct Shape_func_8021A2D4_de_2 D_80101190;


extern void func_80255FB8_de(void *, s32);

void func_802511AC_de(void) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    s32 i;
    s32 var_s1;
    u32 temp_a0;
    u32 mask;

    var_s1 = 0;
    var_s0 = 0;
    do {
        if (D_80101134[var_s0] != 0) {
            if (D_801005A8 != var_s0) {
                var_s1 += 1;
                D_801005A0[var_s0] = 1;
                goto block_7;
            }
            D_80100598[var_s0] = 0;
            func_80254D44_de(0, var_s0);
            var_s0 += 1;
        } else {
block_7:
            var_s0 += 1;
        }
    } while (var_s0 < 2);
    if (var_s1 != 0) {
        mask = func_802BCF30_de();
        temp_v1 = D_8010515C - 1;
        D_8010515C = temp_v1;
        if (temp_v1 != 0) {
            __osRestoreInt(mask);
            func_802BB420_de(&D_80101140, 0, 1);
            i = 0;
        } else {
            __osRestoreInt(mask);
            i = 0;
        }
        if (var_s1 > 0) {
            do {
                func_802BB2A0_de(&D_80101160, 0, 1);
                i += 1;
            } while (i < var_s1);
        }
        temp_a0 = func_802BCF30_de();
        temp_v1_2 = D_8010515C + 1;
        D_8010515C = temp_v1_2;
        if (temp_v1_2 != 1) {
            __osRestoreInt(temp_a0);
            func_802BB2A0_de(&D_80101140, 0, 1);
            return;
        }
        __osRestoreInt(temp_a0);
    }
}

s32 func_80251328_de(s32 unused0, s32 unused1, s32 keep_recent) {
    ResourceCacheEntry *recent;
    ResourceCacheEntry *node;
    s32 result;

    recent = 0;
    node = find_stale(&recent);
    if (node == 0) {
        if (keep_recent == 0) {
            node = recent;
        }
    }
    if (node != 0) {
        func_80254DD0_de(0, node);
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
        *(ResourceCacheEntry **)(D_8010513C * 4 + (char *)D_80100564) = node;
        D_8010513C++;
        return result;
    }
    return 0;
}

void *func_802514A8_de(s32 unused0, s32 flags) {
    void *node;

    node = pool_alloc(flags);
    if (node == 0) {
        s32 keep = flags & 0x10;

        if (func_80251328_de(0, 2, keep == 0) != 0) {
            node = pool_alloc(flags);
        }
    }
    return node;
}

void func_802515F0_de(s32 unused, s32 arg1) {
    IntrusiveList queue;
    Node80254C10 *node;
    Node80254C10 *next;
    Node80254C10 *scan;
    u32 split;
    s32 *arena_end;
    s32 *arena;
    s32 *pool;

    func_80255CA0_de(&queue, 0x20, 0x24);
    if (arg1 != 0 || ((s32 *)&D_80100568)[0] == 0) {
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
                func_80265378_de(split, node->start, node->end);
                node->start = split;
                func_80255ED8_de(&pool[7], node);
                func_80255D14_de(&queue, node);
            }
            if (arg1 == 0) {
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

void *func_802517B4_de(s32 arg0, s32 arg1) {
    s32 temp_v1;
    s32 temp_v1_2;
    u32 mask;
    u32 temp_v0;
    HashNode *node;
    void *value;
    void **out;
    struct IntrusiveList *object;

    mask = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(mask);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }

    out = &value;
    node = (HashNode *)((s32)D_80101194 +
        ((((arg1 << 5) ^ ((u32)arg1 >> 1) ^ ((u32)arg1 >> 9) ^
           ((u32)arg1 >> 17)) & D_80101190.field_0) * 0x10));
    if (node->key != arg1) {
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
    if (node->key == arg1) {
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

    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        __osRestoreInt(temp_v0);
        func_802BB420_de(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(temp_v0);
    }
    return object;
}
