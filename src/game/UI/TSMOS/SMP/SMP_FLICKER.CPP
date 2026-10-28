#include "RSP/8026E1F8_5.H"
#include "include_asm.h"
#include "COMMON/FRUSTUM.H"
#include "COMMON/ANIMATION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/INTEGERSTATE530.H"
#include "stddef.h"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "UI/TSMOS/SMP/SMP_FLICKER.H"
#include "FRONTEND/8040B45C_33.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "SCENE/802508E0_13.H"

#if defined(VERSION_US)
#include "COMMON/ANIMATION.H"
#include "TYPES.H"
#include "RENDER/8025DE50_5.H"
/* Per-frame step of a menu widget flicker: while the effect is armed (state 1) the timer counts down to 0 (capped at 50); at 0 a roll below 2 in 100
   starts the flicker (flag set, current entry shown on the widget, sound 0xE75). While flickering each frame spends one hold count of the current
   entry and moves on to the next entry; after the last one the effect is re-rolled and the timer rewinds to 50. Returns 0. */
s32 SmpFlicker_UpdateFlicker(func_80419D04_S1 *flicker) {
 s32 entry,timer,next;
 func_80419D04_S1 *widgetOwner = flicker;
 if(flicker->unk84==1) {
  if(flicker->unk44==0) {
   timer=flicker->unk7C-1<0?0:flicker->unk7C-1>50?50:flicker->unk7C-1;
   widgetOwner->unk7C=timer;
   if(timer<=0 && Graphu64_NextRandom()%100<2) {
    widgetOwner->unk44=1;
    widgetOwner->unk78->value=widgetOwner->unk4C[widgetOwner->unk74];
    SoundElement_PlayFlatSound(0xe75);
   }
  } else {
   flicker->unk78->value=flicker->unk80;
   flicker->unk60[flicker->unk74]--;
   entry=flicker->unk74;
   if(flicker->unk60[entry]<=0 || entry+1>=flicker->unk48) {
    next=entry+1; flicker->unk74=next;
    if(flicker->unk48<=next) {
     SmpFlicker_InitFlicker(flicker,-1);
     flicker->unk78->value=flicker->unk80;
     flicker->unk7C=50;
    } else {
     widgetOwner->unk78->value=widgetOwner->unk4C[next];
     SoundElement_PlayFlatSound(0xe75);
    }
   }
  }
 }
 return 0;
}
#endif

#if defined(VERSION_EU)
#include "COMMON/ANIMATION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/INTEGERSTATE530.H"
#include "stddef.h"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "UI/TSMOS/SMP/SMP_FLICKER.H"
#include "FRONTEND/8040B45C_33.H"
#include "TYPES.H"
#include "RENDER/8025DE50_5.H"
#include "RESMGR/resmgr_string_memory.H"
/* Per-frame step of a menu widget flicker: while the effect is armed (state 1) the timer counts down to 0 (capped at 50); at 0 a roll below 2 in 100
   starts the flicker (flag set, current entry shown on the widget, sound 0xE75). While flickering each frame spends one hold count of the current
   entry and moves on to the next entry; after the last one the effect is re-rolled and the timer rewinds to 50. Returns 0. */
s32 SmpFlicker_UpdateFlicker(func_80419D04_S1 *flicker) {
 s32 entry,timer,next;
 func_80419D04_S1 *widgetOwner = flicker;
 if(flicker->unk84==1) {
  if(flicker->unk44==0) {
   timer=flicker->unk7C-1<0?0:flicker->unk7C-1>50?50:flicker->unk7C-1;
   widgetOwner->unk7C=timer;
   if(timer<=0 && Graphu64_NextRandom()%100<2) {
    widgetOwner->unk44=1;
    widgetOwner->unk78->value=widgetOwner->unk4C[widgetOwner->unk74];
    SoundElement_PlayFlatSound(0xe75);
   }
  } else {
   flicker->unk78->value=flicker->unk80;
   flicker->unk60[flicker->unk74]--;
   entry=flicker->unk74;
   if(flicker->unk60[entry]<=0 || entry+1>=flicker->unk48) {
    next=entry+1; flicker->unk74=next;
    if(flicker->unk48<=next) {
     SmpFlicker_InitFlicker(flicker,-1);
     flicker->unk78->value=flicker->unk80;
     flicker->unk7C=50;
    } else {
     widgetOwner->unk78->value=widgetOwner->unk4C[next];
     SoundElement_PlayFlatSound(0xe75);
    }
   }
  }
 }
 return 0;
}
#endif

