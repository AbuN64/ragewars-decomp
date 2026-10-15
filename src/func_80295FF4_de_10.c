#include "span_1000/code_80297CD0.h"
#include "types.h"

/* Moves the focus of the current screen's selected widget in a direction (5 to 8 following its first, second, third or fourth link) past linked widgets flagged 0x100, and selects the first unflagged one through func_802991D4_de. */







extern Ui *D_8014D080;
extern void func_802991D4_de(s32 id, Widget **links, s32 direction);

void func_80296CD0_de(s32 direction) {
    Widget *widget;
    Widget **links;
    s32 id;

    widget = D_8014D080->screens[D_8014D080->current].focus;
    id = -1;
    links = widget->links;
    if (widget == 0 || !(widget->flags & 0x10)) {
        return;
    }
    switch (direction) {
    case 5:
        while (links[0] != 0) {
            widget = links[0];
            if (!(widget->flags & 0x100)) {
                goto found;
            }
            links = widget->links;
        }
        break;
    case 6:
        while (links[1] != 0) {
            widget = links[1];
            links = widget->links;
            if (!(widget->flags & 0x100)) {
                goto found;
            }
        }
        break;
    case 7:
        while (links[2] != 0) {
            widget = links[2];
            links = widget->links;
            if (!(widget->flags & 0x100)) {
                goto found;
            }
        }
        break;
    found:
        id = widget->id;
        break;
    case 8:
        while (links[3] != 0) {
            widget = links[3];
            links = widget->links;
            if (!(widget->flags & 0x100)) {
                goto found;
            }
        }
        break;
    }
    if (id >= 0) {
        func_802991D4_de(id, links, direction);
    }
}
