#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/PACKEDMESHMATERIAL.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLD.H"
#include "COMMON/S1.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "RENDER/POOLRECAT28V1.H"
#include "TYPES.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "RENDER/8028469C_17.H"

#include "COMMON/TRIPLE.H"
#include "COMMON/UNUSED.H"
#include "sdk/os.h"
#include "RENDER/80263760_8.H"
#include "SYSTEM/80255C40_7.H"
#include "ENGINE/SCENE_12.H"


#if !defined(VERSION_US)
static inline f32 distanceToNode(func_80285880_S1 *node, CVector3 from) {
    f32 x = from.x - node->position.x;
    f32 y = from.y - node->position.y;
    f32 z = from.z - node->position.z;
    return Math_Sqrtf(x * x + y * y + z * z);
}
/* Sums the strength of every source in the pool at the given position (inverse-distance falloff scaled by each
 * source's two curves), clamped to 0..1; the pool is read with interrupts disabled. */
f32 Render_GetSpatialEffectLevel(func_80285D00_S1 *pool, CVector3 position) {
    f32 value = pool->baseLevel;
    s32 mask = __osDisableInt();
    func_80285880_S1 *node;
    f32 distance, amount, first, second, limit;
    if (D_801462C8.counters.transitionActive == 1 || Camera_IsSequenceInWindow() != 0) {
        value = 0.0f;
    } else {
        node = pool->unk14.head;
        while (node != 0) {
            distance = distanceToNode(node, position);
            if (distance == 0.0f || node->unk18 == 0.0f) {
                amount = 1.0f;
            } else if (distance < node->unk18) {
                amount = 1.0f - distance / node->unk18;
            } else {
                amount = 0.0f;
            }
            amount *= node->unk1C;
            first = func_80264EE0_de(&node->amplitudeCurve);
            second = func_80264EE0_de(&node->lifetimeCurve);
            value += amount * first * second;
            node = node->next;
        }
    }
    __osRestoreInt(mask);
    limit = 1.0f;
    if (!(limit < value) && value < 0.0f) {
        return 0.0f;
    }
    return limit < value ? limit : value;
}
#else
INCLUDE_ASM("span_1000", func_80285634);
#endif

#include "sdk/os.h"
#include "RENDER/80263760_8.H"
#include "ENGINE/SCENE_12.H"

/* With interrupts masked, takes the first node of a pool's free list, moves it onto the pool's active list and initialises it with its key, position, two values and owner slot (storing the node there), then binds the two handles named by the key's identifiers, returning the node or null. */












static inline void bind(NodeCode8028469C *node, s32 offset, s32 id) {

    func_80264DE0_de((char *)node + offset, func_8028CE78_de(&D_8011FE88, id));
}

static inline void init(NodeCode8028469C *node, Clip *key, CVector3 position, f32 value0, f32 value1, NodeCode8028469C **owner) {
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

void func_802858B0_de(NodeCode8028469C *arg0, Clip *arg1, CVector3 arg2,
                   f32 arg5, f32 arg6, void **arg7) {

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

extern f32 D_800C4ECC_de;
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
    magnitude = Math_Sqrtf((dx * dx) + (dy * dy) + (dz * dz));
    if ((magnitude == 0.0f) || ((limit = arg0[6]) == 0.0f)) {
        factor = D_800C4ECC_de;
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

void Render_InitPoolNodes(void *arg0, void *arg1, s32 arg2) {

    s32 i;
    NodeCode8028469C *p;
    u32 saved;

    p = arg1;
    saved = __osDisableInt();
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

NodeCode8028469C *func_80285B64_de(PoolRecAt28V1 *pool, Clip *key, CVector3 position, f32 value0, f32 value1, NodeCode8028469C **owner) {

    s32 mask;
    NodeCode8028469C *node;

    mask = __osDisableInt();
    node = pool->free.head;
    if (node != 0) {
        func_80255ED8_de(&pool->free, node);
        func_80255D14_de(&pool->active, node);
        init(node, key, position, value0, value1, owner);
    }
    __osRestoreInt(mask);
    return node;
}

void func_80285C78_de(void *pool) {

    NodeCode8028469C *node;
    NodeCode8028469C *next;
    s32 flag;
    u32 saved;
    NodeCode8028469C **inner;

    saved = __osDisableInt();
    for (node = (*active_list(pool)).head; node != 0; node = next) {
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
        func_80255ED8_de(&(*active_list(pool)), node);
        func_80255D14_de(pool, node);
    }
    __osRestoreInt(saved);
}

void Render_FreeAllPoolNodes(void *arg0) {

    void *node;
    void *next;
    s32 saved;

    saved = __osDisableInt();
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
