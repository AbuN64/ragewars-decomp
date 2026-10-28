#include "MATH/N64_ENG.H"
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
#include "FRONTEND/FRONTEND_OPENRESOURCEARCHIVE.H"
#include "MATH/SMSMNGR_INITIALIZESCREENMANAGER.H"
#include "RESMGR/STREAM.H"
#include "MATH/math_controller_events.H"
#include "MATH/SM_SMNGR.H"
#include "RESMGR/resmgr_string_memory.H"
#include "MATH/MENU.H"
#include "FRONTEND/NODE_FINDWIDGETBYRESOURCEID.H"

/* Refreshes the selected entry and updates its interface state. */


 /* extern */
                               /* extern */


/* Dispatches a pending menu event and clears its pending state. */


 /* extern */

 /* extern */
void Stream_DrainResourceWork(void);

 /* extern */


/* Initialises the interface system for a number of screens: resets the input state and display, allocates and clears the 0x544-byte interface state in D_8014D080 with its 64 widget slots, its 900-byte object cache and its screen table, records the screen count, a 4000 limit and the frame duration from N64Eng_GetTimeSeconds, resets the focus and paging fields, and registers fonts 9 and 11. */









extern void *Cache_AllocateMemory(s32 size);


/* Returns the object loaded for an identifier in the current context: reuses a cached entry whose context and identifier match and whose object still carries that identifier, and otherwise loads it through Node_FindWidgetByResourceId, counts the load in g_menuElementLoadCount with its high-water mark in g_menuElementLoadPeak, and records it while the cache holds fewer than 75 entries. */







void SmSmngr_InitializeCurrentScreen(void) {
    s32 (*callback2Value)(s32);
    s32 current;
    s32 value, param;
    current = D_8014D080->current;
    callback2Value = D_8014D080->callback2;
    param = D_8014D080->screens[current].owner;
    if (callback2Value != NULL) {
        value = callback2Value(param);
        ((struct ObjRecAt40V1 *)D_8014D080->screens[current].primary)->unk40 = value;
    }
    DispatchCurrentScreenEvent(1, 0xE06, 0, 0, 0);
    DispatchCurrentScreenEvent(1, 0xE07, 0, 0, 0);
    D_8014D080->screens[current].data.readPosition = 0;
    DispatchCurrentScreenEvent(1, 0xE02, &D_8014D080->screens[current].data, 0, 0);
    StreamBufferFree(&D_8014D080->screens[current].data);
}

int SmSmngr_DeactivateCurrentScreen(int arg0) {
 int index,event,result; ObjRecAtCV1 *item; int (*callback)(int,int,int,int);
 index=D_8014D080->current;
 if(index>=0 && D_8014D080->field530) {
 item=(ObjRecAtCV1 *)D_8014D080->screens[index].focus;
 if(item) Menu_RouteElementEvent(item->unkC,0x10,0,0,0);
 event=arg0;
 Stream_DrainResourceWork();
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

void SmSmngr_InitializeScreenManager(s32 screenCount, s32 value) {
    s32 i;
    f64 frames;

    g_dispatchingScreenOwner = -1;
    N64Eng_GetScreenSize(&g_screenDrawWidth, &g_screenDrawHeight);
    Node_InitializeResourceState();
    Node_SetDisplayClipBounds(g_screenDrawWidth, g_screenDrawHeight);
    Controller_AllocateControllerContext();
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
    frames = N64Eng_GetTimeSeconds() * D_800C5668_de;
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
    SmSmngr_RegisterElementHandlers(9, D_0040C5C0, D_0040C5C8, 1);
    SmSmngr_RegisterElementHandlers(11, D_004125A4, D_00412634, 1);
}

Element *FindMenuElement(s32 id) {
    Element *object;
    s32 context;
    s32 i;

    context = (s32)Node_GetScreenData(GetMenuScreenOwner());
    for (i = 0; i < D_8014D080->cacheCount; i++) {
        if (D_8014D080->cache[i].context == context && D_8014D080->cache[i].id == id
            && D_8014D080->cache[i].object != 0 && D_8014D080->cache[i].object->id == id) {
            return D_8014D080->cache[i].object;
        }
    }
    object = (Element *)Node_FindWidgetByResourceId((struct Tree *)context, id & 0xFFFF);
    g_menuElementLoadCount++;
    if (g_menuElementLoadPeak < g_menuElementLoadCount) {
        g_menuElementLoadPeak = g_menuElementLoadCount;
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
void SmSmngr_RegisterElementHandlers(s32 id, MenuElementHandler arg1, MenuDrawHandler draw_handler, s32 arg3) {
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
