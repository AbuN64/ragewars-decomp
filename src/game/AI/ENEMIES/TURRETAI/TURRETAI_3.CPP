#include "COMMON/EXTERNS_15.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJ.H"
#include "COMMON/REC.H"
#include "COMMON/S1_3.H"
#include "COMMON/TRIPLE.H"
#include "stddef.h"
#include "TYPES.H"
#include "AI/ENEMIES/TURRETAI.H"
#include "WEAPONS/80213ED4_11.H"
#include "WEAPONS/80213ED4_17.H"
#include "WEAPONS/80213ED4.H"

void AI_DynTurretGetTargetInfo(SharedPlayer *player, RiderRecAt130V1 *rider, Result *result);

void Graphu64_TransformDirectionTranspose(void *arg0, void *arg1, void *arg2);

void Turret_Move(struct Owner *owner, Rider *rider, s32 mode, SharedPlayer *target);

void Barrel_SetLoopingSound(void *arg0, void *arg1, s32 arg2);

void Barrel_StopActorLoopingSound(void *arg0, void *arg1);

f32 GraphU64_ApproachValue(f32 arg0, f32 arg1, f32 arg2);

typedef union NavRider { RiderRecAt130V1 target; Rider rider; struct { char pad0[0x9C]; f32 heading; char padA0[0x124-0xA0]; f32 speed; char pad128[8]; CVector3 aim; } nav; } NavRider;

/* Callers reserve a 136-byte result workspace shared by both target searches. */
static inline void navRotation(CQuatern *q,CVector3 *aim) {
    ((void (*)(CQuatern *,CVector3 *))CVector3_GetDirectionRotation2)(q,aim); }
typedef union NavResult { Result result; Output80216D3C output; struct { s32 kind; void *target; f32 projection; char padC[0x88-0xC]; } workspace; } NavResult;

static inline void navProject(f32 *matrix,CVector3 *local,CVector3 *out,CVector3 *to,CVector3 *from) { GraphU64_SubtractVectors(local,to,from); Graphu64_TransformDirectionTranspose(matrix,local,out); }


typedef struct NavWork {
    NavResult result;
    NavVec origin,destination,relative;
    f32 matrix[16];
    NavVec local;
    CQuatern rotation;
    NavVec aim;
    f32 heading;
} NavWork;

/* Installs a weapon record's handler table and routine pointers and, when its owner's id is 0x40C,
   clears its counters and sets its rate to 200 and its range and speed from D_800C6B2C and D_800C6B30. */










extern s32 Rumble_TestActorStateBit(void *, void *);

/** Run the object's update hook, then advance its timer and fire the expiry action when due. */



typedef struct Owner Owner;

s32 Turret_TrackTarget(NavActor *actor,NavRider *riderState) {
    NavWork work;
    SharedPlayer *target;
    f32 heightScale;
    f32 maxTurn;
    f32 minTurn;
    f32 fireCone;
    f32 turnLimit;
    f32 turnedAimError;
    f32 aimError;
    f32 desiredSpeed;
    s32 inFireCone;
    u16 actorKind;
    CTurretIntelligence *turret;

    inFireCone = 0;
    turret = &actor->player.views18.navigationTrack->segment;
    work.heading = actor->player.views1C.view6C_4.unk6C - riderState->nav.heading;
    Graphu64_WrapPeriodicValue(&work.heading);
    actorKind = actor->player.views1C.viewE4_6.unkE4;
    switch (actorKind) {                              /* irregular */
    case 0x40B:
        Barrel_UpdateTrackGoals(&actor->input, riderState, &work.result.output, 0, 1);
        break;
    case 0x40C:
        AI_DynTurretGetTargetInfo(&actor->player,&riderState->target,&work.result.result);
        break;
    }
    target = riderState->target.target;
    if ((target != NULL) && (work.result.result.distance <= turret->m_SightRadius)) {
        heightScale = D_800C1A28;
        work.origin.v=actor->player.views0.view8_2.unk8;
        desiredSpeed=GameObject_GetActorHeight(&actor->player);
        work.origin.v.y+=desiredSpeed*heightScale;
        work.destination.v=target->views0.view8_2.unk8;
        desiredSpeed=GameObject_GetActorHeight(target);
        work.destination.v.y+=desiredSpeed*heightScale;
        work.aim.v.x = riderState->nav.aim.x;
        work.aim.v.y = riderState->nav.aim.y;
        work.aim.v.z = riderState->nav.aim.z;
        /* SN64 struct-return ABI writes directly to the caller-supplied CQuatern. */
        navRotation(&work.rotation,&work.aim.v);
        MatrixFromQuaternion(&work.rotation.x,work.matrix);
        navProject(work.matrix,&work.local.v,&work.destination.v,&work.destination.v,&work.origin.v);
        GraphU64_AddVec3(&work.destination.v, &work.destination.v, &work.origin.v);
        GraphU64_SubtractVectors(&work.relative.v, &work.destination.v, &work.origin.v);
        desiredSpeed = Graphu64_GetVerticalAngle(&work.relative.v.x);
        aimError = Barrel_GetSignedAngleToPoint(&actor->actor,work.destination.v);
        work.result.workspace.projection = aimError;
        if (work.result.result.distance <= turret->range) {
            fireCone = turret->m_FireAngle * heightScale;
            if (aimError < 0.0f) {
                if (!(-aimError < fireCone)) {

                } else {
                    goto block_12;
                }
            } else if (aimError < fireCone) {
block_12:
                inFireCone = 1;
            }
        }
        turnLimit = turret->limit;
        if (turnLimit < D_800C1A2C) {
            maxTurn = turnLimit * D_800C1A30;
            turnedAimError = work.heading + aimError;
            if (maxTurn < turnedAimError) {
                aimError = maxTurn - work.heading;
            } else {
                minTurn = -maxTurn;
                if (turnedAimError < minTurn) {
                    aimError = minTurn - work.heading;
                }
            }
        }
        Turret_Move(&actor->owner,&riderState->rider,turret->m_TargetVisibleMotionType,target);
    } else {
        desiredSpeed = 0.0f;
        
        aimError = -work.heading;
        Turret_Move(&actor->owner,&riderState->rider,turret->m_TargetNotVisibleMotionType,target);
    }

    if(aimError<0.0f) {
        if(D_800C1A34_de < -aimError) goto changed;
    } else if(D_800C1A38_de < aimError) goto changed;
    if(riderState->nav.speed != desiredSpeed) {
changed:
        Barrel_SetLoopingSound(actor,riderState,0xC3F);
    } else Barrel_StopActorLoopingSound(actor,riderState);
    /* The second ABI word is the actual rider pointer, used as such by this callee. */
    ((void (*)(void *,void *,f32,f32))Barrel_ApplyClampedTurn)(actor,riderState, turret->rate, aimError);
    riderState->nav.speed = GraphU64_ApproachValue(riderState->nav.speed, desiredSpeed, turret->rate);
    return inFireCone;
}

