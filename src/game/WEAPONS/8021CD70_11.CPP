#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "TYPES.H"

/* Updates player forward, strafe and impulse velocities, accumulates movement and plays the impulse sound. */
extern float D_800D2988[];




extern s32 func_80245784_de(void);
extern void func_8025DE54_de(s16,CVector3,s32,s32),func_80271F34_de(CVector3 *,CVector3 *,CVector3 *),func_80271F9C_de(CVector3 *,CVector3 *,f32),func_80272748_de(CVector3 *,f32);

void func_802233F0_de(SharedPlayer *player, func_802165F8_S1 *body, SharedMovement *arg2) {
    CVector3 motion;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 var_a1;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f14;
    f32 var_f14_2;
    f32 var_f1;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s3;
    s32 var_s4;
    CVector3 *temp_a0;

    if (func_80245784_de() == 0) {
        var_s3 = 0;
        if (player->views5E8.view11B8_137.unk11B8 == 0) {
            temp_f1 = player->views5E8.view6DC_60.unk6DC;
            var_s4 = 1;
            if (!(temp_f1 <= 0.0f)) {
                var_s4 = 0;
                player->views5E8.view6DC_60.unk6DC = (f32) (temp_f1 - D_800D2988[0]);
            }
            temp_f0=player->views5E8.view6C0_51.unk6C0; temp_f1_2=arg2->unk4;
            if (temp_f0 < 0.0f ? temp_f1_2 < -temp_f0 : temp_f1_2 < temp_f0) {
                player->views5E8.view6C0_51.unk6C0=func_802747A0_de(player->views5E8.view6C0_51.unk6C0,arg2->unk8*0.5f);
            } else if(player->views5E8.view6A8_43.unk6A8 != 0.0f && player->views5E8.view7E8_105.unk7E8 != 2) {
                player->views5E8.view6C0_51.unk6C0=func_802746A0_de(player->views5E8.view6C0_51.unk6C0,player->views5E8.view6A8_43.unk6A8*arg2->unk0,(player->views5E8.view6A8_43.unk6A8<0.0f?-player->views5E8.view6A8_43.unk6A8:player->views5E8.view6A8_43.unk6A8)*arg2->unk4);
            } else {
                player->views5E8.view6C0_51.unk6C0=func_802747A0_de(player->views5E8.view6C0_51.unk6C0,arg2->unk8);
            }
            temp_f1_4 = player->views5E8.view6C0_51.unk6C0 * func_802B7130_de(body->unk6C + 3.1415927f);
            motion.y = 0;
            motion.x = temp_f1_4;
            motion.z = player->views5E8.view6C0_51.unk6C0 * func_802B6560_de(body->unk6C + 3.1415927f);
            temp_f1_5=player->views5E8.view6C4_54.unk6C4; temp_f2_2=arg2->unk10;
            if (temp_f1_5 < 0.0f ? temp_f2_2 < -temp_f1_5 : temp_f2_2 < temp_f1_5) {
                player->views5E8.view6C4_54.unk6C4=func_802747A0_de(player->views5E8.view6C4_54.unk6C4,arg2->unk14*0.5f);
            } else if(player->views5E8.view6A4_41.unk6A4 != 0.0f) {
                player->views5E8.view6C4_54.unk6C4=func_802746A0_de(player->views5E8.view6C4_54.unk6C4,player->views5E8.view6A4_41.unk6A4*arg2->unkC,(player->views5E8.view6A4_41.unk6A4<0.0f?-player->views5E8.view6A4_41.unk6A4:player->views5E8.view6A4_41.unk6A4)*arg2->unk10);
            } else {
                player->views5E8.view6C4_54.unk6C4=func_802747A0_de(player->views5E8.view6C4_54.unk6C4,arg2->unk14);
            }
            motion.x += player->views5E8.view6C4_54.unk6C4 * func_802B7130_de(body->unk6C - 1.5707964f);
            motion.z += player->views5E8.view6C4_54.unk6C4 * func_802B6560_de(body->unk6C - 1.5707964f);
            var_f1 = player->views5E8.view6C4_54.unk6C4;
            if (var_f1 < 0.0f) {
                var_f1 = -var_f1;
            }
            temp_f0_2 = player->views5E8.view6C0_51.unk6C0;
            if (temp_f0_2 < 0.0f) {
                if (-temp_f0_2 < var_f1) {
                    goto block_35;
                }
                goto block_36;
            }
            if (temp_f0_2 < var_f1) {
block_35:
                func_80272748_de(&motion,arg2->unk10);
            } else {
block_36:
                func_80272748_de(&motion,arg2->unk4);
            }
            if (var_s4 != 0) {
                temp_v1 = player->views5E8.view6B0_46.unk6B0;
                if (temp_v1 & 8) {
                    var_f0_3 = arg2->unk18;
                    var_s3 = 1;
                } else if (temp_v1 & 4) {
                    var_f0_3 = -arg2->unk18 * 0.5f;
                    var_s3 = 1;
                } else {
                    goto block_42;
                }
            } else {
block_42:
                var_f0_3 = func_802747A0_de(player->views5E8.view6D4_58.unk6D4, arg2->unk1C);
            }
            player->views5E8.view6D4_58.unk6D4 = var_f0_3;
            motion.x += player->views5E8.view6D4_58.unk6D4 * func_802B7130_de(body->unk6C + 3.1415927f);
            motion.z += player->views5E8.view6D4_58.unk6D4 * func_802B6560_de(body->unk6C + 3.1415927f);
            if (var_s4 && (player->views5E8.view6B8_49.unk6B8 & 1)) {
                player->views5E8.view6D8_59.unk6D8 = arg2->unk18;
                player->views5E8.view6D8_59.unk6D8 *= 0.75f;
                var_s3=1;
            } else if (var_s4 && (player->views5E8.view6B8_49.unk6B8 & 2)) {
                player->views5E8.view6D8_59.unk6D8 = -arg2->unk18*0.75f;
                var_s3=1;
            } else {
                player->views5E8.view6D8_59.unk6D8=func_802747A0_de(player->views5E8.view6D8_59.unk6D8,arg2->unk1C*0.75f);
            }
            motion.x += player->views5E8.view6D8_59.unk6D8 * func_802B7130_de(body->unk6C - 1.5707964f);
            motion.z += player->views5E8.view6D8_59.unk6D8 * func_802B6560_de(body->unk6C - 1.5707964f);
            func_80271F9C_de(&motion, &motion, player->views5E8.view66C_29.unk66C);
            temp_a0 = &player->views5E8.view6E8_63.unk6E8;
            func_80271F34_de(temp_a0, temp_a0, &motion);
            if (var_s3 != 0) {
                player->views5E8.view6DC_60.unk6DC = (f32) (player->views5E8.view6DC_60.unk6DC + 7.5f);
                func_8025DE54_de(arg2->unk22, body->unk8, 0, -1);
            }
        }
    }
}
