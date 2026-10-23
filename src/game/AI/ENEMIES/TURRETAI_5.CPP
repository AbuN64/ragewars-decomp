#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_REACTIONS.H"
#include "COMMON/WORLD.H"
#include "COMMON/EXTERNS_15.H"
#include "COMMON/OBJ.H"
#include "COMMON/OBJRECAT30.H"
#include "AI/ENEMIES/TURRETAI_5.H"
#include "WEAPONS/80213ED4.H"

extern s32 func_80285F58_de(void *arg0, void *arg1);

extern void Turret_LinkEffect_MakeVisible(void *arg0, void *arg1, s32 arg2);

extern void CVector3__GetDirectionRotation2(f32 *, f32 *);
extern void func_80274244_de(f32 *, f32 *);

extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);

extern void func_80272BCC_de(f32 *, CVector3 *, CVector3 *);

extern void func_80271F34_de(CVector3 *, CVector3 *, CVector3 *);

static inline void build_rotation(struct RotationObject *object, f32 *matrix) {
    f32 rotation[4];
    f32 angles[3];

    angles[0] = object->angleX;
    angles[1] = object->angleY;
    angles[2] = object->angleZ;
    CVector3__GetDirectionRotation2(rotation, angles);
    func_80274244_de(rotation, matrix);
}

extern void func_80273C68_de(void *arg0, f32 arg1);

/* Returns whether a player may act on a target: never on its own linked object or an inactive
   target, always when the team rule D_801468C4 is off, otherwise only across different teams. */




extern int D_801468C4;

/* Tests whether a viewer can see a target: raises both positions by their heights scaled by one half and casts
   a ray between them through func_802444A4_de into D_80103FD0, returning 1 when nothing or the target itself
   blocks it. */







extern Player **D_80103FCC;

extern char D_80103FD0[];

extern f32 Particle_GetActorHeight(Player *);

extern s32 func_802444A4_de(Player *, CVector3, CVector3, char *);

void Turret_LinkEffect_Activate(void *arg0, WeaponFireState *arg1, s32 arg2) {
    if ((func_80285F58_de(&D_8011FE88, arg0) == 0) &&
        (arg1->variant == 0)) {
        Turret_LinkEffect_MakeVisible(arg0, arg1, arg2);
        func_80214178_de(arg0, arg1, 1);
    }
}

void Turret_BuildPlaneOrient(void *unused0, struct RotationObject *arg1, f32 *arg2) {
    f32 sp10[4];
    f32 sp20[3];

    sp20[0] = arg1->angleX;
    sp20[1] = arg1->angleY;
    sp20[2] = arg1->angleZ;
    CVector3__GetDirectionRotation2(sp10, sp20);
    func_80274244_de(sp10, arg2);
}

void Turret_MoveTargetIntoTurretSpace(void *unused, struct RotationObject *object, CVector3 *pivot, CVector3 *point) {
    f32 matrix[16];
    CVector3 offset;

    build_rotation(object, matrix);
    func_80271F68_de(&offset, point, pivot);
    func_80272BCC_de(matrix, &offset, point);
    func_80271F34_de(point, point, pivot);
}

void Turret_SpecialEffects(void *arg0, ObjRecAt8V1 *event) {
    ObjRecAt294 *temp_a0;
    CTurretIntelligence *temp_s1;
    ObjRecAt294 *temp_v0;

    struct NavigationTrack *track;

    temp_a0 = event->unk8;
    track = (void *)temp_a0->unk18;
    temp_s1 = &track->segment;
    if (event->unk4 == temp_s1->m_GunNode) {
        func_802738C0_de(arg0, temp_a0->unk294);
    }
    if (event->unk4 == temp_s1->m_RotNode) {
        temp_v0 = event->unk8;
        func_80273C68_de(arg0,
                      temp_v0->targetHeading -
                          temp_v0->heading);
    }
}

void Turret_DecreaseHealth(void *arg0, Dest *arg1, CDamageInfo *arg2) {
    s32 var_v1;

    var_v1 = arg1->health - arg2->damage;
    if (var_v1 < 0) {
        var_v1 = 0;
    }
    arg1->health = var_v1;
    if (var_v1 == 0) {
        func_80214178_de(arg0, arg1, 0x40);
    }
}

int AI_DynTurretOpposingPlayer(Actor *self, int unused, Actor *target) {
    Actor *linked = self->linked;
    if (linked == target || target->active == 0) {
        return 0;
    }
    if (D_801468C4 != 0) { if (linked->info->team == target->info->team) { return 0; } } return 1;
}

s32 AI_DynTurretCanSeePlayer(Player *player, RiderRecAt130V2 *rider, Player *other) {
    CVector3 from;
    CVector3 to;
    f32 lift;
    s32 blocked;

    func_80271F68_de(&to, &other->pos, &player->pos);
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
