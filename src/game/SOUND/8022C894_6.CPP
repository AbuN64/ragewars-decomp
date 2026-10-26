#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/SHAPE_TYPEMAP_14.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "TYPES.H"
#include "FX/802631D0.H"
extern f32 D_800C2E10_de;

extern char D_8010F328[];




extern s32 D_80140FF8;

typedef struct CollisionInfo CollisionInfo;

extern CollisionInfo D_80100030;

extern f32 GameObject_GetActorHeight(Instance8020CD74 *);

extern s32 Unicol_MoveActorWithCollision(Instance8020CD74 *, CVector3, CollisionInfo *);

extern f32 GraphU64_GetPointDistance(f32 *a, f32 *b);

void Player_ApplyLinkedProjectileStatus(void *arg0, s32 arg1, s32 arg2) {
    func_8021C45C_de((((struct ActorRecAt1D8V1 *) ((s8 *) arg0))->link), arg0, arg1, arg2);
}

void func_8022E290_de(void *player) {
    Player *object = player;
    void *attributes;
    void *state = object->tuning;
    f32 zero;

    if (object->computer != 0) {
        attributes = D_8010EEB8;
    } else {
        s32 index = object->slot;
        attributes = (void *)(index << 4);
        attributes = (char *)attributes + index;
        attributes = (void *)((s32)attributes << 3);
        attributes = (char *)attributes + index;
        attributes = (void *)((s32)attributes << 2);
        attributes = D_8010F328 + (s32)attributes;
    }
    ContPad_InitControllerInput(state, attributes);

    object->stick = 0;
    object->state6C4 = 0;
    object->landing = 0;
    object->state6CC = 0;
    object->active = 1;
    object->state6D4 = 0;
    object->state6D8 = 0;
    object->state6DC = 0;
    object->state6E4 = 0;
    object->state758 = 0;
    object->state75C = 0;
    object->locked = 0;
    object->lockState = 0;
    object->state708 = 0;
    object->state70C = 0;
    object->state710 = 0;
    object->state714 = 0;
    object->pitchOffset = 0;
    object->kickYaw = 0;
    object->lean = 0;
    object->sway[0] = 0;
    object->sway[1] = 0;
    object->sway[2] = 0;
    object->sideOffset = 0;
    object->baseHeight = Weapons_GetObjectOwnerHeight(object);
    object->forwardOffset = 0;
    zero = object->forwardOffset;
    (&object->velocity)->x = (&object->velocity)->y = (&object->velocity)->z = zero;
    object->velocityScale = D_800C2E10_de;
    object->cameraOffset = zero;
    object->cameraScale = D_800C2E10_de;
    object->previousPosition = object->pos;
    object->previousTarget = object->pos;
}

s32 Player_HasWeaponClassType(Player *player, s32 arg1, s32 arg2) {
    s16 **entry;
    s16 **scan;
    WeaponInfo *resource;
    s16 *item;
    s32 i;

    resource = D_800D052C[arg1];
    if (player->computer != 0) {
        entry = resource->computerClasses;
        goto scan_setup;
    }
    if (D_80140FF8 != 1) {
        entry = resource->computerClasses;
        goto scan_setup;
    }
    entry = &resource->weaponClass;

scan_setup:
    i = 0;
    scan = entry;
loop:
    item = *scan;
    if (item == 0) {
        goto null_item;
    }
    if (item[2] != arg2) {
        goto mismatch;
    }
    return 1;
null_item:
    return 0;
mismatch:
    i += 1;
    if (i < 3) {
        scan += 1;
        goto loop;
    }
    return 0;
}

s32 Player_ProbeCollisionAdjustedPosition(Instance8020CD74 *arg0, CVector3 *arg1) {
    Instance8020CD74 saved;
    s32 moved;

    saved = *arg0;
    ((struct Actor_func_80214DD4_de *)arg0)->pos.y += GameObject_GetActorHeight(arg0) * (&D_800C2E10_de)[1];
    ((struct Actor_func_80214DD4_de *)arg0)->pos.y += ((struct Actor_func_80214DD4_de *)arg0)->height;
    Unicol_MoveActorWithCollision(arg0, *arg1, &D_80100030);

    moved = (arg1->x != ((struct Actor_func_80214DD4_de *)arg0)->pos.x) ||
            (arg1->y != ((struct Actor_func_80214DD4_de *)arg0)->pos.y) ||
            (arg1->z != ((struct Actor_func_80214DD4_de *)arg0)->pos.z);
    *arg1 = ((struct Actor_func_80214DD4_de *)arg0)->pos;
    *arg0 = saved;

    return moved;
}

f32 Player_SumActivePlayerDistances(void *arg0, f32 *arg1) {
    f32 result;
    Round *round = arg0;
    Shared_ActorView *var_s0;

    var_s0 = round->players;
    result = 0.0f;
    if (var_s0 != 0) {
        do {
            if (var_s0->message != 0) {
                result += GraphU64_GetPointDistance(arg1, &var_s0->position.vector.x);
            }
            var_s0 = (Shared_ActorView *)var_s0->next;
        } while (var_s0 != 0);
    }
    return result;
}

/* Returns whether a record in state 3 carries type 0x5E2A or 0x5E5A, or a type in the range 0x7DF to 0x7E3. */

s32 Player_IsStateThreeUpperAnimationGroup(struct SharedPlayer *player) {
    s32 type;

    if (player->views5E8.view650_15.unk650 == 3) {
        type = player->views5E8.view86C_125.unk86C;
        if (type == 0x5E2A || type == 0x5E5A) {
            return 1;
        }
    }
    return player->views5E8.view650_15.unk650 == 3 && player->views5E8.view86C_125.unk86C >= 0x7DF && player->views5E8.view86C_125.unk86C < 0x7E4;
}

/* Returns whether a record in state 3 carries type 0x5E29 or 0x5E59, or a type in the range 0x7DA to 0x7DE. Adapted from Player_IsStateThreeUpperAnimationGroup with the type constants changed. */

s32 Player_IsStateThreeLowerAnimationGroup(struct SharedPlayer *player) {
    s32 type;

    if (player->views5E8.view650_15.unk650 == 3) {
        type = player->views5E8.view86C_125.unk86C;
        if (type == 0x5E29 || type == 0x5E59) {
            return 1;
        }
    }
    return player->views5E8.view650_15.unk650 == 3 && player->views5E8.view86C_125.unk86C >= 0x7DA && player->views5E8.view86C_125.unk86C < 0x7DF;
}

int Player_IsStateFifteen(struct SharedPlayer *player) {
    return player->views5E8.view650_15.unk650 == 0xF;
}
