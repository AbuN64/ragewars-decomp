#include "span_1000/code_8020AF9C.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
extern f32 D_800C1D74_de;
#include "TYPES.H"
f32 func_802726BC_de(void *a, void *b);
s32 func_8020C078_de(NavigationGraph *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4, f32 *arg5, f32 arg6) {
    s32 sp20[64];
    s32 sp120[64];
    f32 sp220;
    f32 *temp_a1;
    f32 *temp_s4;
    f32 temp_fv0f;
    f32 var_fs0;
    NavigationBuffer *temp_a0;
    NavigationBuffer *temp_a2;
    NavigationBuffer *temp_v1_2;
    NavigationBuffer *temp_v1_3;
    s32 *var_a0_2;
    s32 *var_a2;
    s32 *var_s1;
    s32 temp_v0;
    s32 var_a0;
    s32 var_fp;
    s32 var_s0;
    s32 var_t0;
    s32 var_t1;
    s32 var_v0;
    NavigationPortal *temp_v1;
    NavigationPortal *temp_v1_4;

    var_fs0 = D_800C1D74_de;
    var_fp = -1;
    var_s0 = 0;
    temp_v0 = arg0->portalCount;
    if (temp_v0 > 0) {
        s32 stride;
        temp_a2 = arg0->portals;
        stride = temp_a2->stride;
        var_a0 = 8;
        do {
            temp_v1 = (void *)(temp_a2->data + (var_a0 - 8));
            var_s0++;
            if (temp_v1->first == arg2 && temp_v1->kind == (u8)arg3) return arg2;
            var_a0 += stride;
        } while (var_s0 < temp_v0);
    }
block_5:
    var_t0 = 0;
    if (arg4 == 0) {
        return -1;
    }
    temp_v1_2 = arg0->points;
    var_t1 = 0;
    var_a0_2 = sp20;
    temp_s4 = navigationRecord(temp_v1_2, arg1);
    if (arg0->portalCount > 0) {
        var_a2 = sp120;
        do {
            temp_v1_3 = arg0->portals;
            temp_v1_4 = navigationRecord(temp_v1_3, var_t0);
            if (temp_v1_4->first == arg1) {
                var_t1 += 1;
                *var_a0_2 = (s32) temp_v1_4->second;
                *var_a2 = var_t0;
                var_a2 += 1;
                var_a0_2 += 1;
            }
            if (temp_v1_4->second == arg1) {
                var_t1 += 1;
                *var_a0_2 = (s32) temp_v1_4->first;
                *var_a2 = var_t0;
                var_a2 += 1;
                var_a0_2 += 1;
            }
            var_t0 += 1;
        } while (var_t0 < arg0->portalCount);
    }
    for (var_s0 = 0; var_s0 < var_t1; var_s0++) {
        NavigationBuffer *table = arg0->points;
        void *point = navigationRecord(table, sp20[var_s0]);
        if (point != temp_s4) {
            sp220 = *arg5 + func_802726BC_de(temp_s4, point);
            if (sp220 < arg6) {
                var_v0 = func_8020C078_de(arg0, arg2, sp20[var_s0], (u8)arg3, arg4 - 1, &sp220, arg6);
            } else var_v0 = -1;
            if (var_v0 != -1 && sp220 < var_fs0) {
                var_fs0 = sp220;
                var_fp = var_v0;
            }
        }
    }
    if (var_fs0 < arg6) {
        *arg5 = var_fs0;
    }
    return var_fp;
}
