#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/OBJECTLINKS1458.H"
#include "TYPES.H"

#if defined(VERSION_EU)
INCLUDE_ASM("span_1000", func_8020F6E0_eu);
#endif

#if defined(VERSION_DE) && !defined(NON_MATCHING)
INCLUDE_ASM("span_1000", func_8020F6C0_de);
#endif

#if !(defined(VERSION_DE) || defined(VERSION_EU)) || (defined(VERSION_DE) && defined(NON_MATCHING))
/* Fuzzy draft for de: the other versions' body under the de name. */
#ifdef VERSION_DE
#define FX_FN func_8020F6C0_de
#else
#define FX_FN func_8020F6D8_eu_x
#endif
#ifdef NON_MATCHING
#define FX_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
extern s32 D_801468C4;
extern void *func_8020993C_de(void *);
extern f32 func_802726F8_de(void *, void *);
extern s32 func_80209A94_de(void *);
extern s32 func_8020F93C_de(void *);
extern s32 func_8020F984_de(void *);
s32 FX_FN(void *self) {
    void *camera;
    u8 *link;
    u8 *target;
    u8 *linkObj = 0;
    u8 *altObj = 0;
    u8 *alt;
    f32 linkDist = 0.0f;
    f32 altDist = 0.0f;
    s32 i;
    camera = func_8020993C_de(self);
    link = FX_FIELD(self, u8 *, 0x64);
    if (link != 0) {
        linkObj = FX_FIELD(link, u8 *, 0x1D8);
        if (FX_FIELD(linkObj, s32, 0x5E4) == 0) {
            FX_FIELD(self, u8 *, 0x64) = 0;
        }
        if (FX_FIELD(linkObj, s32, 0x122C) & 0x20) {
            FX_FIELD(self, u8 *, 0x64) = 0;
        }
        if (D_801468C4 != 0) {
            if (FX_FIELD(FX_FIELD(FX_FIELD(self, u8 *, 0), u8 *, 0x5D8), u8, 0x92) == FX_FIELD(FX_FIELD(linkObj, u8 *, 0x5D8), u8, 0x92)) {
                FX_FIELD(self, u8 *, 0x64) = 0;
            }
        }
    }
    link = FX_FIELD(self, u8 *, 0x64);
    if (link != 0) {
        linkObj = FX_FIELD(link, u8 *, 0x1D8);
        linkDist = func_802726F8_de(camera, linkObj + 8);
    } else {
        linkObj = 0;
        linkDist = 0.0f;
    }
    alt = FX_FIELD(self, u8 *, 0x28C);
    if (alt != 0 && (FX_FIELD(alt, s32, 0x100) & 0x300000)) {
        altObj = FX_FIELD(alt, u8 *, 0x1D8);
        altDist = func_802726F8_de(camera, altObj + 8);
    } else {
        altObj = 0;
        altDist = 0.0f;
    }
    if (func_80209A94_de(self) == 0 || linkObj == 0) {
        if (func_8020F93C_de(self) == 0) {
            FX_FIELD(self, u8 *, 0x64) = 0;
            return 1;
        }
        if (altObj != 0 && func_8020F8F0_de(self) != 0) {
            target = altObj;
        } else {
            i = func_8020F984_de(self);
            target = FX_FIELD(self, u8 *, 0x3C + i * 4);
        }
    } else if (altObj != 0 && altDist <= linkDist) {
        target = altObj;
    } else {
        i = func_8020F984_de(self);
        if (i != -1 && (f32)FX_FIELD(self, s32, 0x94 + i * 4) < linkDist) {
            target = FX_FIELD(self, u8 *, 0x3C + i * 4);
        } else if (FX_FIELD(self, s32, 0x21C) == 1 && D_800C21F0_eu_x.unk4 < linkDist) {
            FX_FIELD(self, u8 *, 0x64) = 0;
            return 1;
        } else {
            target = FX_FIELD(self, u8 *, 0x64);
        }
    }
    FX_FIELD(self, u8 *, 0x64) = target;
    FX_FIELD(self, f32, 0x258) = FX_FIELD(target, f32, 8);
    FX_FIELD(self, f32, 0x25C) = FX_FIELD(target, f32, 0xC);
    FX_FIELD(self, f32, 0x260) = FX_FIELD(target, f32, 0x10);
    return 1;
}
#else
INCLUDE_ASM("span_1000", func_8020F6D8_eu_x);
#endif
#endif

/* Returns 1 when one of the object's ten entries at 0x3C matches its current value at 0x28C and the
   paired flag at 0x6C is set, and 0 otherwise or when the current value is zero. */

int func_8020F8F0_de(ObjRecAt28C *obj) {
    int i;

    if (obj->current == 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (obj->keys[i] == obj->current && obj->flags[i] != 0) {
            return 1;
        }
    }
    return 0;
}

s32 func_8020F93C_de(void *arg0)
{
  s32 var_a1;
  s32 var_v1;
  ObjRecAt28C *var_a0;
  var_a0 = arg0;
  var_a1 = 0;
  if ((var_a0->count) == 0)
  {
    return 0;
  }
  var_v1 = 0;
  do
  {
    if (((var_a0->keys[var_v1]) != 0) && ((var_a0->flags[var_v1]) != 0))
    {
      var_a1 += 1;
    }
    var_v1 += 1;
  }
  while (var_v1 < 0xA);
  return var_a1;
}


s32 func_8020F984_de(void *arg0) {
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f1;
    s32 temp_v0;
    s32 mask;
    s32 var_a1;
    s32 var_v1;
    ObjRecAt28C *var_a0;

    var_a0 = arg0;
    var_a1 = -1;
    var_f1 = D_800C21F0_eu_x.unk4;
    var_v1 = 0;
    if (var_a0->count > 0) {
        mask = 0x300000;
        temp_f2 = var_f1;
        temp_v0 = var_a0->count;
        do {
            struct Actor_func_80214DD4_de *actor = (struct Actor_func_80214DD4_de *)var_a0->keys[var_v1];
            if ((actor->flags100 & mask) &&
                ((temp_f0 = (f32)var_a0->distances[var_v1], temp_f0 < var_f1) ||
                 (var_f1 == temp_f2)) &&
                (var_a0->flags[var_v1] != 0)) {
                var_f1 = temp_f0;
                var_a1 = var_v1;
            }
            var_v1 += 1;
        } while (var_v1 < temp_v0);
    }
    return var_a1;
}
