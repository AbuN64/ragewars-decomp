#ifndef MATH_SHARED_WIDGETIDE_H
#define MATH_SHARED_WIDGETIDE_H
/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/INTEGERSTATE530.H"
struct Shared_WidgetIdE { u8 pad0[0xE]; u16 id; };











static inline WidgetCallback func_8029AA80_find(s32 id) {
    struct MenuHandlerEntry *h = D_8014D080->handlers;
    s32 i;

    for (i = 0; i < 64; i++, h++) {
        if (h->id == id) {
            return (WidgetCallback)h->draw_handler;
        }
    }
    return 0;
}

/* Finds the widget's handler by identifier and, if present, calls it with the widget and the by-value event arguments. */
#endif
