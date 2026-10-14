#include "span_1000/code_80208000.h"
#include "span_1000/code_8020AF9C.h"
typedef struct NavigationCollisionQuery { s32 flags, word4, word8, wordC, word10, word14, word18; } NavigationCollisionQuery;
extern NavigationCollisionQuery D_80103FF0, D_80104050, D_80104070, D_801040D0;
s32 func_8024E62C_de(Player *);
s32 func_8024DEE0_de(Player *);
s32 func_8024DF5C_de(Player *);
s32 func_8024DFA0_de(Player *);
s32 func_80243A90_de(Player *, Vec3, NavigationCollisionQuery *);
void func_80271F68_de(Vec3 *, void *, Vec3 *);
extern f32 D_800C1D54_de;
extern f32 D_800C1D58_de;
extern f32 D_800C1D5C_de;
extern f32 D_800C1D60_de;
extern f32 D_800C1D64_de;

static __inline__ s32 navigationCanReach(Player *actor, Vec3 *position) {
    NavigationCollisionQuery query;
    u8 saved[0x50];
    s32 mode, result;
    if (actor->kind == 1 && (actor->weaponFlags & 0x300000)) {
        query = D_801040D0;
    } else {
        mode = func_8024DEE0_de(actor);
        if (func_8024DF5C_de(actor) == 0) {
            if (mode != 0) query = D_80104050;
            else query = D_801040D0;
        } else if (func_8024DFA0_de(actor) == 0) query = D_80104070;
        else query = D_80103FF0;
    }
    query.flags = 0x4000;
    __builtin_memcpy(saved, actor, sizeof(saved));
    result = func_80243A90_de(actor, *position, &query);
    __builtin_memcpy(actor, saved, sizeof(saved));
    return result;
}
void func_8020AF9C_de(NavigationGraph *arg0, Player *arg1) {
    s32 sp18[64];
    s32 sp118[64];
    Vec3 sp218;
    Vec3 position;
    s32 sp2A8;
    s32 sp2AC;
    AiController *temp_v0_2;
    AiController *temp_v1;
    AiController *temp_v1_10;
    AiController *temp_v1_2;
    NavigationBuffer *temp_a0;
    NavigationBuffer *temp_a1;
    NavigationBuffer *temp_a3;
    NavigationBuffer *temp_v1_3;
    NavigationBuffer *temp_v1_4;
    NavigationBuffer *temp_v1_6;
    NavigationBuffer *temp_v1_8;
    f32 temp_fs1f;
    f32 var_fs0;
    f32 var_fs0f;
    f32 var_fs1;
    f32 var_fv0f;
    s32 *var_a0;
    s32 *var_a0_3;
    s32 *var_a1;
    s32 *var_v1;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s3;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_t1;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_a0_2;
    s32 var_a3;
    s32 var_fp;
    s32 var_s2;
    s32 var_s3;
    s32 var_t0;
    s32 var_v0_2;
    s32 var_v1_2;
    NavigationPoint *temp_s0;
    NavigationPoint *temp_s0_2;
    NavigationPortal *temp_s4;
    NavigationPortal *temp_v1_5;
    NavigationPoint *temp_v1_7;
    NavigationPoint *temp_v1_9;
    u8 temp_a0_2;

    var_s2 = 0;
    var_a0 = sp118;
    var_v1 = sp18;
    do {
        *var_v1 = -1;
        *var_a0 = -1;
        var_a0++;
        var_s2 += 1;
        var_v1++;
    } while (var_s2 < 0x40);
    temp_a3 = arg0->points;
    sp2AC = 0;
    temp_v0 = arg1->movementFlags;
    temp_s7 = temp_v0 & 0x2000;
    temp_s6 = temp_v0 & 0x1000;
    func_80271F68_de(&sp218, navigationRecord(temp_a3, arg1->controller->current), &arg1->pos);
    if ((temp_s7 != 0) || (temp_s6 != 0)) {
        var_fs0 = (sp218.x * sp218.x) + (sp218.y * sp218.y) + (sp218.z * sp218.z);
    } else {
        var_fs0 = (sp218.x * sp218.x) + (sp218.z * sp218.z);
    }
    var_fs1 = sp218.y;
    var_fs0f = var_fs0;
    if (var_fs1 < 0.0f) {
        var_fs1 = -var_fs1;
    }
    temp_v1 = arg1->controller;
    var_fp = temp_v1->current;
    if (arg1->computer != 0) {
        var_a3 = 0;
        if (temp_v1->queue[0] != -1) {
            var_a0_2 = 0;
            if (func_8024E62C_de(arg1) != 0) {
                var_a0_2 = arg1->active == 0;
                goto block_14;
            }
            if ((arg1->pose == 0xF) || (var_a3 = 0, (temp_s7 != 0))) {
block_14:
                if (var_a0_2 == 0) {
                    temp_v1_2 = arg1->controller;
                    var_s3 = temp_v1_2->queue[0];
                    if (var_s3 == -1) {
                        var_s3 = temp_v1_2->mode;
                    }
                    temp_v1_3 = arg0->points;
                    temp_s0 = navigationRecord(temp_v1_3, var_s3);
                    func_80271F68_de(&sp218, &temp_s0->position, &arg1->pos);
                    if ((temp_s7 != 0) || (temp_s6 != 0) || (temp_s0->flags & 0x200)) {
                        var_fs0 = (sp218.x * sp218.x) + (sp218.y * sp218.y) + (sp218.z * sp218.z);
                    } else {
                        var_fs0 = (sp218.x * sp218.x) + (sp218.z * sp218.z);
                    }
                    if (var_fs0 < var_fs0f) {
                        if (sp218.y < 0.0f) {
                            if (-sp218.y < D_800C1D54_de) {
                                goto block_27;
                            }
                        } else if (sp218.y < D_800C1D58_de) {
block_27:
                            temp_v0_2 = arg1->controller;
                            temp_v0_2->previous = temp_v0_2->current;
                            arg1->controller->current = var_s3;
                        }
                    }
                } else {
                    arg1->controller->queue[0] = -1;
                    goto block_29;
                }
            } else {
                goto block_30;
            }
        } else {
            goto block_30;
        }
    } else {
block_29:
        var_a3 = 0;
block_30:
        var_t0 = 0;
        temp_t1 = arg1->controller->current;
        if (arg0->portalCount > 0) {
            var_a1 = sp118;
            var_a0_3 = sp18;
            do {
                temp_v1_4 = arg0->portals;
                temp_v1_5 = navigationRecord(temp_v1_4, var_a3);
                if (temp_v1_5->first == temp_t1) {
                    var_t0 += 1;
                    *var_a0_3 = (s32) temp_v1_5->second;
                    *var_a1 = var_a3;
                    var_a1++;
                    var_a0_3++;
                }
                if (temp_v1_5->second == temp_t1) {
                    var_t0 += 1;
                    *var_a0_3 = (s32) temp_v1_5->first;
                    *var_a1 = var_a3;
                    var_a1++;
                    var_a0_3++;
                }
                var_a3 += 1;
            } while (var_a3 < arg0->portalCount);
        }
        var_s2 = 0;
        sp2A8 = var_t0;
        if (var_t0 > 0) {
            temp_fs1f = D_800C1D5C_de;
            var_v1_2 = 0 * 4;
            do {
                temp_a1 = arg0->points;
                temp_s3 = sp18[var_s2];
                temp_a0 = arg0->portals;
                temp_s0_2 = navigationRecord(temp_a1, temp_s3);
                temp_s4 = navigationRecord(temp_a0, sp118[var_s2]);
                if (!(temp_s0_2->flags & 0x30) || (temp_s6 != 0) || (temp_s7 != 0)) {
                    func_80271F68_de(&sp218, &temp_s0_2->position, &arg1->pos);
                    if ((temp_s7 != 0) || (temp_s6 != 0)) {
                        var_fs0 = (sp218.x * sp218.x) + (sp218.y * sp218.y) + (sp218.z * sp218.z);
                    } else {
                        var_fs0 = (sp218.x * sp218.x) + (sp218.z * sp218.z);
                    }
                    var_fv0f = sp218.y;
                    if (var_fv0f < 0.0f) {
                        var_fv0f = -var_fv0f;
                    }
                    temp_a0_2 = temp_s4->kind;
                    if ((temp_a0_2 == 3) || (temp_a0_2 == 0xA) || (temp_a0_2 == 5) || ((temp_s6 == 0) && (temp_s0_2->flags & 0x20))) {
                        if (var_fv0f < var_fs1) {
                            if (sp2AC == 0) {
                                var_fs0f = D_800C1D60_de;
                                sp2AC = 1;
                            }
                            if ((var_fs0 < var_fs0f) || (var_fs0f == D_800C1D64_de)) {
                                temp_v1_6 = arg0->points;
                                temp_v1_7 = navigationRecord(temp_v1_6, temp_s3);
                                position = temp_v1_7->position;
                                position.y += temp_fs1f;
                                var_v0_2 = navigationCanReach(arg1, &position);
                                goto block_86;
                            }
                        }
                    } else if (var_fs0 < var_fs0f) {
                        temp_v1_8 = arg0->points;
                        temp_v1_9 = navigationRecord(temp_v1_8, temp_s3);
                        position = temp_v1_9->position;
                        position.y += temp_fs1f;
                        var_v0_2 = navigationCanReach(arg1, &position);
block_86:
                        if (var_v0_2 == 0) {
                            var_fs0f = var_fs0;
                            var_fp = temp_s3;
                        }
                    }
                }
                var_s2 += 1;
                var_v1_2 = var_s2 * 4;
            } while (var_s2 < sp2A8);
        }
        temp_v1_10 = arg1->controller;
        temp_v0_3 = temp_v1_10->current;
        if (temp_v0_3 != var_fp) {
            temp_v1_10->previous = temp_v0_3;
        }
        arg1->controller->current = var_fp;
    }
}
