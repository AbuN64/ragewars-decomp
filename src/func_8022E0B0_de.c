#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022D944.h"
#include "types.h"


extern void func_802738C0_de(void *arg0, f32 arg1);










void func_8022E0B0_de(void *arg0, void *arg1) {
    ObjRecAt1AV1 *range;
    ObjRecAt724 *actor;
    s32 value;
    f32 amount;

    ObjRecAt1CV2 *event = arg1;
    ObjRecAt1D8V1 *object;

    range = event->unk1C;
    value = event->unk4;
    if (value < range->unk18) {
        return;
    }
    if (range->unk19 < value) {
        return;
    }

    object = event->unk8;
    actor = object->unk1D8;
    amount = -actor->unk724;
    if (actor->unk650 == 0xF) {
        amount += D_800C2E0C_de;
    }
    func_802738C0_de(arg0, amount / (f32)range->unk1A);
}
