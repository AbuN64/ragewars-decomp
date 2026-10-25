#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "TYPES.H"
#include "particle/80271B18_3.H"

/* Updates flying-player thrust and impulses, transforms movement into world space and applies descent and roll. */








extern f32 D_800D2988[];
extern CQuatern func_8024796C_de(Actor_func_802238E0_de *);
extern void MatrixFromQuaternion(CQuatern *,MatrixF *),func_80271F34_de(CVector3 *,CVector3 *,CVector3 *),func_8025DE54_de(s16,CVector3,s32,s32),func_80274870_de(f32 *,f32,f32);
extern f32 func_802B72B0_de(f32);
void func_802238E0_de(SharedPlayer *player, Actor_func_802238E0_de *body, SharedMovement *arg2) {
    CVector3 v18,v28,v38,v48,v58;
    MatrixF sp68;
    CQuatern spA8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f14;
    f32 var_f14_2;
    f32 var_f1;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    s32 var_s5;

    var_s5 = 0;
    temp_f1 = player->views5E8.view6DC_60.unk6DC;
    var_s0 = 1;
    if (!(temp_f1 <= 0.0f)) {
        var_s0 = 0;
        player->views5E8.view6DC_60.unk6DC = (f32) (temp_f1 - D_800D2988[0]);
    }
    temp_f0=player->views5E8.view6C0_51.unk6C0; temp_f1_2=arg2->unk4;
    if (temp_f0<0.0f ? temp_f1_2 < -temp_f0 : temp_f1_2 < temp_f0) {
        player->views5E8.view6C0_51.unk6C0=Nav_DecayToZero(player->views5E8.view6C0_51.unk6C0,arg2->unk8*0.5f);
    } else if(player->views5E8.view6A8_43.unk6A8 != 0.0f) {
        player->views5E8.view6C0_51.unk6C0=func_802746A0_de(player->views5E8.view6C0_51.unk6C0,player->views5E8.view6A8_43.unk6A8*arg2->unk0,(player->views5E8.view6A8_43.unk6A8<0.0f?-player->views5E8.view6A8_43.unk6A8:player->views5E8.view6A8_43.unk6A8)*arg2->unk4);
    } else {
        player->views5E8.view6C0_51.unk6C0=Nav_DecayToZero(player->views5E8.view6C0_51.unk6C0,arg2->unk8);
    }
    temp_f1_4=player->views5E8.view6C4_54.unk6C4; temp_f2_2=arg2->unk4;
    if (temp_f1_4<0.0f ? temp_f2_2 < -temp_f1_4 : temp_f2_2 < temp_f1_4) {
        player->views5E8.view6C4_54.unk6C4=Nav_DecayToZero(player->views5E8.view6C4_54.unk6C4,arg2->unk8*0.5f);
    } else if(player->views5E8.view6A4_41.unk6A4 != 0.0f) {
        player->views5E8.view6C4_54.unk6C4=func_802746A0_de(player->views5E8.view6C4_54.unk6C4,player->views5E8.view6A4_41.unk6A4*arg2->unk0,(player->views5E8.view6A4_41.unk6A4<0.0f?-player->views5E8.view6A4_41.unk6A4:player->views5E8.view6A4_41.unk6A4)*arg2->unk4*0.75f);
    } else {
        player->views5E8.view6C4_54.unk6C4=Nav_DecayToZero(player->views5E8.view6C4_54.unk6C4,arg2->unk8);
    }
    if (var_s0 != 0) {
        temp_v1 = player->views5E8.view6B0_46.unk6B0;
        if (temp_v1 & 8) {
            var_f0_3 = arg2->unkC;
            var_s5 = 1;
        } else if (temp_v1 & 4) {
            var_f0_3 = -arg2->unkC * 0.5f;
            var_s5 = 1;
        } else {
            goto block_31;
        }
    } else {
block_31:
        var_f0_3 = Nav_DecayToZero(player->views5E8.view6D4_58.unk6D4, arg2->unk10);
    }
    player->views5E8.view6D4_58.unk6D4 = var_f0_3;
    if (var_s0 && (player->views5E8.view6B8_49.unk6B8 & 1)) {
        player->views5E8.view6D8_59.unk6D8=arg2->unkC;
        player->views5E8.view6D8_59.unk6D8*=0.75f;
        var_s5=1;
    } else if (var_s0 && (player->views5E8.view6B8_49.unk6B8 & 2)) {
        player->views5E8.view6D8_59.unk6D8=-arg2->unkC*0.75f;
        var_s5=1;
    } else {
        player->views5E8.view6D8_59.unk6D8=Nav_DecayToZero(player->views5E8.view6D8_59.unk6D8,arg2->unk10*0.75f);
    }
    if ((var_s0 != 0) && (player->views5E8.view6B0_46.unk6B0 & 0x10)) {
        var_s5 = 1;
        body->unk20 = (f32) (body->unk20 + arg2->unk1C);
    }
    if (player->views5E8.view6AC_45.unk6AC & 0x10) {
        temp_f12 = body->unk20;
        temp_f0_2 = arg2->unk18;
        if (temp_f12 < temp_f0_2) {
            body->unk20 = func_802746A0_de(temp_f12, arg2->unk14, temp_f0_2);
        }
    }
    v18.x = 0.0f;
    v18.y = 0;
    v18.z = player->views5E8.view6C0_51.unk6C0 + player->views5E8.view6D4_58.unk6D4;
    v28.x = player->views5E8.view6C4_54.unk6C4 + player->views5E8.view6D8_59.unk6D8;
    v28.y = 0;
    v28.z = 0;
    spA8 = func_8024796C_de(body);
    MatrixFromQuaternion(&spA8, &sp68);
    Particle_TransformPoint(&sp68, &v18, &v38);
    Particle_TransformPoint(&sp68, &v28, &v48);
    player->views5E8.view6E8_63.unk6E8 = (f32) (player->views5E8.view6E8_63.unk6E8 + ((v38.x + v48.x) * player->views5E8.view66C_29.unk66C));
    player->views5E8.view6EC_64.unk6EC = (f32) (player->views5E8.view6EC_64.unk6EC + ((v38.y + v48.y) * player->views5E8.view66C_29.unk66C));
    player->views5E8.view6F0_66.unk6F0 = (f32) (player->views5E8.view6F0_66.unk6F0 + ((v38.z + v48.z) * player->views5E8.view66C_29.unk66C));
    if (body->unk20 < 0.0f) {
        func_80271F34_de(&v58, &v38, &v48);
        body->unk20 = (f32) (body->unk20 - (player->views13B4.view13B4_2.unk13B4[player->views5E8.view650_15.unk650].physics->unk8 * (func_802B72B0_de((v58.x * v58.x) + (v58.y * v58.y) + (v58.z * v58.z)) / (arg2->unk4 * 4.0f)) * player->views5E8.view66C_29.unk66C));
    }
    func_80274870_de(&player->views5E8.view72C_75.unk72C, ((player->views5E8.view6C4_54.unk6C4 * 1.8f) + (player->views5E8.view69C_39.unk69C * 16.0f)) * 0.01745329424738884f, 0.04f);
    if (var_s5 != 0) {
        player->views5E8.view6DC_60.unk6DC = (f32) (player->views5E8.view6DC_60.unk6DC + 7.5f);
        func_8025DE54_de(arg2->unk22, body->unk8, 0, -1);
    }
}
