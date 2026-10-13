#include "span_1000/code_80208000.h"
#include "span_1000/code_8020AF9C.h"
#include "span_1000/code_80206258.h"
extern NavigationGraph D_8013B364;
float func_802726F8_de(void *, void *);
void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
void func_8027207C_de(Vec3 *);
float func_80209308_de(AiController *, Vec3 *,float,float);
void func_80209910_de(AiController *,float,s32);
void func_80209E80_de(AiController *);
float func_802B72B0_de(float);
NavigationPoint *func_8020C994_de(NavigationGraph *,s32);
NavigationPortal *func_8020C9B0_de(NavigationGraph *,s32);
NavigationSearchNode *func_8020CFE0_de(NavigationGraph *,s32);
s32 func_8020CC0C_de(NavigationGraph *,s32,s32);
s32 func_80209828_de(AiController *);
typedef struct GroundObject { char pad[0x18]; ActorMotionResource *resource; } GroundObject;
GroundObject *func_8024E6A0_de(Player *);

extern f32 D_800C1BB8_de;
extern f32 D_800C1BBC_de;
extern f32 D_800C1BC0_de;
extern f32 D_800C1BC4_de;
extern f32 D_800C1BC8_de;
extern f32 D_800C1BCC_de;
extern f32 D_800C1BD0_de;
extern f32 D_800C1BD4_de;
extern f32 D_800C1BD8_de;

