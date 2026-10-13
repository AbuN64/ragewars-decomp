#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80233920.h"
#include "types.h"

/* Configures an emitter: stores a position vector, a shared value in three channels, a scale, and three rates converted by the constant in D_800C8628. */



extern f32 D_800C8628[];




static inline void set_emitter(func_80239314_S1 *obj, f32 a, f32 b, f32 c, f32 scale, s32 value, Vec3 pos)
{
    obj->unkA8 = pos;
    obj->unkB4 = scale;
    obj->unkB8 = value;
    obj->unkBC = a;
    obj->unkCC = value;
    obj->unkD0 = b;
    obj->unkE0 = value;
    obj->unkE4 = c;
}

void func_80239324_de(func_80239314_S1 *obj, f32 a, f32 b, f32 c, f32 scale, s32 value, Vec3 pos)
{
    if (obj != 0) {
        f32 k = D_800C8628[1];
        set_emitter(obj, a * k, b * k, c * k, scale, value, pos);
    }
}
