#include "TYPES.H"
#include "COMMON/LONE/D_80103FD0.H"
#include "COMMON/VECTOR4F.H"
#include "stddef.h"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"

#include "WEAPONS/AIM_TYPES.H"






extern const f32 D_800C23B4_de;
extern const f32 D_800C23B8_de;
extern const f32 D_800C23BC_de;
extern const f32 D_800C23C0_de;
extern const f32 D_800C23C4_de;
extern const f32 D_800C23C8_de;
extern const f32 D_800C23CC_de;
extern const f32 D_800C23D0_de;
extern f32 D_800D2988;
extern AimHit *D_80103FCC;
extern char D_801000F0;
extern void *D_800D052C[];
void CopyMatrix(f32 *, f32 *);
void Player_BuildPlayerViewTransform(void *, f32 *);
void func_8022B144_de(void *, f32 *);
s32 func_802444A4_de(char *, CVector3, CVector3, s32);
void GraphU64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
void GraphU64_AddVec3(CVector3 *, CVector3 *, CVector3 *);
void GraphU64_ScaleVector(CVector3 *, CVector3 *, f32);
f32 Math_Sqrtf(f32);
void func_8021D408_de(struct SharedPlayer *, CVector3 *, CVector3 *);
CQuatern Player_ComputeAimRotation(void *, AimActor **, void *);
CQuatern func_8024796C_de(char *);
typedef struct func_8021CD70_S1 func_8021CD70_S1;
typedef struct func_8021CD70_S2 func_8021CD70_S2;
s32 Player_CanLockTarget(func_8021CD70_S1 *, func_8021CD70_S2 *);
f32 GameObject_GetActorHeight(void *);
void func_8021D774_de(AimPlayer *player) {
    AimOutput aimResult;
    CVector3 localForward;
    CVector3 smoothOffset;
    CVector3 desired;
    f32 matrix[16];
    CVector3 current;
    CQuatern aimRotation;
    AimWeapon *weapon;
    AimOutput probeLow;
    CQuatern probeHigh;
    CVector3 direction;
    AimActor *lockedTarget, *probeTarget;
    CVector3 *aimOffsetOutput, *temp_s2, *temp_s2_2, *var_a1, *temp_s0_2, *temp_s1;
    f32 smoothingFactor, temp_fs1f, temp_fs2, temp_fv0, temp_fv0_2, var_fs0f, var_fs1;
    s16 selectedWeapon, temp_v1_2;
    s32 var_s4;
    s32 temp_v1_3, var_s0, var_s5;
    AimActor *rayHitActor, *target;
    AimView *view;
    lockedTarget = NULL;
    view = player->view;
    temp_fs1f = D_800C23B4_de;
    temp_fs2 = D_800C23B8_de;
    if (view) { switch (view->mode) { case 1: Player_BuildPlayerViewTransform(player, matrix); func_8022B144_de(player, &current.x); break; default: CopyMatrix(matrix, view->matrix); current = view->origin; break; } } else { Player_BuildPlayerViewTransform(player, matrix); func_8022B144_de(player, &current.x); }
    localForward.x = 0.0f;
    localForward.y = 0;
    localForward.z = D_800C23BC_de;
    GraphU64_TransformPoint(matrix, &localForward, &desired);
    if (func_802444A4_de((char *)player, current, desired, (s32) &D_80103FD0) != 0) {
        player->aim = D_80103FCC->point;
        player->normal = D_80103FCC->normal;
        player->target = D_80103FCC->actor;
    } else {
        player->aim = desired;
        player->target = NULL;
    }
    localForward.x = 0.0f;
    localForward.y = 0;
    localForward.z = D_800C23C0_de;
    GraphU64_TransformPoint(matrix, &localForward, &desired);
    if (player->enabled != 0) {
        if ((func_802444A4_de((char *)player, current, desired, (s32) &D_801000F0) != 0) && (rayHitActor = D_80103FCC->actor, (rayHitActor != NULL))) {
            if (rayHitActor->kind == 1) {
                if (rayHitActor->flags & 0x300000) {
                    GraphU64_SubtractVectors((CVector3 *)&aimRotation, &rayHitActor->pos, &player->unk8);
                    temp_fv0 = Math_Sqrtf((aimRotation.x * aimRotation.x) + (aimRotation.y * aimRotation.y) + (aimRotation.z * aimRotation.z));
                    direction = localForward;
                    GraphU64_NormalizeVec3(&direction);
                    GraphU64_ScaleVector(&probeLow.xyz, &direction, temp_fv0);
                    GraphU64_TransformPoint(matrix, &probeLow.xyz, (CVector3 *)&probeHigh);
                    player->aim2 = (*(CVector3 *)&probeHigh);
                    func_8021D408_de((void *)player, (CVector3 *)&probeHigh, &D_80103FCC->normal);
                } else {
                    goto block_14;
                }
            } else {
                goto block_15;
            }
        } else {
block_14:
block_15:
            player->aim2 = player->aim;
            func_8021D408_de((void *)player, &player->aim, &D_80103FCC->normal);
        }
    } else {
        player->aim2 = desired;
    }
    if (player->unk62E == 1 && player->unk594 == 2) {
        var_s4 = 0x2C6;
    } else {
        weapon=D_800D052C[player->unk62E]; var_s4=weapon->idle;
    }
    selectedWeapon = player->unk62E;
    var_s5 = var_s4 + 0x64;
    var_s0 = 1;
    if ((selectedWeapon == 1) || (selectedWeapon == 0x12)) {
        var_fs0f = D_800C23C4_de;
        var_fs1 = var_fs0f;
    } else {
        var_fs0f = 0.0f;
        var_fs1 = 0.0f;
    }
    switch (player->unk62E) {
    case 7:
        if (player->unk7E8 != 0) {
            var_s4 = 0x2E4;
            var_s5 = -1;
        }
        break;
    case 2:
        if (player->unk7E8 != 0) {
            var_s4 = 0x2BC;
            var_s5 = -1;
        }
        break;
    case 1:
    case 0x12:
        aimRotation = Player_ComputeAimRotation(player, &lockedTarget, &aimResult.words);
        var_s0 = 0;
        break;
    default:
        var_s5 = -1;
        break;
    }
    aimRotation = func_8024796C_de((char *)player);
    player->rotation = aimRotation;
    probeLow.xyz = player->aim;
    probeLow.xyz.x -= D_800C23C8_de;
    (*(CVector3 *)&probeHigh) = player->aim;
    (*(CVector3 *)&probeHigh).x += D_800C23C8_de;
    probeLow.xyz = player->aim;
    probeLow.xyz.z -= D_800C23C8_de;
    (*(CVector3 *)&probeHigh) = player->aim;
    (*(CVector3 *)&probeHigh).z += D_800C23C8_de;
    probeLow.xyz = player->aim;
    probeLow.xyz.y -= D_800C23C8_de;
    (*(CVector3 *)&probeHigh) = player->aim;
    (*(CVector3 *)&probeHigh).y += D_800C23C8_de;
    if (lockedTarget == NULL) {
        aimResult.xyz = desired;
        if ((player->unk5D8->active != 0) && (var_s0 != 0)) {
            probeHigh = Player_ComputeAimRotation(player, &probeTarget, &probeLow.words);
            if (probeTarget != NULL) {
                player->rotation = probeHigh;
            }
        }
        if (lockedTarget == NULL) {
            player->unk794 = NULL;
        }
    }
    if (var_s4 == -1) {
        player->unk788 = 0;
    } else if (player->unk788 == 0) {
        player->unk788 = 1;
        player->out = desired;
        player->velocity.x = 0;
        player->velocity.y = 0;
        player->velocity.z = 0;
        player->smooth = desired;
        player->smoothVelocity.x = 0;
        player->smoothVelocity.y = 0;
        player->smoothVelocity.z = 0;
    }
    temp_s2 = &player->smooth;
    smoothingFactor = D_800C23CC_de;
    GraphU64_SubtractVectors(&smoothOffset, &aimResult.xyz, temp_s2);
    GraphU64_ScaleVector(&smoothOffset, &smoothOffset, temp_fs1f * smoothingFactor);
    temp_s0_2 = &player->smoothVelocity;
    GraphU64_AddVec3(temp_s0_2, temp_s0_2, &smoothOffset);
    GraphU64_AddVec3(temp_s2, temp_s2, temp_s0_2);
    GraphU64_ScaleVector(temp_s0_2, temp_s0_2, temp_fs2 * smoothingFactor);
    if (lockedTarget != NULL) {
        weapon=D_800D052C[player->unk62E]; player->unk7B8=weapon->locked+0x64;
    } else {
        player->unk7B8 = var_s5;
    }
    switch (player->unk788) {
    case 1:
        if ((lockedTarget == NULL) || (player->unk794 != lockedTarget)) {
            player->unk794 = lockedTarget;
            player->unk78C = 0.0f;
        }
        temp_fv0_2 = player->unk78C + D_800D2988;
        player->unk78C = temp_fv0_2;
        if (var_fs1 <= temp_fv0_2) {
            player->unk788 = 2;
            player->unk78C = 0.0f;
        }
        goto reset_position;
    case 2:
            if (player->unk7B4 != lockedTarget) {
                player->unk7B4 = lockedTarget;
                player->unk78C = 0.0f;
            } else {
                player->unk78C += D_800D2988;
            }
            if ((lockedTarget != NULL) && (player->unk794 != lockedTarget) && (var_fs0f <= player->unk78C)) {
                player->unk794 = lockedTarget;
                player->unk78C = 0.0f;
            }
            target = player->unk794;
            lockedTarget = target;
            if (target != NULL) {
                if (Player_CanLockTarget((void *)player, (void *)target) == 0) {
                    player->unk788 = 1;
                    player->unk78C = 0.0f;
                }
                if (player->unk62E == 0x12) {
                    aimResult.xyz = lockedTarget->focus;
                } else {
                    aimResult.xyz = lockedTarget->pos;
                    aimResult.xyz.y = aimResult.xyz.y + lockedTarget->height;
                    aimResult.xyz.y += GameObject_GetActorHeight(lockedTarget) * D_800C23D0_de;
                }
                if (player->unk62E == 1 && player->unk594 == 2) {
                    var_s4 = 0x2C7;
                } else {
                    weapon=D_800D052C[player->unk62E]; var_s4=weapon->locked;
                }
            } else {
                goto reset_position;
            }
        break;
    case 0:
reset_position:
        aimResult.xyz = desired;
        break;
    default:
        break;
    }
    aimOffsetOutput = &smoothOffset;
    temp_s2_2 = &player->out;
    GraphU64_SubtractVectors(aimOffsetOutput, &aimResult.xyz, temp_s2_2);
    GraphU64_ScaleVector(&smoothOffset, &smoothOffset, temp_fs1f);
    temp_s1 = &player->velocity;
    GraphU64_AddVec3(temp_s1, temp_s1, &smoothOffset);
    GraphU64_AddVec3(temp_s2_2, temp_s2_2, temp_s1);
    GraphU64_ScaleVector(temp_s1, temp_s1, temp_fs2);
    player->unk798 = (s32) var_s4;
}
