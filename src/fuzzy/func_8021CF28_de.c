#include "types.h"
#include "common/types_8a8189af7b05.h"

typedef struct DraftAimQuat { f32 x, y, z, w; } DraftAimQuat;
typedef struct DraftAimPlayer {
    char pad0[8]; Vec3 position;
    char pad14[0x5C]; f32 height;
    char pad74[0x1D4]; Vec3 specialAim;
    char pad254[0x3DA]; s16 weapon;
    char pad630[0x10B0]; struct DraftAimPlayer *next;
} DraftAimPlayer;
typedef struct DraftAimWeapon { char pad0[0x1C]; f32 angle; } DraftAimWeapon;
extern DraftAimWeapon *D_800D052C[];
extern DraftAimPlayer *D_80145060, *D_8011CA18[];
extern s32 D_8011CC18;
extern u8 D_801462E5;
extern f32 D_80115DEC;
extern f32 D_800C2388_de, D_800C238C_de, D_800C2390_de, D_800C2394_de;
extern f32 D_800C2398_de, D_800C239C_de, D_800C23A0_de;
extern Vec3 func_8024BC94_de(DraftAimPlayer *, Vec3);
extern f32 func_8022ADBC_de(DraftAimPlayer *);
extern s32 func_8021CD94_de(DraftAimPlayer *, DraftAimPlayer *);
extern f32 func_8024D284_de(DraftAimPlayer *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_8027207C_de(Vec3 *);
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);
extern f32 func_802B72B0_de(f32);
extern DraftAimQuat func_8024796C_de(DraftAimPlayer *);
extern void func_80274098_de(DraftAimQuat *, DraftAimQuat *, DraftAimQuat *);

DraftAimQuat func_8021CF28_de(DraftAimPlayer *player, DraftAimPlayer **target,
                            Vec3 *targetPosition)
{
    Vec3 candidate, direction, origin, bestPosition, forward, unit, bestDirection, axis;
    DraftAimQuat correction, facing, result;
    DraftAimPlayer *other, *best;
    f32 angle, dot, threshold, half, amount;
    s32 count, i;

    bestPosition.x = bestPosition.y = bestPosition.z = 0.0f;
    bestDirection.x = bestDirection.y = bestDirection.z = 0.0f;
    result.x = result.y = result.z = 0.0f;
    result.w = D_800C2388_de;
    best = 0;
    if (player->weapon != -1) angle = D_800D052C[player->weapon]->angle;
    else angle = 0.0f;
    threshold = func_802B6560_de(angle * D_800C238C_de);
    if (angle != 0.0f) {
        unit.x = unit.y = 0.0f;
        unit.z = D_800C2390_de;
        forward = func_8024BC94_de(player, unit);
        origin = player->position;
        origin.y += func_8022ADBC_de(player);
        if (D_801462E5) {
            for (other = D_80145060; other; other = other->next) {
                if (func_8021CD94_de(player, other) && other != player) {
                    if (player->weapon == 0x12) candidate = other->specialAim;
                    else {
                        candidate = other->position;
                        candidate.y += other->height;
                        candidate.y += func_8024D284_de(other) * D_800C2394_de;
                    }
                    func_80271F68_de(&direction, &candidate, &origin);
                    func_8027207C_de(&direction);
                    dot = forward.x * direction.x + forward.y * direction.y +
                          forward.z * direction.z;
                    if (threshold < dot) {
                        threshold = dot;
                        bestPosition = candidate;
                        best = other;
                    }
                }
            }
        }
        count = D_8011CC18;
        for (i = 0; i < count; i++) {
            other = D_8011CA18[i];
            if (func_8021CD94_de(player, other)) {
                if (player->weapon == 0x12) candidate = other->specialAim;
                else {
                    candidate = other->position;
                    candidate.y += other->height;
                    candidate.y += func_8024D284_de(other) * D_800C2398_de;
                }
                func_80271F68_de(&direction, &candidate, &origin);
                func_8027207C_de(&direction);
                dot = forward.x * direction.x + forward.y * direction.y +
                      forward.z * direction.z;
                if (threshold < dot) {
                    threshold = dot;
                    best = other;
                    bestPosition = candidate;
                    bestDirection = direction;
                }
            }
        }
    }
    *target = best;
    *targetPosition = bestPosition;
    if (best) {
        func_80272018_de(&axis, &forward, &bestDirection);
        func_8027207C_de(&axis);
        half = D_800C239C_de;
        threshold = func_802745D0_de(threshold);
        amount = func_802B72B0_de(D_800C23A0_de - threshold / (angle * half));
        amount = func_802B72B0_de(amount);
        threshold = threshold * amount * half;
        amount = func_802B7130_de(threshold);
        correction.x = axis.x * amount;
        correction.y = axis.y * amount;
        correction.z = axis.z * amount;
        D_80115DEC = amount;
        correction.w = func_802B6560_de(threshold);
        facing = func_8024796C_de(player);
        func_80274098_de(&result, &facing, &correction);
    }
    return result;
}
