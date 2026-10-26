#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "TYPES.H"
#include "particle/80271B18_3.H"

/* Updates flying-player thrust and impulses, transforms movement into world space and applies descent and roll. */








extern f32 D_800D2988[];
extern CQuatern func_8024796C_de(Actor_func_802238E0_de *);
extern void MatrixFromQuaternion(CQuatern *,MatrixF *),Particle_AddVec3(CVector3 *,CVector3 *,CVector3 *),Render_PlaySoundAtPosition(s16,CVector3,s32,s32),Nav_EaseValueToward(f32 *,f32,f32);
extern f32 Math_Sqrtf(f32);
void func_802238E0_de(SharedPlayer *player, Actor_func_802238E0_de *body, SharedMovement *movementProfile) {
    CVector3 v18,v28,v38,v48,v58;
    MatrixF rotationMatrix;
    CQuatern bodyRotation;
    f32 forwardSpeed;
    f32 upwardSpeedLimit;
    f32 verticalSpeed;
    f32 boostCooldown;
    f32 forwardSpeedLimit;
    f32 temp_f1_3;
    f32 strafeSpeed;
    f32 temp_f1_5;
    f32 temp_f2;
    f32 strafeSpeedLimit;
    f32 temp_f2_3;
    f32 var_f0;
    f32 var_f0_2;
    f32 forwardBoostSpeed;
    f32 var_f0_4;
    f32 var_f14;
    f32 var_f14_2;
    f32 var_f1;
    s32 boostButtons;
    s32 temp_v1_2;
    s32 boostReady;
    s32 boostApplied;

    boostApplied = 0;
    boostCooldown = player->views5E8.view6DC_60.unk6DC;
    boostReady = 1;
    if (!(boostCooldown <= 0.0f)) {
        boostReady = 0;
        player->views5E8.view6DC_60.unk6DC = (f32) (boostCooldown - D_800D2988[0]);
    }
    forwardSpeed=player->views5E8.view6C0_51.unk6C0; forwardSpeedLimit=movementProfile->unk4;
    if (forwardSpeed<0.0f ? forwardSpeedLimit < -forwardSpeed : forwardSpeedLimit < forwardSpeed) {
        player->views5E8.view6C0_51.unk6C0=Nav_DecayToZero(player->views5E8.view6C0_51.unk6C0,movementProfile->unk8*0.5f);
    } else if(player->views5E8.view6A8_43.unk6A8 != 0.0f) {
        player->views5E8.view6C0_51.unk6C0=func_802746A0_de(player->views5E8.view6C0_51.unk6C0,player->views5E8.view6A8_43.unk6A8*movementProfile->unk0,(player->views5E8.view6A8_43.unk6A8<0.0f?-player->views5E8.view6A8_43.unk6A8:player->views5E8.view6A8_43.unk6A8)*movementProfile->unk4);
    } else {
        player->views5E8.view6C0_51.unk6C0=Nav_DecayToZero(player->views5E8.view6C0_51.unk6C0,movementProfile->unk8);
    }
    strafeSpeed=player->views5E8.view6C4_54.unk6C4; strafeSpeedLimit=movementProfile->unk4;
    if (strafeSpeed<0.0f ? strafeSpeedLimit < -strafeSpeed : strafeSpeedLimit < strafeSpeed) {
        player->views5E8.view6C4_54.unk6C4=Nav_DecayToZero(player->views5E8.view6C4_54.unk6C4,movementProfile->unk8*0.5f);
    } else if(player->views5E8.view6A4_41.unk6A4 != 0.0f) {
        player->views5E8.view6C4_54.unk6C4=func_802746A0_de(player->views5E8.view6C4_54.unk6C4,player->views5E8.view6A4_41.unk6A4*movementProfile->unk0,(player->views5E8.view6A4_41.unk6A4<0.0f?-player->views5E8.view6A4_41.unk6A4:player->views5E8.view6A4_41.unk6A4)*movementProfile->unk4*0.75f);
    } else {
        player->views5E8.view6C4_54.unk6C4=Nav_DecayToZero(player->views5E8.view6C4_54.unk6C4,movementProfile->unk8);
    }
    if (boostReady != 0) {
        boostButtons = player->views5E8.view6B0_46.unk6B0;
        if (boostButtons & 8) {
            forwardBoostSpeed = movementProfile->unkC;
            boostApplied = 1;
        } else if (boostButtons & 4) {
            forwardBoostSpeed = -movementProfile->unkC * 0.5f;
            boostApplied = 1;
        } else {
            goto block_31;
        }
    } else {
block_31:
        forwardBoostSpeed = Nav_DecayToZero(player->views5E8.view6D4_58.unk6D4, movementProfile->unk10);
    }
    player->views5E8.view6D4_58.unk6D4 = forwardBoostSpeed;
    if (boostReady && (player->views5E8.view6B8_49.unk6B8 & 1)) {
        player->views5E8.view6D8_59.unk6D8=movementProfile->unkC;
        player->views5E8.view6D8_59.unk6D8*=0.75f;
        boostApplied=1;
    } else if (boostReady && (player->views5E8.view6B8_49.unk6B8 & 2)) {
        player->views5E8.view6D8_59.unk6D8=-movementProfile->unkC*0.75f;
        boostApplied=1;
    } else {
        player->views5E8.view6D8_59.unk6D8=Nav_DecayToZero(player->views5E8.view6D8_59.unk6D8,movementProfile->unk10*0.75f);
    }
    if ((boostReady != 0) && (player->views5E8.view6B0_46.unk6B0 & 0x10)) {
        boostApplied = 1;
        body->unk20 = (f32) (body->unk20 + movementProfile->unk1C);
    }
    if (player->views5E8.view6AC_45.unk6AC & 0x10) {
        verticalSpeed = body->unk20;
        upwardSpeedLimit = movementProfile->unk18;
        if (verticalSpeed < upwardSpeedLimit) {
            body->unk20 = func_802746A0_de(verticalSpeed, movementProfile->unk14, upwardSpeedLimit);
        }
    }
    v18.x = 0.0f;
    v18.y = 0;
    v18.z = player->views5E8.view6C0_51.unk6C0 + player->views5E8.view6D4_58.unk6D4;
    v28.x = player->views5E8.view6C4_54.unk6C4 + player->views5E8.view6D8_59.unk6D8;
    v28.y = 0;
    v28.z = 0;
    bodyRotation = func_8024796C_de(body);
    MatrixFromQuaternion(&bodyRotation, &rotationMatrix);
    Particle_TransformPoint(&rotationMatrix, &v18, &v38);
    Particle_TransformPoint(&rotationMatrix, &v28, &v48);
    player->views5E8.view6E8_63.unk6E8 = (f32) (player->views5E8.view6E8_63.unk6E8 + ((v38.x + v48.x) * player->views5E8.view66C_29.unk66C));
    player->views5E8.view6EC_64.unk6EC = (f32) (player->views5E8.view6EC_64.unk6EC + ((v38.y + v48.y) * player->views5E8.view66C_29.unk66C));
    player->views5E8.view6F0_66.unk6F0 = (f32) (player->views5E8.view6F0_66.unk6F0 + ((v38.z + v48.z) * player->views5E8.view66C_29.unk66C));
    if (body->unk20 < 0.0f) {
        Particle_AddVec3(&v58, &v38, &v48);
        body->unk20 = (f32) (body->unk20 - (player->views13B4.view13B4_2.unk13B4[player->views5E8.view650_15.unk650].physics->unk8 * (Math_Sqrtf((v58.x * v58.x) + (v58.y * v58.y) + (v58.z * v58.z)) / (movementProfile->unk4 * 4.0f)) * player->views5E8.view66C_29.unk66C));
    }
    Nav_EaseValueToward(&player->views5E8.view72C_75.unk72C, ((player->views5E8.view6C4_54.unk6C4 * 1.8f) + (player->views5E8.view69C_39.unk69C * 16.0f)) * 0.01745329424738884f, 0.04f);
    if (boostApplied != 0) {
        player->views5E8.view6DC_60.unk6DC = (f32) (player->views5E8.view6DC_60.unk6DC + 7.5f);
        Render_PlaySoundAtPosition(movementProfile->unk22, body->unk8, 0, -1);
    }
}
