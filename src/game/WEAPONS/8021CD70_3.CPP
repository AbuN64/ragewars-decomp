#include "TYPES.H"
#include "COMMON/LONE/D_80103FD0.H"
#include "COMMON/VECTOR4F.H"
#include "stddef.h"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"

typedef union AimOutput { CVector3 xyz; CQuatern full; Shared_Quad words; } AimOutput;
typedef struct AimActor {
    u8 kind; char pad1[7]; CVector3 pos; char pad14[0x5c];
    f32 height; char pad74[0x8c]; s32 flags; char pad104[0x144]; CVector3 focus;
} AimActor;
typedef struct AimController { char pad0[0x7e]; u8 active; } AimController;
typedef struct AimView {
    char pad0[0x24]; s32 mode; char pad28[0x100]; CVector3 origin;
    char pad134[0x2c]; f32 matrix[16];
} AimView;
typedef struct AimWeapon { char pad0[14]; s16 idle; s16 locked; } AimWeapon;
typedef struct AimHit { AimActor *actor; char pad4[0xe0]; CVector3 point; CVector3 normal; } AimHit;
typedef struct AimPlayer {
    s8 unk0; char pad1[7]; CVector3 unk8; char pad14[0x580]; s32 unk594;
    char pad598[0x40]; AimController *unk5D8; AimView *view;
    char pad5E0[0x4e]; s16 unk62E; char pad630[0x158]; s32 unk788;
    f32 unk78C; char pad790[4]; AimActor *unk794; s32 unk798;
    CVector3 out; CVector3 velocity; AimActor *unk7B4; s32 unk7B8; char pad7BC[4];
    CVector3 smooth; CVector3 smoothVelocity; CQuatern rotation; s32 unk7E8;
    char pad7EC[0xa24]; s32 enabled; char pad1214[0x244];
    CVector3 aim; CVector3 aim2; CVector3 normal; AimActor *target;
} AimPlayer;
extern const f32 D_800C23B4_de, D_800C23B8_de, D_800C23BC_de, D_800C23C0_de;
extern const f32 D_800C23C4_de, D_800C23C8_de, D_800C23CC_de, D_800C23D0_de;
extern f32 D_800D2988;
extern AimHit *D_80103FCC;
extern char D_801000F0;
extern void *D_800D052C[];
void func_8027302C(f32 *, f32 *);
void Weapons_BuildPlayerViewTransform(void *, f32 *);
void func_8022B144_de(void *, f32 *);
s32 func_802444A4_de(char *, CVector3, CVector3, s32);
void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
void Particle_AddVec3(CVector3 *, CVector3 *, CVector3 *);
void Particle_ScaleVector(CVector3 *, CVector3 *, f32);
f32 Math_Sqrtf(f32);
typedef struct SharedPlayer_func_8021D408_de SharedPlayer_func_8021D408_de;
void func_8021D408_de(struct SharedPlayer_func_8021D408_de *, CVector3 *, CVector3 *);
CQuatern Weapons_ComputeAimRotation(void *, AimActor **, void *);
CQuatern func_8024796C_de(char *);
typedef struct func_8021CD70_S1 func_8021CD70_S1;
typedef struct func_8021CD70_S2 func_8021CD70_S2;
s32 Weapons_CanLockTarget(func_8021CD70_S1 *, func_8021CD70_S2 *);
f32 Particle_GetActorHeight(void *);
void func_8021D774_de(AimPlayer *player) {
    AimOutput sp20;
    CVector3 sp30;
    CVector3 sp40;
    CVector3 desired;
    f32 matrix[16];
    CVector3 current;
    CQuatern spB0;
    AimWeapon *weapon;
    AimOutput spC0;
    CQuatern spD0;
    CVector3 spE0;
    AimActor *spF0, *spF4;
    CVector3 *var_a0, *temp_s2, *temp_s2_2, *var_a1, *temp_s0_2, *temp_s1;
    f32 temp_fs0, temp_fs1f, temp_fs2, temp_fv0, temp_fv0_2, var_fs0f, var_fs1;
    s16 temp_v1, temp_v1_2;
    s32 var_s4;
    s32 temp_v1_3, var_s0, var_s5;
    AimActor *temp_a1, *target;
    AimView *view;
    spF0 = NULL;
    view = player->view;
    temp_fs1f = D_800C23B4_de;
    temp_fs2 = D_800C23B8_de;
    if (view) { switch (view->mode) { case 1: Weapons_BuildPlayerViewTransform(player, matrix); func_8022B144_de(player, &current.x); break; default: func_8027302C(matrix, view->matrix); current = view->origin; break; } } else { Weapons_BuildPlayerViewTransform(player, matrix); func_8022B144_de(player, &current.x); }
    sp30.x = 0.0f;
    sp30.y = 0;
    sp30.z = D_800C23BC_de;
    Particle_TransformPoint(matrix, &sp30, &desired);
    if (func_802444A4_de((char *)player, current, desired, (s32) &D_80103FD0) != 0) {
        player->aim = D_80103FCC->point;
        player->normal = D_80103FCC->normal;
        player->target = D_80103FCC->actor;
    } else {
        player->aim = desired;
        player->target = NULL;
    }
    sp30.x = 0.0f;
    sp30.y = 0;
    sp30.z = D_800C23C0_de;
    Particle_TransformPoint(matrix, &sp30, &desired);
    if (player->enabled != 0) {
        if ((func_802444A4_de((char *)player, current, desired, (s32) &D_801000F0) != 0) && (temp_a1 = D_80103FCC->actor, (temp_a1 != NULL))) {
            if (temp_a1->kind == 1) {
                if (temp_a1->flags & 0x300000) {
                    Particle_SubtractVectors((CVector3 *)&spB0, &temp_a1->pos, &player->unk8);
                    temp_fv0 = Math_Sqrtf((spB0.x * spB0.x) + (spB0.y * spB0.y) + (spB0.z * spB0.z));
                    spE0 = sp30;
                    Particle_NormalizeVec3(&spE0);
                    Particle_ScaleVector(&spC0.xyz, &spE0, temp_fv0);
                    Particle_TransformPoint(matrix, &spC0.xyz, (CVector3 *)&spD0);
                    player->aim2 = (*(CVector3 *)&spD0);
                    func_8021D408_de((void *)player, (CVector3 *)&spD0, &D_80103FCC->normal);
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
    temp_v1 = player->unk62E;
    var_s5 = var_s4 + 0x64;
    var_s0 = 1;
    if ((temp_v1 == 1) || (temp_v1 == 0x12)) {
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
        spB0 = Weapons_ComputeAimRotation(player, &spF0, &sp20.words);
        var_s0 = 0;
        break;
    default:
        var_s5 = -1;
        break;
    }
    spB0 = func_8024796C_de((char *)player);
    player->rotation = spB0;
    spC0.xyz = player->aim;
    spC0.xyz.x -= D_800C23C8_de;
    (*(CVector3 *)&spD0) = player->aim;
    (*(CVector3 *)&spD0).x += D_800C23C8_de;
    spC0.xyz = player->aim;
    spC0.xyz.z -= D_800C23C8_de;
    (*(CVector3 *)&spD0) = player->aim;
    (*(CVector3 *)&spD0).z += D_800C23C8_de;
    spC0.xyz = player->aim;
    spC0.xyz.y -= D_800C23C8_de;
    (*(CVector3 *)&spD0) = player->aim;
    (*(CVector3 *)&spD0).y += D_800C23C8_de;
    if (spF0 == NULL) {
        sp20.xyz = desired;
        if ((player->unk5D8->active != 0) && (var_s0 != 0)) {
            spD0 = Weapons_ComputeAimRotation(player, &spF4, &spC0.words);
            if (spF4 != NULL) {
                player->rotation = spD0;
            }
        }
        if (spF0 == NULL) {
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
    temp_fs0 = D_800C23CC_de;
    Particle_SubtractVectors(&sp40, &sp20.xyz, temp_s2);
    Particle_ScaleVector(&sp40, &sp40, temp_fs1f * temp_fs0);
    temp_s0_2 = &player->smoothVelocity;
    Particle_AddVec3(temp_s0_2, temp_s0_2, &sp40);
    Particle_AddVec3(temp_s2, temp_s2, temp_s0_2);
    Particle_ScaleVector(temp_s0_2, temp_s0_2, temp_fs2 * temp_fs0);
    if (spF0 != NULL) {
        weapon=D_800D052C[player->unk62E]; player->unk7B8=weapon->locked+0x64;
    } else {
        player->unk7B8 = var_s5;
    }
    switch (player->unk788) {
    case 1:
        if ((spF0 == NULL) || (player->unk794 != spF0)) {
            player->unk794 = spF0;
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
            if (player->unk7B4 != spF0) {
                player->unk7B4 = spF0;
                player->unk78C = 0.0f;
            } else {
                player->unk78C += D_800D2988;
            }
            if ((spF0 != NULL) && (player->unk794 != spF0) && (var_fs0f <= player->unk78C)) {
                player->unk794 = spF0;
                player->unk78C = 0.0f;
            }
            target = player->unk794;
            spF0 = target;
            if (target != NULL) {
                if (Weapons_CanLockTarget((void *)player, (void *)target) == 0) {
                    player->unk788 = 1;
                    player->unk78C = 0.0f;
                }
                if (player->unk62E == 0x12) {
                    sp20.xyz = spF0->focus;
                } else {
                    sp20.xyz = spF0->pos;
                    sp20.xyz.y = sp20.xyz.y + spF0->height;
                    sp20.xyz.y += Particle_GetActorHeight(spF0) * D_800C23D0_de;
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
        sp20.xyz = desired;
        break;
    default:
        break;
    }
    var_a0 = &sp40;
    temp_s2_2 = &player->out;
    Particle_SubtractVectors(var_a0, &sp20.xyz, temp_s2_2);
    Particle_ScaleVector(&sp40, &sp40, temp_fs1f);
    temp_s1 = &player->velocity;
    Particle_AddVec3(temp_s1, temp_s1, &sp40);
    Particle_AddVec3(temp_s2_2, temp_s2_2, temp_s1);
    Particle_ScaleVector(temp_s1, temp_s1, temp_fs2);
    player->unk798 = (s32) var_s4;
}
