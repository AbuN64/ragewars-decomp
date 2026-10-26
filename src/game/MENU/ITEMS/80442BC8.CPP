#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "MENU/OBJECT1C8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/OBJECTLINKSC_2.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_8.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "MENU/ITEMS/80442BC8.H"
#include "SYSTEM/80255C40_7.H"
#include "GFX/TEXT/802A8A94_5.H"

/* Removes every item from a list until its head is null, running each item's optional callback, clearing three words of its state, unlinking it through func_80255ED8_de and releasing its resource through Cache_ReleaseResource. Adapted from func_8044334C_de with its body wrapped as an inline helper called in a loop over the list head changed. */










static inline void remove_item(struct List_func_80442A60_de *list, struct ItemRecAt20V2 *item) {
    struct StateRecAtBCV2 *state;

    if (item->handlers->callback != 0) {
        item->handlers->callback(item, list);
    }
    state = item->state;
    state->a = 0;
    state->b = 0;
    state->c = 0;
    func_80255ED8_de(list, item);
    Cache_ReleaseResource(0, item->resource);
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

/* Hands Pak_MeasureLine a target and the scale twice: the target is what func_8043F290 returns for
   an object of kind 5, otherwise the word the pointer at offset 0x14 addresses. */


#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void * func_8043F290(struct ObjectRecAt14 *);
#else
extern void * func_8043F114_de(struct ObjectRecAt14 *);
#endif

extern void Pak_MeasureLine(void *, f32, f32);

/* Draws a pulsing sprite for an active menu element: when the word at 0x1CC is set, it takes the frame at 0x1C8 folded back after 23, sets up drawing through OnScreen_SetupTextRendering and Geometry_SetModePreset, emits a yellow environment and primitive colour to the display list and draws sprite 0x67 at the owner's rectangle scaled to the screen through OnScreen_DrawSpriteResource. Adapted from func_8022C2B4_de. */



extern void Geometry_SetModePreset(s32);

/* Selects the descriptor for a single masked category bit; on eu and eu-x the slot is
   additionally offset by nine descriptors per local player, read from the byte after D_80146848. */

extern char D_800E1E24_de[];


/* Steps a pointer back 0x554 bytes: callers pass the pointer held at offset 0x44 of an object and
   get back the start of the structure whose member at offset 0x554 it addresses. */
void *Pak_GetListContext(s8 *member) {
    return member - 0x554;
}

void func_80442A60_de(struct List_func_80442A60_de *list) {
    struct ItemRecAt20V2 *item;

loop:
    item = list->head;
    if (item != 0) {
        remove_item(list, item);
        goto loop;
    }
}

void func_80442ADC_de(struct ObjectRecAt14 *object, f32 scale) {
    void *target;

    if (object->kind == 5) {
        target = 
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_8043F290
#else
func_8043F114_de
#endif
(object);
    } else {
        
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        target = object->target[g_languageIndex];
#else
        target = *object->target;
#endif
    }
    Pak_MeasureLine(target, scale, scale);
}

/* Clears the two words at offsets 0x1C8 and 0x1CC of an object; func_80442B40_de, which follows it,
   tests the word at 0x1CC. */


void Pak_StopMenuPulse(struct Object1C8 *object) {
    object->second = 0;
    object->first = 0;
}

/* Starts a one-shot state: when the word at offset 0x1CC is clear it sets it and clears the word
   at 0x1C8; func_80442B34_de clears both. */


void Pak_StartMenuPulse(struct Object1C8 *object) {
    if (object->second == 0) {
        object->second = 1;
        object->first = 0;
    }
}

/* Advances the counter at offset 0x1C8 of an object by the step at 0x1CC and clears both once
   the counter reaches 0x30. */


void Pak_StepSpriteFrame(struct Object1C8 *object) {
    object->first += object->second;
    if (object->first >= 0x30) {
        object->first = 0;
        object->second = 0;
    }
}

/* Folds the counter at offset 0x1C8 of an object into a triangle wave: values below 0x18 are
   returned as they are and the rest as 0x2F less the value. */


s32 func_80442B88_de(struct ObjectRecAt1C8 *object) {
    s32 count = object->count;

    if (count < 0x18) {
        return count;
    }
    return 0x2F - count;
}

void func_80442BA8_de(MenuSpriteElement *e) {
    s32 frame;
    Gfx *gfx;
    Shared_HudView *o;
    f32 w;
    f32 h;

    if (e->active != 0) {
        if (e->frame < 0x18) {
            frame = e->frame;
        } else {
            frame = 0x2F - e->frame;
        }
        OnScreen_SetupTextRendering();
        Geometry_SetModePreset(0x15);
        o = e->owner;
        gfx = g_displayListCursor++;
        w = o->width;
        h = o->height;
        gDPSetEnvColor(gfx, 255, 0, 0, 255);
        gfx = g_displayListCursor++;
        gDPSetPrimColor(gfx, 0, 0, 224, 0, 0, 255);
        OnScreen_DrawSpriteResource(0x67, frame, e->owner->x, e->owner->y,
                      w / (f32)D_800E28D0 * 5.0f, h / (f32)D_800E28D4 * 4.0f, 1);
    }
}

/* Returns 0x480 when the halfword a record starts with is 3, otherwise zero. */
s32 func_80442CD8_de(s16 *record) {
    if (*record == 3) {
        return 0x480;
    }
    return 0;
}

/* Sets the word at offset 0x478 of the second argument when the halfword the first starts with
   is 3. */


void func_80442CF4_de(s16 *record, struct ObjectRecAt478 *object) {
    if (*record == 3) {
        object->flag = 1;
    }
}

/* Initializes a widget from its descriptor and reserves extra state for type three widgets. */





void func_80442D10_de(CMenuItem *w, WidgetDescriptor *d, char **arena, int id, int arg) {
 int size; char *extra;
 w->id=id; w->type=d->type; w->flags=d->flags|0x1800000;
 w->x=d->x; w->y=d->y; w->r=d->r; w->g=d->g; w->b=d->b; w->a=d->a;
 w->value=d->value; w->desc=d; w->index=-1; w->m_pMenu=arg;
 size=0; if(d->type==3) size=0x480;
 if(size) {
 w->extra=*arena;
 extra=*arena; if(d->type==3) ((struct ObjectRecAt478 *)(extra))->flag=1;
 { int step=0; if(d->type==3) step=0x480;
 *arena+=step; }
 }
}

void *Pak_GetWidgetStyle(ObjRecAt8V4 *arg0) {
 s32 index=0;
 switch(arg0->flags & 0x3fe0) {
 case 0x20: break;
 case 0x40: index=1; break;
 case 0x80: index=2; break;
 case 0x100: index=3; break;
 case 0x200: index=4; break;
 case 0x400: index=5; break;
 case 0x800: index=6; break;
 case 0x1000: index=7; break;
 case 0x2000: index=8; break;
 default: index=0; break;
 }
#if defined(VERSION_EU) || defined(VERSION_EU_X)
 index += (&D_80146848)[1] * 9;
#endif
 return D_800E1E24_de+index*28;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DD344[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E9ED4[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EED14[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DE694[1] = {
    0x00000000,
};
#endif
