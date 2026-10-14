#include "span_1000/code_80297CD0.h"
#include "types.h"





extern WidgetTable_func_802982C4_de *D_8014D080;

/* Registers a widget handler under an identifier, reusing its slot or the first free one, or clears that slot when no handler is given. */
void func_802982C4_de(s32 id, MenuElementHandler arg1, MenuDrawHandler draw_handler, s32 arg3) {
    s32 slot = -1;
    s32 i;

    for (i = 0; i < 64; i++) {
        if (D_8014D080->handlers[i].id == id) {
            slot = i;
            break;
        }
        if (D_8014D080->handlers[i].id == -1 && slot == -1) {
            slot = i;
        }
    }
    if (arg1 != 0) {
        D_8014D080->handlers[slot].id = id;
        D_8014D080->handlers[slot].default_handler = arg1;
        D_8014D080->handlers[slot].draw_handler = draw_handler;
        D_8014D080->handlers[slot].override_handler = 0;
        D_8014D080->handlers[slot].flags = arg3;
    } else {
        D_8014D080->handlers[slot].id = -1;
        D_8014D080->handlers[slot].default_handler = 0;
        D_8014D080->handlers[slot].draw_handler = 0;
        D_8014D080->handlers[slot].override_handler = 0;
    }
}