#if defined(VERSION_DE)
#include "COMMON/ANIMATION.H"
#include "RENDER/8025DE50_5.H"
/* Per-frame step of a menu widget flicker: while the effect is armed (state 1) the timer counts down to 0 (capped at 50); at 0 a roll below 2 in 100
   starts the flicker (flag set, current entry shown on the widget, sound 0xE75). While flickering each frame spends one hold count of the current
   entry and moves on to the next entry; after the last one the effect is re-rolled and the timer rewinds to 50. Returns 0. */
s32 SmpFlicker_UpdateFlicker(func_80419D04_S1 *flicker) {
 s32 entry,timer,next;
 func_80419D04_S1 *widgetOwner = flicker;
 if(flicker->unk84==1) {
  if(flicker->unk44==0) {
   timer=flicker->unk7C-1<0?0:flicker->unk7C-1>50?50:flicker->unk7C-1;
   widgetOwner->unk7C=timer;
   if(timer<=0 && Graphu64_NextRandom()%100<2) {
    widgetOwner->unk44=1;
    widgetOwner->unk78->value=widgetOwner->unk4C[widgetOwner->unk74];
    SoundElement_PlayFlatSound(0xe75);
   }
  } else {
   flicker->unk78->value=flicker->unk80;
   flicker->unk60[flicker->unk74]--;
   entry=flicker->unk74;
   if(flicker->unk60[entry]<=0 || entry+1>=flicker->unk48) {
    next=entry+1; flicker->unk74=next;
    if(flicker->unk48<=next) {
     SmpFlicker_InitFlicker(flicker,-1);
     flicker->unk78->value=flicker->unk80;
     flicker->unk7C=50;
    } else {
     widgetOwner->unk78->value=widgetOwner->unk4C[next];
     SoundElement_PlayFlatSound(0xe75);
    }
   }
  }
 }
 return 0;
}
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
#include "RENDER/8025DE50_5.H"
#include "RESMGR/resmgr_string_memory.H"
/* Per-frame step of a menu widget flicker: while the effect is armed (state 1) the timer counts down to 0 (capped at 50); at 0 a roll below 2 in 100
   starts the flicker (flag set, current entry shown on the widget, sound 0xE75). While flickering each frame spends one hold count of the current
   entry and moves on to the next entry; after the last one the effect is re-rolled and the timer rewinds to 50. Returns 0. */
s32 SmpFlicker_UpdateFlicker(func_80419D04_S1 *flicker) {
 s32 entry,timer,next;
 func_80419D04_S1 *widgetOwner = flicker;
 if(flicker->unk84==1) {
  if(flicker->unk44==0) {
   timer=flicker->unk7C-1<0?0:flicker->unk7C-1>50?50:flicker->unk7C-1;
   widgetOwner->unk7C=timer;
   if(timer<=0 && Graphu64_NextRandom()%100<2) {
    widgetOwner->unk44=1;
    widgetOwner->unk78->value=widgetOwner->unk4C[widgetOwner->unk74];
    SoundElement_PlayFlatSound(0xe75);
   }
  } else {
   flicker->unk78->value=flicker->unk80;
   flicker->unk60[flicker->unk74]--;
   entry=flicker->unk74;
   if(flicker->unk60[entry]<=0 || entry+1>=flicker->unk48) {
    next=entry+1; flicker->unk74=next;
    if(flicker->unk48<=next) {
     SmpFlicker_InitFlicker(flicker,-1);
     flicker->unk78->value=flicker->unk80;
     flicker->unk7C=50;
    } else {
     widgetOwner->unk78->value=widgetOwner->unk4C[next];
     SoundElement_PlayFlatSound(0xe75);
    }
   }
  }
 }
 return 0;
}
#endif

s32 Graphu64_NextRandom(void);

/* Allocates and initializes an object, attaches its resource and owner value, then registers it with the resource. */



extern MenuResourceWidget *Cache_AllocateMemory(int);




extern void Node_InsertWidgetBefore(ResourceSmpFlickerCreateFlickerWidget *, MenuResourceWidget *);


void SmpFlicker_InitFlicker(func_80419D04_S1 *flicker, s32 sampleCount);

void SmpFlicker_EnableFlicker(struct StateBlock *object);

