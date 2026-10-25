#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GAMEPLAY_ROUND_RULES.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "CAMERA/80233920_14.H"
#include "FX_2/80271B18.H"

extern const f32 D_800C2D9C_de;

extern void func_80218464_de();

extern s32 Render_PlaySoundAtPosition(s16 arg0, CVector3 arg1, s32 arg4, s32 arg5);

/* Runs a player's landing state: sets state 0xD when the value at 0x6C8 is zero or 0xE otherwise,
   applies the movement tables D_800CE88C and D_800CE8A4, picks animation 0x8A2 for the model
   D_800CE47C or, unless animation 0x1144 is still running with the byte at 0x10E clear, 0x8A2, 0x8A7
   or 0x14 by the stick at 0x6C0 against D_800C7E94 and D_800C7E98, and switches to state 3 once the
   timer at 0x658 passes D_800C7E9C without input bit 0x20000. */

extern void Weapons_UpdateViewAngles(void *, void *, void *);

extern void func_802238E0_de(void *, void *, void *);

extern s32 Weapons_SetPlayerState(void *, void *, s32);



extern f32 D_800C2DB0_de;

extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);


extern void Particle_ScaleVector(void *, void *, f32);

extern void Particle_AddVec3(CVector3 *, CVector3 *, CVector3 *);

extern void func_8044A07C_de(s32 arg0);

void func_8022CF38_de(void *arg0, LevelActor *actor) {
    f32 value;
    f32 minimum;
    ((Shared_ActorView *)arg0)->forwardSpeed *= D_800C2D94_de;
    ((Shared_ActorView *)arg0)->lateralSpeed *= D_800C2D94_de;

    value = actor->position1.y * D_800C2D98_de;
    minimum = D_800C2D9C_de;
    actor->position1.y = value;
    if (value < minimum) {
        actor->position1.y = minimum;
    }

    ((Shared_ActorView *)arg0)->collisionState = 0;
    func_8023913C_de(((Shared_ActorView *)arg0)->message);
    func_80218464_de(((Shared_func_80227014_S2 *)arg0)->unk938);

    if (actor->motionState & 0x8000) {
        Render_PlaySoundAtPosition(0x2DA, actor->position0, 0, -1);
    } else {
        Render_PlaySoundAtPosition(0x2DC, actor->position0, 0, -1);
    }
}

/** Scales the floats at 0x6C0 and 0x6C4 of the first object and the float at 0x20 of the second by D_800C7E90. */








void func_8022D010_de(void *arg0, void *levelActor) {
    Actor_func_8022D290_de *actor = arg0;
    LevelActor *other = levelActor;
    actor->unk_0x06C0 = actor->unk_0x06C0 * (D_800C7E90);
    actor->unk_0x06C4 = actor->unk_0x06C4 * (D_800C7E90);
    other->position1.y = other->position1.y * (D_800C7E90);
}

void func_8022D040_de(void *arg0, LevelActor *actor) {
    Player *player;
    s32 busy;
    f32 x;

    player = arg0;
    if (player->landing == 0.0f) {
        player->pose = 0xD;
    } else {
        player->pose = 0xE;
    }
    Weapons_UpdateViewAngles(player, actor, &D_800CE88C);
    func_802238E0_de(player, actor, &D_800CE8A4);
    busy = 0;
    if (player->animation == 0x1144) {
        busy = player->animationDone == 0;
    }
    if (player->objectId == D_800CE47C) {
        player->animation = 0x8A2;
    } else if (!busy) {
        x = player->stick;
        if (D_800C7E94 <= x) {
            player->animation = 0x8A2;
        } else if (x <= D_800C7E98) {
            player->animation = 0x8A7;
        } else {
            player->animation = 0x14;
        }
    }
    if (!(actor->motionState & 0x20000) && player->poseTimer > D_800C7E9C) {
        Weapons_SetPlayerState(player, actor, 3);
    }
}

void func_8022D164_de(void *arg0, LevelActor *arg1)
{
  f32 new_var3;
  f32 *new_var;
  s8 *new_var2;
  new_var2 = (s8 *) arg0;
  new_var3 = (f32) D_800C2DB0_de;
  ((Player *)new_var2)->stick = 0;
  new_var = &((Player *)arg0)->movementScale;
  ((Player *)arg0)->state6C4 = 0;
  *new_var = new_var3;
  arg1->position1.x = 0;
  arg1->position1.y = 0;
  arg1->position1.z = 0;
}

void func_8022D188_de(void *unused, void *object) {
    LevelActor *actor = object;
    actor->position1.x = 0.0f;
    actor->position1.y = 0.0f;
    actor->position1.z = 0.0f;
}

/** Perform no operation. */
void func_8022D198_de(void) {
}

/** Perform no operation. */
void func_8022D1A0_de(void) {
}

void func_8022D1A8_de(void *arg0) {
    CVector3 vector;
    CVector3 *temp_s1;

    temp_s1 = &((Shared_ActorView *)arg0)->weapon.aimPosition;
    Particle_SubtractVectors(&vector, &((Shared_ActorView *)arg0)->resetPosition, temp_s1);
    Particle_NormalizeVec3(&vector);
    Particle_ScaleVector(&vector, &vector, 30.0f);
    Particle_AddVec3(&((Player *)arg0)->previousPosition, temp_s1, &vector);
}

void func_8022D20C_de(void) {
}

void func_8022D214_de(void *widget) {
    LevelActor *actor = widget;
    Shared_ActorView *player = widget;
    actor->flags &= 0xFF7FFFFF;
    player->stun = 0;
    player->markerTime = 0.0f;
    actor->flags |= 0x01000000;
    func_8044A07C_de((s32) widget);
}

void func_8022D254_de(void) {
}

/** Reset two object fields and replace the control word's mode bit. */
void func_8022D25C_de(void *arg0) {
    Actor_func_8022D290_de *actor = arg0;
    actor->flags &= 0xFF7FFFFF;
    actor->unk_0x11D8 = 0;
    actor->unk_0x11FC = 0;
    actor->flags |= 0x01000000;
}

/** Perform the no-op callback at VRAM 0x8022D278. */
void func_8022D288_de(void) {
}
