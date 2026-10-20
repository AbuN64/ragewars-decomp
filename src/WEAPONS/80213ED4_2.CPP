#include "include_asm.h"
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
extern void func_8024796C_de(CQuatern *, Actor_func_80214310_de *);
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
  func_80271F68_de(&dir, &to, &from);
  distance = func_802B72B0_de(((dir.x * dir.x) + (dir.y * dir.y)) + (dir.z * dir.z));
  if (range < distance)
  {
    return 0;
  }
  func_8024796C_de(&rotation, viewer);
  func_80274244_de(&rotation, &matrix);
  ahead.x = 0.0f;
  ahead.y = 0.0f;
  ahead.z = distance;
  func_80272898_de(&matrix, &ahead, &forward);
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

s32 func_80214624_de(Actor_func_80214624_de *arg0, Plan *arg1, Actor_func_80214624_de *arg2) {
    CVector3 pos,hit;
    s32 room;
    f32 temp_f20;
    Actor_func_80214624_de *temp_a2;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_v0;
    ApproachLocation *temp_v0;
    Runtime *temp_v1;

    if (arg1->unk4 == 0) {
        var_s1 = 6;
    } else if (arg2 == 0) {
        var_s1 = 3;
        if (arg1->unk94 != 0) {
            var_s1 = 4;
        }
    } else {
        var_s1 = 2;
        if (arg2 != arg1->unk68) {
            if (*arg2->unk18 == 5) var_s1=5;
            else if(arg2->unkE4==0x64F) var_s1=7;
            else {
                var_s1=0;
                if(!D_8013B290) {
                    if((!(arg2->unk100&0x300000) || arg2->unk1D8->unk794!=arg0 || (var_s1=1,arg2->unk1D8->unk788!=2)) && (!(arg0->unk2E0&2) || (var_s1=1,arg0->unkE4==0xCA))) var_s1=0;
                }
            }
        }
    }
    switch (var_s1) {
    case 6:
        pos = arg0->pos;
        room = arg0->unk14;
        break;
    case 4:
        temp_v0 = func_80219408_de(&arg1->unk94);
        pos = temp_v0->pos;
        room = temp_v0->unkC;
        break;
    case 3:
        pos = arg1->pos;
        room = arg1->unkBC;
        break;
    case 7:
        approach(arg0,arg2,arg1->unk80,&pos,&room);
        break;
    case 1:
        temp_v0_2 = func_80240698_de(arg0, arg1->unk84, arg2->pos, arg2->unk14, arg1->unk30->unkC, &pos);
        room = temp_v0_2;
        if (temp_v0_2 == 0) {
        default:
            pos = arg2->pos;
            room = arg2->unk14;
        }
        break;
    }
    if (func_80240660_de(arg0, pos, room, arg1->unk30->unkC, &hit) != 0) {
        if (func_80275B10_de(arg0->unk14, hit.x, hit.z) != 0) {
            arg1->unk90 = hit.y;
        } else {
            arg1->unk90 = (f32) (hit.y + D_800C2160_de[0]);
        }
        func_80271F68_de(&hit, &hit, &arg0->pos);
        arg1->unk8C = (f32) (func_80271AA8_de(&hit) + D_800C2160_de[1]);
        return 1;
    }
    if (var_s1 == 1) {
        arg1->unk90 = pos.y;
        arg1->unk8C = (f32) (arg0->unk6C + func_80216F44_de(arg0, pos));
        return 1;
    }
    return 0;
}

INCLUDE_ASM("span_1000", func_802149C0_de);
