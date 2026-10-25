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





extern f32 Particle_GetActorHeight(Actor_func_80214310_de *);
extern f32 func_802B72B0_de(f32);
extern CQuatern func_8024796C_de(Actor_func_80214310_de *);
extern void func_80274244_de(CQuatern *, Matrix *);

s32 func_80214310_de(Actor_func_80214310_de *viewer, Actor_func_80214310_de *target, f32 range, f32 across, f32 up)
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
  from.y += Particle_GetActorHeight(viewer) * 0.9f;
  to = target->position;
  to.y += target->eye;
  to.y += Particle_GetActorHeight(target) * 0.9f;
  Particle_SubtractVectors(&dir, &to, &from);
  distance = func_802B72B0_de(((dir.x * dir.x) + (dir.y * dir.y)) + (dir.z * dir.z));
  if (range < distance)
  {
    return 0;
  }
  rotation = func_8024796C_de(viewer);
  func_80274244_de(&rotation, &matrix);
  ahead.x = 0.0f;
  ahead.y = 0.0f;
  ahead.z = distance;
  Particle_TransformPoint(&matrix, &ahead, &forward);
  across *= 0.5f;
  up *= 0.5f;
  flatDir.x = dir.x;
  flatDir.y = 0.0f;
  zero = *((volatile f32 *) (&flatDir.y));
  flatDir.z = dir.z;
  dirLength = func_802B72B0_de((flatDir.x * flatDir.x) + (flatDir.z * flatDir.z));
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
  forwardLength = func_802B72B0_de((flatForward.x * flatForward.x) + (flatForward.z * flatForward.z));
  if (forwardLength != zero)
  {
    flatForward.x /= forwardLength;
    flatForward.z /= forwardLength;
  }
  angle = func_802745D0_de(((flatDir.x * flatForward.x) + (flatDir.y * flatForward.y)) + (flatDir.z * flatForward.z));
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
  func_8027207C_de(&pitchDir);
  *((volatile f32 *) (&pitchForward.x)) = 0.0f;
  pitchForward.z = forwardLength;
  pitchForward.y = forward.y;
  func_8027207C_de(&pitchForward);
  angle = func_802745D0_de(((pitchDir.x * pitchForward.x) + (pitchDir.y * pitchForward.y)) + (pitchDir.z * pitchForward.z));
  if (up < ((angle < 0.0f) ? (-angle) : (angle)))
  {
    return 0;
  }
  return 1;
}

s32 func_80214624_de(Actor_func_80214624_de *actor, Plan *tracker, Actor_func_80214624_de *candidate) {
    CVector3 pos,hit;
    s32 room;
    f32 temp_f20;
    Actor_func_80214624_de *temp_a2;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_v0;
    ApproachLocation *approachLocation;
    Runtime *runtime;

    if (tracker->unk4 == 0) {
        var_s1 = 6;
    } else if (candidate == 0) {
        var_s1 = 3;
        if (tracker->unk94 != 0) {
            var_s1 = 4;
        }
    } else {
        var_s1 = 2;
        if (candidate != tracker->unk68) {
            if (*candidate->unk18 == 5) var_s1=5;
            else if(candidate->unkE4==0x64F) var_s1=7;
            else {
                var_s1=0;
                if(!D_8011FE88.visibilityEnabled) {
                    if((!(candidate->unk100&0x300000) || candidate->unk1D8->unk794!=actor || (var_s1=1,candidate->unk1D8->unk788!=2)) && (!(actor->unk2E0&2) || (var_s1=1,actor->unkE4==0xCA))) var_s1=0;
                }
            }
        }
    }
    switch (var_s1) {
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
        temp_v0_2 = func_80240698_de(actor, tracker->unk84, candidate->pos, candidate->unk14, tracker->unk30->unkC, &pos);
        room = temp_v0_2;
        if (temp_v0_2 == 0) {
        default:
            pos = candidate->pos;
            room = candidate->unk14;
        }
        break;
    }
    if (func_80240660_de(actor, pos, room, tracker->unk30->unkC, &hit) != 0) {
        if (func_80275B10_de(actor->unk14, hit.x, hit.z) != 0) {
            tracker->unk90 = hit.y;
        } else {
            tracker->unk90 = (f32) (hit.y + D_800C2160_de[0]);
        }
        Particle_SubtractVectors(&hit, &hit, &actor->pos);
        tracker->unk8C = (f32) (Particle_GetHorizontalAngle(&hit) + D_800C2160_de[1]);
        return 1;
    }
    if (var_s1 == 1) {
        tracker->unk90 = pos.y;
        tracker->unk8C = (f32) (actor->unk6C + Weapons_GetSignedAngleToPoint(actor, pos));
        return 1;
    }
    return 0;
}