s32 Turret_BuildPlaneRot(s32 out, s32 actor, struct RotationObject *rotation) {
    f32 angles[3];
    angles[0] = rotation->angleX;
    angles[1] = rotation->angleY;
    angles[2] = rotation->angleZ;
    ((void (*)(s32, f32 *))CVector3_GetDirectionRotation2)(out, angles);
    return out;
}
void Turret_Construct(struct OwnerRecAtE4 *owner, struct RecordRecAt13C *record)
{
    record->table = D_800C8170_de;
    record->first = D_002039F8;
    record->second = D_00203E78;
    record->third = D_00202E4C;
    record->fourth = D_00203DF0;
    if (owner->id == 0x40C) {
        record->a = 0;
        record->b = 0;
        record->fourth = D_00203DF0;
        record->rate = 0xC8;
        record->c = 0;
        record->range = D_800C6B2C;
        record->speed = D_800C6B30;
    }
}

void Turret_Setup(LevelActor *actor, struct RecordRecAt13C *turret) {
    s32 flags;
    ActorMotionDefinition *record;

    record = &((ActorMotionResource *)actor->definition)->motion;
    if (actor->type == 0x40C) {
        turret->speed = (&D_800C6B30)[1];
    } else {
        turret->speed = 0.0f;
    }
    turret->pad128 = 0;
    turret->threshold = record->eventThreshold;

    if (Rumble_TestActorStateBit(&g_world, actor) == 0) {
        if (record->flags & 0x1000) {
            flags = actor->flags & ~0x2000;
            flags = flags & ~0x100;
            actor->flags = flags;
        }
        if (record->flags & 0x800) {
            actor->flags =
                actor->flags & ~0x100;
            Nav_RequestActorState(actor, turret, 0);
        } else {
            Nav_RequestActorState(actor, turret, 1);
        }
    } else {
        Nav_RequestActorState(actor, turret, 0x40);
    }
    turret->state = 0;
}

void Turret_Advance(char *actor, Obj *state) {
    if (state->hook != 0 && state->hook->fn != 0) {
        state->hook->fn(actor, state);
    }
    if (((struct OwnerRecAtE4 *)(actor))->id == 0x40C) {
        state->timer += D_800D2988;
        if (D_800C1A48_de < state->timer || state->count <= 0) {
            Nav_RequestActorState(actor, state, 0x40);
        }
    }
}

/** Return the nested record's field, or a fallback constant when zero. */
int Turret_Anim_ACTIVATE(struct Owner *owner) {
    int temp = ((struct MenuRules *) owner->track)->locked;
    if (temp != 0) {
        return temp;
    }
    return 0x2F44;
}

void Turret_Code_ACTIVATE(void *a, struct WeaponEventSource *b) {
    if (b->eventEnabled != 0) {
        Nav_RequestActorState(a, b, 0x3E);
    }
}
