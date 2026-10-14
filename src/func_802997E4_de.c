#include "span_1000/code_80297CD0.h"
#include "types.h"

extern WidgetTable_func_802982C4_de *D_8014D080;

/* The twenty-byte table owns callable values at +4 and +8. The override
 * takes precedence; an absent identifier yields no handler. */
MenuElementHandler func_802997E4_de(s32 id)
{
    s32 i;
    s32 *key;
    struct MenuHandlerEntry *entry;

    key = &D_8014D080->handlers[0].id;
    entry = &D_8014D080->handlers[0];
    for (i = 0; i < 64; i++) {
        if (*key == id) {
            if (entry->override_handler != 0) {
                return entry->override_handler;
            }
            return entry->default_handler;
        }
        entry++;
        key += 5;
    }
    return 0;
}
