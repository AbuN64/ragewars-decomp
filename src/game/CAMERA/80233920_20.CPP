#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VIEWFLAGS.H"
#include "CAMERA/80233920.H"
#include "TYPES.H"

/* Configures an emitter: stores a position vector, a shared value in three channels, a scale, and three rates converted by the constant in D_800C8628. */



extern f32 D_800C8628[];




static inline void set_emitter(ObjRecAtE4V1 *obj, f32 a, f32 b, f32 c, f32 scale, s32 value, CVector3 pos)
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

void func_80239324_de(ObjRecAtE4V1 *obj, f32 a, f32 b, f32 c, f32 scale, s32 value, CVector3 pos)
{
    if (obj != 0) {
        f32 k = D_800C8628[1];
        set_emitter(obj, a * k, b * k, c * k, scale, value, pos);
    }
}
