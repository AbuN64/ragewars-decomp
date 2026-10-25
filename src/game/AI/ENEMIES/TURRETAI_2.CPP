#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJ.H"
#include "GAME/CODE_8027302C.H"
#include "particle/80271B18_3.H"

typedef struct Owner Owner;

/* Moves a rider along its path segment: limits the throttle change by the segment's length over its radius, then either rocks the throttle back and forth between 0 and 1 (mode 1, flipping direction at the ends) or steers it toward a target's projected distance along the segment (mode 2), eases the change through func_80274808_de, clamps the throttle to 0..1 and places the rider at the segment's circle point for that throttle through func_80271FC8_de. */








extern f32 Math_Sqrtf(f32);

extern f32 Nav_ApproachValue(f32, f32, f32);


extern void func_80271FC8_de(CVector3 *, f32, CVector3 *, CVector3 *);

/* Picks a rider's nearest target: walks the player list D_80145060 for players within the segment's range at 0x54 (squared distance through func_802726BC_de) that are not the rider's own player, are active and, in team play (D_801468C4), are on the other team, keeps those with a clear line of sight between their raised centres through func_802444A4_de (or whose blocker is the player itself), and records the nearest in the rider at 0x80 and in the result with its distance through func_802B72B0_de, clearing both when none qualifies. */









extern SharedPlayer *D_80145060;

extern SharedPlayer **D_80103FCC;

extern char D_80103FD0[];

extern f32 func_802726BC_de(CVector3 *, CVector3 *);

extern f32 Particle_GetActorHeight(SharedPlayer *);

extern s32 func_802444A4_de(SharedPlayer *, CVector3, CVector3, char *);

extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
void Turret_Move(Owner *owner, Rider *rider, s32 mode, SharedPlayer *target) {
    Segment *segment;
    f32 throttle;
    f32 limit;
    f32 step;
    f32 goal;
    CVector3 position;
    CVector3 offset;
    CVector3 local;
    f32 matrix[16];

    segment = (Segment *)(owner->track + 0x14);
    throttle = rider->throttle;
    if (segment->radius != 0.0f || segment->rise != 0.0f) {
        limit = segment->length / Math_Sqrtf(segment->radius * segment->radius + segment->rise * segment->rise);
    } else {
        limit = 0.0f;
    }
    switch (mode) {
    case 0:
        break;
    case 1:
        step = limit;
        if (rider->direction == mode) {
            step = -step;
        }
        rider->change = Nav_ApproachValue(rider->change, step, 0.25f);
        throttle += rider->change;
        if (rider->direction == 0) {
            if (throttle > 1.0f) {
                rider->change = 0.0f;
                rider->direction = mode;
            }
        } else if (throttle < 0.0f) {
            rider->change = 0.0f;
            rider->direction = 0;
        }
        break;
    case 2:
        if (target != 0) {
            if (segment->angle != 0.0f) {
                Particle_SubtractVectors(&offset, &target->views0.view8_3.pos, &rider->base);
                BuildYawMatrix(matrix, -segment->angle);
                Particle_TransformPoint(matrix, &offset, &local);
                goal = local.z / segment->radius;
            } else {
                goal = 0.0f;
            }
            step = goal - throttle;
            if (step > limit) {
                step = limit;
            } else if (step < -limit) {
                step = -limit;
            }
            rider->change = Nav_ApproachValue(rider->change, step, 0.25f);
            throttle += rider->change;
        }
        break;
    }
    if (throttle > 1.0f) {
        throttle = 1.0f;
    } else if (throttle < 0.0f) {
        throttle = 0.0f;
    }
    rider->throttle = throttle;
    position = rider->base;
    position.x += segment->radius * Math_Sinf(segment->angle);
    position.y += segment->rise;
    position.z += segment->radius * Math_Cosf(segment->angle);
    func_80271FC8_de(rider->frame, throttle, &rider->base, &position);
}

void AI_DynTurretGetTargetInfo(SharedPlayer *player, RiderRecAt130V1 *rider, Result *result) {
    f32 nearest;
    SharedPlayer *best;
    CTurretIntelligence *segment;
    SharedPlayer *other;
    f32 distance;
    f32 lift;
    s32 enemy;
    s32 valid;
    s32 blocked;
    CVector3 from;
    CVector3 to;

    nearest = 0.0f;
    best = 0;
    segment = (CTurretIntelligence *)(player->views18.view18_1.track + 0x14);
    other = D_80145060;
    if (other != 0) {
        lift = (0.5f);
        do {
            distance = func_802726BC_de(&player->views0.view8_3.pos, &other->views0.view8_3.pos);
            if (distance < segment->range * segment->range) {
                enemy = 0;
                if (player->views1C.view1D8_23.self != other && other->views5E4.view5E4_1.active != 0) {
                    enemy = 1;
                    if (D_801462C8.counters.teams != 0) {
                        enemy = player->views1C.view1D8_23.self->views5D8.view5D8_1.record->team != other->views5D8.view5D8_1.record->team;
                    }
                }
                if (enemy) {
                    Particle_SubtractVectors(&to, &other->views0.view8_3.pos, &player->views0.view8_3.pos);
                    from.x = rider->aim.x;
                    from.y = rider->aim.y;
                    from.z = rider->aim.z;
                    from = player->views0.view8_3.pos;
                    from.y += Particle_GetActorHeight(player) * lift;
                    to = other->views0.view8_3.pos;
                    to.y += Particle_GetActorHeight(other) * lift;
                    blocked = func_802444A4_de(player, from, to, D_80103FD0);
                    valid = 1;
                    if (blocked != 0) {
                        valid = *D_80103FCC == other;
                    }
                    if (valid && (best == 0 || distance < nearest)) {
                        best = other;
                        nearest = distance;
                    }
                }
            }
            other = other->views16E0.view16E0_1.next;
        } while (other != 0);
    }
    if (best != 0) {
        rider->target = best;
        result->distance = Math_Sqrtf(nearest);
        result->target = best;
    } else {
        result->target = 0;
        rider->target = 0;
    }
}
