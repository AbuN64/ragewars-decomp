#include "span_1000/code_8022D944.h"
#include "types.h"











void func_8022DB04_de(Actor126 *actor, Object126 *arg1) {
    Object126 *object;
    f32 angle;
    f32 object_angle;
    f32 sine;
    f32 cosine;

    actor->flags |= 0x800000;
    actor->value1D4 = D_800C2DC8_de;
    if (actor->state652 == 15) {
        object = arg1;
        object_angle = object->angle;
        angle = D_800C2DCC_de;
        sine = func_802B7130_de(object_angle + angle);
        cosine = func_802B6560_de(object->angle + angle);
        sine *= D_800C7EC0;
        cosine *= D_800C7EC0;
        object->x += sine;
        object->y += cosine;
        object->angle += actor->offset728;
        actor->offset728 = 0.0f;
    }
}
