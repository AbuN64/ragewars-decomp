#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022D944.h"
#include "types.h"



extern char D_8010EEB8[];
extern char D_8010F328[];
extern f32 D_800C2E10_de;
extern void func_8026367C_de(void *arg0, void *arg1);
extern f32 func_8022ADBC_de(void *arg0);





void func_8022E290_de(void *arg0) {
    Player *object = arg0;
    void *attributes;
    void *state = object->tuning;
    f32 zero;

    if (object->computer != 0) {
        attributes = D_8010EEB8;
    } else {
        s32 index = object->slot;
        attributes = (void *)(index << 4);
        attributes = (char *)attributes + index;
        attributes = (void *)((s32)attributes << 3);
        attributes = (char *)attributes + index;
        attributes = (void *)((s32)attributes << 2);
        attributes = D_8010F328 + (s32)attributes;
    }
    func_8026367C_de(state, attributes);

    object->stick = 0;
    object->state6C4 = 0;
    object->landing = 0;
    object->state6CC = 0;
    object->active = 1;
    object->state6D4 = 0;
    object->state6D8 = 0;
    object->state6DC = 0;
    object->state6E4 = 0;
    object->state758 = 0;
    object->state75C = 0;
    object->locked = 0;
    object->lockState = 0;
    object->state708 = 0;
    object->state70C = 0;
    object->state710 = 0;
    object->state714 = 0;
    object->pitchOffset = 0;
    object->state728 = 0;
    object->lean = 0;
    object->state730 = 0;
    object->state734 = 0;
    object->state738 = 0;
    object->state73C = 0;
    object->baseHeight = func_8022ADBC_de(object);
    object->verticalOffset = 0;
    zero = object->verticalOffset;
    (&object->velocity)->x = (&object->velocity)->y = (&object->velocity)->z = zero;
    object->velocityScale = D_800C2E10_de;
    object->cameraOffset = zero;
    object->cameraScale = D_800C2E10_de;
    object->previousPosition = object->pos;
    object->previousTarget = object->pos;
}
