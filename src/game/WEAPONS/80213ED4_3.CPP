#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/MATH_HELPERS.H"
#include "WEAPONS/80213ED4_27.H"
#include "FX_2/80271B18.H"

extern s32 D_8011CD20;
extern s32 D_8013B290;
extern s32 func_80214624_de(Actor_func_80214DD4_de *arg0, Tracker *arg1, Actor_func_80214DD4_de *target);
extern Actor_func_80214DD4_de *Weapons_SelectCombatTarget(Actor_func_80214DD4_de *arg0, Tracker *arg1, s32 arg2, s32 arg3);
extern f32 Weapons_FindClearAimAngle(Actor_func_80214DD4_de *arg0, CVector3 pos, Actor_func_80214DD4_de *target, f32 arg3);
extern f32 func_80216F44_de(Actor_func_80214DD4_de *arg0, CVector3 pos);
struct Cursor;
extern Location *func_80219408_de(struct Cursor *slot);
extern f32 Particle_GetActorHeight(Actor_func_80214DD4_de *arg0);
extern f32 func_8024D398_de(Actor_func_80214DD4_de *arg0);
extern f32 Sound_GetActorReach(Actor_func_80214DD4_de *arg0);
extern void func_8024E79C_de(Actor_func_80214DD4_de *arg0, CVector3 pos, CVector3 *outPos, s32 *outRoom, s32 arg4, s32 arg5);
extern f32 func_8024E80C_de(Actor_func_80214DD4_de *arg0);
extern f32 Particle_GetHorizontalAngle(CVector3 *arg0);
extern void func_80271F34_de(CVector3 *result, CVector3 *left, CVector3 *right);
extern void func_80271F68_de(CVector3 *result, CVector3 *left, CVector3 *right);
extern void func_80271F9C_de(CVector3 *result, CVector3 *vec, f32 scale);


extern f32 func_802B72B0_de(f32 value);
/* Places the goal beside kind-7 targets: pushed away from the anchor by both extents. */
static inline void Weapons_PlaceGoalBeside(Actor_func_80214DD4_de *actor, Actor_func_80214DD4_de *target, Actor_func_80214DD4_de *anchor, CVector3 *outPos, s32 *outRoom) {
    CVector3 dir;
    CVector3 goal;
    if (anchor != 0) {
        func_80271F68_de(&dir, &target->pos, &anchor->pos);
        dir.y = 0.0f;
        func_8027207C_de(&dir);
    } else {
        dir.x = 0.0f;
        dir.y = 0.0f;
        dir.z = 0.0f;
    }
    func_80271F9C_de(&dir, &dir, func_8024D398_de(target) + func_8024D398_de(actor) + D_800C216C_de);
    func_80271F34_de(&goal, &target->pos, &dir);
    func_8024E79C_de(target, goal, outPos, outRoom, 0, 0);
}
/** Picks what the tracker aims at (its target, itself, a slot or home point, or the actor) and
    fills out with the kind, target, reach, goal position and its offset from the actor, both in 3D
    and flattened to the ground plane. The third parameter is overwritten: it serves as the boost flag. */
void Weapons_ResolveTrackGoal(Actor_func_80214DD4_de *actor, Tracker *tracker, s32 boost, TrackResult *out) {
    CVector3 pos;
    CVector3 probe;
    CVector3 away;
    CVector3 delta;
    s32 room;
    Actor_func_80214DD4_de *target;
    s32 kind;
    s32 mode;
    f32 range;
    f32 gap;
    f32 angle;
    f32 reach;
    Location *loc;
    boost = 0; /* the shared tracker-callback slot (unused, as in func_80215410_de) holds the boost flag */
    if (*actor->kind != 1) {
        mode = -1;
    }
    if (tracker->team == D_8011CD20) {
        if ((tracker->flags & 0x40000) && tracker->unk78 == 0) {
            if (func_80214624_de(actor, tracker, tracker->target) == 0) {
                tracker->flags &= ~0x40000;
            }
        } else {
            tracker->target = Weapons_SelectCombatTarget(actor, tracker, 0, 1);
        }
    }
    target = tracker->target;
    kind = 6;
    if (tracker->active != 0) {
        if (target == 0) {
            kind = 3;
            if (tracker->slot != 0) {
                kind = 4;
            }
        } else if (target == tracker->self) {
            kind = 2;
        } else if (*target->kind == 5) {
            kind = 5;
        } else if (target->id == 0x64F) {
            kind = 7;
        } else if (D_8013B290 != 0) {
            kind = 0;
        } else if (((target->flags100 & 0x300000) && target->controller->owner == actor &&
                    target->controller->state == 2) ||
                   ((actor->flags2E0 & 2) && actor->id != 0xCA)) {
            kind = 1;
        } else {
            kind = 0;
        }
    }
    if (target != 0) {
        if (kind == 7) {
            Weapons_PlaceGoalBeside(actor, target, tracker->anchor, &pos, &room);
        } else {
            pos = target->pos;
            room = target->room;
            if (mode == 1) {
                pos.y += target->height + Particle_GetActorHeight(target) * D_800C2170_de;
            }
        }
        gap = func_8024D398_de(target) + func_8024D398_de(actor);
        switch (kind) {
            case 2:
                gap += D_800C2174_de;
            default:
                boost = 1;
                break;
            case 5:
            case 7:
                boost = 1;
                gap = 0.0f;
                break;
        }
    } else {
        gap = func_8024D398_de(actor);
        switch (kind) {
            case 4:
                loc = func_80219408_de(&tracker->slot);
                pos = loc->pos;
                gap = 0.0f;
                room = loc->room;
                if (tracker->slot == 2 || tracker->slot == kind) {
                    boost = 1;
                }
                break;
            case 3:
                pos = tracker->homePos;
                room = tracker->homeRoom;
                boost = 1;
                break;
            case 6:
                pos = actor->pos;
                room = actor->room;
                if (mode == 2) {
                    pos.y = func_8024E80C_de(actor);
                }
                break;
        }
    }
    func_80271F34_de(&pos, &pos, &tracker->offset);
    if (gap > 0.0f) {
        func_80271F68_de(&away, &actor->pos, &pos);
        angle = Particle_GetHorizontalAngle(&away);
        pos.x -= gap * func_802B7130_de(angle);
        pos.z -= gap * func_802B6560_de(angle);
    }
    if (mode == 2) {
        pos.y = RW_MIN_LT(pos.y, func_8024E80C_de(actor));
    }
    if (boost) {
        reach = Sound_GetActorReach(actor);
        probe.x = actor->pos.x + reach * func_802B7130_de(tracker->angle);
        probe.y = tracker->height;
        probe.z = actor->pos.z + reach * func_802B6560_de(tracker->angle);
        range = Weapons_FindClearAimAngle(actor, probe, target, D_800C2178_de);
        pos.y = tracker->height;
    } else {
        range = func_80216F44_de(actor, pos);
    }
    func_80271F68_de(&delta, &pos, &actor->pos);
    out->kind = kind;
    out->target = target;
    out->range = range;
    out->pos = pos;
    out->delta = delta;
    out->dist = func_802B72B0_de(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
    delta.y = 0.0f;
    pos.y = 0.0f;
    out->flatPos = pos;
    out->flatDelta = delta;
    out->flatDist = func_802B72B0_de(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
}
