#include "span_1000/code_80231F5C.h"
#include "types.h"
/* Pushes an object by the event source's speed at 0x294 through func_802739C4_de according to the event side: in mode 1 side 1 pushes it negated and side 2 doubled, otherwise side 0 pushes it negated and doubled. */





extern s32 D_80140FF8;
extern void func_802739C4_de(void *, f32);

void func_80233188_de(void *object, Event *event) {
    f32 speed;
    s32 mode;

    speed = event->source->speed;
    mode = D_80140FF8;
    if (mode == 1) {
        switch (event->side) {
        case 1:
            func_802739C4_de(object, -speed);
            break;
        case 2:
            func_802739C4_de(object, speed * 2.0f);
            break;
        }
    } else if (event->side == 0) {
        func_802739C4_de(object, -speed * 2.0f);
    }
}
