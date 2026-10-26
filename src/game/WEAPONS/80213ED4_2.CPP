#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/APPROACHLOCATION.H"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"
#include "GAME_2/80240650.H"

/* Tests target visibility against range and horizontal and vertical angles; volatile zero accesses and identical normalization branches preserve scheduling and register allocation. */





extern f32 GameObject_GetActorHeight(ActorBarrelIsTargetInViewCone *);
extern f32 Math_Sqrtf(f32);
extern CQuatern func_8024796C_de(ActorBarrelIsTargetInViewCone *);
extern void MatrixFromQuaternion(CQuatern *, Matrix *);

s32 Barrel_IsTargetInViewCone(ActorBarrelIsTargetInViewCone *viewer, ActorBarrelIsTargetInViewCone *target, f32 range, f32 across, f32 up)
{
  CVector3 from;
  CVector3 to;
  CVector3 dir;
  CVector3 ahead;
  CVector3 forward;
  CVector3 flatDir;
  CVector3 flatForward;
  CVector3 pitchDir;
  CVector3 pitchForward;
  CQuatern rotation;
  Matrix matrix;
  f32 distance;
  f32 dirLength;
  f32 forwardLength;
  f32 angle;
  f32 zero;
  from = viewer->position;
  from.y += viewer->eye;
  from.y += GameObject_GetActorHeight(viewer) * 0.9f;
  to = target->position;
  to.y += target->eye;
  to.y += GameObject_GetActorHeight(target) * 0.9f;
  GraphU64_SubtractVectors(&dir, &to, &from);
  distance = Math_Sqrtf(((dir.x * dir.x) + (dir.y * dir.y)) + (dir.z * dir.z));
  if (range < distance)
  {
    return 0;
  }
  rotation = func_8024796C_de(viewer);
  MatrixFromQuaternion(&rotation, &matrix);
  ahead.x = 0.0f;
  ahead.y = 0.0f;
  ahead.z = distance;
  GraphU64_TransformPoint(&matrix, &ahead, &forward);
  across *= 0.5f;
  up *= 0.5f;
  flatDir.x = dir.x;
  flatDir.y = 0.0f;
  zero = *((volatile f32 *) (&flatDir.y));
  flatDir.z = dir.z;
  dirLength = Math_Sqrtf((flatDir.x * flatDir.x) + (flatDir.z * flatDir.z));
  if (dirLength != zero)
  {
    if (across)
    {
      flatDir.x /= dirLength;
      flatDir.z /= dirLength;
    }
    else
    {
      flatDir.x /= dirLength;
      flatDir.z /= dirLength;
    }
  }
  flatForward.x = forward.x;
  flatForward.y = zero;
  flatForward.z = forward.z;
  forwardLength = Math_Sqrtf((flatForward.x * flatForward.x) + (flatForward.z * flatForward.z));
  if (forwardLength != zero)
  {
    flatForward.x /= forwardLength;
    flatForward.z /= forwardLength;
  }
  angle = GraphU64_ArcCos(((flatDir.x * flatForward.x) + (flatDir.y * flatForward.y)) + (flatDir.z * flatForward.z));
  if (angle < zero)
  {
    angle = -angle;
  }
  if (across < angle)
  {
    return 0;
  }
  *((volatile f32 *) (&pitchDir.x)) = 0.0f;
  pitchDir.z = dirLength;
  pitchDir.y = dir.y;
  GraphU64_NormalizeVec3(&pitchDir);
  *((volatile f32 *) (&pitchForward.x)) = 0.0f;
  pitchForward.z = forwardLength;
  pitchForward.y = forward.y;
  GraphU64_NormalizeVec3(&pitchForward);
  angle = GraphU64_ArcCos(((pitchDir.x * pitchForward.x) + (pitchDir.y * pitchForward.y)) + (pitchDir.z * pitchForward.z));
  if (up < ((angle < 0.0f) ? (-angle) : (angle)))
  {
    return 0;
  }
  return 1;
}

