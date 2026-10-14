#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8020D370.h"
#include "types.h"

/* Records the next stage of a selection: finds the kind-6 link from the selection's node in the route D_8013B364 (stopping at the stage number at 0x1BC), stores its two node ids in that stage's entry, measures the distance from the selection's own node through func_8020C994_de and func_802726BC_de, multiplies the unit directions from each attached object to the stage's node (func_8027207C_de) into a facing term, and stores the distance scaled by that term (made positive for a single object) before advancing the stage count. Returns zero. */












extern func_80205628_S3 D_8013B364;

extern Link *func_8020C9B0_de(func_80205628_S3 *, s32);
extern Vec3 *func_8020C994_de(func_80205628_S3 *, s32);
extern f32 func_802726BC_de(Vec3 *, Vec3 *);
extern void func_8027207C_de(Vec3 *);

s32 func_8020D4AC_de(Selection_func_8020D4AC_de *sel) {
    Vec3 facing;
    Vec3 *node;
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
