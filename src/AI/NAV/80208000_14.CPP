#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ACTORREC.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

/* Records the next stage of a selection: finds the kind-6 link from the selection's node in the route D_8013B364 (stopping at the stage number at 0x1BC), stores its two node ids in that stage's entry, measures the distance from the selection's own node through func_8020C994_de and func_802726BC_de, multiplies the unit directions from each attached object to the stage's node (func_8027207C_de) into a facing term, and stores the distance scaled by that term (made positive for a single object) before advancing the stage count. Returns zero. */












extern func_80205628_S3 D_8013B364;

extern Link *func_8020C9B0_de(func_80205628_S3 *, s32);
extern CVector3 *func_8020C994_de(func_80205628_S3 *, s32);
extern f32 func_802726BC_de(CVector3 *, CVector3 *);

s32 func_8020D4AC_de(Selection_func_8020D4AC_de *sel) {
    CVector3 facing;
    CVector3 *node;
    s32 i;
    s32 stage;
    Link *link;
    f32 distance;
    f32 term;
    func_80205628_S3 *route;

    node = 0;
    i = 0;
    stage = 0;
    route = &D_8013B364;
    for (; i < route->unkC; i++) {
        link = func_8020C9B0_de(route, i);
        if (link->from == sel->id && link->type == 6) {
            node = func_8020C994_de(route, link->to);
            sel->stages[stage].from = link->from;
            sel->stages[stage].to = link->to;
            if (stage + 1 == sel->stageCount) {
                break;
            }
            stage++;
        }
    }
    distance = func_802726BC_de(node, func_8020C994_de(route, sel->node));
    facing.x = facing.y = facing.z = 1.0f;
    for (i = 0; i < sel->objectCount; i++) {
        if (sel->objects[i] == 0) {
            break;
        }
        sel->dirs[stage].x = node->x - sel->objects[i]->pos.x;
        sel->dirs[stage].y = node->y - sel->objects[i]->pos.y;
        sel->dirs[stage].z = node->z - sel->objects[i]->pos.z;
        func_8027207C_de(&sel->dirs[stage]);
        facing.x *= sel->dirs[stage].x;
        facing.y *= sel->dirs[stage].y;
        facing.z *= sel->dirs[stage].z;
    }
    term = facing.x + facing.y + facing.z;
    if (sel->objectCount == 1 && term < 0.0f) {
        term = -term;
    }
    sel->stages[stage].distance = term * distance;
    sel->stageCount++;
    return 0;
}

#ifdef NON_MATCHING
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "AI/SHARED_PICKUPGOALNODE.H"
#include "COMMON/ACTORREC.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"

extern s32 func_8020CC0C_de(PickupGoalNodeList *, s32, s32);
extern CVector3 *func_8020C994_de(PickupGoalNodeList *, s32);

s32 func_8020D6E4_de(Selection_func_8020D4AC_de *sel) {
    CVector3 avg;
    Shared_PickupGoalNode *info;
    CVector3 *node;
    s32 next;
    s32 best;
    s32 i;
    f32 inv;

    next = -1;
    i = 0;
    best = sel->objectCount;
    if (best > 0) {
        for (; i < sel->objectCount; i++) {
            if (0.0f < sel->stages[i].distance) {
                best = i;
            }
        }
    }
    if (best != sel->objectCount) {
        if (sel->stages[best].to >= 0) {
            for (i = 0; i < 3; i++) {
                if (sel->ids[i] == sel->id) {
                    next = sel->ids[i + 1];
                    break;
                }
            }
            if (next != -1 && func_8020CC0C_de(&D_8013B364, sel->id, sel->stages[best].to) != -1 &&
                func_8020CC0C_de(&D_8013B364, next, sel->stages[best].to) != -1) {
                i = 3;
                do {
                    if (sel->ids[i - 1] == sel->id) {
                        sel->ids[i] = sel->stages[best].to;
                        break;
                    }
                    sel->ids[i] = sel->ids[i - 1];
                    i--;
                } while (i > 0);
                avg.z = 0.0f;
                avg.y = 0.0f;
                avg.x = 0.0f;
                for (i = 0; i < sel->objectCount; i++) {
                    avg.x += sel->dirs[i].x;
                    avg.y += sel->dirs[i].y;
                    avg.z += sel->dirs[i].z;
                }
                inv = D_800C1DB4_de / (f32)sel->objectCount;
                avg.x = avg.x * inv;
                avg.y = avg.y * inv;
                avg.z = avg.z * inv;
                info = func_8020CFE0_de(&D_8013B364, sel->stages[best].to);
                avg.x = avg.x * (f32)info->unknown14[0];
                avg.y = avg.y * (f32)info->unknown14[0];
                avg.z = avg.z * (f32)info->unknown14[0];
                node = func_8020C994_de(&D_8013B364, sel->stages[best].to);
                sel->result.x = node->x + avg.x;
                sel->result.y = node->y + avg.y;
                sel->result.z = node->z + avg.z;
                sel->stageCount++;
                sel->lastNode = sel->stages[best].to;
                return 0;
            }
        }
    }
    sel->failed = 0;
    sel->stageCount += 0x14;
    return 1;
}
#else
INCLUDE_ASM("span_1000", func_8020D6E4_de);
#endif