s32 Weapons_UpdateTrackerAim(Actor_func_80214624_de *actor, Plan *tracker, Actor_func_80214624_de *candidate) {
    CVector3 pos,hit;
    s32 room;
    f32 temp_f20;
    Actor_func_80214624_de *temp_a2;
    s32 resolvedRoom;
    s32 targetKind;
    s32 var_v0;
    ApproachLocation *approachLocation;
    Runtime *runtime;

    if (tracker->unk4 == 0) {
        targetKind = 6;
    } else if (candidate == 0) {
        targetKind = 3;
        if (tracker->unk94 != 0) {
            targetKind = 4;
        }
    } else {
        targetKind = 2;
        if (candidate != tracker->unk68) {
            if (*candidate->unk18 == 5) targetKind=5;
            else if(candidate->unkE4==0x64F) targetKind=7;
            else {
                targetKind=0;
                if(!g_world.visibilityEnabled) {
                    if((!(candidate->unk100&0x300000) || candidate->unk1D8->unk794!=actor || (targetKind=1,candidate->unk1D8->unk788!=2)) && (!(actor->unk2E0&2) || (targetKind=1,actor->unkE4==0xCA))) targetKind=0;
                }
            }
        }
    }
    switch (targetKind) {
    case 6:
        pos = actor->pos;
        room = actor->unk14;
        break;
    case 4:
        approachLocation = func_80219408_de(&tracker->unk94);
        pos = approachLocation->pos;
        room = approachLocation->unkC;
        break;
    case 3:
        pos = tracker->pos;
        room = tracker->unkBC;
        break;
    case 7:
        approach(actor,candidate,tracker->unk80,&pos,&room);
        break;
    case 1:
        resolvedRoom = func_80240698_de(actor, tracker->unk84, candidate->pos, candidate->unk14, tracker->unk30->unkC, &pos);
        room = resolvedRoom;
        if (resolvedRoom == 0) {
        default:
            pos = candidate->pos;
            room = candidate->unk14;
        }
        break;
    }
    if (func_80240660_de(actor, pos, room, tracker->unk30->unkC, &hit) != 0) {
        if (Region_IsPointInTriangleXZ(actor->unk14, hit.x, hit.z) != 0) {
            tracker->unk90 = hit.y;
        } else {
            tracker->unk90 = (f32) (hit.y + D_800C2160_de[0]);
        }
        GraphU64_SubtractVectors(&hit, &hit, &actor->pos);
        tracker->unk8C = (f32) (GraphU64_GetHorizontalAngle(&hit) + D_800C2160_de[1]);
        return 1;
    }
    if (targetKind == 1) {
        tracker->unk90 = pos.y;
        tracker->unk8C = (f32) (actor->unk6C + Weapons_GetSignedAngleToPoint(actor, pos));
        return 1;
    }
    return 0;
}

typedef struct CollisionInfo CollisionInfo;
extern f32 D_800C2168_de;
extern CollisionInfo D_80100030;
extern Instance8020CD74 *D_801041F0;
extern char D_80145040[];
extern s32 Cinema_IsSequenceInWindow(void);
extern s32 Cinema_GetSequenceRequest(void);
extern Actor_func_80214DD4_de *Weapons_FindNearestLivePlayer(void *players, CVector3 point, void *exclude);
extern Actor_func_80214DD4_de *Weapons_FindNearestPlayer(void *players, CVector3 point);
extern s32 InstHdr_FindActorModelEntry(void *actor);
extern f32 Weapons_GetEyeDistanceSquared(void *candidate, CVector3 point);
extern f32 Weapons_GetFlatDistanceSquared(void *candidate, CVector3 point);
extern s32 InstHdr_HasActorTerritory(void *actor);
extern f32 InstHdr_GetActorTerritoryRadius(void *actor);
extern s32 func_802444A4_de(void *actor, CVector3 from, CVector3 to, CollisionInfo *info);

/* The two player-record fields the picker reads from a found player (lives 0x5EA, state 0x650). */
typedef struct CombatPlayerView {
    u8 pad0[0x5EA];
    s16 lives;
    u8 pad5EC[0x650 - 0x5EC];
    s16 state;
} CombatPlayerView;

/* Picks the best target for an actor: the tracker's locked target (0x78) if it has one, otherwise
 * gathers up to two candidates (the tracker's own entry at 0x68 and the nearest player found around the
 * actor), keeps the nearest within D_800C2168_de that passes the territory/visibility tests
 * (func_80214624_de and a line-of-sight probe through func_802444A4_de when requested), and remembers the
 * actor's position as the tracker's home when nothing qualified. */
