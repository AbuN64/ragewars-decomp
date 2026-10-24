#include "COMMON/TARGET.H"
#include "SYSTEM_2/802661FC.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "SYSTEM_2/802661FC_2.H"
extern void func_80266810_de(void *, s32, s32, Triple, struct IntPair, s32, s32, s32);

/* Returns how strongly a blast at a position with a radius affects an actor: finds the shield covering the position (the held carrier shield D_801041F0 of the actor for an object target other than the two 0x402/0x404 types, otherwise func_8024B06C_de's shield in D_80110570), reports it, scales by the shield factor unless friendly fire is off for team damage, and when falloff is asked returns zero for an invulnerable player's untouched full hit, zero beyond the radius plus the actor's width, or the scale times one minus the distance to the actor's body over that reach. */

















extern u8 D_801462E5;

extern Carrier D_801041F0;


extern s32 func_8024B06C_de(Actor_func_802676EC_de *, CVector3, Shield *);

extern f32 Particle_GetActorHeight(Actor_func_802676EC_de *);

extern f32 func_8024D398_de(Actor_func_802676EC_de *);

extern f32 func_802726F8_de(CVector3 *, CVector3 *);

/* Spawns a hit effect when the target has a rider: turns the negated hit direction into the victim's frame through func_8022B09C_de, makes it relative to the victim rider's centre and converts it to a rotation, resolves the hit position on the attacker through func_8024E79C_de, spawns effect 0xE9 there raised by D_800C9538 (size 3 for kind 5, otherwise 1), and starts effect 3 on the victim's emitter. */












extern f32 D_800C4450_de;

extern char D_8011D8D0;

extern void func_8022B09C_de(SharedPlayerCode802661FC *, CVector3 *);

extern struct Shape_typemap_165 func_80271818_de(CVector3 *);

extern void func_8024E79C_de(void *, Triple, void *, s32 *, s32, s32);

#include "particle/8027A0F4_8.H"

extern void func_8028CE94_de(void *, void *, s32, Triple, f32, f32);

/* Forwards a position and extent to func_80266810_de with zero flags and priority 0x80, but only when
   the first byte of the given object is 1. Adapted from the matched twin func_80267BC8_de with the object
   type test added and the leading flag changed to 0. */







extern void func_80267260_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern void *D_80140FE8_de;

extern s32 func_802393AC_de(Node_func_80267CE4_de *arg0, Triple arg1);


f32 func_802676EC_de(Actor_func_802676EC_de *self, Target *target, CVector3 position, f32 radius, s32 falloff, s32 flags, Shield **found) {
    PlayerRecAt122C *player;
    s32 shielded;
    s32 scaled;
    s32 special;
    Shield *shield;
    f32 scale;
    f32 bottom;
    f32 top;
    f32 reach;
    f32 distance;
    CVector3 body;

    special = 0;
    shielded = 1;
    player = 0;
    scale = *(&D_800C46E8_eu + 1);
    scaled = 1;
    if (self->flags & 0x300000) {
        player = self->player;
    }
    if (D_801462E5 != 0 && (flags & 0x200)) {
        shielded = 0;
    }
    if (target->kind == 2) {
        if (target->type == 0x404 || target->type == 0x402) {
            special = 1;
        }
        if (target->kind == 2 && D_801041F0.owner == self && D_801041F0.slot != -1 && !special) {
            shield = &D_801041F0.shield;
            falloff = 0;
            goto have;
        }
    }
    shield = func_8024B06C_de(self, position, &D_80110570) ? &D_80110570 : 0;
have:
    *found = shield;
    if (shielded && shield != 0) {
        scale *= shield->factor;
    }
    if (falloff != 0) {
        if (player != 0 && (player->flags & 2) && scale == D_800C4440_de && (flags & 0x200)) {
            scale = 0.0f;
        } else {
            body = self->position;
            bottom = self->position.y + self->height;
            top = bottom + Particle_GetActorHeight(self);
            if (top < position.y) {
                body.y = top;
            } else if (position.y < bottom) {
                body.y = bottom;
            } else {
                body.y = position.y;
            }
            reach = radius + func_8024D398_de(self);
            distance = func_802726F8_de(&position, &body);
            if (reach < distance) {
                return 0.0f;
            }
            if (scaled) {
                scale *= (1.0f) - distance / reach;
            }
        }
    }
    return scale;
}

