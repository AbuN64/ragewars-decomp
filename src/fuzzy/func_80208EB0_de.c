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

extern f32 D_800C1C00;
extern f32 D_800C1C04;
extern f32 D_800C1C08;
extern f32 D_800C1C0C;
extern f32 D_800C1C10;
extern f32 D_800C1C14;
extern f32 D_800C1C18;
extern f32 D_800C1C1C;
extern f32 D_800C1C20;

void func_80208EB0_de(AiController *arg0) {
    Vec3 sp10;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp40;
    f32 sp44;
    f32 sp48;
    Vec3 extra;
    AiTarget *temp_v1;
    NavigationPoint *temp_v0_3;
    Player *temp_v0;
    Vec3 *temp_s2;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fs0f;
    f32 temp_ft0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1f;
    s32 temp_s4;
    s32 temp_s6;
    s32 temp_v0_2;

    temp_v1 = arg0->target;
    if (temp_v1 == 0) {
        goto block_6;
    }
    if ((arg0->unk308 != 0) || (arg0->unk30C != 0) || (arg0->unk314 != 0)) {
block_6:
        func_80209308_de(arg0, &arg0->destination, 2.0f, 0.0f);
    } else {
        func_80209308_de(arg0, &temp_v1->player->pos, 2.0f, 0.0f);
        func_80209E80_de(arg0);
    }
    if (arg0->unk300 == 0) {
        temp_s2 = &arg0->destination;
        temp_v0 = arg0->player;
        temp_v0_2 = temp_v0->movementFlags;
        temp_s6 = temp_v0_2 & 0x2000;
        temp_s4 = temp_v0_2 & 0x1000;
        func_80271F68_de(&sp10, temp_s2, &temp_v0->pos);
        temp_fv0f = func_802B72B0_de((sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z));
        if (temp_s4 != 0) {
            if (D_800C1C00 < temp_fv0f) {
                temp_fv0 = func_80209308_de(arg0, temp_s2, 2.0f, 0.0f);
                if (temp_fv0 < 0.0f) {
                    if (-temp_fv0 < D_800C1C04) {
                        goto block_15;
                    }
                } else if (temp_fv0 < D_800C1C08) {
block_15:
                    temp_v0->forward = D_800C1C0C;
                }
                if (((temp_s6 != 0) || (temp_s4 != 0)) && (arg0->unk304 != 0)) {
                    func_80209910_de(arg0, func_8029C044_de(sp10.y, func_802B72B0_de((sp10.x * sp10.x) + (sp10.z * sp10.z))), 1);
                    temp_v0->forward = D_800C1C10;
                }
            }
        } else {
            temp_fs0f = arg0->player->heading + D_800C1C14;
            sp30 = func_802B7130_de(temp_fs0f);
            sp34 = 0.0f;
            sp38 = func_802B6560_de(temp_fs0f);
            sp20 = arg0->destination.x - temp_v0->pos.x;
            sp24 = 0.0f;
            sp28 = arg0->destination.z - temp_v0->pos.z;
            temp_v0_3 = func_8020C994_de(&D_8013B364, arg0->current);
            sp40 = temp_v0_3->position.x;
            sp44 = temp_v0_3->position.y;
            sp48 = temp_v0_3->position.z;
            temp_fa0 = sp40 - arg0->destination.x;
            sp40 = temp_fa0;
            temp_fv0_2 = sp48 - arg0->destination.z;
            sp44 = temp_fa0;
            sp44 = 0.0f;
            sp48 = temp_fv0_2;
            temp_fa1 = -temp_fv0_2;
            sp40 = temp_fa1;
            sp48 = temp_fa0;
            temp_fv0_3 = func_8029C044_de(temp_fa0, temp_fa1);
            sp40 = func_802B6560_de(temp_fv0_3);
            temp_fv0_4 = func_802B7130_de(temp_fv0_3);
            temp_fv1 = (sp20 * sp40) + (sp24 * sp44) + (sp28 * temp_fv0_4);
            temp_ft0 = sp40 * temp_fv1;
            temp_fv1_2 = temp_fv0_4 * temp_fv1;
            sp48 = temp_fv0_4;
            extra.y = 0.0f;
            sp40 = temp_ft0;
            sp48 = temp_fv1_2;
            extra.x = sp20 + temp_ft0;
            extra.z = sp28 + temp_fv1_2;
            func_8027207C_de(&extra);
            temp_v0->forward = (extra.x * sp30) + (extra.y * sp34) + (extra.z * sp38);
            temp_fv1f = -sp30;
            temp_fv0_5 = extra.z * temp_fv1f;
            sp34 = sp30;
            sp30 = sp38;
            temp_fv0f_2 = (extra.x * sp38) + temp_fv0_5;
            sp38 = temp_fv1f;
            sp34 = 0.0f;
            temp_v0->strafe = temp_fv0f_2;
        }
        if (((temp_s6 != 0) || (temp_s4 != 0)) && (arg0->unk304 != 0)) {
            func_80209910_de(arg0, func_8029C044_de(sp10.y, func_802B72B0_de((sp10.x * sp10.x) + (sp10.z * sp10.z))), 1);
            temp_v0->forward = D_800C1C18;
        }
        if (arg0->player->pose == 0xF) {
            if (arg0->destination.y < temp_v0->pos.y) {
                temp_v0->forward = D_800C1C1C;
            } else {
                temp_v0->forward = D_800C1C20;
            }
        }
        if (arg0->unk310 != 0) {
            temp_v0->strafe = 0.0f;
            temp_v0->forward = 0.0f;
        }
    }
}
