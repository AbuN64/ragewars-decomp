#include "RENDER_3/RANGENODE.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_3.H"
#include "include_asm.h"

extern void GraphU64_ScaleVector(void *, void *, f32);

extern void GraphU64_AddVec3(CVector3 *, CVector3 *, CVector3 *);

extern void *Scene_GetStridedWorldRecord(struct Shared_World *object, int index);

void *DynLight_AllocateLightNode(void *intrusiveList, void *arg1);

void DynLight_AccumulateLightDirections(RangeNode **arg0, u32 arg1, u32 arg2, u32 arg3,
                   CVector3 *arg4, f32 *arg5) {
    CVector3 delta;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f3;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    RangeNode *node;
    u16 *radius_ptr;

    node = *arg0;
    if (node != 0) {
        do {
            if (node->active != 0) {
                var_f2 = *(f32 *)&arg1 - (f32)node->x;
                radius_ptr = node->radius;
                if (var_f2 < 0.0f) {
                    var_f2 = -var_f2;
                }
                temp_f1 = *(f32 *)&arg2 - (f32)node->y;
                if (temp_f1 < 0.0f) {
                    var_f2_2 = var_f2 - temp_f1;
                } else {
                    var_f2_2 = var_f2 + temp_f1;
                }
                temp_f0 = *(f32 *)&arg3 - (f32)node->z;
                if (temp_f0 < 0.0f) {
                    var_f2_3 = var_f2_2 - temp_f0;
                } else {
                    var_f2_3 = var_f2_2 + temp_f0;
                }
                temp_f3 = (f32)*radius_ptr;
                if (var_f2_3 < temp_f3) {
                    delta.x = (f32)node->x - *(f32 *)&arg1;
                    delta.y = (f32)node->y - *(f32 *)&arg2;
                    delta.z = (f32)node->z - *(f32 *)&arg3;
                    temp_f20 = D_800C4490_de - (var_f2_3 / temp_f3);
                    GraphU64_NormalizeVec3(&delta);
                    temp_f20_2 = temp_f20 * D_800C4494_de;
                    GraphU64_ScaleVector(&delta, &delta, temp_f20_2);
                    GraphU64_AddVec3(arg4, arg4, &delta);
                    *arg5 -= temp_f20_2;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}

void *DynLight_AllocateWorldLight(s32 arg0, s32 index) {
    return DynLight_AllocateLightNode(arg0, Scene_GetStridedWorldRecord(&g_world, index));
}

void *DynLight_AllocateLightNode(void *intrusiveList, void *arg1) {
    void *temp_s0;

    temp_s0 = ((IntrusiveList *)intrusiveList)[1].head;
    if (temp_s0 != 0) {
        func_80255ED8_de(&((IntrusiveList *)intrusiveList)[1], temp_s0);
        func_80255CB8_de(intrusiveList, temp_s0);
        ((RangeNode *)temp_s0)->radius = arg1;
        ((RangeNode *)temp_s0)->active = 0;
    }
    return temp_s0;
}

void DynLight_ReleaseLight(void *a, s32 b) {
    (((struct Limit *) ((s8 *) b))->limit) = 0;
    func_80255ED8_de(a, b);
    func_80255CB8_de(a + 0x14, b);
}

int DynLight_GetFirstLight(void *intrusiveList) {
    IntrusiveList *list = intrusiveList;
    return (int)list->head;
}

int DynLight_GetNextLight(void *unused0, void *rangeNode) {
    RangeNode *node = rangeNode;
    return (int)node->next;
}

#if !(defined(VERSION_US_REV1))
const unsigned int D_80268A40_CA180[2] = {
    0x3F800000, 0x3ECCCCCD,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80268A40_CA180_us_rev1.c */
const unsigned int D_blob_b6dc0b0a225255b58d34[2] = {
    0x3F800000, 0x3ECCCCCD,
};
#endif