Actor_func_80214DD4_de *Weapons_SelectCombatTarget(Actor_func_80214DD4_de *actor, Tracker *tracker, s32 lineOfSight,
                                                   s32 combat) {
    Actor_func_80214DD4_de *candidates[128];
    Instance8020CD74 saved;
    CVector3 target;
    Actor_func_80214DD4_de *best;
    Actor_func_80214DD4_de *candidate;
    f32 bestDistance;
    f32 distance;
    s32 count;
    s32 ok;
    s32 i;
    s32 blocked;

    if (tracker->lockedTarget != 0) {
        if (combat != 0) {
            Weapons_UpdateTrackerAim((Actor_func_80214624_de *)actor, (Plan *)tracker,
                             (Actor_func_80214624_de *)tracker->lockedTarget);
        }
        return tracker->lockedTarget;
    }
    count = 0;
    best = 0;
    ok = 1;
    if (Cinema_IsSequenceInWindow() != 0) {
        ok = 0;
        if (Cinema_GetSequenceRequest() >= 10) {
            ok = Cinema_GetSequenceRequest() < 61;
        }
    }
    if (ok != 0) {
        if (combat != 0) {
            candidate = tracker->self;
            if (candidate != 0) {
                candidates[count++] = candidate;
            }
        }
        if ((actor->kind[1] & 0x400) == 0) {
            if ((actor->flags100 & 0x300000) != 0) {
                candidate = Weapons_FindNearestLivePlayer(D_80145040, actor->pos, actor->controller);
            } else {
                candidate = Weapons_FindNearestPlayer(D_80145040, actor->pos);
            }
            if (candidate != 0) {
                /* i and best are both reset again before the loop */
                i = 1;
                if (((CombatPlayerView *)candidate)->lives != 0 && ((CombatPlayerView *)candidate)->state != 1) {
                    if (InstHdr_FindActorModelEntry(candidate) != 0) {
                        best = candidate;
                    } else {
                        i = 0;
                    }
                    if (candidate != 0) {
                        candidates[count++] = candidate;
                    }
                }
            }
        }
        bestDistance = D_800C2168_de;
        best = 0;
        for (i = 0; i < count; i++) {
            candidate = candidates[i];
            distance = Weapons_GetEyeDistanceSquared(candidate, actor->pos);
            if (!(distance < bestDistance)) {
                continue;
            }
            if (combat != 0) {
                if (actor->kind[0] == 1 && tracker->unk37 == 0) {
                    continue;
                }
                if (InstHdr_HasActorTerritory(actor) != 0) {
                    f32 reach = Weapons_GetFlatDistanceSquared(candidate, tracker->homePos);
                    f32 range = InstHdr_GetActorTerritoryRadius(actor);
                    if (range * InstHdr_GetActorTerritoryRadius(actor) <= reach) {
                        continue;
                    }
                }
                if (Weapons_UpdateTrackerAim((Actor_func_80214624_de *)actor, (Plan *)tracker,
                                     (Actor_func_80214624_de *)candidate) == 0) {
                    continue;
                }
            }
            if (lineOfSight != 0) {
                saved = *(Instance8020CD74 *)actor;
                actor->pos.y += GameObject_GetActorHeight((ActorBarrelIsTargetInViewCone *)actor);
                actor->pos.y += candidate->height;
                target = candidate->pos;
                target.y += GameObject_GetActorHeight((ActorBarrelIsTargetInViewCone *)candidate);
                target.y += candidate->height;
                blocked = func_802444A4_de(actor, actor->pos, target, &D_80100030);
                if (D_801041F0 == (Instance8020CD74 *)candidate) {
                    blocked = 0;
                }
                *(Instance8020CD74 *)actor = saved;
                if (blocked != 0) {
                    continue;
                }
            }
            bestDistance = distance;
            best = candidate;
        }
    }
    if (combat != 0 && best == 0 &&
        Weapons_UpdateTrackerAim((Actor_func_80214624_de *)actor, (Plan *)tracker, 0) == 0) {
        tracker->homePos = actor->pos;
        tracker->homeRoom = actor->room;
    }
    return best;
}

