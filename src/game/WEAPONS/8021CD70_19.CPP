#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "TYPES.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/GAMEPLAY_MOVEMENT.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "DATA/OVLTAB2/800C9FA8.H"
#include "WEAPONS/800C7B48.H"

extern char D_800CED30;
s32 InstHdr_GetActorMotionState(void *);
extern void GraphU64_EaseValueToward(f32 *value, f32 target, f32 rate);
/* Updates swimming turn, pitch, stride motion, sounds, and animation. */
void func_802251DC_de(SharedPlayer *player, SharedPlayer *body) {
    Shared_Game *game;
    f32 detachDistance;
    f32 jumpHeadingOffset;
    f32 previousClimbSpeed;
    f32 strafeHeadingOffset;
    f32 motionSine;
    f32 motionIntermediate;
    f32 jumpedHeading;
    f32 releaseTurn;
    f32 movementHeading;
    f32 jumpTurn;
    f32 strideRoll;
    f32 climbInput;
    f32 strafeInput;
    f32 rollInput;
    f32 strideTime;
    f32 climbAcceleration;
    f32 strafeAcceleration;
    f32 pitchLimit;
    f32 adjustedJumpHeading;
    f32 climbSpeedLimit;
    f32 strafeSpeedLimit;
    f32 turnLimit;
    f32 targetPitch;
    s32 surfaceFlagsOrActorKind;
    s32 jumpStarted;
    s32 descending;
    f32 *eyex;
    f32 *eyey;
    f32 *eyez;
    s32 actorKindOrAnimation;
    s32 ascending;

    if (!(body->views1C.view38_3.flags & 0x100)) {
        player->views5E8.view724_72.pitch = 0.0f;
        player->turnAccumulator = 0.0f;
        if (InstHdr_GetActorMotionState(body) == 0) {
            detachDistance = D_800C2A58_de;
            player->views5E8.view6E8_79.unk6E8.x -= Math_Sinf(body->views1C.view6C_5.heading) * detachDistance;
            player->views5E8.view6E8_79.unk6E8.z -= Math_Cosf(body->views1C.view6C_5.heading) * detachDistance;
        }
        Player_SetPlayerState(player, body, 5);
        return;
    }
    motionIntermediate = player->views5E8.view69C_39.unk69C;
    if ((D_800C2A5C_de < motionIntermediate) || (motionIntermediate < D_800C2A5C_de)) {
        player->turnAccumulator += motionIntermediate * D_800C2A60_de;
    }
    motionIntermediate = player->turnAccumulator;
    turnLimit = D_800C2A64_de;
    if (turnLimit < motionIntermediate) player->turnAccumulator = turnLimit;
    else if (motionIntermediate < D_800C2A68_de) player->turnAccumulator=D_800C2A68_de;
    GraphU64_EaseValueToward(&player->views5E8.view728_73.unk728, player->turnAccumulator * D_800C2A6C_de, 0.5f);
    targetPitch = -player->views5E8.view69C_39.pitchInput * D_800C2A70_de;
    pitchLimit = D_800C2A74_de;
    if ((targetPitch < pitchLimit) || (pitchLimit = D_800C2A78_de, (pitchLimit < targetPitch))) {
        targetPitch = pitchLimit;
    }
    GraphU64_EaseValueToward(&player->views5E8.view724_72.pitch, targetPitch * D_800C2A7C_de, 0.0625f);
    if ((player->views5E8.view7E8_105.unk7E8 == 0) && !(player->views5E8.view6E4_61.unk6E4 > D_800C2A80_de) && !(body->views1C.view38_3.flags & 0xC0000) && (body->views18.view18_2.model->flags & 2) && (player->views5E8.view6B0_46.unk6B0 & 0x10) && (player->views5E8.view11D8_147.unk11D8 <= 0.0f)) { Player_SetPlayerState(player, body, 5); jumpStarted = 1; } else jumpStarted = 0;
    if (jumpStarted != 0) {
        jumpedHeading = body->views1C.view6C_5.heading + player->views5E8.view728_73.unk728;
        body->views1C.view6C_5.heading = jumpedHeading;
        jumpTurn = player->views5E8.view728_73.unk728;
        if (D_800C2A84_de <= jumpTurn) {
            adjustedJumpHeading = jumpedHeading + D_800C2A88_de;
            goto block_25;
        }
        if (jumpTurn <= D_800C2A8C_de) {
            adjustedJumpHeading = jumpedHeading - D_800C2A90_de;
block_25:
            body->views1C.view6C_5.heading = adjustedJumpHeading;
        }
        movementHeading = body->views1C.view6C_5.heading;
        jumpHeadingOffset = D_800C2A94_de;
        motionSine = Math_Sinf(movementHeading + jumpHeadingOffset);
        motionIntermediate = Math_Cosf(body->views1C.view6C_5.heading + jumpHeadingOffset);
        body->views1C.view1C_0.localDisplacement.x += motionSine * D_800C2A98_de;
        body->views1C.view1C_0.localDisplacement.z += motionIntermediate * D_800C2A98_de;
        releaseTurn = player->views5E8.view728_73.unk728;
        if (D_800C2A9C_de <= releaseTurn) {
            body->views1C.view6C_5.heading += D_800C2AA0_de;
        } else if (releaseTurn <= D_800C2AA4_de) {
            body->views1C.view6C_5.heading -= D_800C2AA8_de;
        }
        player->views5E8.view728_73.unk728 = 0.0f;
        player->turnAccumulator = 0.0f;
        return;
    }
    strideRoll = player->views5E8.view6DC_60.strideSign * player->views5E8.view6C0_51.unk6C0 * Math_Sinf(player->views5E8.view658_23.stride * D_800C2AAC_de);
    rollInput = player->views5E8.view6A8_44.lift;
    if (rollInput > 0.0f || rollInput < 0.0f)
        GraphU64_EaseValueToward(&player->views5E8.view72C_75.unk72C, strideRoll, 0.25f);
    else GraphU64_EaseValueToward(&player->views5E8.view72C_75.unk72C, 0.0f, 0.9f);
    climbInput = player->views5E8.view6A8_44.lift;
    ascending = climbInput > 0.0f;
    descending = climbInput < 0.0f;
    previousClimbSpeed = player->views5E8.view6C0_51.unk6C0;
    if ((ascending != 0) || (descending != 0)) {
        climbAcceleration = climbInput * D_800C2AB0_de;
        if (climbInput < 0.0f) {
            climbSpeedLimit = -climbInput * D_800C2AB4_de;
        } else {
            climbSpeedLimit = climbInput * D_800C2AB8_de;
        }
        player->views5E8.view6C0_51.unk6C0 = GraphU64_IntegrateBoundedValue(player->views5E8.view6C0_51.unk6C0, climbAcceleration, climbSpeedLimit);
    } else {
        player->views5E8.view6C0_51.unk6C0 = GraphU64_DecayToZero(previousClimbSpeed, D_800C2ABC_de);
    }
    strafeInput = player->views5E8.view6A4_42.strafe;
    if (strafeInput != 0.0f) {
        strafeAcceleration = strafeInput * D_800C2AC0_de;
        if (strafeInput < 0.0f) {
            strafeSpeedLimit = -strafeInput * D_800C2AC4_de;
        } else {
            strafeSpeedLimit = strafeInput * D_800C2AC8_de;
        }
        player->views5E8.view6C4_54.unk6C4 = GraphU64_IntegrateBoundedValue(player->views5E8.view6C4_54.unk6C4, strafeAcceleration, strafeSpeedLimit);
    } else {
        player->views5E8.view6C4_54.unk6C4 = GraphU64_DecayToZero(player->views5E8.view6C4_54.unk6C4, D_800C2ACC_de);
    }
    if ((player->views5E8.view6C0_51.unk6C0 == 0.0f) && (player->views5E8.view6C4_54.unk6C4 == 0.0f)) {
        player->views5E8.view658_23.stride = 0.0f;
        if (previousClimbSpeed != 0.0f) {
            player->views5E8.view6DC_60.strideSign = -player->views5E8.view6DC_60.strideSign;
        }
    } else {
        strideTime = player->views5E8.view658_23.stride;
        if (D_800C2AD0_de < strideTime) {
            player->views5E8.view6DC_60.strideSign = -player->views5E8.view6DC_60.strideSign;
            player->views5E8.view658_23.stride = strideTime - D_800C2AD0_de;
            player->views5E8.view6C0_51.unk6C0 *= D_800C2AD4_de;
            player->views5E8.view6C4_54.unk6C4 *= D_800C2AD4_de;
            game = &D_801462C8;
            if ((game->local != 0) && ((player->views5D8.view5D8_9.profile->remote != 1) || (game->unk62C == 0))) {
                surfaceFlagsOrActorKind = player->views1C.view38_3.flags;
                if (surfaceFlagsOrActorKind & 0x200) {
                    SoundElement_PlaySoundAtPosition(D_800C9FD6, body->views0.view8_4.position, 0, -1);
                } else if (surfaceFlagsOrActorKind & 0x400) {
                    SoundElement_PlaySoundAtPosition(D_800C9FDA, body->views0.view8_4.position, 0, -1);
                } else if (surfaceFlagsOrActorKind & 0x800) {
                    SoundElement_PlaySoundAtPosition(D_800C9FDE, body->views0.view8_4.position, 0, -1);
                } else {
                    SoundElement_PlaySoundAtPosition(strideSound(player->views5DC.view5E0_10.slot), body->views0.view8_4.position, 0, -1);
                }
            }
        }
    }
    eyex = &player->views5E8.view6E8_79.unk6E8.x;
    eyey = &player->views5E8.view6E8_79.unk6E8.y;
    eyez = &player->views5E8.view6E8_79.unk6E8.z;
    movementHeading = body->views1C.view6C_5.heading;
    strafeHeadingOffset = D_800C2AD8_de;
    motionSine = Math_Sinf(movementHeading - strafeHeadingOffset);
    motionIntermediate = Math_Cosf(body->views1C.view6C_5.heading - strafeHeadingOffset);
    {
    f32 horizontal = *eyex + motionSine * player->views5E8.view6C4_54.unk6C4 * player->views5E8.view66C_29.unk66C;
    f32 coefficient = D_800C2ADC_de;
    f32 frameDelta = D_800D2988;
    *eyex = horizontal;
    *eyez += motionIntermediate * player->views5E8.view6C4_54.unk6C4 * player->views5E8.view66C_29.unk66C;
    motionIntermediate = *eyey + player->views5E8.view6C0_51.unk6C0 * (frameDelta * coefficient);
    *eyey = motionIntermediate;
    actorKindOrAnimation = D_800CE47C;
    surfaceFlagsOrActorKind = player->views1C.viewE4_7.kind;
    if (surfaceFlagsOrActorKind != actorKindOrAnimation) { if (player->views5E8.view6C0_51.unk6C0 > 0.0f) { if (player->views13B4.view13B4_3.character != &D_800CED30) player->views5E8.view86C_125.unk86C = 0xA46; else player->views5E8.view86C_125.unk86C = 0x5E28; } else { if (player->views13B4.view13B4_3.character != &D_800CED30) player->views5E8.view86C_125.unk86C = 0xA3C; else player->views5E8.view86C_125.unk86C = 0x5E27; } } else { actorKindOrAnimation = 0xA46; player->views5E8.view86C_125.unk86C = actorKindOrAnimation; }
}}
