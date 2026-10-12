#include "span_1000/code_80297CD0.h"
#include "types.h"

typedef struct DraftEventState {
    s32 pad0, count;
    char pad8[0x518]; s32 handled;
} DraftEventState;
extern DraftEventState *D_8014D080;
extern s32 D_80146E04;
extern s32 func_80299958_de(void);
extern Element *func_80411DCC_de(s32);
extern Element *func_80298170_de(s32);
extern void func_8029973C_de(void);
extern void func_80298368_de(s32);
extern void func_8040E928_de(Element *, s32);

s32 func_80296E3C_de(s32 id, s32 event, s32 arg2, s32 arg3, s32 arg4)
{
    Element *element, *context, *current;
    MenuElementHandler kindHandler, handler;
    s32 result, category, previous;
    s32 *handled;
    u32 code;

    result = 0;
    kindHandler = 0;
    code = event;
    if (code != 0xE09) D_80146E04++;
    handled = &D_8014D080->handled;
    category = 0;
    if (code >= 0xE00) {
        category = 1;
        if (code - 0x1000 >= 0x1000) {
            category = 2;
            if (code - 0xE00 >= 0x200) {
                category = 0;
                if (code - 0x4000 < 0x4000) category = 3;
            }
        }
    }
    context = func_80411DCC_de(func_80299958_de());
    element = context;
    if (id != -1) {
        element = func_80298170_de(id);
        if (!element) return 0;
        kindHandler = func_802997E4_de(element->kind);
        if (!kindHandler) {
    category = 0;
    if (code >= 0xE00) {
        category = 1;
        if (code - 0x1000 >= 0x1000) {
            category = 2;
            if (code - 0xE00 >= 0x200) {
                category = 0;
                if (code - 0x4000 < 0x4000) category = 3;
            }
        }
    }
            if (category != 0) return 0;
        switch (code) {
        case 1:
            if ((element->flags & 0x10) && element->linked_id) {
                func_8029973C_de();
                func_80298368_de(element->linked_id);
            }
            break;
        case 2:
            if (D_8014D080->count > 0) func_802998A8_de();
            break;
        case 5: case 6: case 7: case 8:
            if (arg3 == 1) func_80296CD0_de(event);
            break;
        case 15:
            func_8040E928_de(element, 1);
            break;
        case 16:
            func_8040E928_de(element, 0);
            break;
        default:
            break;
        }
            return 0;
        }
    }
    previous = *handled;
    *handled = 0;
    if (context->handler) result = context->handler(element, event, arg2, arg3, arg4);
    if (*handled == 1) goto restore;
    if (id != -1) {
        if (category != 2) {
            if (context->handler) result = context->handler(context, event, arg2, arg3, arg4);
            if (*handled == 1) goto restore;
        }
        current = func_80298170_de(id);
        handler = 0;
        if (current) handler = current->handler;
        if (handler) result = handler(element, event, arg2, arg3, arg4);
        if (*handled == 1) goto restore;
        if (kindHandler) result = kindHandler(element, event, arg2, arg3, arg4);
        if (*handled == 1) goto restore;
    }
    result = 0;
    category = 0;
    if (code >= 0xE00) {
        category = 1;
        if (code - 0x1000 >= 0x1000) {
            category = 2;
            if (code - 0xE00 >= 0x200) {
                category = 0;
                if (code - 0x4000 < 0x4000) category = 3;
            }
        }
    }
    if (category == 0) {
        switch (code) {
        case 1:
            if ((element->flags & 0x10) && element->linked_id) {
                func_8029973C_de();
                func_80298368_de(element->linked_id);
            }
            break;
        case 2:
            if (D_8014D080->count > 0) func_802998A8_de();
            break;
        case 5: case 6: case 7: case 8:
            if (arg3 == 1) func_80296CD0_de(event);
            break;
        case 15:
            func_8040E928_de(element, 1);
            break;
        case 16:
            func_8040E928_de(element, 0);
            break;
        default:
            break;
        }
    }
restore:
    *handled = previous;
    return result;
}
