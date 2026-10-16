#include "span_1000/code_80296014.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_80299DB4.h"
#include "span_16E000/code_8040C780.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_80411B68.h"
#include "stddef.h"
#include "TYPES.H"
#include "common/unused.h"

/* Refreshes the selected entry and updates its interface state. */


 /* extern */
                               /* extern */


/* Dispatches a pending menu event and clears its pending state. */


 /* extern */
int func_802995D4_de(s16, int, int, int, s32);

 /* extern */
int func_80299CC4_de();

 /* extern */


/* Initialises the interface system for a number of screens: resets the input state and display, allocates and clears the 0x544-byte interface state in D_8014D080 with its 64 widget slots, its 900-byte object cache and its screen table, records the screen count, a 4000 limit and the frame duration from func_802A18CC_de, resets the focus and paging fields, and registers fonts 9 and 11. */









extern void *func_8025305C_de(s32 size);

extern void func_802A0748_de(void *buffer, s32 value, s32 size);

extern f64 func_802A18CC_de(void);

/* Returns the object loaded for an identifier in the current context: reuses a cached entry whose context and identifier match and whose object still carries that identifier, and otherwise loads it through func_8040EC30_de, counts the load in D_8014D0A0 with its high-water mark in D_8014D09C, and records it while the cache holds fewer than 75 entries. */






extern struct Tree *func_8040EC30_de(struct Tree *context, u16 id);

void func_80297DBC_de(void) {
    void func_80297310_de(s32, s32, void *, s32, s32);
    extern State_func_80297DBC_de *D_8014D080;
    s32 (*temp_v0)(s32);
    s32 temp_s0;
    s32 value, param;
    temp_s0 = D_8014D080->unk4;
    temp_v0 = D_8014D080->unk10;
    param = (&D_8014D080->unkC[temp_s0])->unk4;
    if (temp_v0 != NULL) {
        value = temp_v0(param);
        (&D_8014D080->unkC[temp_s0])->unk0->unk40 = value;
    }
    func_80297310_de(1, 0xE06, 0, 0, 0);
    func_80297310_de(1, 0xE07, 0, 0, 0);
    (&D_8014D080->unkC[temp_s0])->unkC.readPosition = 0;
    func_80297310_de(1, 0xE02, &D_8014D080->unkC[temp_s0].unkC, 0, 0);
    func_80299C80_de(&D_8014D080->unkC[temp_s0].unkC);
}

int func_80297EA4_de(int arg0) {
    int func_80297310_de(int, int, s32, int, s32);
    extern State_func_80297EA4_de *D_8014D080;
 int index,event,result; ObjRecAtCV1 *item; int (*callback)(int,int,int,int);
 index=D_8014D080->unk4;
 if(index>=0 && D_8014D080->unk530) {
 item=D_8014D080->unkC[index].unk8;
 if(item) func_802995D4_de(item->unkC,0x10,0,0,0);
 event=arg0;
 func_80299CC4_de();
 if(D_8014D080->unk4 != -1) {
 callback=D_8014D080->unk0;
 if(callback) {
 arg0=D_8014D080->unk520;
 D_8014D080->unk520=0;
 callback(0xE03,event,0,0);
 result=D_8014D080->unk520;
 if(result==1) { D_8014D080->unk520=arg0; goto done; }
 D_8014D080->unk520=arg0;
 }
 func_80297310_de(1,0xE03,event,0,0);
 }
 done:
 D_8014D080->unk530=0;
 }
 return 1;
}

void func_80297FA0_de(s32 screenCount, s32 value) {
    extern ScreenManager *D_8014D080;
    s32 i;
    f64 frames;

    D_80146E18 = -1;
    func_802A1918_de(&D_80146E08, &D_80146E0C);
    func_80411EEC_de();
    func_8040F534_de(D_80146E08, D_80146E0C);
    func_8029AA78_de();
    D_80146E04 = 0;
    D_8014D080 = func_8025305C_de(0x544);
    func_802A0748_de(D_8014D080, 0, 0x544);
    D_8014D080->value = value;
    D_8014D080->limit = 4000;
    {
        Rec_func_8024C92C_de *slot = D_8014D080->slots;
        s32 *ids = &D_8014D080->slots[0].x;
        for (i = 0; i < 64; slot++, i++, ids += 5) {
            slot->z = 0;
            *ids = -1;
            slot->y = 0;
            slot->pad0 = 0;
        }
    }
    D_8014D080->cache = func_8025305C_de(0x384);
    func_802A0748_de(D_8014D080->cache, 0, 0x384);
    D_8014D080->cacheCount = 0;
    frames = func_802A18CC_de() * D_800C5668_de;
    D_8014D080->screenCount = screenCount;
    D_8014D080->frames = frames;
    D_8014D080->screens = func_8025305C_de(screenCount * 28);
    func_802A0748_de(D_8014D080->screens, 0, screenCount * 28);
    D_80146E14 = 0;
    D_8014D080->current = -1;
    D_8014D080->focus = -1;
    D_8014D080->field534 = 0;
    D_8014D080->field538 = 0;
    D_8014D080->paging = 1;
    func_802982C4_de(9, D_0040C5C0, D_0040C5C8, 1);
    func_802982C4_de(11, D_004125A4, D_00412634, 1);
}

Element *func_80298170_de(s32 id) {
    extern s32 D_8014D080;
    Element *object;
    s32 context;
    s32 i;

    context = (s32)func_80411DCC_de(func_80299958_de());
    for (i = 0; i < ((CacheRecAt540 *)D_8014D080)->count; i++) {
        if (((CacheRecAt540 *)D_8014D080)->entries[i].context == context && ((CacheRecAt540 *)D_8014D080)->entries[i].id == id
            && ((CacheRecAt540 *)D_8014D080)->entries[i].object != 0 && ((CacheRecAt540 *)D_8014D080)->entries[i].object->id == id) {
            return ((CacheRecAt540 *)D_8014D080)->entries[i].object;
        }
    }
    object = (Element *)func_8040EC30_de((struct Tree *)context, id & 0xFFFF);
    D_8014D0A0++;
    if (D_8014D09C < D_8014D0A0) {
        D_8014D09C = D_8014D0A0;
    }
    if (((CacheRecAt540 *)D_8014D080)->count < 75) {
        ((CacheRecAt540 *)D_8014D080)->entries[((CacheRecAt540 *)D_8014D080)->count].id = id;
        ((CacheRecAt540 *)D_8014D080)->entries[((CacheRecAt540 *)D_8014D080)->count].object = object;
        ((CacheRecAt540 *)D_8014D080)->entries[((CacheRecAt540 *)D_8014D080)->count].context = context;
        ((CacheRecAt540 *)D_8014D080)->count++;
    }
    return object;
}

/* Registers a widget handler under an identifier, reusing its slot or the first free one, or clears that slot when no handler is given. */
void func_802982C4_de(s32 id, MenuElementHandler arg1, MenuDrawHandler draw_handler, s32 arg3) {
    extern MenuHandlerTable *D_8014D080;
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
