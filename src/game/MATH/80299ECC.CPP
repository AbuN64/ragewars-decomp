#include "MATH/802A2870.H"
#include "COMMON/FRUSTUM.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/CALLBACK.H"
#include "COMMON/RECORD.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/WIDGETRECAT34.H"
#include "TYPES.H"
#include "COMMON/REQUESTRECAT10.H"
#include "FRONTEND/8040B45C_32.H"
#include "FRONTEND/8040B45C_35.H"
#include "MATH/80297CD0.H"
#include "MATH/math_stream_lifecycle.H"
#include "RESMGR/8029AA48_12.H"
#include "RESMGR/802A23A4_9.H"
#include "SCENE/802508E0_13.H"
#include "MATH/80299ECC.H"

extern void func_80297EA4_de(s32 arg0);

extern void func_80411E18_de(s16 arg0);



extern void func_8040E67C_de(void *, ArgsCode80296014);

extern s32 Frontend_ComputeWidgetBounds(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *, void *, ArgsCode80296014 *);

/* Moves menu focus and sends leave and enter events through menu and element callbacks. */










extern Element *FindMenuElement(s32 id);
static inline s32 send_event(s32 value, s32 event, s32 arg2, s32 amount, s32 context) {
    ScreenManager *manager;
    s32 locked;
    s32 index;
    s32 minusOne;
    s32 saved;
    s32 result;

    if (Frontend_IsValidScreenIndex(value) != 0) {
        if (value != D_8014D080->screens[D_8014D080->current].owner) {
            return 0;
        }
    }
    manager = D_8014D080;
    locked = manager->focus;
    index = manager->current;
    minusOne = -1;
    if ((value == locked) || (index == minusOne)) {
        return 0;
    }
    if (D_8014D080->callback != 0) {
        saved = D_8014D080->handled;
        D_8014D080->handled = 0;
        result = D_8014D080->callback(event, arg2, amount, context);
        if (D_8014D080->handled == 1) {
            D_8014D080->handled = saved;
            return result;
        }
        D_8014D080->handled = saved;
    }
    if (value == D_8014D080->screens[D_8014D080->current].primary->id) {
        result = func_80297A34_de(event, arg2, amount, context);
    } else {
        result = DispatchElementEvent(value, event, arg2, amount, context);
    }
    return result;
}

                                                              






typedef s32 (*FuncPtr)(s32, s32, s32, s32);


                                                             






/** Mark the global object's field at offset 0x520. */


s32 func_80298368_de(s32);


void func_80298ECC_de(void) {
    s32 index;

    if (D_8014D080->screens[D_8014D080->current].primary != 0) {
        func_80297EA4_de(D_8014D080->screens[D_8014D080->current - 1].owner);
        StreamBufferFree(&D_8014D080->screens[D_8014D080->current].data);
        {
            Element *element = D_8014D080->screens[D_8014D080->current].primary;
            func_80411E18_de(element->id);
        }
    }
    D_8014D080->screens[D_8014D080->current].primary = 0;
    D_8014D080->screens[D_8014D080->current].owner = 0;
    D_8014D080->screens[D_8014D080->current].focus = 0;
    index = D_8014D080->current - 1;
    D_8014D080->current = index;
    if (index < D_8014D080->lowIndex) {
        D_8014D080->lowIndex = index;
    }
}

void func_80298FE8_de(void) {
    ArgsCode80296014 args;
    Quad_func_802A1BE0_de first;
    Quad_func_802A1BE0_de basis;
    s32 delta;
    s32 index;
    s32 offset;
    s32 now;

    args.word0 = D_8014D080->field534;
    args.word4 = D_8014D080->field538;
    args.byte14 = 0xFF;
    args.word8 = 0;
    args.wordC = D_800C5678_de;
    args.word10 = D_800C5678_de;
    args.word18 = D_8014D080->field534;
    g_menuEventCount = 0;
    args.word20 = D_8014D080->field538;
    args.word1C = D_80146E08 - 1;
    args.word24 = D_80146E0C - 1;

    now = (s32)(func_802A18CC_de() * D_800C5680_de);
    if (s_smackFormat == 0) {
        s_smackFormat = now;
    }
    delta = now - s_smackFormat;
    s_smackFormat = now;
    DispatchScreenRangeEvent(0, 0xE0A, 0, &args, delta);

    index = D_8014D080->lowIndex;
    if (D_8014D080->current >= index) {
        offset = index * 0x1C;
        do {
            index++;
            func_802A18F4_de();
            func_8040E67C_de(*(void **)(offset + (s32)D_8014D080->screens), args);
            func_8040E894_de();
            func_802A18FC_de();
            Frontend_ComputeWidgetBounds(&first, &basis,
                          *(void **)(offset + (s32)D_8014D080->screens), &args);
            offset += 0x1C;
        } while (D_8014D080->current >= index);
    }
    DispatchScreenRangeEvent(0, 0xE0A, 1, 0, delta);
    D_8014D0A0 = 0;
}

void func_802991D4_de(s32 id) {
    Element *previous;

    if (FindKindHandler(FindMenuElement(id)->kind) == 0) {
        return;
    }
    previous = D_8014D080->screens[D_8014D080->current].focus;
    if (previous != 0) {
        send_event(previous->id, 0x10,0,0,0);
    }
    D_8014D080->screens[D_8014D080->current].focus = FindMenuElement(id);
    send_event(id, 0xF,0,0,0);
}

