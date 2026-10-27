#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/WORLD.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "stddef.h"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/OBJ.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "COMMON/TRIPLE.H"
#include "FX_2/80271B18.H"

s32 Barrel_TestTargetEyeObstruction(void *, void *, void *);
/* Whether the target's view reports an active shield. */
static inline s32 Weapons_TargetShielded(func_8021CD70_S2 *target) {
    View *view = target->unk5DC;
    if (view == NULL) {
        return 0;
    }
    return view->unk564 != 0;
}
/* Checks whether the player's current weapon can lock onto the target. Kind 0 and 7 targets never lock. */
s32 Player_CanLockTarget(func_8021CD70_S1 *attacker, func_8021CD70_S2 *target) {
    s16 weapon;
    s8 mode;
    s32 canLock;

    weapon = attacker->unk62E;
    if (weapon == 0x12) {
        if (target->unk100 & 0x300000) {
            if (!(target->unk18->unk14 & 0x20)) {
                return 0;
            }
            mode = target->unk1A4;
            if (mode == 0x26 || mode == weapon || target->unk174 == 0) {
                return 0;
            }
            if (!Weapons_TargetShielded(target)) {
                return Barrel_TestTargetEyeObstruction(attacker, &attacker->unk170, target) == 0;
            }
            return 0;
        }
        if (target->unk18->unk0 == 1) {
            if (!(target->unk18->unk14 & 0x2400)) {
                return 0;
            }
            mode = target->unk1A4;
            if (mode == 0x21 || mode == 0x34 || mode == 0x3C || mode == 0x3D) {
                return 0;
            }
            if (target->unk174 != 0) {
                return Barrel_TestTargetEyeObstruction(attacker, &attacker->unk170, target) == 0;
            }
            return 0;
        }
    }
    switch (target->unk18->unk0) {
    case 4:
        if (target->unk174 != 0) {
            return Barrel_TestTargetEyeObstruction(attacker, &attacker->unk170, target) == 0;
        }
        return 0;
    case 0:
    case 7:
        return 0;
    case 11:
        canLock = 0;
        mode = target->unk1A4;
        if (mode != 0x26 && mode != 0x12 && target->unk174 != 0 && !Weapons_TargetShielded(target)) {
            canLock = 1;
        }
        return canLock;
    }
    return 0;
}

/* These contiguous globals place the actor-list pointer 0x1285 bytes before the enable flag. */
#include "ENGINE/INSTANCE/GOBJINST_13.H"
struct func_8021CD70_S1;
struct func_8021CD70_S2;
extern s32 Player_CanLockTarget(func_8021CD70_S1 *, func_8021CD70_S2 *);
extern void GraphU64_CrossVectors(CVector3 *, CVector3 *, CVector3 *);
extern CQuatern func_8024796C_de(char *);
extern void MultiplyQuaternions(void *, void *, void *);

CQuatern Player_ComputeAimRotation(DraftAimPlayer *player, DraftAimPlayer **target,
                            CVector3 *targetPosition)
{
    CVector3 candidate, direction, origin;
    CVector3 bestPosition;
    CVector3 forward, unit;
    CVector3 bestDirection;
    CVector3 axis;
    CQuatern correction, facing, result;
    DraftAimPlayer *other, *best;
    AimGlobals *globals;
    u8 *enable;
    f32 angle, dot, threshold, half, amount, scale;
    s32 count, i, firstSpecial, secondSpecial;

    bestPosition.x = 0.0f;
    bestPosition.y = 0.0f;
    bestPosition.z = 0.0f;
    bestDirection.x = 0.0f;
    bestDirection.y = 0.0f;
    bestDirection.z = 0.0f;
    result.x = result.y = result.z = bestPosition.x;
    result.w = D_800C2388_de;
    best = 0;
    if (player->weapon != -1) angle = ((DraftAimWeapon *)D_800D052C[player->weapon])->angle;
    else angle = bestPosition.x;
    threshold = Math_Cosf(angle * D_800C238C_de);
    if (angle != 0.0f) {
        unit.x = 0.0f;
        unit.y = 0.0f;
        unit.z = D_800C2390_de;
        func_8024BC94_de(&forward, player, unit);
        origin = player->position;
        origin.y += Player_GetObjectOwnerHeight(player);
        enable = &D_80145088.settings.local;
        if (*enable) {
            other = ((AimGlobals *)(enable - 0x1285))->head;
            if (other) {
                firstSpecial = 0x12;
                scale = D_800C2394_de;
                do {
                if (Player_CanLockTarget((void *)player, (void *)other) && other != player) {
                    if (player->weapon == firstSpecial) candidate = other->specialAim;
                    else {
                        candidate = other->position;
                        candidate.y += other->height;
                        candidate.y += GameObject_GetActorHeight(other) * scale;
                    }
                    GraphU64_SubtractVectors(&direction, &candidate, &origin);
                    GraphU64_NormalizeVec3(&direction.x);
                    dot = forward.x * direction.x + forward.y * direction.y +
                          forward.z * direction.z;
                    if (threshold < dot) {
                        threshold = dot;
                        bestPosition = candidate;
                        best = other;
                    }
                }
                            } while ((other = other->next) != 0);
            }
        }
        count = g_world.registeredCount;
        i = 0;
        if (i < count) {
            secondSpecial = 0x12;
            scale = D_800C2398_de;
            do {
            other = (void *)D_8011CA18[i];
            if (Player_CanLockTarget((void *)player, (void *)other)) {
                if (player->weapon == secondSpecial) candidate = other->specialAim;
                else {
                    candidate = other->position;
                    candidate.y += other->height;
                    candidate.y += GameObject_GetActorHeight(other) * scale;
                }
                GraphU64_SubtractVectors(&direction, &candidate, &origin);
                GraphU64_NormalizeVec3(&direction.x);
                dot = forward.x * direction.x + forward.y * direction.y +
                      forward.z * direction.z;
                if (threshold < dot) {
                    threshold = dot;
                    best = other;
                    bestPosition = candidate;
                    bestDirection = direction;
                }
            }
                        i++;
            } while (i < count);
        }
    }
    *target = best;
    *targetPosition = bestPosition;
    if (best) {
        GraphU64_CrossVectors(&axis, &forward, &bestDirection);
        GraphU64_NormalizeVec3(&axis.x);
        scale = D_800C239C_de;
        threshold = GraphU64_ArcCos(threshold);
        amount = Math_Sqrtf(D_800C23A0_de - threshold / (angle * scale));
        amount = Math_Sqrtf(amount);
        threshold *= amount;
        threshold *= scale;
        amount = Math_Sinf(threshold);
        correction.x = axis.x * amount;
        correction.y = axis.y * amount;
        correction.z = axis.z * amount;
        D_80115DEC = amount;
        correction.w = Math_Cosf(threshold);
        facing = func_8024796C_de((char *)player);
        MultiplyQuaternions(&result, &facing, &correction);
    }
    return result;
}
