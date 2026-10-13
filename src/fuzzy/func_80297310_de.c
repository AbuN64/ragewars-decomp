#include "span_1000/code_80297CD0.h"
#include "span_1000/code_80299DB4.h"
#include "common/unused.h"
extern WidgetTable *D_8014D080;
extern void func_80299CF0_de(Node_func_80299CF0_de *, s32, s32, s32, s32, s32);
extern void func_8040E928_de(void *, s32);
extern void func_8029973C_de(void);
extern void func_80298368_de(s32);
/* Send an event through the menu, selected element and its child trees,
 * restoring each dispatcher's handled flag before applying default actions. */
s32 func_80297310_de(s32 recurse, s32 event, s32 arg2, s32 arg3, s32 arg4)
{
    WidgetTable *table = D_8014D080;
    WidgetTable *tree;
    Element *element = table->menu.entries[table->menu.current].primary;
    MenuElementHandler handler;
    s32 result = 0;
    s32 saved, handled, treeSaved;
    if (table->menu.callback != 0) {
        saved = table->handled;
        table->handled = 0;
        result = table->menu.callback(event, arg2, arg3, arg4);
        handled = table->handled;
        table->handled = saved;
        if (handled == 1) return result;
    }
    handler = D_8014D080->menu.entries[D_8014D080->menu.current].primary->handler;
    if (handler != 0) {
        saved = table->handled;
        table->handled = 0;
        result = handler(element, event, arg2, arg3, arg4);
        handled = table->handled;
        table->handled = saved;
        if (handled == 1) return result;
    }
    if (recurse != 0) {
        saved = table->handled;
        table->handled = 0;
        if (element != 0) {
            tree = D_8014D080;
            treeSaved = tree->handled;
            tree->handled = 0;
            if (element->left != 0) func_80299CF0_de(element->left, event, arg2, arg3, arg4, 1);
            if (tree->handled == 0 && element->right != 0) func_80299CF0_de(element->right, event, arg2, arg3, arg4, 1);
            tree->handled = treeSaved;
        }
        handled = table->handled;
        table->handled = saved;
        if (handled == 1) return result;
    }
    switch (event) {
    case 1:
        if ((element->flags & 0x10) && element->linked_id != 0) {
            func_8029973C_de();
            func_80298368_de(element->linked_id);
        }
        break;
    case 2:
        if (D_8014D080->menu.current > 0) func_802998A8_de();
        break;
    case 5: case 6: case 7: case 8:
        if (arg3 == 1) func_80296CD0_de(event);
        break;
    case 15: func_8040E928_de(element, 1); break;
    case 16: func_8040E928_de(element, 0); break;
    }
    return 0;
}
