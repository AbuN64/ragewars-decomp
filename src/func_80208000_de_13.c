#include "span_1000/code_80208000.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8020D370.h"
#include "types.h"

extern void *func_8020CFE0_de(char *, s32);

extern void *func_8020C994_de(void *, s32);

/** Find the first of an object's four nodes that starts a type-6 link, record it and return 0; return 1 when none does. */








extern Link *func_8020C9B0_de(func_80205628_S3 *, int);

s32 func_8020D9C0_de(Obj_func_8020D9C0_de *obj) {
    extern s32 D_8013B364;
    Vec3 sum;
    s32 i;
    f32 scale;
    Info *info;
    Vec3 *base;
    void *global;

    sum.x = sum.y = sum.z = 0.0f;
    global = &D_8013B364;
    for (i = 0; i < obj->count; i++) {
        sum.x += obj->points[i].x;
        sum.y += obj->points[i].y;
        sum.z += obj->points[i].z;
    }
    if (obj->count == 0)
        return 1;

    scale = D_800C1DB8_de / (f32)obj->count;
    sum.x *= scale;
    sum.y *= scale;
    sum.z *= scale;
    info = func_8020CFE0_de(global, obj->infoIndex);
    sum.x *= info->scale;
    sum.y *= info->scale;
    sum.z *= info->scale;
    base = func_8020C994_de(global, obj->infoIndex);
    obj->result.x = base->x + sum.x;
    obj->result.y = base->y + sum.y;
    obj->result.z = base->z + sum.z;
    return 1;
}

int func_8020DB14_de(Obj_func_8020DB14_de *obj) {
    extern func_80205628_S3 D_8013B364;
    int j;
    int i;
    Link *link;
    func_80205628_S3 *graph = &D_8013B364;

    obj->node = -1;
    obj->pending = 0;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < graph->unkC; i++) {
            link = func_8020C9B0_de(graph, i);
            if (link->from == obj->nodes[j] && link->type == 6) {
                obj->hits++;
                obj->node = obj->nodes[j];
                return 0;
            }
        }
    }
    return 1;
}
