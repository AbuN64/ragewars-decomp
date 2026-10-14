#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Positions a scroll bar: records the current item at offset 0x50 and stores in the halfword at
   0x18 of the bar object at 0x44 the item scaled from the item count at 0x4C to the track
   length at 0x48. */




void func_8041A6EC_de(struct Scroll *scroll, s32 item) {
    scroll->item = item;
    scroll->bar->field18 = (f32) item / (f32) scroll->count * (f32) scroll->length;
}