#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern f32 D_800C2168_de;
extern void *D_801041F0;
extern char D_80100030[];
extern s32 func_80245798_de(void);
extern s32 func_80245B0C_de(void);
extern void *func_8022A504_de(void *, f32, f32, f32, void *);
extern void *func_8022A480_de(void *, f32, f32, f32);
extern s32 func_8024E7DC_de(void *);
extern f32 func_80217224_de(void *, f32, f32, f32);
extern f32 func_80217290_de(void *, f32, f32, f32);
extern s32 func_8024DE6C_de(void *);
extern f32 func_8024E570_de(void *);
extern char D_80145040[];
extern s32 func_802444A4_de(void *, f32, f32, f32, CVector3, void *);
/* Picks the best target for an actor: returns the state's fixed target (0x78) if it has one, otherwise
 * gathers up to two candidates (the state's remembered one at 0x68 and the nearest player found around the
 * actor), keeps the nearest within D_800C2168_de that passes the range/visibility tests (func_80214624_de and
 * a line-of-sight probe through func_802444A4_de when requested), and remembers the actor's position when
 * nothing qualified. */
typedef struct Copy50_802149C0 { s32 words[20]; } Copy50_802149C0;
void *Weapons_SelectCombatTarget(void *actor, void *state, s32 lineOfSight, s32 combat) {
    void *candidates[3];
    u8 spare[0x1F0];
    Copy50_802149C0 saved;
    CVector3 target;
    void *best;
    void *candidate;
    f32 bestDistance;
    f32 distance;
    s32 count;
    s32 ok;
    s32 i;
    s32 blocked;
    if (FIELD(void *, state, 0x78) != 0) {
        if (combat != 0) {
            func_80214624_de(actor, state, FIELD(void *, state, 0x78));
        }
        return FIELD(void *, state, 0x78);
    }
    count = 0;
    best = 0;
    ok = 1;
    if (func_80245798_de() != 0) {
        ok = 0;
        if (func_80245B0C_de() >= 10) {
            ok = func_80245B0C_de() < 0x3D;
        }
    }
    if (ok != 0) {
        if (combat != 0) {
            candidate = FIELD(void *, state, 0x68);
            if (candidate != 0) {
                candidates[count++] = candidate;
            }
        }
        if ((FIELD(u32, FIELD(void *, actor, 0x18), 4) & 0x400) == 0) {
            if ((FIELD(u32, actor, 0x100) & 0x300000) != 0) {
                candidate = func_8022A504_de(&D_80145040, FIELD(f32, actor, 0x8), FIELD(f32, actor, 0xC), FIELD(f32, actor, 0x10),
                                             FIELD(void *, actor, 0x1D8));
            } else {
                candidate = func_8022A480_de(&D_80145040, FIELD(f32, actor, 0x8), FIELD(f32, actor, 0xC), FIELD(f32, actor, 0x10));
            }
            if (candidate != 0) {
                i = 1;
                if (FIELD(s16, candidate, 0x5EA) != 0 && FIELD(s16, candidate, 0x650) != 1) {
                    if (func_8024E7DC_de(candidate) != 0) {
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
            distance = func_80217224_de(candidate, FIELD(f32, actor, 0x8), FIELD(f32, actor, 0xC), FIELD(f32, actor, 0x10));
            if (!(distance < bestDistance)) {
                continue;
            }
            if (combat != 0) {
                if (FIELD(s32, FIELD(void *, actor, 0x18), 0) == 1 && FIELD(s8, state, 0x37) == 0) {
                    continue;
                }
                if (func_8024DE6C_de(actor) != 0) {
                    f32 reach = func_80217290_de(candidate, FIELD(f32, state, 0xB0), FIELD(f32, state, 0xB4), FIELD(f32, state, 0xB8));
                    f32 range = func_8024E570_de(actor);
                    if (range * func_8024E570_de(actor) <= reach) {
                        continue;
                    }
                }
                if (func_80214624_de(actor, state, candidate) == 0) {
                    continue;
                }
            }
            if (lineOfSight != 0) {
                saved = *(Copy50_802149C0 *)actor;
                FIELD(f32, actor, 0xC) += Particle_GetActorHeight((Actor_func_80214310_de *)actor);
                FIELD(f32, actor, 0xC) += FIELD(f32, candidate, 0x70);
                target = FIELD(CVector3, candidate, 0x8);
                target.y += Particle_GetActorHeight((Actor_func_80214310_de *)candidate);
                target.y += FIELD(f32, candidate, 0x70);
                blocked = func_802444A4_de(actor, FIELD(f32, actor, 0x8), FIELD(f32, actor, 0xC), FIELD(f32, actor, 0x10), target, D_80100030);
                if (D_801041F0 == candidate) {
                    blocked = 0;
                }
                *(Copy50_802149C0 *)actor = saved;
                if (blocked != 0) {
                    continue;
                }
            }
            bestDistance = distance;
            best = candidate;
        }
    }
    if (combat != 0 && best == 0 && func_80214624_de(actor, state, 0) == 0) {
        FIELD(CVector3, state, 0xB0) = FIELD(CVector3, actor, 0x8);
        FIELD(s32, state, 0xBC) = FIELD(s32, actor, 0x14);
    }
    return best;
}

