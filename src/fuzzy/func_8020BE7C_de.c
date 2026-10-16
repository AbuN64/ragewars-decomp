#include "span_1000/code_8020AF9C.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
extern f32 D_800C1D70_de;
#include "TYPES.H"
f32 func_802726BC_de(void *a, void *b);
s32 func_8020C078_de(NavigationGraph *, s32, s32, s32, s32, f32 *, f32);

static __inline__ s32 navigationNeighbors(NavigationGraph *graph, s32 key, s32 *out, s32 *edges) {
    s32 i = 0;
    s32 count = 0;
    if (graph->portalCount > 0) {
        do {
            NavigationPortal *portal = navigationRecord(graph->portals, i);
            if (portal->first == key) {
                count++;
                *out = portal->second;
                *edges = i;
                edges++;
                out++;
            }
            if (portal->second == key) {
                count++;
                *out = portal->first;
                *edges = i;
                edges++;
                out++;
            }
            i++;
        } while (i < graph->portalCount);
    }
    return count;
}

s32 func_8020BE7C_de(NavigationGraph *arg0, s32 arg1, u8 arg2, s32 arg3) {
    s32 sp20[64];
    s32 sp120[64];
    f32 sp220;
    f32 *sp224;
    f32 var_fs0;
    NavigationBuffer *temp_a1;
    NavigationBuffer *temp_a2;
    NavigationBuffer *temp_v1_2;
    NavigationBuffer *temp_v1_3;
    s32 *var_a0_2;
    s32 *var_a1;
    s32 *var_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a0;
    s32 var_fp;
    s32 var_s0;
    s32 var_t0;
    s32 var_t1;
    s32 var_v0;
    NavigationPortal *temp_v1;
    NavigationPortal *temp_v1_4;

    var_fp = -1;
    var_s0 = 0;
    temp_v0 = arg0->portalCount;
    var_fs0 = D_800C1D70_de;
    if (temp_v0 > 0) {
        s32 stride;
        temp_a1 = arg0->portals;
        stride = temp_a1->stride;
        var_a0 = 8;
        do {
            temp_v1 = (void *)(temp_a1->data + (var_a0 - 8));
            var_s0++;
            if (temp_v1->first == arg1 && temp_v1->kind == (u8)arg2) return arg1;
            var_a0 += stride;
        } while (var_s0 < temp_v0);
    }
block_7:
    temp_v1_2 = arg0->points;
    sp224 = navigationRecord(temp_v1_2, arg1);
    var_t1 = navigationNeighbors(arg0, arg1, sp20, sp120);
    for (var_s0 = 0; var_s0 < var_t1; var_s0++) {
        NavigationBuffer *table = arg0->points;
        sp220 = func_802726BC_de(sp224, navigationRecord(table, sp20[var_s0]));
        temp_v0_2 = func_8020C078_de(arg0, arg1, sp20[var_s0], (u8)arg2, arg3 - 1, &sp220, var_fs0);
        if (temp_v0_2 != -1) {
            var_fs0 = sp220;
            var_fp = temp_v0_2;
        }
    }
    return var_fp;
}
