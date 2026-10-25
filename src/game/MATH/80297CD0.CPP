#include "include_asm.h"
#include "COMMON/INTEGERSTATE530.H"
#include "TYPES.H"
#include "MATH/80297CD0.H"
#include "FRONTEND/8040B45C_32.H"
#include "COMMON/UNUSED.H"

/* Moves the focus of the current screen's selected widget in a direction (5 to 8 following its first, second, third or fourth link) past linked widgets flagged 0x100, and selects the first unflagged one through func_802991D4_de. */







extern void func_802991D4_de(s32 id, Widget **links, s32 direction);

void MoveMenuFocus(s32 direction) {
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

extern void *Frontend_GetScreenData(s32 index);
extern Element *FindMenuElement(s32);
extern void MarkMenuEventHandled(void);
extern void func_80298368_de(s32);

static inline s32 eventCategory(u32 event) {
    if (event < 0xE00) return 0;
    if (event - 0x1000 < 0x1000) return 1;
    if (event - 0xE00 < 0x200) return 2;
    if (event - 0x4000 < 0x4000) return 3;
    return 0;
}

/* Unhandled default events return zero, regardless of earlier callback results. */
static inline s32 defaultElementEvent(Element *element, s32 event, s32 argument) {
    s32 result;
    s32 fallbackCategory;
    result = 0;
    fallbackCategory = eventCategory(event);
    switch (fallbackCategory) {
    case 0:
        switch (event) {
        case 5: case 6: case 7: case 8:
            if (argument == 1) MoveMenuFocus(event);
            break;
        case 1:
            if ((element->flags & 0x10) && element->linked_id) {
                MarkMenuEventHandled();
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

/* Sends an event to element id (-1: the screen owner itself) through the owner, the element and its kind handler;
 * the first that sets the handled flag wins, otherwise the default actions run. */
s32 DispatchElementEvent(s32 id, s32 event, s32 value, s32 argument, s32 context)
{
    Element *element, *owner, *current;
    MenuElementHandler kindHandler, handler;
    s32 result, category, previous;
    s32 direct;
    s32 *handled;

    result = 0;
    element = 0;
    kindHandler = 0;
    direct = 0;
    if (event != 0xE09) g_menuEventCount++;
    handled = &D_8014D080->handled;
    category = eventCategory(event);
    owner = Frontend_GetScreenData(GetMenuScreenOwner());
    if (id == -1) {
        direct = 1;
        element = owner;
    }
    if (!direct) {
        element = FindMenuElement(id);
        if (!element) return 0;
        kindHandler = FindKindHandler(element->kind);
        if (!kindHandler) {
            switch (eventCategory(event)) {
            case 0:
                switch (event) {
                case 5: case 6: case 7: case 8:
                    if (argument == 1) MoveMenuFocus(event);
                    break;
                case 1:
                    if ((element->flags & 0x10) && element->linked_id) {
                        MarkMenuEventHandled();
                        func_80298368_de(element->linked_id);
                    }
                    break;
                case 2:
                    if (D_8014D080->current > 0) func_802998A8_de();
                    break;
                case 15:
                    func_8040E928_de(element, 1);
                    break;
                case 16:
                    func_8040E928_de(element, 0);
                    break;
                default:
                    return 0;
                }
                break;
            case 1:
                return 0;
            case 2:
                return 0;
            case 3:
                return 0;
            }
            return 0;
        }
    }

    previous = *handled;
    *handled = 0;
    if (owner->handler) result = owner->handler(element, event, value, argument, context);
    if (*handled == 1) { *handled = previous; return result; }
    if (!direct) {
        if (category != 2) {
            if (owner->handler) result = owner->handler(owner, event, value, argument, context);
            if (*handled == 1) { *handled = previous; return result; }
        }
        current = FindMenuElement(id);
        handler = 0;
        if (current) handler = current->handler;
        if (handler) result = handler(element, event, value, argument, context);
        if (*handled == 1) { *handled = previous; return result; }
        if (kindHandler) result = kindHandler(element, event, value, argument, context);
        if (*handled == 1) { *handled = previous; return result; }
    }
    result = defaultElementEvent(element, event, argument);

    *handled = previous;
    return result;
}

#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/CALLBACK.H"
#include "COMMON/UNUSED.H"
extern void func_80299CF0_de(NodeRecAt12 *, s32, s32, s32, s32, s32);
extern void MarkMenuEventHandled(void);
extern void func_80298368_de(s32);
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
            if (argument == 1) MoveMenuFocus(event);
            break;

        case 1:
            if ((element->flags & 0x10) && element->linked_id != 0) {
                MarkMenuEventHandled();
                func_80298368_de(element->linked_id);
            }
            break;
        case 2:
            if (D_8014D080->current > 0) func_802998A8_de();
            break;
        case 15: result = 0; func_8040E928_de(element, 1); break;
        case 16: result = 0; func_8040E928_de(element, 0); break;
        default: result = 0; break;
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
/* Sends an event through the menu callback, the current screen's primary element and (recurse) its child
 * trees, restoring each dispatcher's handled flag; unhandled events get the default actions. */
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
        if (*handledFlag == 1) {
            *handledFlag = saved;
            return result;
        }
        *handledFlag = saved;
    }
    if (recurse != 0) {
        saved = *handledFlag;
        *handledFlag = 0;
        Menu_DispatchChildEvents(element, event, value, argument, context);
        if (*handledFlag == 1) {
            *handledFlag = saved;
            return result;
        }
        *handledFlag = saved;
    }
    result = Menu_DispatchDefaultEvent(element, event, argument);
    return result;
}

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "MATH/SHARED_WIDGETIDE.H"
#include "COMMON/INTEGERSTATE530.H"


void func_80299CF0_de(struct NodeRecAt12 *, s32, s32, s32, s32, s32);
#include "COMMON/CALLBACK.H"
void MarkMenuEventHandled(void);
void func_80298368_de(s32);

/* 1/250 words differ: the recurse test branch is a plain beqz here where the ROM uses beql (reorg annuls the
 * inline's result = 0 in its delay slot); everything else matches. Same inlines as DispatchCurrentScreenEvent. */
s32 DispatchScreenRangeEvent(s32 recurse, s32 event, s32 value, void *argument, s32 context) {
    ScreenManager *table = D_8014D080;
    s32 *handledFlag = &table->handled;
    Element *element;
    MenuElementHandler handler;
    s32 result = 0;
    s32 saved, handled;
    s32 first, last;
    if (table->callback != 0) {
        saved = table->handled;
        table->handled = 0;
        result = table->callback(event, value, (s32)argument, context);
        handled = table->handled;
        table->handled = saved;
        if (handled == 1) return result;
    }
    first = D_8014D080->lowIndex;
    last = D_8014D080->current;
    for (; first <= last; first++) {
        switch (event) {
        case 0xE01:
        case 0xE02:
            value = (s32)&D_8014D080->screens[first].data;
            break;
        }
        element = D_8014D080->screens[first].primary;
        handler = element->handler;
        if (handler != 0) {
            saved = *handledFlag;
            *handledFlag = 0;
            result = handler(element, event, value, (s32)argument, context);
            if (*handledFlag == 1) {
                *handledFlag = saved;
                return result;
            }
            *handledFlag = saved;
        }
        if (recurse != 0) {
            D_80146E18 = D_8014D080->screens[first].owner;
            saved = *handledFlag;
            *handledFlag = 0;
            Menu_DispatchChildEvents(element, event, value, (s32)argument, context);
            D_80146E18 = -1;
            if (*handledFlag == 1) {
                *handledFlag = saved;
                return result;
            }
            *handledFlag = saved;
        }
        result = Menu_DispatchDefaultEvent(element, event, (s32)argument);
    }
    return result;
}
#else
INCLUDE_ASM("span_1000", DispatchScreenRangeEvent);
#endif
