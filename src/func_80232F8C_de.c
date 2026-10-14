#include "span_1000/code_80231F5C.h"
/* Applies the negated, scaled speed of the event's source (float at 0x294, scaled by D_800C8130) to an
   object through func_802739C4_de when the event side at 0x4 matches the mode: side 2 in mode 1, side 0
   otherwise. */





extern int D_80140FF8;
extern void func_802739C4_de(void *, float);

void func_80232F8C_de(void *obj, Event *event) {
    float v = event->source->speed * D_800C8130;

    if (D_80140FF8 == 1) {
        if (event->side == 2) {
            func_802739C4_de(obj, -v);
        }
    } else if (event->side == 0) {
        func_802739C4_de(obj, -v);
    }
}
