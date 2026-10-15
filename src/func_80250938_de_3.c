#include "span_1000/code_802508E0.h"
#include "common/data.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "shared/heap_sorted_list.h"
#include "span_1000/code_80255BEC.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"

extern s32 D_80101134[];

extern s32 D_80101160;

extern u32 func_802BCF30_de(void);

extern void __osRestoreInt(u32);

/* Reclaims one pool node: finds the first unlocked node (none of flags 0x702) in the D_80104574 list that
 * was last used five or more frames ago, falling back unless keep_recent is set to the first unlocked node
 * even if recent; the node's resource is released through func_80254DD0_de and func_80255B2C_de, it is unlinked
 * from its lists, cleared, and pushed back on the free stack, returning func_80255B2C_de's result (0 when no
 * node could be reclaimed). */



extern ResourceCacheEntry *D_80104574;

extern void func_80254DD0_de(void *, ResourceCacheEntry *);

static inline ResourceCacheEntry *find_stale(ResourceCacheEntry **recent) {
    extern s32 D_80105180;
    ResourceCacheEntry *node;

    for (node = D_80104574; node != 0; node = node->next) {
        if (!(node->flags & 0x702)) {
            if ((u32)(D_80105180 - node->lastUsed) >= 5) {
                return node;
            }
            *recent = node;
            break;
        }
    }
    for (; node != 0; node = node->next) {
        if (!(node->flags & 0x702) && (u32)(D_80105180 - node->lastUsed) >= 5) {
            return node;
        }
    }
    return 0;
}

/* Allocates a node from the free pool D_8010513C (as func_80254A28_de does: pops it, resets its fields,
 * stamps the current frame and links it through func_80255CB8_de with the caller's 0xC flags); when the pool
 * is empty it runs the collector func_80251328_de (keeping the 0x10-flagged kind) and retries once, returning
 * 0 when nothing could be freed. Adapted by inlining func_80254A28_de as a static helper. */





extern s32 func_80255CB8_de(void *arg0, s32 arg1);

static inline void *pool_alloc(s32 arg1) {
    extern Pool D_8010513C;
    extern void **D_80100564;
    struct ResourceCacheEntry *temp_s0;

    if (D_8010513C.count == 0) {
        return 0;
    }
    D_8010513C.count -= 1;
    temp_s0 = D_80100564[D_8010513C.count];
    temp_s0->flags = 0x800;
    temp_s0->references = 0;
    temp_s0->resource = 0;
    temp_s0->callback = 0;
    temp_s0->pending = 0;
    temp_s0->owner = 0;
    temp_s0->lastUsed = D_8010513C.field44;
    func_80255CB8_de((char *)&D_8010513C - 0xBCC, (s32)temp_s0);
    temp_s0->flags |= (arg1 & 0xC);
    return temp_s0;
}

extern s32 func_80255920_de(void *, s32);

extern void func_80265378_de(u32, u32, s32);

extern void func_80255D70_de(void *, s32, s32);

/* Looks up a key in the hash table under the queue lock and, if found, bumps the object's reference count, flags it, stamps it and passes it to func_80255FB8_de, returning the object. Adapted from func_80253F8C_de, with the count/flag updates added and the object returned. */







extern struct Shape_func_8021A2D4_de_2 D_80101190;

extern struct Shape_func_8021A2D4_de_2 D_80101194;

extern void func_80255FB8_de(void *, s32);

void func_802511AC_de(void) {
    extern s32 func_802BB420_de(void *, s32, s32);
    extern s32 D_80101140;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    u32 temp_a0;
    u32 temp_v0;

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
        temp_v0 = func_802BCF30_de();
        temp_v1 = D_8010515C - 1;
        D_8010515C = temp_v1;
        if (temp_v1 != 0) {
            __osRestoreInt(temp_v0);
            func_802BB420_de(&D_80101140, 0, 1);
            var_s0_2 = 0;
        } else {
            __osRestoreInt(temp_v0);
            var_s0_2 = 0;
        }
        if (var_s1 > 0) {
            do {
                func_802BB2A0_de(&D_80101160, 0, 1);
                var_s0_2 += 1;
            } while (var_s0_2 < var_s1);
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
    extern void func_80255ED8_de(void *, ResourceCacheEntry *);
    extern s32 func_80255B2C_de(void *, s32);
    extern char D_801051A0;
    extern s32 D_8010513C;
    extern char D_80100570;
    extern ResourceCacheEntry *D_80100568;
    extern ResourceCacheEntry **D_80100564;
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
    extern void func_80255ED8_de(void *, s32);
    extern void func_80255B2C_de(void *, s32);
    extern s32 D_801051A0[3];
    extern s32 D_80100568[];
    IntrusiveList queue;
    Node80254C10 *node;
    Node80254C10 *next;
    Node80254C10 *scan;
    u32 split;
    s32 *arena_end;
    s32 *arena;
    s32 *pool;

    func_80255CA0_de(&queue, 0x20, 0x24);
    if (arg1 != 0 || D_80100568[0] == 0) {
        D_80100568[0] = D_80100568[7];
        if (D_80100568[7] == 0) {
            goto drain;
        }
    }

    pool = D_80100568;
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
                func_80255ED8_de(&pool[7], (s32)node);
                func_80255D14_de(&queue, node);
            }
            if (arg1 == 0) {
                break;
            }
        }
    } while (D_80100568[0] != 0);

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
    extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
    extern struct Shape_func_8021A2D4_de_2 D_80105180;
    extern OSMesgQueue D_80101140;
    extern s32 D_80100570;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;
    HashNode *node;
    void *value;
    void **out;
    struct IntrusiveList *object;

    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(temp_a0);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(temp_a0);
    }

    out = &value;
    node = (HashNode *)((s32)D_80101194.field_0 +
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