/* Initializes a flicker effect and randomizes each element's intensity. */
void SmpFlicker_InitFlicker(func_80419D04_S1 *flicker, s32 sampleCount) {
    s32 i;
    s32 sampleValue;
    s32 offset;
    int temp;
    flicker->unk44 = 0;
    flicker->unk74 = 0;
    if (sampleCount > 0) {
        flicker->unk48 = sampleCount;
    } else {
        flicker->unk48 = (s32) (Graphu64_NextRandom() % 5 + 1);
    }
    for (i = 0; i < flicker->unk48; i++) {
        flicker->unk60[i] = (s32) (Graphu64_NextRandom() % 3 + 1);
        sampleValue = (offset = Graphu64_NextRandom() % 40 + 30, flicker->unk80 - offset) < 0 ? 0 : ((offset = Graphu64_NextRandom() % 40 + 30, flicker->unk80 - offset) >= 0x100 ? 0xFF : (offset = temp = Graphu64_NextRandom() % 40 + 30, flicker->unk80 - offset));
        flicker->unk4C[i] = sampleValue;
    }
}

void SmpFlicker_RegisterFlickerClass(void) {
    SmSmngr_RegisterElementHandlers(0xB62, D_00419F9C, D_0041A02C, 3);
}

MenuResourceWidget *SmpFlicker_CreateFlickerWidget(int arg0, int arg1)
{
  ResourceSmpFlickerCreateFlickerWidget *r;
  MenuResourceWidget *p;
  int kind;
  r = Node_FindWidgetByResourceId(Node_GetScreenData(GetMenuScreenOwner()), arg0 & 65535);
  Node_GetScreenData(GetMenuScreenOwner());
  p = Cache_AllocateMemory(0x88);
  XPlus_FillBytes(p, 0, 0x88);
  p->b = (kind = 0xB62);
  p->resource = r;
  p->owner.value = arg1;
  p->c = 8;
  p->a = kind;
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  /* The low byte of the owner word sits at its address on a little-endian host, not 3 bytes in. */
  p->resource->value = p->owner.bytes[0];
#else
  p->resource->value = p->owner.bytes[3];
#endif
  SmpFlicker_InitFlicker(p, -1);
  SmpFlicker_EnableFlicker(p);
  Node_InsertWidgetBefore(r, p);
  return p;
}

/* Calls func_80419C84_de on an object, marks it busy at offset 0x44 and copies the low byte of the
   current entry of the word array at 0x4C, selected by the index at 0x74, into offset 0x10 of the
   object at 0x78. */





/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3330, an actor kind at D_800E3334 and a handler at D_800E3338: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */






/* Calls Cache_FreeMemory with the arguments it was given and returns zero. */

/* Sets the word at offset 0x84 of an object to one. */


void SmpFlicker_EnableFlicker(struct StateBlock *object) {
    object->unk84 = 1;
}

/* Copies the byte at offset 0x83 of an object into offset 0x10 of the object at 0x78, and clears
   the pending word at 0x84 that SmpFlicker_EnableFlicker sets and SmpFlicker_IsFlickerIdle tests. */




void SmpFlicker_RestoreFlickerValue(struct SourceRecAt84 *source) {
    struct ResourceSmpFlickerCreateFlickerWidget *target = source->target;
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    /* value is the low byte of the word at 0x80, which a little-endian host holds at 0x80. */
    u8 value = *((u8 *) source + 0x80);
#else
    u8 value = source->value;
#endif

    source->pending = 0;
    target->value = value;
}

/* Returns one when nothing is pending at offset 0x84 of an object, and otherwise whether the word
   at offset 0x44 is zero; SmpFlicker_EnableFlicker sets the pending word and SmpFlicker_RestoreFlickerValue clears it. */


s32 SmpFlicker_IsFlickerIdle(struct ObjectRecAt84 *object) {
    if (object->pending == 0) {
        return 1;
    }
    return object->busy == 0;
}

void SmpFlicker_StartFlicker(struct ObjectCode804196C0 *object, s32 count) {
    SmpFlicker_InitFlicker(object, count);
    object->busy = 1;
    object->target->value = object->entries[object->index];
}

s32 SmpFlicker_DispatchEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3338 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3338;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3330)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3334)) + offset))->field_0;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler802A2B50 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            offset += 0xC;
        } while (*(Handler802A2B50 *)entry != 0);
    }
    return 0;
}

/* Does nothing: an unreferenced empty stub whose only code stores the argument registers a1 to a3
   to their home stack slots. */


void SmpFlicker_IgnoreEvent(s32 unused0, struct Triple unused1) {
}

s32 SmpFlicker_DestroyController(void *arg0) {
    Cache_FreeMemory(arg0);
    return 0;
}
