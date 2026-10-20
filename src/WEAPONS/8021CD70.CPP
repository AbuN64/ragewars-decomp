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
/* Checks whether the player's current weapon can lock onto the target. */
s32 func_8021CD94_de(func_8021CD70_S1 *arg0, func_8021CD70_S2 *arg1) {
    s16 temp_a1;
    s32 temp_v1_3;
    s32 var_a0;
    s32 var_v0;
    s32 var_v0_2;
    s16 shielded;
    s8 temp_v1;
    s8 temp_v1_2;
    s8 temp_v1_4;
    ObjRecAt14V3 *temp_a1_2;
    View *temp_a1_3;
    View *temp_v0;
    temp_a1 = arg0->unk62E;
    if (temp_a1 == 0x12) {
        if (arg1->unk100 & 0x300000) {
            if (arg1->unk18->unk14 & 0x20) {
                temp_v1 = arg1->unk1A4;
                if ((temp_v1 != 0x26) && (temp_v1 != temp_a1) && (arg1->unk174 != 0)) {
                    temp_v0 = arg1->unk5DC;
                    if (temp_v0 == NULL) {
                        var_v0 = 0;
                    } else {
                        var_v0 = temp_v0->unk564 != 0;
                    }
                    if (var_v0 != 0) {
                        return 0;
                    }
                    goto block_25;
                }
                /* Duplicate return node #35. Try simplifying control flow for better match */
                return 0;
            }
            goto block_34;
        }
        temp_a1_2 = arg1->unk18;
        if (temp_a1_2->unk0 == 1) {
            if ((temp_a1_2->unk14 & 0x2400) == 0) {
                goto block_34;
            }
            temp_v1_2 = arg1->unk1A4;
            if (((temp_v1_2 == 0x21) || (temp_v1_2 == 0x34) ||
                 (temp_v1_2 == 0x3C) || (temp_v1_2 == 0x3D)) ||
                (arg1->unk174 == 0)) {
                goto block_34;
            }
            goto block_25;
        }
        goto block_19;
    }
block_19:
    temp_v1_3 = arg1->unk18->unk0;
    if (temp_v1_3 == 4) goto block_24;
    if (temp_v1_3 < 5) return 0;
    if (temp_v1_3 == 7) goto block_34;
    if (temp_v1_3 == 11) goto block_27;
    return 0;
block_24:
    do {
        if (arg1->unk174 == 0) goto block_34;
    } while (0);
block_25:
    return func_80216BF4_de(arg0, &arg0->unk170, arg1) == 0;
block_27:
    temp_v1_4 = arg1->unk1A4;
    var_a0 = 0;
    if (temp_v1_4 == 0x26) goto block_33;
    if (temp_v1_4 == 0x12) goto block_33;
    if (arg1->unk174 == 0) goto block_33;
    var_v0_2 = 0;
    temp_a1_3 = arg1->unk5DC;
    if (temp_a1_3 != NULL) {
        /* FAKEMATCH: keep the shield predicate in a named flag for register selection. */
        shielded = temp_a1_3->unk564 != 0;
        var_v0_2 = shielded;
    }
    if (var_v0_2 == 0) var_a0 = 1;
block_33:
    return var_a0;
block_34:
    return 0;
}

/* These contiguous globals place the actor-list pointer 0x1285 bytes before the enable flag. */
extern void *func_8024BC94_de(void *arg0, s32 unused1, struct IntPair arg2);
struct func_8021CD70_S1;
struct func_8021CD70_S2;
extern s32 func_8021CD94_de(func_8021CD70_S1 *, func_8021CD70_S2 *);
extern void func_80272018_de(CVector3 *, CVector3 *, CVector3 *);
extern CQuatern func_8024796C_de(char *);
extern void func_80274098_de(void *, void *, void *);

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
                if (func_8021CD94_de((void *)player, (void *)other) && other != player) {
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
            if (func_8021CD94_de((void *)player, (void *)other)) {
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
