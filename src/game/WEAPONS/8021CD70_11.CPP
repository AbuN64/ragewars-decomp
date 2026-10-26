#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "TYPES.H"

/* Updates player forward, strafe and impulse velocities, accumulates movement and plays the impulse sound. */
extern float D_800D2988[];




extern s32 Cinema_IsSequenceActive(void);
extern void SoundElement_PlaySoundAtPosition(s16,CVector3,s32,s32),GraphU64_AddVec3(CVector3 *,CVector3 *,CVector3 *),GraphU64_ScaleVector(CVector3 *,CVector3 *,f32),GraphU64_ClampMotionLength(CVector3 *,f32);

void func_802233F0_de(SharedPlayer *player, func_802165F8_S1 *body, SharedMovement *movementProfile) {
    CVector3 motion;
    f32 forwardSpeed;
    f32 updatedForwardSpeed;
    f32 boostCooldown;
    f32 forwardSpeedLimit;
    f32 temp_f1_3;
    f32 forwardMotionX;
    f32 strafeSpeed;
    f32 temp_f1_6;
    f32 temp_f2;
    f32 strafeSpeedLimit;
    f32 temp_f2_3;
    f32 var_a1;
    f32 var_f0;
    f32 var_f0_2;
    f32 forwardBoostSpeed;
    f32 var_f0_4;
    f32 var_f14;
    f32 var_f14_2;
    f32 strafeSpeedMagnitude;
    s32 boostButtons;
    s32 temp_v1_2;
    s32 boostApplied;
    s32 boostReady;
    CVector3 *movementOutput;

    if (Cinema_IsSequenceActive() == 0) {
        boostApplied = 0;
        if (player->views5E8.view11B8_137.unk11B8 == 0) {
            boostCooldown = player->views5E8.view6DC_60.unk6DC;
            boostReady = 1;
            if (!(boostCooldown <= 0.0f)) {
                boostReady = 0;
                player->views5E8.view6DC_60.unk6DC = (f32) (boostCooldown - D_800D2988[0]);
            }
            forwardSpeed=player->views5E8.view6C0_51.unk6C0; forwardSpeedLimit=movementProfile->unk4;
            if (forwardSpeed < 0.0f ? forwardSpeedLimit < -forwardSpeed : forwardSpeedLimit < forwardSpeed) {
                player->views5E8.view6C0_51.unk6C0=GraphU64_DecayToZero(player->views5E8.view6C0_51.unk6C0,movementProfile->unk8*0.5f);
            } else if(player->views5E8.view6A8_43.unk6A8 != 0.0f && player->views5E8.view7E8_105.unk7E8 != 2) {
                player->views5E8.view6C0_51.unk6C0=GraphU64_IntegrateBoundedValue(player->views5E8.view6C0_51.unk6C0,player->views5E8.view6A8_43.unk6A8*movementProfile->unk0,(player->views5E8.view6A8_43.unk6A8<0.0f?-player->views5E8.view6A8_43.unk6A8:player->views5E8.view6A8_43.unk6A8)*movementProfile->unk4);
            } else {
                player->views5E8.view6C0_51.unk6C0=GraphU64_DecayToZero(player->views5E8.view6C0_51.unk6C0,movementProfile->unk8);
            }
            forwardMotionX = player->views5E8.view6C0_51.unk6C0 * Math_Sinf(body->unk6C + 3.1415927f);
            motion.y = 0;
            motion.x = forwardMotionX;
            motion.z = player->views5E8.view6C0_51.unk6C0 * Math_Cosf(body->unk6C + 3.1415927f);
            strafeSpeed=player->views5E8.view6C4_54.unk6C4; strafeSpeedLimit=movementProfile->unk10;
            if (strafeSpeed < 0.0f ? strafeSpeedLimit < -strafeSpeed : strafeSpeedLimit < strafeSpeed) {
                player->views5E8.view6C4_54.unk6C4=GraphU64_DecayToZero(player->views5E8.view6C4_54.unk6C4,movementProfile->unk14*0.5f);
            } else if(player->views5E8.view6A4_41.unk6A4 != 0.0f) {
                player->views5E8.view6C4_54.unk6C4=GraphU64_IntegrateBoundedValue(player->views5E8.view6C4_54.unk6C4,player->views5E8.view6A4_41.unk6A4*movementProfile->unkC,(player->views5E8.view6A4_41.unk6A4<0.0f?-player->views5E8.view6A4_41.unk6A4:player->views5E8.view6A4_41.unk6A4)*movementProfile->unk10);
            } else {
                player->views5E8.view6C4_54.unk6C4=GraphU64_DecayToZero(player->views5E8.view6C4_54.unk6C4,movementProfile->unk14);
            }
            motion.x += player->views5E8.view6C4_54.unk6C4 * Math_Sinf(body->unk6C - 1.5707964f);
            motion.z += player->views5E8.view6C4_54.unk6C4 * Math_Cosf(body->unk6C - 1.5707964f);
            strafeSpeedMagnitude = player->views5E8.view6C4_54.unk6C4;
            if (strafeSpeedMagnitude < 0.0f) {
                strafeSpeedMagnitude = -strafeSpeedMagnitude;
            }
            updatedForwardSpeed = player->views5E8.view6C0_51.unk6C0;
            if (updatedForwardSpeed < 0.0f) {
                if (-updatedForwardSpeed < strafeSpeedMagnitude) {
                    goto block_35;
                }
                goto block_36;
            }
            if (updatedForwardSpeed < strafeSpeedMagnitude) {
block_35:
                GraphU64_ClampMotionLength(&motion,movementProfile->unk10);
            } else {
block_36:
                GraphU64_ClampMotionLength(&motion,movementProfile->unk4);
            }
            if (boostReady != 0) {
                boostButtons = player->views5E8.view6B0_46.unk6B0;
                if (boostButtons & 8) {
                    forwardBoostSpeed = movementProfile->unk18;
                    boostApplied = 1;
                } else if (boostButtons & 4) {
                    forwardBoostSpeed = -movementProfile->unk18 * 0.5f;
                    boostApplied = 1;
                } else {
                    goto block_42;
                }
            } else {
block_42:
                forwardBoostSpeed = GraphU64_DecayToZero(player->views5E8.view6D4_58.unk6D4, movementProfile->unk1C);
            }
            player->views5E8.view6D4_58.unk6D4 = forwardBoostSpeed;
            motion.x += player->views5E8.view6D4_58.unk6D4 * Math_Sinf(body->unk6C + 3.1415927f);
            motion.z += player->views5E8.view6D4_58.unk6D4 * Math_Cosf(body->unk6C + 3.1415927f);
            if (boostReady && (player->views5E8.view6B8_49.unk6B8 & 1)) {
                player->views5E8.view6D8_59.unk6D8 = movementProfile->unk18;
                player->views5E8.view6D8_59.unk6D8 *= 0.75f;
                boostApplied=1;
            } else if (boostReady && (player->views5E8.view6B8_49.unk6B8 & 2)) {
                player->views5E8.view6D8_59.unk6D8 = -movementProfile->unk18*0.75f;
                boostApplied=1;
            } else {
                player->views5E8.view6D8_59.unk6D8=GraphU64_DecayToZero(player->views5E8.view6D8_59.unk6D8,movementProfile->unk1C*0.75f);
            }
            motion.x += player->views5E8.view6D8_59.unk6D8 * Math_Sinf(body->unk6C - 1.5707964f);
            motion.z += player->views5E8.view6D8_59.unk6D8 * Math_Cosf(body->unk6C - 1.5707964f);
            GraphU64_ScaleVector(&motion, &motion, player->views5E8.view66C_29.unk66C);
            movementOutput = &player->views5E8.view6E8_63.unk6E8;
            GraphU64_AddVec3(movementOutput, movementOutput, &motion);
            if (boostApplied != 0) {
                player->views5E8.view6DC_60.unk6DC = (f32) (player->views5E8.view6DC_60.unk6DC + 7.5f);
                SoundElement_PlaySoundAtPosition(movementProfile->unk22, body->unk8, 0, -1);
            }
        }
    }
}
