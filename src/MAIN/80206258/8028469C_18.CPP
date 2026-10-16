#include "span_1000/code_8028469C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/world.h"
#include "span_1000/code_80255BEC.h"
#include "span_1000/code_802646F4.h"
#include "span_1000/code_8028567C.h"
#include "TYPES.H"
#include "shared/func_8027AD4C_de_closed.h"


extern f32 func_80264EE0_de(void *arg0);

/* With interrupts masked, takes the first node of a pool's free list, moves it onto the pool's active list and initialises it with its key, position, two values and owner slot (storing the node there), then binds the two handles named by the key's identifiers, returning the node or null. */












static inline void bind(NodeCode8028469C *node, s32 offset, s32 id) {
    extern s32 func_8028CE78_de(void *table, s32 id);
    extern void func_80264DE0_de(void *slot, s32 handle);
    func_80264DE0_de((char *)node + offset, func_8028CE78_de(&D_8011FE88, id));
}

static inline void init(NodeCode8028469C *node, Clip *key, Vec3 position, f32 value0, f32 value1, NodeCode8028469C **owner) {
    node->key = key;
    node->position = position;
    node->value0 = value0;
    node->value1 = value1;
    node->owner = owner;
    if (owner != 0) {
        *owner = node;
    }
    bind(node, 0x20, key->mode);
    bind(node, 0x2C, key->frames);
}

static inline IntrusiveList *active_list(PoolRecAt28V1 *pool) {
    return &pool->active;
}

void func_802858B0_de(NodeCode8028469C *arg0, Clip *arg1, Vec3 arg2,
                   f32 arg5, f32 arg6, void **arg7) {
    extern void *func_8028CE78_de(void *object, int index);
    extern void func_80264DE0_de(unsigned int *record, unsigned int value);
    arg0->key = arg1;
    arg0->position = arg2;
    arg0->value0 = arg5;
    arg0->value1 = arg6;
    arg0->owner = arg7;
    if (arg7 != 0) {
        *arg7 = arg0;
    }
    func_80264DE0_de(&arg0->amplitudeHandle,
                  (unsigned int)func_8028CE78_de(&D_8011FE88, arg1->mode));
    func_80264DE0_de(&arg0->lifetimeHandle,
                  (unsigned int)func_8028CE78_de(&D_8011FE88, arg1->frames));
}

/** Clear the target word when the pointer field is populated. */
void func_80285960_de(char *object) {
    struct NodeCode8028469C *node = (void *)object;
    struct NodeCode8028469C **target = node->owner;
    if (target != 0) {
        *target = 0;
    }
}

/** Store the supplied word at object offset 0x38. */
void func_80285974_de(void *arg0, int arg1) {
    func_8020D1FC_S1 *record = arg0;
    record->unk38 = arg1;
}

s32 func_8028597C_de(s32 arg0) {
    s32 result;

    result = 0;
    if (func_80264DF0_de(arg0 + 0x20) != 0) {
        result = 1;
    } else if (func_80264DF0_de(arg0 + 0x2C) != 0) {
        result = 1;
    }
    return result;
}

f32 func_802859D0_de(f32 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    f32 magnitude;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 limit;
    f32 factor;
    f32 first;

    dx = *(f32 *)&arg1 - arg0[3];
    dy = *(f32 *)&arg2 - arg0[4];
    dz = *(f32 *)&arg3 - arg0[5];
    magnitude = func_802B72B0_de((dx * dx) + (dy * dy) + (dz * dz));
    if ((magnitude == 0.0f) || ((limit = arg0[6]) == 0.0f)) {
        factor = *(&D_800C4EC8_de + 1);
    } else {
        factor = 0.0f;
        if (magnitude < limit) {
            factor = D_800C4ED0_de - (magnitude / limit);
        }
    }
    factor *= arg0[7];
    first = func_80264EE0_de(&arg0[8]);
    return factor * first * func_80264EE0_de(&arg0[11]);
}

void func_80285AC4_de(void *arg0, void *arg1, s32 arg2) {
    extern void __osRestoreInt(u32);
    extern u32 func_802BCF30_de(void);
    s32 i;
    NodeCode8028469C *p;
    u32 saved;

    p = arg1;
    saved = func_802BCF30_de();
    func_80255CA0_de(arg0, 0, 4);
    func_80255CA0_de(&((PoolRecAt28V1 *)arg0)->active, 0, 4);
    i = 0;
    if (arg2 > 0) {
        do {
            func_80255D14_de(arg0, p);
            i += 1;
            p++;
        } while (i < arg2);
    }
    ((PoolRecAt28V1 *)arg0)->baseLevel = 0;
    __osRestoreInt(saved);
}

NodeCode8028469C *func_80285B64_de(PoolRecAt28V1 *pool, Clip *key, Vec3 position, f32 value0, f32 value1, NodeCode8028469C **owner) {
    extern void __osRestoreInt(s32 mask);
    extern s32 func_802BCF30_de(void);
    extern void func_80255ED8_de(IntrusiveList *list, NodeCode8028469C *node);
    s32 mask;
    NodeCode8028469C *node;

    mask = func_802BCF30_de();
    node = pool->free.head;
    if (node != 0) {
        func_80255ED8_de(&pool->free, node);
        func_80255D14_de(&pool->active, node);
        init(node, key, position, value0, value1, owner);
    }
    __osRestoreInt(mask);
    return node;
}

void func_80285C78_de(void *arg0) {
    extern void __osRestoreInt(u32);
    extern u32 func_802BCF30_de(void);
    extern void func_80255ED8_de(void *, void *);
    NodeCode8028469C *node;
    NodeCode8028469C *next;
    s32 flag;
    u32 saved;
    NodeCode8028469C **inner;

    saved = func_802BCF30_de();
    for (node = (*active_list(arg0)).head; node != 0; node = next) {
        next = node->next;
        flag = 0;
        if (func_80264DF0_de(&node->amplitudeHandle) != 0 || func_80264DF0_de(&node->lifetimeHandle) != 0) {
            flag = 1;
        }
        if (flag == 0) {
            continue;
        }
        inner = node->owner;
        if (inner != 0) {
            *inner = 0;
        }
        func_80255ED8_de(&(*active_list(arg0)), node);
        func_80255D14_de(arg0, node);
    }
    __osRestoreInt(saved);
}

void func_80285D30_de(void *arg0) {
    extern void __osRestoreInt(s32 arg0);
    extern s32 func_802BCF30_de(void);
    extern void func_80255ED8_de(void *, s32);
    void *node;
    void *next;
    s32 saved;

    saved = func_802BCF30_de();
    node = ((PoolRecAt28V1 *)arg0)->active.head;
    if (node != 0) {
        do {
            next = ((NodeCode8028469C *)node)->next;
            func_80255ED8_de(&((PoolRecAt28V1 *)arg0)->active, node);
            func_80255D14_de(arg0, node);
            node = next;
        } while (node != 0);
    }
    ((PoolRecAt28V1 *)arg0)->baseLevel = 0;
    __osRestoreInt(saved);
}
