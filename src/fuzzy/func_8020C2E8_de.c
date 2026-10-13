#include "span_1000/code_8020AF9C.h"
f32 func_802726F8_de(void *, void *);
extern f32 D_800C1D78_de;
extern f32 D_800C1D7C_de;

f32 func_8020C2E8_de(NavigationGraph *arg0, NavigationSearchNode *arg1) {
    s32 sp10[64];
    s32 sp110[64];
    NavigationBuffer *temp_a0;
    NavigationBuffer *temp_a0_2;
    NavigationBuffer *temp_a0_3;
    NavigationBuffer *temp_v1;
    NavigationBuffer *temp_v1_2;
    NavigationBuffer *temp_v1_4;
    s32 *var_s1;
    s32 *var_s1_2;
    f32 temp_fs0f;
    f32 temp_fs0f_2;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 var_fs0;
    s32 *var_a0;
    s32 *var_a0_2;
    s32 *var_a1;
    s32 *var_s4;
    s32 *var_v1;
    s32 temp_a1;
    s32 temp_a1_3;
    s32 temp_t1;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s3;
    s32 var_t0;
    NavigationPortal *temp_a1_2;
    u8 *temp_s2;
    u8 *temp_s2_2;
    NavigationPortal *temp_v1_3;

    temp_a0 = arg0->points;
    var_s0 = 0;
    var_fs0 = D_800C1D78_de;
    var_s1 = arg0->goals;
    temp_fs0f = var_fs0;
    temp_s2 = navigationRecord(temp_a0, arg1->key);
    do {
        temp_a1 = *var_s1;
        if ((temp_a1 != -1) && ((temp_v1 = arg0->points, temp_fv0 = func_802726F8_de(temp_s2, navigationRecord(temp_v1, temp_a1)), (temp_fv0 < var_fs0)) || (var_fs0 == temp_fs0f))) {
            var_fs0 = temp_fv0;
        }
        var_s0 += 1;
        var_s1++;
    } while (var_s0 < 0x40);
    var_s0_2 = 0;
    var_a0 = sp110;
    var_v1 = sp10;
    do {
        *var_v1 = -1;
        *var_a0 = -1;
        var_a0++;
        var_s0_2 += 1;
        var_v1++;
    } while (var_s0_2 < 0x40);
    temp_t1 = arg1->key;
    var_a2 = 0;
    var_t0 = 0;
    var_a0_2 = sp10;
    if (arg0->portalCount > 0) {
        var_a1 = sp110;
        do {
            temp_v1_2 = arg0->portals;
            temp_v1_3 = navigationRecord(temp_v1_2, var_a2);
            if (temp_v1_3->first == temp_t1) {
                var_t0 += 1;
                *var_a0_2 = (s32) temp_v1_3->second;
                *var_a1 = var_a2;
                var_a1++;
                var_a0_2++;
            }
            if (temp_v1_3->second == temp_t1) {
                var_t0 += 1;
                *var_a0_2 = (s32) temp_v1_3->first;
                *var_a1 = var_a2;
                var_a1++;
                var_a0_2++;
            }
            var_a2 += 1;
        } while (var_a2 < arg0->portalCount);
    }
    var_s3 = 0;
    if (var_t0 > 0) {
        temp_fs0f_2 = D_800C1D7C_de;
        var_s4 = sp110;
        do {
            temp_a0_2 = arg0->portals;
            temp_a1_2 = navigationRecord(temp_a0_2, *var_s4);
            if ((temp_a1_2->kind == 9) && (temp_a1_2->first == arg1->key)) {
                temp_a0_3 = arg0->points;
                var_s0_3 = 0;
                var_s1_2 = arg0->goals;
                temp_s2_2 = navigationRecord(temp_a0_3, temp_a1_2->second);
                do {
                    temp_a1_3 = *var_s1_2;
                    if ((temp_a1_3 != -1) && ((temp_v1_4 = arg0->points, temp_fv0_2 = func_802726F8_de(temp_s2_2, navigationRecord(temp_v1_4, temp_a1_3)), (temp_fv0_2 < var_fs0)) || (var_fs0 == temp_fs0f_2))) {
                        var_fs0 = temp_fv0_2;
                    }
                    var_s0_3 += 1;
                    var_s1_2++;
                } while (var_s0_3 < 0x40);
            }
            var_s3 += 1;
            var_s4++;
        } while (var_s3 < var_t0);
    }
    return var_fs0;
}
