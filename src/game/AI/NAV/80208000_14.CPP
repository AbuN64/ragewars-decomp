#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ACTORREC.H"
#include "AI/SHARED_PICKUPGOALNODE.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

/* Records the next stage of a selection: finds the kind-6 link from the selection's node in the route D_8013B364 (stopping at the stage number at 0x1BC), stores its two node ids in that stage's entry, measures the distance from the selection's own node through func_8020C994_de and func_802726BC_de, multiplies the unit directions from each attached object to the stage's node (func_8027207C_de) into a facing term, and stores the distance scaled by that term (made positive for a single object) before advancing the stage count. Returns zero. */













extern Link *Nav_GetStridedTableEntry(PickupGoalNodeList *, s32);
extern CVector3 *Nav_GetGraphPoint(PickupGoalNodeList *, s32);
extern f32 func_802726BC_de(CVector3 *, CVector3 *);

s32 Nav_AppendDirectionalRouteStage(SelectionNavAppendDirectionalRouteStage *sel) {
    CVector3 facing;
    CVector3 *node;
    s32 i;
    s32 stage;
    Link *link;
    f32 distance;
    f32 term;
    PickupGoalNodeList *route;

    node = 0;
    i = 0;
    stage = 0;
    route = &D_8013B364;
    for (; i < route->count; i++) {
        link = Nav_GetStridedTableEntry(route, i);
        if (link->from == sel->id && link->type == 6) {
            node = Nav_GetGraphPoint(route, link->to);
            sel->stages[stage].from = link->from;
            sel->stages[stage].to = link->to;
            if (stage + 1 == sel->stageCount) {
                break;
            }
            stage++;
        }
    }
    distance = func_802726BC_de(node, Nav_GetGraphPoint(route, sel->node));
    facing.x = facing.y = facing.z = 1.0f;
    for (i = 0; i < sel->objectCount; i++) {
        if (sel->objects[i] == 0) {
            break;
        }
        sel->dirs[stage].x = node->x - sel->objects[i]->pos.x;
        sel->dirs[stage].y = node->y - sel->objects[i]->pos.y;
        sel->dirs[stage].z = node->z - sel->objects[i]->pos.z;
        Particle_NormalizeVec3(&sel->dirs[stage]);
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

extern s32 Nav_FindLinkIndex(PickupGoalNodeList *list, s32 from, s32 to);
s32 Nav_InsertPickupRouteNode(SelectionNavAppendDirectionalRouteStage *sel) {
    CVector3 avg;
    Shared_PickupGoalNode *info;
    CVector3 *node;
    PickupGoalNodeList *list;
    s32 next;
    s32 best;
    s32 i;
    s32 count;
    f32 inv;

    next = -1;
    count = 0;
    best = sel->objectCount;
    list = &D_8013B364;
    for (i = 0; i < sel->objectCount; i++) {
        if (sel->stages[i].distance > count) {
            best = i;
        }
    }
    count = sel->objectCount;
    if (best == count) {
        sel->failed = 0;
        sel->stageCount += 0x14;
        return 1;
    }
    if (sel->stages[best].to < 0) {
        sel->failed = 0;
        sel->stageCount += 0x14;
        return 1;
    }
    for (i = 0; i < 3; i++) {
        if (sel->ids[i] == sel->id) {
            next = sel->ids[i + 1];
            break;
        }
    }
    if (next == -1 || Nav_FindLinkIndex(list, sel->id, sel->stages[best].to) == -1 ||
        Nav_FindLinkIndex(list, next, sel->stages[best].to) == -1) {
        sel->failed = 0;
        sel->stageCount += 0x14;
        return 1;
    }
    for (i = 3; i > 0; i--) {
        if (sel->ids[i - 1] == sel->id) {
            sel->ids[i] = sel->stages[best].to;
            break;
        }
        sel->ids[i] = sel->ids[i - 1];
    }
    avg.x = avg.y = avg.z = 0.0f;
    for (i = 0; i < sel->objectCount; i++) {
        avg.x += sel->dirs[i].x;
        avg.y += sel->dirs[i].y;
        avg.z += sel->dirs[i].z;
    }
    count = sel->objectCount;
    inv = 1.0f / (f32)count;
    avg.x = avg.x * inv;
    avg.y = avg.y * inv;
    avg.z = avg.z * inv;
    info = Nav_FindSearchNode(list, sel->stages[best].to);
    avg.x = avg.x * info->radius;
    avg.y = avg.y * info->radius;
    avg.z = avg.z * info->radius;
    node = Nav_GetGraphPoint(list, sel->stages[best].to);
    sel->result.x = node->x + avg.x;
    sel->result.y = node->y + avg.y;
    sel->result.z = node->z + avg.z;
    sel->lastNode = sel->stages[best].to;
    sel->stageCount++;
    return 0;
}
