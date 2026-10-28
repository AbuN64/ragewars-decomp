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
#include "RENDER/RUMBLE.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/UNUSED.H"
#include "sdk/os.h"
#include "RENDER/CONTROL_CYCLEACTORSNAPSHOTMODE.H"
#include "SYSTEM/LIST.H"
#include "ENGINE/SCENE_DRAWTRANSITIONCOLOROVERLAY.H"

static inline f32 distanceToNode(func_80285880_S1 *node, CVector3 from) {
    f32 x = from.x - node->position.x;
    f32 y = from.y - node->position.y;
    f32 z = from.z - node->position.z;
    return Gu_Sqrtf(x * x + y * y + z * z);
}
/* Sums the strength of every source in the pool at the given position (inverse-distance falloff scaled by each
 * source's two curves), clamped to 0..1; the pool is read with interrupts disabled. */
f32 Rumble_GetSpatialEffectLevel(func_80285D00_S1 *pool, CVector3 position) {
    f32 value = pool->baseLevel;
    s32 mask = __osDisableInt();
    func_80285880_S1 *node;
    f32 distance, amount, first, second, limit;
    if (D_801462C8.counters.transitionActive == 1 || Cinema_IsSequenceInWindow() != 0) {
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
            first = Control_SampleEffectCurve(&node->amplitudeCurve);
            second = Control_SampleEffectCurve(&node->lifetimeCurve);
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

#include "sdk/os.h"
#include "RENDER/CONTROL_CYCLEACTORSNAPSHOTMODE.H"
#include "ENGINE/SCENE_DRAWTRANSITIONCOLOROVERLAY.H"

/* With interrupts masked, takes the first node of a pool's free list, moves it onto the pool's active list and initialises it with its key, position, two values and owner slot (storing the node there), then binds the two handles named by the key's identifiers, returning the node or null. */

static inline void bind(NodeCode8028469C *node, s32 offset, s32 id) {

    Control_InitializeCurvePlayer((char *)node + offset, Scene_GetEffectCurveRecord(&g_world, id));
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

void Rumble_InitEffectNode(NodeCode8028469C *arg0, Clip *effectClip, CVector3 effectPosition,
                   f32 valueStart, f32 valueEnd, void **ownerSlot) {

    arg0->key = effectClip;
    arg0->position = effectPosition;
    arg0->value0 = valueStart;
    arg0->value1 = valueEnd;
    arg0->owner = ownerSlot;
    if (ownerSlot != 0) {
        *ownerSlot = arg0;
    }
    Control_InitializeCurvePlayer(&arg0->amplitudeHandle,
                  (unsigned int)Scene_GetEffectCurveRecord(&g_world, effectClip->mode));
    Control_InitializeCurvePlayer(&arg0->lifetimeHandle,
                  (unsigned int)Scene_GetEffectCurveRecord(&g_world, effectClip->frames));
}

/** Clear the target word when the pointer field is populated. */
void Rumble_ClearEffectOwnerSlot(char *object) {
    struct NodeCode8028469C *node = (void *)object;
    struct NodeCode8028469C **target = node->owner;
    if (target != 0) {
        *target = 0;
    }
}

/** Store the supplied word at object offset 0x38. */
void Rumble_SetEffectOwnerSlot(void *arg0, int arg1) {
    func_8020D1FC_S1 *record = arg0;
    record->unk38 = arg1;
}

s32 Rumble_TestEffectHandleCompletion(s32 arg0) {
    s32 result;

    result = 0;
    if (Control_AdvanceEffectCurve(arg0 + 0x20) != 0) {
        result = 1;
    } else if (Control_AdvanceEffectCurve(arg0 + 0x2C) != 0) {
        result = 1;
    }
    return result;
}

f32 Rumble_EvaluateSpatialEffectNode(f32 *arg0, u32 arg1, u32 arg2, u32 arg3) {
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
    magnitude = Gu_Sqrtf((dx * dx) + (dy * dy) + (dz * dz));
    if ((magnitude == 0.0f) || ((limit = arg0[6]) == 0.0f)) {
        factor = D_800C4ECC_de;
    } else {
        factor = 0.0f;
        if (magnitude < limit) {
            factor = D_800C4ED0_de - (magnitude / limit);
        }
    }
    factor *= arg0[7];
    first = Control_SampleEffectCurve(&arg0[8]);
    return factor * first * Control_SampleEffectCurve(&arg0[11]);
}

void Rumble_InitPoolNodes(void *effectPool, void *nodeStorage, s32 nodeCount) {

    s32 i;
    NodeCode8028469C *p;
    u32 saved;

    p = nodeStorage;
    saved = __osDisableInt();
    func_80255CA0_de(effectPool, 0, 4);
    func_80255CA0_de(&((PoolRecAt28V1 *)effectPool)->active, 0, 4);
    i = 0;
    if (nodeCount > 0) {
        do {
            func_80255D14_de(effectPool, p);
            i += 1;
            p++;
        } while (i < nodeCount);
    }
    ((PoolRecAt28V1 *)effectPool)->baseLevel = 0;
    __osRestoreInt(saved);
}

NodeCode8028469C *Rumble_AllocatePoolNode(PoolRecAt28V1 *pool, Clip *key, CVector3 position, f32 value0, f32 value1, NodeCode8028469C **owner) {

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

void Rumble_RecycleFinishedEffectNodes(void *pool) {

    NodeCode8028469C *node;
    NodeCode8028469C *next;
    s32 flag;
    u32 saved;
    NodeCode8028469C **inner;

    saved = __osDisableInt();
    for (node = (*active_list(pool)).head; node != 0; node = next) {
        next = node->next;
        flag = 0;
        if (Control_AdvanceEffectCurve(&node->amplitudeHandle) != 0 || Control_AdvanceEffectCurve(&node->lifetimeHandle) != 0) {
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

void Rumble_FreeAllPoolNodes(void *effectPool) {

    void *node;
    void *next;
    s32 saved;

    saved = __osDisableInt();
    node = ((PoolRecAt28V1 *)effectPool)->active.head;
    if (node != 0) {
        do {
            next = ((NodeCode8028469C *)node)->next;
            func_80255ED8_de(&((PoolRecAt28V1 *)effectPool)->active, node);
            func_80255D14_de(effectPool, node);
            node = next;
        } while (node != 0);
    }
    ((PoolRecAt28V1 *)effectPool)->baseLevel = 0;
    __osRestoreInt(saved);
}


/* ROM-grounded data: src/rw_pool_802859D0_CABBC_us_rev1.c */
const unsigned int D_blob_4faf23a8416908d6583f[2] = {
    0x3F800000, 0x3F800000,
};

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C4E04[3] = {
    0x000B0000, 0x00000012, 0x43414D45,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C51C4[3] = {
    0x3F000000, 0x3B088889, 0x4F000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C5184[3] = {
    0xAC450000, 0x01201821, 0x28620002,
};
#endif

#if defined(VERSION_DE)
char rodata_unresolved_800C4ED4[12] =
    "ne__Construc";
#endif