void func_80299468_de(void) {
    ScreenManager *manager;
    s32 lowIndex;
    s32 one;

    manager = D_8014D080;
    lowIndex = manager->lowIndex;
    if (manager->current >= lowIndex) {
        one = 1;
        do {
            manager->field530 = one;
            func_80298ECC_de();
            manager = D_8014D080;
        } while (manager->current >= lowIndex);
    }
    if (D_8014D080->callback != 0) {
        D_8014D080->callback(0xE05, 0, 0, 0);
    }
    if (D_8014D080->cache != 0) {
        Cache_FreeMemory(D_8014D080->cache);
    }
    Cache_FreeMemory(D_8014D080->screens);
    Cache_FreeMemory(D_8014D080);
    D_8014D080 = 0;
    func_8029AAAC_de();
    func_8040F568_de();
    func_80411F28_de();
}

void func_80299550_de(FuncPtr arg0) {
    D_8014D080->callback = arg0;
    if (arg0 != 0) {
        arg0(0xE04, 0, 0, 0);
    }
}

void func_8029958C_de(s32 arg0) {
    if (arg0 != 0) {
        D_8014D080->paging = (s32) (D_8014D080->paging | 1);
        return;
    }
    D_8014D080->paging = (s32) (D_8014D080->paging & ~1);
}

void func_802995C4_de(int arg0) {
    D_80146E14 = arg0;
}

s32 func_802995D4_de(s32 value, s32 arg1, s32 arg2, s32 control, s32 extra) {
    ScreenManager *manager;
    s32 blockedValue;
    s32 index;
    s32 minusOne;
    s32 saved;
    s32 result;
    Element *element;

    if (Frontend_IsValidScreenIndex(value) != 0) {
        if (value != D_8014D080->screens[D_8014D080->current].owner) {
            return 0;
        }
    }
    manager = D_8014D080;
    blockedValue = manager->focus;
    index = manager->current;
    minusOne = -1;
    if ((value == blockedValue) || (index == minusOne)) {
        return 0;
    }
    if (D_8014D080->callback != 0) {
        saved = D_8014D080->handled;
        D_8014D080->handled = 0;
        result = D_8014D080->callback(arg1, arg2, control, extra);
        if (D_8014D080->handled == 1) {
            D_8014D080->handled = saved;
            return result;
        }
        D_8014D080->handled = saved;
    }
    element = D_8014D080->screens[D_8014D080->current].primary;
    if (value == element->id) {
        result = func_80297A34_de(arg1, arg2, control, extra);
    } else {
        result = DispatchElementEvent(value, arg1, arg2, control, extra);
    }
    return result;
}

void MarkMenuEventHandled(void) {
    ScreenManager *object = D_8014D080;
    object->handled = 1;
}

void func_80299750_de(s32 arg0, s32 arg1) {
    ((ObjRecAt40V1 *)FindMenuElement(arg0))->unk40 = arg1;
}

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

/* The twenty-byte table owns callable values at +4 and +8. The override
 * takes precedence; an absent identifier yields no handler. */
MenuElementHandler FindKindHandler(s32 id)
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

s32 func_80299838_de(s32 arg0)
{
  s32 count;
  struct MenuHandlerEntry *ptr;
  count = 0;
  ptr = D_8014D080->handlers;
  loop:
  if ((ptr->id) != arg0)
  {
    goto not_found;
  }

  return ptr->flags;
  not_found:
  count += 1;

  ptr += 1;
  if (count < 0x40)
  {
    if (ptr)
    {
      goto loop;
    }
    else
    {
      goto loop;
    }
  }
  return 0;
}

void func_80299874_de(s32 arg0, s32 arg1) {
    s32 i;
    struct MenuHandlerEntry *var_v1;
    i = 0;
    var_v1 = D_8014D080->handlers;
    do {
        if (var_v1->id == arg0) {
            var_v1->flags = arg1;
        }
        i += 1;
        var_v1++;
    } while (i < 0x40);
}

void func_802998A8_de(void) {
    if (D_8014D080->current > 0) {
        func_80298368_de(func_802999A0_de(0));
    }
}

s32 func_802998E0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    Element *element = arg0;
    MenuElementHandler handler;

    handler = FindKindHandler(element->kind);
    if (handler != 0) {
        return handler(arg0, arg1, arg2, arg3, arg4);
    }
    return 0;
}

s32 GetMenuScreenOwner(void) {
    s32 result;
    s32 field4;
    result = D_80146E18;
    if (result < 0) {
        field4 = D_8014D080->current;
        if (field4 < 0) {
            return -1;
        }
        result = D_8014D080->screens[field4].owner;
    }
    return result;
}

s32 func_802999A0_de(s32 arg0) {
    s32 idx;
    s32 countMinus1;
    countMinus1 = D_8014D080->current - 1;
    idx = countMinus1 - arg0;
    if (idx >= 0) {
        return D_8014D080->screens[idx].owner;
    }
    return -1;
}

/** Return one greater than the current object's word at offset four. */
unsigned int func_802999E0_de(void) {
    return D_8014D080->current + 1;
}

/** Return the word at offset 0x528 of the current global object. */
unsigned int func_802999F4_de(void) {
    return D_8014D080->focus;
}

s16 func_80299A08_de(void) {
    Element *ptr;
    ptr = D_8014D080->screens[D_8014D080->current].focus;
    if (ptr != 0) {
        return ptr->id;
    }
    return -1;
}
