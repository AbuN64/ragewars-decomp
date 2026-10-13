#include "shared/navigation_graph.h"
#include "stddef.h"
f32 func_802726BC_de(f32 *a, f32 *b);
s32 func_8020B95C_de(NavigationGraph *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4) {
    NavigationPoint *var_s7;
    NavigationBuffer *temp_v1;
    NavigationBuffer *temp_v1_2;
    s32 *var_a3;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;
    s32 temp_a0;
    s32 temp_a0_2;
    NavigationPortal *temp_v1_3;

    if (arg2 != -1) {
        temp_v1 = arg0->points;
        var_s7 = navigationRecord(temp_v1, arg2);
    } else {
        var_s7 = NULL;
    }
    var_t0 = 0;
    var_s4 = 0;
    if (arg0->portalCount > 0) {
        s32 reversibleKind4 = 4;
        s32 reversibleKind1 = 1;
        s32 reversibleKind7 = 7;
        s32 noRoom = -1;
        s32 forwardExcludedKind = 6;
        var_a3 = arg3;
        do {
            temp_v1_2 = arg0->portals;
            temp_v1_3 = navigationRecord(temp_v1_2, var_t0);
            if (arg4 != 0) {
                if (temp_v1_3->second == arg1) {
                    var_s4 += 1;
                    *var_a3 = (s32) temp_v1_3->first;
                    var_a3 += 1;
                }
                if (temp_v1_3->first == arg1) {
                    temp_a0 = temp_v1_3->kind;
                    if (temp_a0 != reversibleKind4) {
                        if ((s32) temp_a0 < 5) {
                            var_v0 = 0;
                            if (temp_a0 != reversibleKind1) {

                            } else {
                                goto block_14;
                            }
                        } else {
                            var_v0 = 0;
                            if (temp_a0 == reversibleKind7) {
                                goto block_14;
                            }
                        }
                    } else {
block_14:
                        var_v0 = 1;
                    }
                    if (var_v0 != 0) {
                        var_s4 += 1;
                        *var_a3 = (s32) temp_v1_3->second;
                        var_a3 += 1;
                    }
                }
                if ((arg2 != noRoom) && (temp_v1_3->first == arg1) && (temp_v1_3->second == arg2) && (var_s7 != NULL) && (var_s7->attributes.halves.flags & 2)) {
                    *var_a3 = arg2;
                    var_a3 += 1;
                    var_s4 += 1;
                }
            } else {
                if ((temp_v1_3->first == arg1) && (temp_v1_3->kind != forwardExcludedKind)) {
                    var_s4 += 1;
                    *var_a3 = (s32) temp_v1_3->second;
                    var_a3 += 1;
                }
                if (temp_v1_3->second == arg1) {
                    temp_a0_2 = temp_v1_3->kind;
                    if (temp_a0_2 != reversibleKind4) {
                        if ((s32) temp_a0_2 < 5) {
                            var_v0_2 = 0;
                            if (temp_a0_2 != reversibleKind1) {

                            } else {
                                goto block_32;
                            }
                        } else {
                            var_v0_2 = 0;
                            if (temp_a0_2 == reversibleKind7) {
                                goto block_32;
                            }
                        }
                    } else {
block_32:
                        var_v0_2 = 1;
                    }
                    if (var_v0_2 != 0) {
                        var_s4 += 1;
                        *var_a3 = (s32) temp_v1_3->first;
                        var_a3 += 1;
                    }
                }
            }
            var_t0 += 1;
        } while (var_t0 < arg0->portalCount);
    }
    if (arg2 == -1) return var_s4;
    if (var_s7 != 0) {
            for (var_s5 = 0; var_s5 < var_s4 - 1; var_s5++) {
                for (var_s2 = var_s5 + 1; var_s2 < var_s4; var_s2++) {
                    NavigationBuffer *table = arg0->points;
                    s32 firstIndex = arg3[var_s5] * table->stride;
                    s32 secondIndex = arg3[var_s2] * table->stride;
                    void *first = table->data + firstIndex;
                    void *other = table->data + secondIndex;
                    f32 distance = func_802726BC_de(&var_s7->position.x, first);
                    if (func_802726BC_de(&var_s7->position.x, other) < distance) {
                        s32 saved = arg3[var_s5];
                        arg3[var_s5] = arg3[var_s2];
                        arg3[var_s2] = saved;
                    }
                }
            }
    }
    return var_s4;
}
