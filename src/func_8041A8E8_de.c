#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Scrolls up: moves a scroll bar to the previous item through func_8041A6EC_de unless it is already
   at the first. */


extern void func_8041A6EC_de(struct Scroll_func_8041A8E8_de *, s32);

void func_8041A8E8_de(struct Scroll_func_8041A8E8_de *scroll) {
    if (scroll->item > 0) {
        func_8041A6EC_de(scroll, scroll->item - 1);
    }
}
