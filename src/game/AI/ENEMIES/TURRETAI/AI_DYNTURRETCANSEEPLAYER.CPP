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
#include "WEAPONS/ACTOR_REQUESTACTORSTATE.H"

extern s32 Rumble_TestActorStateBit(void *arg0, void *arg1);

extern void Turret_LinkEffect_MakeVisible(void *arg0, void *arg1, s32 arg2);

extern void MatrixFromQuaternion(f32 *, f32 *);

extern void Graphu64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);

extern void Graphu64_TransformDirectionTranspose(f32 *, CVector3 *, CVector3 *);

extern void Graphu64_AddVec3(CVector3 *, CVector3 *, CVector3 *);

static inline void build_rotation(struct RotationObject *object, f32 *matrix) {
    CQuatern rotation;
    f32 angles[3];

    angles[0] = object->angleX;
    angles[1] = object->angleY;
    angles[2] = object->angleZ;
    rotation = CVector3_GetDirectionRotation2(angles);
    MatrixFromQuaternion(&rotation.x, matrix);
}

extern void RollMatrix(void *arg0, f32 arg1);

/* Returns whether a player may act on a target: never on its own linked object or an inactive
   target, always when the team rule D_801468C4 is off, otherwise only across different teams. */





/* Tests whether a viewer can see a target: raises both positions by their heights scaled by one half and casts
   a ray between them through CCollision_SweepPoint into D_80103FD0, returning 1 when nothing or the target itself
   blocks it. */







extern Player **D_80103FCC;

extern char D_80103FD0[];

extern f32 Gobjinst_GetActorHeight(Player *);

extern s32 CCollision_SweepPoint(Player *, CVector3, CVector3, char *);

void Turret_LinkEffect_Activate(void *actor, WeaponFireState *state, s32 unusedArg) {
    if ((Rumble_TestActorStateBit(&g_world, actor) == 0) &&
        (state->variant == 0)) {
        Turret_LinkEffect_MakeVisible(actor, state, unusedArg);
        Actor_RequestActorState(actor, state, 1);
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
    Graphu64_SubtractVectors(&offset, point, pivot);
    Graphu64_TransformDirectionTranspose(matrix, &offset, point);
    Graphu64_AddVec3(point, point, pivot);
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
        PitchMatrix(actor, eventOwner->unk294);
    }
    if (event->unk4 == turretInfo->m_RotNode) {
        headingOwner = event->unk8;
        RollMatrix(actor,
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
        Actor_RequestActorState(actor, state, 0x40);
    }
}

int AI_DynTurretOpposingPlayer(TurretPlayerRelation *self, int unused, TurretPlayerRelation *target) {
    TurretPlayerRelation *linked = self->linked;
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

    Graphu64_SubtractVectors(&to, &other->pos, &player->pos);
    lift = 0.5f;
    from.x = rider->aim.x;
    from.y = rider->aim.y;
    from.z = rider->aim.z;
    from = player->pos;
    from.y += Gobjinst_GetActorHeight(player) * lift;
    to = other->pos;
    to.y += Gobjinst_GetActorHeight(other) * lift;
    blocked = CCollision_SweepPoint(player, from, to, D_80103FD0);
    if (blocked != 0 && *D_80103FCC != other) {
        return 0;
    }
    return 1;
}
