#include "COMMON/ITEMRECAT20V1.H"
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

s32 func_80216BF4_de(void *, void *, void *);
/* Whether the target's view reports an active shield. */
static inline s32 Weapons_TargetShielded(func_8021CD70_S2 *target) {
    View *view = target->unk5DC;
    if (view == NULL) {
        return 0;
    }
    return view->unk564 != 0;
}
/* Checks whether the player's current weapon can lock onto the target. Kind 0 and 7 targets never lock. */
s32 Weapons_CanLockTarget(func_8021CD70_S1 *attacker, func_8021CD70_S2 *target) {
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
                return func_80216BF4_de(attacker, &attacker->unk170, target) == 0;
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
                return func_80216BF4_de(attacker, &attacker->unk170, target) == 0;
            }
            return 0;
        }
    }
    switch (target->unk18->unk0) {
    case 4:
        if (target->unk174 != 0) {
            return func_80216BF4_de(attacker, &attacker->unk170, target) == 0;
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
extern void *func_8024BC94_de(void *arg0, s32 unused1, struct IntPair arg2);
struct func_8021CD70_S1;
struct func_8021CD70_S2;
extern s32 Weapons_CanLockTarget(func_8021CD70_S1 *, func_8021CD70_S2 *);
extern void func_80272018_de(CVector3 *, CVector3 *, CVector3 *);
#ifdef NON_MATCHING
#define func_8024796C_de func_8024796C_de_value
#endif
extern CQuatern func_8024796C_de(char *);
extern void func_80274098_de(void *, void *, void *);

#ifdef NON_MATCHING
#define func_8021CF28_de func_8021CF28_de_value
#endif
CQuatern func_8021CF28_de(DraftAimPlayer *player, DraftAimPlayer **target,
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
    threshold = func_802B6560_de(angle * D_800C238C_de);
    if (angle != 0.0f) {
        unit.x = 0.0f;
        unit.y = 0.0f;
        unit.z = D_800C2390_de;
        /* The ROM ABI returns a three-float vector and takes a three-float offset. */
        forward = ((CVector3 (*)(void *, CVector3))func_8024BC94_de)(player, unit);
        origin = player->position;
        origin.y += func_8022ADBC_de(player);
        enable = &D_801462E5;
        if (*enable) {
            other = ((AimGlobals *)(enable - 0x1285))->head;
            if (other) {
                firstSpecial = 0x12;
                scale = D_800C2394_de;
                do {
                if (Weapons_CanLockTarget((void *)player, (void *)other) && other != player) {
                    if (player->weapon == firstSpecial) candidate = other->specialAim;
                    else {
                        candidate = other->position;
                        candidate.y += other->height;
                        candidate.y += Particle_GetActorHeight(other) * scale;
                    }
                    func_80271F68_de(&direction, &candidate, &origin);
                    func_8027207C_de(&direction.x);
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
        count = D_8011CC18;
        i = 0;
        if (i < count) {
            secondSpecial = 0x12;
            scale = D_800C2398_de;
            do {
            other = (void *)D_8011CA18[i];
            if (Weapons_CanLockTarget((void *)player, (void *)other)) {
                if (player->weapon == secondSpecial) candidate = other->specialAim;
                else {
                    candidate = other->position;
                    candidate.y += other->height;
                    candidate.y += Particle_GetActorHeight(other) * scale;
                }
                func_80271F68_de(&direction, &candidate, &origin);
                func_8027207C_de(&direction.x);
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
        func_80272018_de(&axis, &forward, &bestDirection);
        func_8027207C_de(&axis.x);
        scale = D_800C239C_de;
        threshold = func_802745D0_de(threshold);
        amount = func_802B72B0_de(D_800C23A0_de - threshold / (angle * scale));
        amount = func_802B72B0_de(amount);
        threshold *= amount;
        threshold *= scale;
        amount = func_802B7130_de(threshold);
        correction.x = axis.x * amount;
        correction.y = axis.y * amount;
        correction.z = axis.z * amount;
        D_80115DEC = amount;
        correction.w = func_802B6560_de(threshold);
        facing = func_8024796C_de((char *)player);
        func_80274098_de(&result, &facing, &correction);
    }
    return result;
}
#ifdef NON_MATCHING
#undef func_8021CF28_de
void func_8021CF28_de(CQuatern *out, DraftAimPlayer *player, DraftAimPlayer **target, CVector3 *targetPosition) {
    *out = func_8021CF28_de_value(player, target, targetPosition);
}
#endif
