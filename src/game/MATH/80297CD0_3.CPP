#include "MATH/802A2870.H"
#include "COMMON/FRUSTUM.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/CALLBACK.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/WIDGETRECAT34.H"
#include "stddef.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/8040B45C_35.H"
#include "MATH/80297CD0_3.H"
#include "MATH/math_stream_lifecycle.H"
#include "RESMGR/8029AA48_12.H"
#include "MATH/80297CD0.H"
#include "RESMGR/resmgr_string_memory.H"
#include "MATH/80299ECC.H"
#include "FRONTEND/8040B45C_33.H"

/* Refreshes the selected entry and updates its interface state. */


 /* extern */
                               /* extern */


/* Dispatches a pending menu event and clears its pending state. */


 /* extern */

 /* extern */
int func_80299CC4_de();

 /* extern */


/* Initialises the interface system for a number of screens: resets the input state and display, allocates and clears the 0x544-byte interface state in D_8014D080 with its 64 widget slots, its 900-byte object cache and its screen table, records the screen count, a 4000 limit and the frame duration from func_802A18CC_de, resets the focus and paging fields, and registers fonts 9 and 11. */









extern void *Cache_AllocateMemory(s32 size);


/* Returns the object loaded for an identifier in the current context: reuses a cached entry whose context and identifier match and whose object still carries that identifier, and otherwise loads it through Frontend_FindWidgetByResourceId, counts the load in D_8014D0A0 with its high-water mark in D_8014D09C, and records it while the cache holds fewer than 75 entries. */







void func_80297DBC_de(void) {
    s32 (*temp_v0)(s32);
    s32 current;
    s32 value, param;
    current = D_8014D080->current;
    temp_v0 = D_8014D080->callback2;
    param = D_8014D080->screens[current].owner;
    if (temp_v0 != NULL) {
        value = temp_v0(param);
        ((struct ObjRecAt40V1 *)D_8014D080->screens[current].primary)->unk40 = value;
    }
    DispatchCurrentScreenEvent(1, 0xE06, 0, 0, 0);
    DispatchCurrentScreenEvent(1, 0xE07, 0, 0, 0);
    D_8014D080->screens[current].data.readPosition = 0;
    DispatchCurrentScreenEvent(1, 0xE02, &D_8014D080->screens[current].data, 0, 0);
    StreamBufferFree(&D_8014D080->screens[current].data);
}

int func_80297EA4_de(int arg0) {
 int index,event,result; ObjRecAtCV1 *item; int (*callback)(int,int,int,int);
 index=D_8014D080->current;
 if(index>=0 && D_8014D080->field530) {
 item=(ObjRecAtCV1 *)D_8014D080->screens[index].focus;
 if(item) func_802995D4_de(item->unkC,0x10,0,0,0);
 event=arg0;
 func_80299CC4_de();
 if(D_8014D080->current != -1) {
 callback=D_8014D080->callback;
 if(callback) {
 arg0=D_8014D080->handled;
 D_8014D080->handled=0;
 callback(0xE03,event,0,0);
 result=D_8014D080->handled;
 if(result==1) { D_8014D080->handled=arg0; goto done; }
 D_8014D080->handled=arg0;
 }
 DispatchCurrentScreenEvent(1,0xE03,event,0,0);
 }
 done:
 D_8014D080->field530=0;
 }
 return 1;
}

void func_80297FA0_de(s32 screenCount, s32 value) {
    s32 i;
    f64 frames;

    D_80146E18 = -1;
    func_802A1918_de(&D_80146E08, &D_80146E0C);
    func_80411EEC_de();
    Frontend_SetDisplayClipBounds(D_80146E08, D_80146E0C);
    Smos_AllocateControllerContext();
    g_menuEventCount = 0;
    D_8014D080 = Cache_AllocateMemory(0x544);
    XPlus_FillBytes(D_8014D080, 0, 0x544);
    D_8014D080->callback2 = (s32 (*)(s32))value;
    D_8014D080->limit = 4000;
    {
        struct MenuHandlerEntry *slot = D_8014D080->handlers;
        s32 *ids = &D_8014D080->handlers[0].id;
        for (i = 0; i < 64; slot++, i++, ids += 5) {
            slot->override_handler = 0;
            *ids = -1;
            slot->default_handler = 0;
            slot->draw_handler = 0;
        }
    }
    D_8014D080->cache = Cache_AllocateMemory(0x384);
    XPlus_FillBytes(D_8014D080->cache, 0, 0x384);
    D_8014D080->cacheCount = 0;
    frames = func_802A18CC_de() * D_800C5668_de;
    D_8014D080->screenCount = screenCount;
    D_8014D080->frames = frames;
    D_8014D080->screens = Cache_AllocateMemory(screenCount * 28);
    XPlus_FillBytes(D_8014D080->screens, 0, screenCount * 28);
    D_80146E14 = 0;
    D_8014D080->current = -1;
    D_8014D080->focus = -1;
    D_8014D080->field534 = 0;
    D_8014D080->field538 = 0;
    D_8014D080->paging = 1;
    func_802982C4_de(9, D_0040C5C0, D_0040C5C8, 1);
    func_802982C4_de(11, D_004125A4, D_00412634, 1);
}

Element *FindMenuElement(s32 id) {
    Element *object;
    s32 context;
    s32 i;

    context = (s32)Frontend_GetScreenData(GetMenuScreenOwner());
    for (i = 0; i < D_8014D080->cacheCount; i++) {
        if (D_8014D080->cache[i].context == context && D_8014D080->cache[i].id == id
            && D_8014D080->cache[i].object != 0 && D_8014D080->cache[i].object->id == id) {
            return D_8014D080->cache[i].object;
        }
    }
    object = (Element *)Frontend_FindWidgetByResourceId((struct Tree *)context, id & 0xFFFF);
    D_8014D0A0++;
    if (D_8014D09C < D_8014D0A0) {
        D_8014D09C = D_8014D0A0;
    }
    if (D_8014D080->cacheCount < 75) {
        D_8014D080->cache[D_8014D080->cacheCount].id = id;
        D_8014D080->cache[D_8014D080->cacheCount].object = object;
        D_8014D080->cache[D_8014D080->cacheCount].context = context;
        D_8014D080->cacheCount++;
    }
    return object;
}

/* Registers a widget handler under an identifier, reusing its slot or the first free one, or clears that slot when no handler is given. */
void func_802982C4_de(s32 id, MenuElementHandler arg1, MenuDrawHandler draw_handler, s32 arg3) {
    s32 slot = -1;
    s32 i;

    for (i = 0; i < 64; i++) {
        if (D_8014D080->handlers[i].id == id) {
            slot = i;
            break;
        }
        if (D_8014D080->handlers[i].id == -1 && slot == -1) {
            slot = i;
        }
    }
    if (arg1 != 0) {
        D_8014D080->handlers[slot].id = id;
        D_8014D080->handlers[slot].default_handler = arg1;
        D_8014D080->handlers[slot].draw_handler = draw_handler;
        D_8014D080->handlers[slot].override_handler = 0;
        D_8014D080->handlers[slot].flags = arg3;
    } else {
        D_8014D080->handlers[slot].id = -1;
        D_8014D080->handlers[slot].default_handler = 0;
        D_8014D080->handlers[slot].draw_handler = 0;
        D_8014D080->handlers[slot].override_handler = 0;
    }
}
