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

/* 188/309 aligned edits; remaining: callback and direct-id live ranges, category switch scheduling. */
s32 DispatchElementEvent(s32 id, s32 event, s32 arg2, s32 arg3, s32 arg4)
{
    Element *element, *context, *current;
    MenuElementHandler kindHandler, handler;
    s32 result, category, previous;
    s32 fallbackCategory;
    s32 direct;
    s32 *handled;
    u32 code;

    direct = 0;
    element = 0;
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
    if (id == -1) {
        direct = 1;
        element = context;
    }
    if (!direct) {
        element = func_80298170_de(id);
        if (!element) return 0;
        kindHandler = func_802997E4_de(element->kind);
        if (!kindHandler) {
    fallbackCategory = 0;
    if (code >= 0xE00) {
        fallbackCategory = 1;
        if (code - 0x1000 >= 0x1000) {
            fallbackCategory = 2;
            if (code - 0xE00 >= 0x200) {
                fallbackCategory = 0;
                if (code - 0x4000 < 0x4000) fallbackCategory = 3;
            }
        }
    }
            if (fallbackCategory != 0) return 0;
        switch (code) {
        case 1:
            if ((element->flags & 0x10) && element->linked_id) {
                func_8029973C_de();
                func_80298368_de(element->linked_id);
            }
            break;
        case 2:
            if (D_8014D080->current > 0) func_802998A8_de();
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
    if (!direct) {
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
    fallbackCategory = 0;
    if (code >= 0xE00) {
        fallbackCategory = 1;
        if (code - 0x1000 >= 0x1000) {
            fallbackCategory = 2;
            if (code - 0xE00 >= 0x200) {
                fallbackCategory = 0;
                if (code - 0x4000 < 0x4000) fallbackCategory = 3;
            }
        }
    }
    if (fallbackCategory == 0) {
        switch (code) {
        case 1:
            if ((element->flags & 0x10) && element->linked_id) {
                func_8029973C_de();
                func_80298368_de(element->linked_id);
            }
            break;
        case 2:
            if (D_8014D080->current > 0) func_802998A8_de();
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
s32 func_80297310_de(s32 recurse, s32 event, s32 arg2, s32 arg3, s32 arg4)
{
    ScreenManager *table = D_8014D080;
    ScreenManager *tree;
    Element *element = table->screens[table->current].primary;
    MenuElementHandler handler;
    s32 result = 0;
    s32 saved, handled, treeSaved;
    if (table->callback != 0) {
        saved = table->handled;
        table->handled = 0;
        result = table->callback(event, arg2, arg3, arg4);
        handled = table->handled;
        table->handled = saved;
        if (handled == 1) return result;
    }
    handler = D_8014D080->screens[D_8014D080->current].primary->handler;
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
        if (D_8014D080->current > 0) func_802998A8_de();
        break;
    case 5: case 6: case 7: case 8:
        if (arg3 == 1) func_80296CD0_de(event);
        break;
    case 15: func_8040E928_de(element, 1); break;
    case 16: func_8040E928_de(element, 0); break;
    }
    return 0;
}
#else
INCLUDE_ASM("span_1000", func_80297310_de);
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

void func_8029764C_de(s32 param_1, s32 param_2, s32 param_3, void *param_4, s32 param_5) {
    /* FAKEMATCH: Published void interface discards native callback result. */
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
    struct ScreenManager *table = D_8014D080;
    s32 uVar13 = 0;
    s32 (*pcCallback)(s32, s32, s32, s32);
    MenuElementHandler pcHandler;
    s32 iVar6;
    s32 iVar10;
    s32 *piVar11;
    s32 uVar9;
    s32 local_res8;
    s32 local_48;
    s32 iVar14;
    u32 uVar7;
    int bVar1;
    int bVar2;
    int bVar3;
    Entry_func_802991D4_de *record;
    Element *iVar8;

    pcCallback = table->callback;
    piVar11 = &table->handled;
    if (pcCallback != 0) {
        uVar9 = table->handled;
        table->handled = 0;
        uVar13 = pcCallback(param_2, param_3, (s32)param_4, param_5);
        iVar6 = table->handled;
        table->handled = uVar9;
        if (iVar6 == 1) {
            return;
        }
    }
    local_48 = table->lowIndex;
    iVar6 = table->current;
    if (local_48 <= iVar6) {
        bVar1 = 0xfff < (u32)param_2 - 0x1000;
        bVar2 = 0x1ff < (u32)param_2 - 0xe00;
        bVar3 = (u32)param_2 - 0x4000 < 0x4000;
        iVar14 = local_48 * 0x1c;
        local_res8 = param_3;
        do {
            if (((int)param_2 < 0xe03) && (0xe00 < (int)param_2)) {
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                record = (Entry_func_802991D4_de *)((char *)table->screens + iVar14);
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                local_res8 = (s32)((char *)record + 0xc);
            }
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
            record = (Entry_func_802991D4_de *)((char *)table->screens + iVar14);
            iVar8 = record->primary;
            pcHandler = iVar8->handler;
            if (pcHandler != 0) {
                iVar10 = *piVar11;
                *piVar11 = 0;
                uVar13 = pcHandler(iVar8, param_2, local_res8, (s32)param_4, param_5);
                if (*piVar11 == 1) {
                    *piVar11 = iVar10;
                    return;
                }
                *piVar11 = iVar10;
            }
            if (param_1 != 0) {
                D_80146E18 = record->owner;
                iVar10 = *piVar11;
                *piVar11 = 0;
                if (iVar8 != 0) {
                    uVar9 = table->handled;
                    table->handled = 0;
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                    if (*(s32 *)((char *)iVar8 + 4) != 0) {
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                        func_80299CF0_de(*(struct NodeRecAt12 **)((char *)iVar8 + 4), param_2, local_res8, (s32)param_4,
                                         param_5, 1);
                    }
                    if (table->handled == 0) {
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                        if (*(s32 *)((char *)iVar8 + 8) != 0) {
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                            func_80299CF0_de(*(struct NodeRecAt12 **)((char *)iVar8 + 8), param_2, local_res8,
                                             (s32)param_4, param_5, 1);
                        }
                        table->handled = uVar9;
                    } else {
                        table->handled = uVar9;
                    }
                }
                D_80146E18 = -1;
                if (*piVar11 == 1) {
                    *piVar11 = iVar10;
                    return;
                }
                *piVar11 = iVar10;
            }
            uVar7 = 0;
            if (0xdff < (u32)param_2) {
                uVar7 = 1;
                if (bVar1) {
                    uVar7 = 2;
                    if (bVar2) {
                        uVar7 = 0;
                        if (bVar3) {
                            uVar7 = 3;
                        }
                    }
                }
            }
            if (uVar7 == 0) {
                switch ((u32)param_2 - 1) {
                case 0:
                    if ((iVar8->flags & 0x10) != 0) {
                        if (iVar8->linked_id != 0) {
                            func_8029973C_de();
                            func_80298368_de(iVar8->linked_id);
                        }
                    }
                    break;
                case 1:
                    if (1 <= table->current) {
                        func_802998A8_de();
                    }
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                    if ((s32)param_4 == 1) {
                        func_80296CD0_de(param_2);
                    }
                    break;
                case 0xe:
                    func_8040E928_de(iVar8, 1);
                    break;
                case 0xf:
                    func_8040E928_de(iVar8, 0);
                    break;
                default:
                    break;
                }
            }
            uVar13 = 0;
            iVar14 = iVar14 + 0x1c;
            local_48 = local_48 + 1;
        } while (local_48 <= iVar6);
    }
}
#else
INCLUDE_ASM("span_1000", func_8029764C_de);
#endif
