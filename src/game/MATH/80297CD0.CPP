#include "include_asm.h"
#include "COMMON/INTEGERSTATE530.H"
#include "TYPES.H"
#include "MATH/80297CD0.H"
#include "FRONTEND/8040B45C_32.H"
#include "COMMON/UNUSED.H"

/* Moves the focus of the current screen's selected widget in a direction (5 to 8 following its first, second, third or fourth link) past linked widgets flagged 0x100, and selects the first unflagged one through func_802991D4_de. */







extern void func_802991D4_de(s32 id, Widget **links, s32 direction);

void func_80296CD0_de(s32 direction) {
    Widget *widget;
    Widget **links;
    s32 id;

    widget = (Widget *)D_8014D080->screens[D_8014D080->current].focus;
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

#ifdef NON_MATCHING
#include "COMMON/INTEGERSTATE530.H"
#include "TYPES.H"

extern s32 D_80146E04;
extern s32 func_80299958_de(void);
extern void *func_80411DCC_de(s32 index);
extern Element *func_80298170_de(s32);
extern void func_8029973C_de(void);
extern void func_80298368_de(s32);

static inline s32 eventCategory(u32 event) {
    if (event < 0xE00) return 0;
    if (event - 0x1000 < 0x1000) return 1;
    if (event - 0xE00 < 0x200) return 2;
    if (event - 0x4000 < 0x4000) return 3;
    return 0;
}

/* Unhandled default events return zero, regardless of earlier callback results. */
static inline s32 defaultElementEvent(Element *element, s32 event, s32 arg3) {
    s32 result;
    s32 fallbackCategory;
    result = 0;
    fallbackCategory = eventCategory(event);
    switch (fallbackCategory) {
    case 0:
        switch (event) {
        case 5: case 6: case 7: case 8:
            if (arg3 == 1) func_80296CD0_de(event);
            break;
        case 1:
            if ((element->flags & 0x10) && element->linked_id) {
                func_8029973C_de();
                func_80298368_de(element->linked_id);
            }
            break;
        case 2:
            if (D_8014D080->current > 0) func_802998A8_de();
            break;
        case 15:
            result = 0;
            func_8040E928_de(element, 1);
            break;
        case 16:
            result = 0;
            func_8040E928_de(element, 0);
            break;
        default:
            result = 0;
            break;
        }
        break;
    case 1: result = 0; break;
    case 2: result = 0; break;
    case 3: result = 0; break;
    }    return result;
}

/* 18/309 aligned edits; remaining: gcc cross-jumps the first default site's case 15/16 calls into one (the ROM keeps two arms), which shifts the later branch targets. */
s32 DispatchElementEvent(s32 id, s32 event, s32 arg2, s32 arg3, s32 arg4)
{
    Element *element, *context, *current;
    MenuElementHandler kindHandler, handler;
    s32 result, category, previous;
    s32 direct;
    s32 *handled;

    result = 0;
    element = 0;
    kindHandler = 0;
    direct = 0;
    if (event != 0xE09) D_80146E04++;
    handled = &D_8014D080->handled;
    category = eventCategory(event);
    context = func_80411DCC_de(func_80299958_de());
    if (id == -1) {
        direct = 1;
        element = context;
    }
    if (!direct) {
        element = func_80298170_de(id);
        if (!element) return 0;
        kindHandler = func_802997E4_de(element->kind);
        if (!kindHandler) {
            defaultElementEvent(element, event, arg3);
            return 0;
        }
    }

    previous = *handled;
    *handled = 0;
    if (context->handler) result = context->handler(element, event, arg2, arg3, arg4);
    if (*handled == 1) { *handled = previous; return result; }
    if (!direct) {
        if (category != 2) {
            if (context->handler) result = context->handler(context, event, arg2, arg3, arg4);
            if (*handled == 1) { *handled = previous; return result; }
        }
        current = func_80298170_de(id);
        handler = 0;
        if (current) handler = current->handler;
        if (handler) result = handler(element, event, arg2, arg3, arg4);
        if (*handled == 1) { *handled = previous; return result; }
        if (kindHandler) result = kindHandler(element, event, arg2, arg3, arg4);
        if (*handled == 1) { *handled = previous; return result; }
    }
    result = defaultElementEvent(element, event, arg3);

    *handled = previous;
    return result;
}
#else
INCLUDE_ASM("span_1000", DispatchElementEvent);
#endif

#ifdef NON_MATCHING
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/CALLBACK.H"
#include "COMMON/UNUSED.H"
extern void func_80299CF0_de(NodeRecAt12 *, s32, s32, s32, s32, s32);
extern void func_8029973C_de(void);
extern void func_80298368_de(s32);
/* Send an event through the menu, selected element and its child trees,
 * restoring each dispatcher's handled flag before applying default actions. */
/* 34/207 aligned edits; remaining: saved flag/result registers and return sharing. */
static inline s32 Menu_GetDispatchCategory(u32 code) {
    if (code < 0xE00) return 0;
    if (code - 0x1000 < 0x1000) return 1;
    if (code - 0xE00 < 0x200) return 2;
    if (code - 0x4000 < 0x4000) return 3;
    return 0;
}
static inline s32 Menu_DispatchDefaultEvent(Element *element, s32 event, s32 argument) {
    s32 result = 0;
    switch (Menu_GetDispatchCategory(event)) {
    case 0:
        switch (event) {
        case 5: case 6: case 7: case 8:
            if (argument == 1) func_80296CD0_de(event);
            break;

        case 1:
            if ((element->flags & 0x10) && element->linked_id != 0) {
                func_8029973C_de();
                func_80298368_de(element->linked_id);
            }
            break;
        case 2:
            if (D_8014D080->current > 0) func_802998A8_de();
            break;
        case 15: result = 0; func_8040E928_de(element, 1); break;
        case 16: result = 0; func_8040E928_de(element, 0); break;
        }
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = 0;
        break;
    case 3:
        result = 0;
        break;
    }
    return result;
}
static inline void Menu_DispatchChildEvents(Element *element, s32 event, s32 value, s32 argument, s32 context) {
    ScreenManager *tree;
    s32 treeSaved;
    s32 *treeHandled;
    if (element != 0) {
        tree = D_8014D080;
        treeHandled = &tree->handled;
        treeSaved = tree->handled;
        tree->handled = 0;
        if (element->left != 0) func_80299CF0_de(element->left, event, value, argument, context, 1);
        if (tree->handled == 0 && element->right != 0) func_80299CF0_de(element->right, event, value, argument, context, 1);
        *treeHandled = treeSaved;
    }
}
s32 DispatchCurrentScreenEvent(s32 recurse, s32 event, s32 value, s32 argument, s32 context)
{
    ScreenManager *table = D_8014D080;
    s32 *handledFlag = &table->handled;
    Element *element = table->screens[table->current].primary;
    MenuElementHandler handler;
    s32 result = 0;
    s32 saved, handled;
    if (table->callback != 0) {
        saved = table->handled;
        table->handled = 0;
        result = table->callback(event, value, argument, context);
        handled = table->handled;
        table->handled = saved;
        if (handled == 1) return result;
    }
    handler = D_8014D080->screens[D_8014D080->current].primary->handler;
    if (handler != 0) {
        saved = *handledFlag;
        *handledFlag = 0;
        result = handler(element, event, value, argument, context);
        handled = *handledFlag;
        *handledFlag = saved;
        if (handled == 1) return result;
    }
    if (recurse != 0) {
        saved = *handledFlag;
        *handledFlag = 0;
        Menu_DispatchChildEvents(element, event, value, argument, context);
        handled = *handledFlag;
        *handledFlag = saved;
        if (handled == 1) return result;
    }
    return Menu_DispatchDefaultEvent(element, event, argument);
}
#else
INCLUDE_ASM("span_1000", DispatchCurrentScreenEvent);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "MATH/SHARED_WIDGETIDE.H"
#include "COMMON/INTEGERSTATE530.H"


void func_80299CF0_de(struct NodeRecAt12 *, s32, s32, s32, s32, s32);
#include "COMMON/CALLBACK.H"
void func_8029973C_de(void);
void func_80298368_de(s32);

/* 113/250 aligned edits; remaining: event-loop scheduling and register allocation. */
static inline void Screen_DispatchChildren(Element *element, s32 event, s32 value, s32 argument, s32 context) {
    ScreenManager *manager;
    s32 saved;
    s32 *handled;
    if (element != 0) {
        manager = D_8014D080;
        handled = &manager->handled;
        saved = manager->handled;
        manager->handled = 0;
        if (element->left != 0) {
            func_80299CF0_de(element->left, event, value, argument, context, 1);
        }
        if (manager->handled != 0) {
            *handled = saved;
            return;
        }
        if (element->right != 0) {
            func_80299CF0_de(element->right, event, value, argument, context, 1);
        }
        *handled = saved;
    }
}

static inline s32 Screen_DispatchStandardEvent(Element *element, s32 event, s32 argument, s32 systemEvents, s32 screenEvents, s32 userEvents) {
    s32 result = 0;
    s32 category = result;
    if ((u32)event >= 0xE00U) {
        category = 1;
        if (!systemEvents) {
            category = 2;
            if (!screenEvents) {
                category = result;
                if (userEvents) category = 3;
            }
        }
    }
    switch (category) {
    case 0:
        switch (event) {
        case 5: case 6: case 7: case 8:
            if (argument == 1) func_80296CD0_de(event);
            break;
        case 1:
            if (element->flags & 0x10) {
                if (element->linked_id != 0) {
                    func_8029973C_de();
                    func_80298368_de(element->linked_id);
                }
            }
            break;
        case 2:
            if (D_8014D080->current > 0) func_802998A8_de();
            break;
        case 15: func_8040E928_de(element, 1); break;
        case 16: func_8040E928_de(element, 0); break;
        }
        break;
    case 1: result = 0; break;
    case 2: result = 0; break;
    case 3: result = 0; break;
    }
    return result;
}

s32 DispatchScreenRangeEvent(s32 recurse, s32 event, s32 value, void *argument, s32 context) {
    s32 first, last;
    s32 systemEvents, screenEvents, userEvents;
    s32 result = 0;
    s32 saved, consumed;
    s32 *handled;
    ScreenManager *manager = D_8014D080;
    Element *element;
    MenuElementHandler handler;
    handled = &manager->handled;
    if (manager->callback != 0) {
        saved = manager->handled;
        manager->handled = 0;
        result = manager->callback(event, value, (s32)argument, context);
        consumed = manager->handled;
        manager->handled = saved;
        if (consumed == 1) return result;
    }
    goto dispatchScreens;
restoreHandled:
    *handled = saved;
    return result;
dispatchScreens:
    first = D_8014D080->lowIndex;
    last = D_8014D080->current;
    if (first > last) return result;
    systemEvents = (u32)event - 0x1000U < 0x1000U;
    screenEvents = (u32)event - 0xE00U < 0x200U;
    userEvents = (u32)event - 0x4000U < 0x4000U;
    do {
        if (event < 0xE03 && event > 0xE00) {
            value = (s32)&D_8014D080->screens[first].data;
        }
        element = D_8014D080->screens[first].primary;
        handler = element->handler;
        if (handler != 0) {
            saved = *handled;
            *handled = 0;
            result = handler(element, event, value, (s32)argument, context);
            if (*handled == 1) goto restoreHandled;
            *handled = saved;
        }
        if (recurse != 0) {
            D_80146E18 = D_8014D080->screens[first].owner;
            saved = *handled;
            *handled = 0;
            Screen_DispatchChildren(element, event, value, (s32)argument, context);
            D_80146E18 = -1;
            if (*handled == 1) goto restoreHandled;
            *handled = saved;
        }
        result = Screen_DispatchStandardEvent(element, event, (s32)argument, systemEvents, screenEvents, userEvents);
        first++;
    } while (first <= last);
    return result;
}
#else
INCLUDE_ASM("span_1000", DispatchScreenRangeEvent);
#endif
