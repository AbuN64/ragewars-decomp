#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Scrolls down: moves a scroll bar to the next item through func_8041A6EC_de while it is below the
   item count. */


extern void func_8041A6EC_de(struct Scroll_func_8041A8E8_de *, s32);

void func_8041A910_de(struct Scroll_func_8041A8E8_de *scroll) {
    if (scroll->item < scroll->count) {
        func_8041A6EC_de(scroll, scroll->item + 1);
    }
}