void func_80208410_de(AiController *arg0) {
    Vec3 sp10;
    GroundObject *temp_v0_6;
    GroundObject *temp_v0_8;
    NavigationPoint *temp_s2;
    NavigationPoint *temp_v0_10;
    NavigationPoint *var_s0;
    NavigationPoint *var_s3;
    NavigationPortal *temp_v0_2;
    NavigationSearchNode *temp_v0_4;
    NavigationSearchNode *temp_v0_9;
    Player *temp_s6;
    Player *temp_v0_5;
    Player *temp_v0_7;
    Vec3 *temp_s4;
    f32 temp_fs0f;
    f32 temp_fv0;
    f32 temp_fv0f;
    f32 var_fv0;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_s2_2;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_a1;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_v0;

    temp_s6 = arg0->player;
    if ((arg0->mode != -1) && (temp_a1 = arg0->queue[0], arg0->unk300 = 0, arg0->unk310 = 0, arg0->unk304 = 0, arg0->unk308 = 0, arg0->unk30C = 0, (temp_a1 != -1))) {
        var_s3 = func_8020C994_de(&D_8013B364, temp_a1);
        temp_s4 = &arg0->player->pos;
        temp_fs0f = func_802726F8_de(temp_s4, var_s3);
        temp_a2 = arg0->queue[0];
        var_a1 = arg0->current;
        arg0->unk304 = (var_s3->attributes.word & 0x300000) != 0;
        if (temp_a2 == var_a1) {
            var_a1 = arg0->previous;
        }
        temp_v0 = func_8020CC0C_de(&D_8013B364, var_a1, temp_a2);
        if (temp_v0 > 0) {
            temp_v0_2 = func_8020C9B0_de(&D_8013B364, temp_v0);
            if (temp_v0_2->kind == 4) {
                arg0->unk30C = 1;
            }
            if (temp_v0_2->kind == 8) {
                func_802726F8_de(temp_s4, func_8020C994_de(&D_8013B364, arg0->current));
                temp_s2 = func_8020C994_de(&D_8013B364, arg0->queue[0]);
                arg0->unk308 = 1;
                if (temp_v0 != arg0->unk32C) {
                    arg0->unk314 = 0;
                    arg0->unk32C = temp_v0;
                }
                if (arg0->unk314 == 0) {
                    var_s0 = func_8020C994_de(&D_8013B364, arg0->current);
                    func_80271F68_de(&sp10, temp_s4, &var_s0->position);
                    if (func_802B72B0_de((sp10.x * sp10.x) + (sp10.z * sp10.z)) < D_800C1BB8_de) {
                        arg0->unk314 = 1;
                        goto block_13;
                    }
                    goto block_35;
                }
block_13:
                if (arg0->unk314 == 1) {
                    arg0->destination = temp_s2->position;
                    temp_fv0 = func_80209308_de(arg0, &arg0->destination, 2.0f, 0.0f);
                    if (temp_fv0 < 0.0f) {
                        if (!(D_800C1BBC_de < -temp_fv0)) {
                            goto block_20;
                        }
                        goto block_18;
                    }
                    if (D_800C1BC0_de < temp_fv0) {
block_18:
                        arg0->unk310 = 1;
                        return;
                    }
block_20:
                    arg0->unk314 = 2;
                    goto block_21;
                }
block_21:
                var_v0 = 3;
                if ((arg0->unk314 == 2) || (var_v0 = 4, (arg0->unk314 == 3)) || (var_v0 = 5, (arg0->unk314 == 4))) {
                    arg0->destination = temp_s2->position;
                    arg0->unk314 = var_v0;
                    return;
                }
                if (arg0->unk314 == 5) {
                    arg0->destination = temp_s2->position;
                    temp_s6->actionFlags |= 0x10;
                    arg0->unk314 = 6;
                    return;
                }
                if (arg0->unk314 == 6) {
                    temp_v0_3 = arg0->player->movementFlags;
                    if ((temp_v0_3 & 0x2000) || (temp_v0_3 & 0x1000)) {
                        arg0->unk314 = 2;
                    }
                    arg0->destination = temp_s2->position;
                }
                goto block_58;
            }
            if (temp_v0_2->kind == 5) {
                if (arg0->unk314 == 0) {
                    var_s0 = func_8020C994_de(&D_8013B364, arg0->current);
                    if (!(func_802726F8_de(temp_s4, var_s0) < D_800C1BC4_de)) {
block_35:
                        arg0->destination = var_s0->position;
                        return;
                    }
                    arg0->unk314 = 1;
                    goto block_37;
                }
block_37:
                temp_s2_2 = arg0->unk314;
                if (temp_s2_2 == 1) {
                    temp_v0_4 = func_8020CFE0_de(&D_8013B364, arg0->current);
                    if (func_802726F8_de(temp_v0_4->platform + 8, temp_v0_4 + 0x44) < D_800C1BC8_de) {
                        temp_v0_5 = temp_v0_4->platform;
                        arg0->destination = temp_v0_5->pos;
                        temp_s6->actionFlags |= 0x10;
                        arg0->unk314 = 2;
                        return;
                    }
                    arg0->destination = temp_v0_4->endpoint;
                    arg0->unk310 = temp_s2_2;
                    goto block_41;
                }
block_41:
                if (arg0->unk314 == 2) {
                    var_s0_2 = 0;
                    temp_v0_6 = func_8024E6A0_de(arg0->player);
                    if (temp_v0_6 != 0) {
                        var_s0_2 = temp_v0_6->resource->kind == 2;
                    }
                    func_80271F68_de(&sp10, temp_s4, func_8020CFE0_de(&D_8013B364, arg0->current)->platform + 8);
                    temp_fv0f = func_802B72B0_de((sp10.x * sp10.x) + (sp10.z * sp10.z));
                    if ((var_s0_2 != 0) && (temp_fv0f < D_800C1BCC_de)) {
                        arg0->unk314 = 3;
                        goto block_49;
                    }
                    temp_v0_7 = func_8020CFE0_de(&D_8013B364, arg0->current)->platform;
                    arg0->destination = temp_v0_7->pos;
                    return;
                }
block_49:
                if (arg0->unk314 == 3) {
                    var_s0_3 = 0;
                    temp_v0_8 = func_8024E6A0_de(arg0->player);
                    if (temp_v0_8 != 0) {
                        var_s0_3 = temp_v0_8->resource->kind == 2;
                    }
                    if (var_s0_3 == 0) {
                        arg0->unk314 = 0;
                    }
                    var_s3 = func_8020C994_de(&D_8013B364, arg0->queue[0]);
                    temp_v0_9 = func_8020CFE0_de(&D_8013B364, arg0->queue[0]);
                    if (func_802726F8_de(temp_v0_9->platform + 8, temp_v0_9 + 0x44) < D_800C1BD0_de) {
                        arg0->destination = var_s3->position;
                        temp_s6->actionFlags |= 0x10;
                        goto block_58;
                    }
                    arg0->destination = var_s3->position;
                    arg0->unk310 = 1;
                    return;
                }
                goto block_58;
            }
            goto block_57;
        }
block_57:
        arg0->unk314 = 0;
block_58:
        if ((arg0->queue[1] == -1) || (var_fv0 = D_800C1BD4_de, ((var_s3->attributes.halves.flags & 0x100) != 0))) {
            var_fv0 = D_800C1BD8_de;
        }
        if ((temp_fs0f < var_fv0) && (arg0->current == arg0->queue[0])) {
            if (func_80209828_de(arg0) != 0) {
                goto block_66;
            }
        } else {
block_66:
            temp_a1_2 = arg0->queue[0];
            if (temp_a1_2 != -1) {
                temp_v0_10 = func_8020C994_de(&D_8013B364, temp_a1_2);
                if (temp_v0_10->attributes.halves.flags & 2) {
                    arg0->destination = arg0->home;
                    return;
                }
                arg0->destination = temp_v0_10->position;
            }
        }
    } else {
        arg0->unk300 = 1;
    }
}
