#include "include_asm.h"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ACTORREC.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "TYPES.H"

extern void *func_8020CFE0_de(char *, s32);

extern void *func_8020C994_de(void *, s32);

/** Find the first of an object's four nodes that starts a type-6 link, record it and return 0; return 1 when none does. */








extern Link *func_8020C9B0_de(NavigationGraph *, int);
extern NavigationGraph D_8013B364;

s32 func_8020D9C0_de(Obj_func_8020D9C0_de *obj) {
    CVector3 sum;
    s32 i;
    f32 scale;
    Info *info;
    CVector3 *base;
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
    int j;
    int i;
    Link *link;
    NavigationGraph *graph = &D_8013B364;

    obj->node = -1;
    obj->pending = 0;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < graph->portalCount; i++) {
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

#if defined(VERSION_DE)
unsigned int rodata_unresolved_8020DC04[3] = {
    0x12F214AC, 0x4A120003, 0x9629070C,
};
#endif
