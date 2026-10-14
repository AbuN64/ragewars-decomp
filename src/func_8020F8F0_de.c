#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8020EAE0.h"
#include "types.h"

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
