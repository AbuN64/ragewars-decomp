#include "shared/navigation_graph.h"
f32 func_802726F8_de(f32 *, f32 *);
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
    f32 temp_fs0f;
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
    s32 var_s3;
    s32 var_t0;
    s32 neighborCount;
    NavigationPortal *temp_a1_2;
    NavigationPoint *temp_s2;
    NavigationPoint *temp_s2_2;
    NavigationPortal *temp_v1_3;

    temp_a0 = arg0->points;
    var_s0 = 0;
    var_fs0 = D_800C1D78_de;
    temp_fs0f = var_fs0;
    temp_s2 = navigationRecord(temp_a0, arg1->key);
    for (var_s0 = 0; var_s0 < 0x40; var_s0++) {
        temp_a1 = arg0->goals[var_s0];
        if (temp_a1 == -1) continue;
        temp_v1 = arg0->points;
        temp_fv0 = func_802726F8_de(&temp_s2->position.x, navigationRecord(temp_v1, temp_a1));
        if (temp_fv0 < var_fs0 || var_fs0 == temp_fs0f) var_fs0 = temp_fv0;
    }
    for (var_s0 = 0; var_s0 < 0x40; var_s0++) {
        sp10[var_s0] = -1;
        sp110[var_s0] = -1;
    }
    {
 s32 temp_t1 = arg1->key;
 s32 *out=sp10,*ids=sp110;
 s32 var_a3=0,var_t0=0; s32 *var_a0_3,*var_a1; NavigationBuffer *temp_v1;NavigationPortal *temp_v1_2;
        if (arg0->portalCount > 0) {
            var_a1 = ids;
            var_a0_3=out;

            do {
                temp_v1 = arg0->portals;
                temp_v1_2=navigationRecord(temp_v1,var_a3);
                if (temp_v1_2->first == temp_t1) {
                    var_t0 += 1;
                    *var_a0_3 = temp_v1_2->second;
                    *var_a1 = var_a3;
                    var_a1++;
                    var_a0_3++;
                }
                if (temp_v1_2->second == temp_t1) {
                    var_t0 += 1;
                    *var_a0_3 = temp_v1_2->first;
                    *var_a1 = var_a3;
                    var_a1++;
                    var_a0_3++;
                }
                var_a3 += 1;
            } while (var_a3 < arg0->portalCount);
        }
neighborCount = var_t0;
}
    var_t0=neighborCount;
    var_s3 = 0;
    {
        for (var_s3 = 0; var_s3 < var_t0; var_s3++) {
            temp_a0_2 = arg0->portals;
            temp_a1_2 = navigationRecord(temp_a0_2, sp110[var_s3]);
            if ((temp_a1_2->kind == 9) && (temp_a1_2->first == arg1->key)) {
                temp_a0_3 = arg0->points;
                var_s0 = 0;
                temp_s2_2 = navigationRecord(temp_a0_3, temp_a1_2->second);
                for (var_s0 = 0; var_s0 < 0x40; var_s0++) {
                    temp_a1_3 = arg0->goals[var_s0];
                    if (temp_a1_3 == -1) continue;
                    temp_v1_4 = arg0->points;
                    temp_fv0_2 = func_802726F8_de(&temp_s2_2->position.x, navigationRecord(temp_v1_4, temp_a1_3));
                    if (temp_fv0_2 < var_fs0 || var_fs0 == -1.0f) var_fs0 = temp_fv0_2;
                }
            }
        }
    }
    return var_fs0;
}
