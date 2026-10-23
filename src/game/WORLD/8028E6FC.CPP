#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "WORLD/8028E6FC.H"
#include "TYPES.H"
#include "SDK/SCHED/8028DF6C_2.H"
#include "sdk/os.h"
#include "RENDER_4/8028FD2C_6.H"








s32 func_8028E6FC_de(Shared_World *arg0)
{
  Shared_World *elem;
  s32 i;
  void *field;
  char *new_var;
  void *ret;
  s32 count;
  count = arg0->sectorCount;
  if (count <= 0)
  {
    return 0;
  }
  i = 0;
  elem = arg0;
  do
  {
    field = arg0->sectors[i].resource;
    ret = func_8028FDB4_de(*((s32 *) field), 2);
    if ((((struct IntPair *)ret)->field_4) != 0)
    {
      if (arg0 || i)
      {
        return 1;
      }
      else
      {
        return 1;
      }
    }
    count = arg0->sectorCount;
    i += 1;

  }
  while (i < count);
  return 0;
}

/** Return an indexed record from the table at object offset 0xAC. */
void *func_8028E770_de(struct Shared_World *object, int index) {
    char *base = (char *)object->actorRecords;
    int stride = *(int *)base;
    return base + (index * stride + 8);
}

extern void func_80271F68_de(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);




s32 func_8028E78C_de(struct ObjectRecAt1A4 *arg0, CVector3 *arg1) {
    CVector3 vector;
    f32 magnitude;
    u16 type;

    func_80271F68_de(&vector, &arg0->x, arg1);
    magnitude = (vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z);
    if (*arg0->kind != 1) {
        return 0;
    }
    type = arg0->team;
    if (type == 0x44E || type == 0x453 || type == 0x451 || type == 0x450 ||
        type == 0x454 || type == 0x455 || type == 0x456) {
        return 0;
    }
    if (arg0->active == 0) {
        return 0;
    }
    if (arg0->state == 0x3D) {
        return 0;
    }
    return magnitude <= D_800C533C_de;
}

/* Reports whether arg1 is within range of arg0, using its type and state to pick the check. */





extern void func_80271F68_de(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);




s32 func_8028E860_de(ObjRecAtE4V2 *player, CVector3 *arg1) {
    CVector3 delta;
    u16 type;

    if (player->unk0 == 1 && *player->unk18 == 7) {
        func_80271F68_de(&delta, &((Player *)(player))->pos, arg1);
        delta.y = 0;
        if (262144.0f < delta.x * delta.x + delta.z * delta.z) {
            return 0;
        }
        return 0xFF;
    }
    if (*player->unk18 != 1) {
        return 0;
    }
    type = player->unkE4;
    if (type == 0x44E || type == 0x453 || type == 0x451 || type == 0x450 ||
        type == 0x454 || type == 0x455 || type == 0x456) {
        return 0xFF;
    }
    return 0;
}
#if defined(VERSION_EU_X)
unsigned int func_8028E860_de_padding_8F66C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C55F4[3] = {
    0x24E7FFFF, 0x0065102B, 0x50400004,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C5344[3] = {
    0x358637BD, 0x358637BD, 0x358637BD,
};
#endif
