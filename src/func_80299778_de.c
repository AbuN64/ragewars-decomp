#include "span_1000/code_80297CD0.h"
#include "types.h"

extern WidgetTable_func_802982C4_de *D_8014D080;

void func_80299778_de(s32 id, s32 mode, MenuElementHandler handler)
{
    s32 index = -1;
    s32 i;
    struct MenuHandlerEntry *entry = &D_8014D080->handlers[0];

    for (i = 0; i < 64; i++, entry++) {
        if (entry->id == id) {
            index = i;
            break;
        }
    }
    entry = &D_8014D080->handlers[index];
    if (mode == 1) {
        entry->default_handler = handler;
        entry->override_handler = 0;
        return;
    }
    entry->override_handler = handler;
}
