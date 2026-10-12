#include "types.h"
#include "common/types_06e4f7ef1f9e.h"
#include "stddef.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022E938.h"
#include "span_C76B0/data.h"
extern AimHit *D_80103FCC;
extern char D_80103FD0;
void func_8027302C(f32 *, f32 *);
void func_80226DD0_de(void *, f32 *);
void func_8022B144_de(void *, f32 *);
s32 func_802444A4_de(char *, Vec3, Vec3, s32);
void func_8021D408_de(SharedPlayer_func_8021D408_de *, Vec3 *, Vec3 *);
void func_8021CF28_de(void *, void *, AimActor **, void *);
Vector4f func_8024796C_de(char *);
s32 func_8021CD94_de(func_8021CD70_S1 *, func_8021CD70_S2 *);
void func_8021D774_de(AimPlayer *arg0) {
    AimOutput sp20;
    Vec3 sp30;
    Vec3 sp40;
    Vec3 sp50;
    f32 sp60[16];
    Vec3 spA0;
    Vector4f spB0;
    AimWeapon *weapon;
    AimOutput spC0;
    AimOutput spD0;
    Vec3 spE0;
    AimActor *spF0, *spF4;
    Vec3 *var_a0, *temp_s2, *temp_s2_2, *var_a1, *temp_s0_2, *temp_s1;
    f32 temp_fs0, temp_fs1f, temp_fs2, temp_fv0, temp_fv0_2, var_fs0f, var_fs1;
    s16 temp_v1, temp_v1_2;
    s32 var_s4;
    s32 temp_v1_3, var_s0, var_s5;
    AimActor *temp_a1, *temp_a1_2;
    AimView *temp_s0;
    spF0 = NULL;
    temp_s0 = arg0->view;
    temp_fs1f = D_800C23B4_de;
    temp_fs2 = D_800C23B8_de;
    if (temp_s0) { switch (temp_s0->mode) { case 1: func_80226DD0_de(arg0, sp60); func_8022B144_de(arg0, &spA0.x); break; default: func_8027302C(sp60, temp_s0->matrix); spA0 = temp_s0->origin; break; } } else { func_80226DD0_de(arg0, sp60); func_8022B144_de(arg0, &spA0.x); }
    sp30.x = 0.0f;
    sp30.y = 0;
    sp30.z = D_800C23BC_de;
    func_80272898_de(sp60, &sp30, &sp50);
    if (func_802444A4_de((char *)arg0, spA0, sp50, (s32) &D_80103FD0) != 0) {
        arg0->aim = D_80103FCC->point;
        arg0->normal = D_80103FCC->normal;
        arg0->target = D_80103FCC->actor;
    } else {
        arg0->aim = sp50;
        arg0->target = NULL;
    }
    sp30.x = 0.0f;
    sp30.y = 0;
    sp30.z = D_800C23C0_de;
    func_80272898_de(sp60, &sp30, &sp50);
    if (arg0->enabled != 0) {
        if ((func_802444A4_de((char *)arg0, spA0, sp50, (s32) &D_801000F0) != 0) && (temp_a1 = D_80103FCC->actor, (temp_a1 != NULL))) {
            if (temp_a1->kind == 1) {
                if (temp_a1->flags & 0x300000) {
                    func_80271F68_de((Vec3 *)&spB0, &temp_a1->pos, &arg0->unk8);
                    temp_fv0 = func_802B72B0_de((spB0.x * spB0.x) + (spB0.y * spB0.y) + (spB0.z * spB0.z));
                    spE0 = sp30;
                    func_8027207C_de(&spE0);
                    func_80271F9C_de(&spC0.xyz, &spE0, temp_fv0);
                    func_80272898_de(sp60, &spC0.xyz, &spD0.xyz);
                    arg0->aim2 = spD0.xyz;
                    func_8021D408_de((void *)arg0, &spD0.xyz, &D_80103FCC->normal);
                } else {
                    goto block_14;
                }
            } else {
                goto block_15;
            }
        } else {
block_14:
block_15:
            arg0->aim2 = arg0->aim;
            func_8021D408_de((void *)arg0, &arg0->aim, &D_80103FCC->normal);
        }
    } else {
        arg0->aim2 = sp50;
    }
    if (arg0->unk62E == 1 && arg0->unk594 == 2) {
        var_s4 = 0x2C6;
    } else {
        weapon=D_800D052C[arg0->unk62E]; var_s4=weapon->idle;
    }
    temp_v1 = arg0->unk62E;
    var_s5 = var_s4 + 0x64;
    var_s0 = 1;
    if ((temp_v1 == 1) || (temp_v1 == 0x12)) {
        var_fs0f = D_800C23C4_de;
        var_fs1 = var_fs0f;
    } else {
        var_fs0f = 0.0f;
        var_fs1 = 0.0f;
    }
    switch (arg0->unk62E) {
    case 7:
        if (arg0->unk7E8 != 0) {
            var_s4 = 0x2E4;
            var_s5 = -1;
        }
        break;
    case 2:
        if (arg0->unk7E8 != 0) {
            var_s4 = 0x2BC;
            var_s5 = -1;
        }
        break;
    case 1:
    case 0x12:
        func_8021CF28_de(&spB0, arg0, &spF0, &sp20.words);
        var_s0 = 0;
        break;
    default:
        var_s5 = -1;
        break;
    }
    spB0 = func_8024796C_de((char *)arg0);
    arg0->rotation = spB0;
    spC0.xyz = arg0->aim;
    spC0.xyz.x -= D_800C23C8_de;
    spD0.xyz = arg0->aim;
    spD0.xyz.x += D_800C23C8_de;
    spC0.xyz = arg0->aim;
    spC0.xyz.z -= D_800C23C8_de;
    spD0.xyz = arg0->aim;
    spD0.xyz.z += D_800C23C8_de;
    spC0.xyz = arg0->aim;
    spC0.xyz.y -= D_800C23C8_de;
    spD0.xyz = arg0->aim;
    spD0.xyz.y += D_800C23C8_de;
    if (spF0 == NULL) {
        sp20.xyz = sp50;
        if ((arg0->unk5D8->active != 0) && (var_s0 != 0)) {
            func_8021CF28_de(&spD0.words, arg0, &spF4, &spC0.words);
            if (spF4 != NULL) {
                arg0->rotation = spD0.full;
            }
        }
        if (spF0 == NULL) {
            arg0->unk794 = NULL;
        }
    }
    if (var_s4 == -1) {
        arg0->unk788 = 0;
    } else if (arg0->unk788 == 0) {
        arg0->unk788 = 1;
        arg0->out = sp50;
        arg0->velocity.x = 0;
        arg0->velocity.y = 0;
        arg0->velocity.z = 0;
        arg0->smooth = sp50;
        arg0->smoothVelocity.x = 0;
        arg0->smoothVelocity.y = 0;
        arg0->smoothVelocity.z = 0;
    }
    temp_s2 = &arg0->smooth;
    temp_fs0 = D_800C23CC_de;
    func_80271F68_de(&sp40, &sp20.xyz, temp_s2);
    func_80271F9C_de(&sp40, &sp40, temp_fs1f * temp_fs0);
    temp_s0_2 = &arg0->smoothVelocity;
    func_80271F34_de(temp_s0_2, temp_s0_2, &sp40);
    func_80271F34_de(temp_s2, temp_s2, temp_s0_2);
    func_80271F9C_de(temp_s0_2, temp_s0_2, temp_fs2 * temp_fs0);
    if (spF0 != NULL) {
        weapon=D_800D052C[arg0->unk62E]; arg0->unk7B8=weapon->locked+0x64;
    } else {
        arg0->unk7B8 = var_s5;
    }
    switch (arg0->unk788) {
    case 1:
        if ((spF0 == NULL) || (arg0->unk794 != spF0)) {
            arg0->unk794 = spF0;
            arg0->unk78C = 0.0f;
        }
        temp_fv0_2 = arg0->unk78C + D_800D2988;
        arg0->unk78C = temp_fv0_2;
        if (var_fs1 <= temp_fv0_2) {
            arg0->unk788 = 2;
            arg0->unk78C = 0.0f;
        }
        goto reset_position;
    case 2:
            if (arg0->unk7B4 != spF0) {
                arg0->unk7B4 = spF0;
                arg0->unk78C = 0.0f;
            } else {
                arg0->unk78C += D_800D2988;
            }
            if ((spF0 != NULL) && (arg0->unk794 != spF0) && (var_fs0f <= arg0->unk78C)) {
                arg0->unk794 = spF0;
                arg0->unk78C = 0.0f;
            }
            temp_a1_2 = arg0->unk794;
            spF0 = temp_a1_2;
            if (temp_a1_2 != NULL) {
                if (func_8021CD94_de((void *)arg0, (void *)temp_a1_2) == 0) {
                    arg0->unk788 = 1;
                    arg0->unk78C = 0.0f;
                }
                if (arg0->unk62E == 0x12) {
                    sp20.xyz = spF0->focus;
                } else {
                    sp20.xyz = spF0->pos;
                    sp20.xyz.y = sp20.xyz.y + spF0->height;
                    sp20.xyz.y += func_8024D284_de(spF0) * D_800C23D0_de;
                }
                if (arg0->unk62E == 1 && arg0->unk594 == 2) {
                    var_s4 = 0x2C7;
                } else {
                    weapon=D_800D052C[arg0->unk62E]; var_s4=weapon->locked;
                }
            } else {
                goto reset_position;
            }
        break;
    case 0:
reset_position:
        sp20.xyz = sp50;
        break;
    default:
        break;
    }
    var_a0 = &sp40;
    temp_s2_2 = &arg0->out;
    func_80271F68_de(var_a0, &sp20.xyz, temp_s2_2);
    func_80271F9C_de(&sp40, &sp40, temp_fs1f);
    temp_s1 = &arg0->velocity;
    func_80271F34_de(temp_s1, temp_s1, &sp40);
    func_80271F34_de(temp_s2_2, temp_s2_2, temp_s1);
    func_80271F9C_de(temp_s1, temp_s1, temp_fs2);
    arg0->unk798 = (s32) var_s4;
}