void func_80267958_de(SharedPlayerCode802661FC *target, Actor_func_80267958_de *actor, Triple position, CVector3 direction, s32 kind) {
    SharedPlayerCode802661FC *player;
    CVector3 v;
    Triple point;
    Triple zero;
    struct Shape_typemap_165 rotation;
    s32 unused;

    if (target->views5DC.view5DC_5.rider == 0) {
        return;
    }
    player = actor->player;
    v.x = -direction.x;
    v.y = direction.y;
    v.z = direction.z;
    func_8022B09C_de(player, &v);
    v.x -= player->views5DC.view5DC_5.rider->unk128.x;
    v.y -= player->views5DC.view5DC_5.rider->unk128.y;
    v.z -= player->views5DC.view5DC_5.rider->unk128.z;
    rotation = func_80271818_de(&v);
    func_8024E79C_de(actor, position, &point, &unused, 0, 1);
    point = position;
    ((CVector3 *)&point)->y += D_800C9538;
    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0xE9, *(CVector3 *)&zero, *(CQuatern *)&rotation, *(CVector3 *)&point, 0, -1, kind == 5 ? 3 : 1);
    point.x = 0;
    point.y = 0;
    point.z = 0;
    func_8028CE94_de(&D_8011FE88, player->views5E8.view698_37.emitter + 0x140, 3, point, *(&D_800C9538 + 1), D_800C4450_de);
}

void func_80267B68_de(unsigned char *source, s32 target, s32 kind, Triple position, struct IntPair arg6) {
    if (*source == 1) {
        func_80266810_de(source, target, kind, position, arg6, 0, 0, 0x80);
    }
}

void func_80267BC8_de(s32 source, s32 target, s32 kind, Triple position, struct IntPair arg6) {
    func_80266810_de((void *)source, target, kind, position, arg6, 1, 0, 0x80);
}

void func_80267C20_de(s32 source, s32 target, s32 kind, Triple position, struct IntPair arg6) {
    func_80266810_de((void *)source, target, kind, position, arg6, 1, 1, 0x80);
}

void func_80267C78_de(int unused0, int unused1, int unused2, int arg3) {
    int *p = &arg3;
    *p = arg3;
}

void func_80267C80_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
  s32 *new_var2;
  int new_var;
  new_var2 = &arg3;
  new_var = 1;
  func_80267260_de(arg0, *new_var2, arg4, arg5, new_var);
}

void func_80267CB4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
  s32 *new_var2;
  int new_var;
  new_var2 = &arg3;
  new_var = 0;
  func_80267260_de(arg0, *new_var2, arg4, arg5, new_var);
}

void func_80267CE4_de(s32 unused0, s32 unused1, s32 unused2, Triple arg3, CEventValueFormat7a arg6) {
    Node_func_80267CE4_de *node;

    node = D_80140FE8_de;
    while (node != 0) {
        if (func_802393AC_de(node, arg3) != 0) {
            func_802391AC_de(node, arg6.a, arg6.b, arg6.c, arg6.m_u8_Value4,
                          arg6.m_u8_Value5, arg6.f, arg6.m_u8_Value7);
        }
        node = node->next;
    }
}

void func_80267D68_de(int unused0, int unused1, int unused2, int arg3) {
    int *p = &arg3;
    *p = arg3;
}

void func_80267D70_de(s32 arg0, void *arg1, s32 arg2, CVector3 arg3, s32 arg6)
{
  s32 t6 = arg6;
  void *temp = ((LevelActor *)arg1)->controller;
  ((Player *)temp)->requestedPosition = arg3;
 /* FAKEMATCH: preserve instruction scheduling between the copied triple and the following call. */
 do { } while (0);
  func_80232744_de(arg1, (s32) (&((struct LevelActor *)arg1)->behaviorFlags), t6);
}
