#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_REACTIONS.H"
#include "COMMON/WORLD.H"
#include "COMMON/EXTERNS_15.H"
#include "COMMON/OBJ.H"
#include "COMMON/OBJRECAT30.H"
#include "AI/ENEMIES/TURRETAI.H"
#include "WEAPONS/80213ED4.H"

extern s32 Render_TestActorStateBit(void *arg0, void *arg1);

extern void Turret_LinkEffect_MakeVisible(void *arg0, void *arg1, s32 arg2);

extern CQuatern CVector3_GetDirectionRotation2(f32 *);
extern void MatrixFromQuaternion(f32 *, f32 *);

extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);

extern void func_80272BCC_de(f32 *, CVector3 *, CVector3 *);

extern void Particle_AddVec3(CVector3 *, CVector3 *, CVector3 *);

static inline void build_rotation(struct RotationObject *object, f32 *matrix) {
    CQuatern rotation;
    f32 angles[3];

    angles[0] = object->angleX;
    angles[1] = object->angleY;
    angles[2] = object->angleZ;
    rotation = CVector3_GetDirectionRotation2(angles);
    MatrixFromQuaternion(&rotation.x, matrix);
}

extern void func_80273C68_de(void *arg0, f32 arg1);

/* Returns whether a player may act on a target: never on its own linked object or an inactive
   target, always when the team rule D_801468C4 is off, otherwise only across different teams. */





/* Tests whether a viewer can see a target: raises both positions by their heights scaled by one half and casts
   a ray between them through func_802444A4_de into D_80103FD0, returning 1 when nothing or the target itself
   blocks it. */







extern Player **D_80103FCC;

extern char D_80103FD0[];

extern f32 Particle_GetActorHeight(Player *);

extern s32 func_802444A4_de(Player *, CVector3, CVector3, char *);

void Turret_LinkEffect_Activate(void *actor, WeaponFireState *state, s32 unusedArg) {
    if ((Render_TestActorStateBit(&D_8011FE88, actor) == 0) &&
        (state->variant == 0)) {
        Turret_LinkEffect_MakeVisible(actor, state, unusedArg);
        Weapons_RequestActorState(actor, state, 1);
    }
}

void Turret_BuildPlaneOrient(void *unused0, struct RotationObject *object, f32 *out) {
    CQuatern orientation;
    f32 angles[3];

    angles[0] = object->angleX;
    angles[1] = object->angleY;
    angles[2] = object->angleZ;
    orientation = CVector3_GetDirectionRotation2(angles);
    MatrixFromQuaternion(&orientation.x, out);
}

void Turret_MoveTargetIntoTurretSpace(void *unused, struct RotationObject *object, CVector3 *pivot, CVector3 *point) {
    f32 matrix[16];
    CVector3 offset;

    build_rotation(object, matrix);
    Particle_SubtractVectors(&offset, point, pivot);
    func_80272BCC_de(matrix, &offset, point);
    Particle_AddVec3(point, point, pivot);
}

void Turret_SpecialEffects(void *actor, ObjRecAt8V1 *event) {
    ObjRecAt294 *eventOwner;
    CTurretIntelligence *turretInfo;
    ObjRecAt294 *headingOwner;

    struct NavigationTrack *track;

    eventOwner = event->unk8;
    track = (void *)eventOwner->unk18;
    turretInfo = &track->segment;
    if (event->unk4 == turretInfo->m_GunNode) {
        func_802738C0_de(actor, eventOwner->unk294);
    }
    if (event->unk4 == turretInfo->m_RotNode) {
        headingOwner = event->unk8;
        func_80273C68_de(actor,
                      headingOwner->targetHeading -
                          headingOwner->heading);
    }
}

void Turret_DecreaseHealth(void *actor, Dest *state, CDamageInfo *damage) {
    s32 health;

    health = state->health - damage->m_Hits;
    if (health < 0) {
        health = 0;
    }
    state->health = health;
    if (health == 0) {
        Weapons_RequestActorState(actor, state, 0x40);
    }
}

int AI_DynTurretOpposingPlayer(Actor *self, int unused, Actor *target) {
    Actor *linked = self->linked;
    if (linked == target || target->active == 0) {
        return 0;
    }
    if (D_801462C8.counters.teams != 0) { if (linked->info->team == target->info->team) { return 0; } } return 1;
}

s32 AI_DynTurretCanSeePlayer(Player *player, RiderRecAt130V2 *rider, Player *other) {
    CVector3 from;
    CVector3 to;
    f32 lift;
    s32 blocked;

    Particle_SubtractVectors(&to, &other->pos, &player->pos);
    lift = 0.5f;
    from.x = rider->aim.x;
    from.y = rider->aim.y;
    from.z = rider->aim.z;
    from = player->pos;
    from.y += Particle_GetActorHeight(player) * lift;
    to = other->pos;
    to.y += Particle_GetActorHeight(other) * lift;
    blocked = func_802444A4_de(player, from, to, D_80103FD0);
    if (blocked != 0 && *D_80103FCC != other) {
        return 0;
    }
    return 1;
}
