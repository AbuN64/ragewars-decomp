#include "include_asm.h"
#include "COMMON/ANIMATION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/INTEGERSTATE530.H"
#include "stddef.h"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MENU_2/804196C0_16.H"
#include "FRONTEND/8040B45C_33.H"

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
#include "RENDER_2/8025DE50_5.H"
#include "RESMGR/resmgr_string_memory.H"
extern s32 GraphU64_NextRandom(void);
extern void SmpFlicker_InitFlicker(func_80419D04_S1 *, s32);
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
   if(timer<=0 && GraphU64_NextRandom()%100<2) {
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

s32 GraphU64_NextRandom(void);

/* Allocates and initializes an object, attaches its resource and owner value, then registers it with the resource. */



extern MenuResourceWidget *Cache_AllocateMemory(int);




extern void Frontend_InsertWidgetBefore(ResourceSmpFlickerCreateFlickerWidget *, MenuResourceWidget *);

extern void *Frontend_GetScreenData(s32 index);

extern void SmpFlicker_InitFlicker(func_80419D04_S1 *arg0, s32 arg1);

extern void SmpFlicker_EnableFlicker(MenuResourceWidget *);

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
        flicker->unk48 = (s32) (GraphU64_NextRandom() % 5 + 1);
    }
    for (i = 0; i < flicker->unk48; i++) {
        flicker->unk60[i] = (s32) (GraphU64_NextRandom() % 3 + 1);
        sampleValue = (offset = GraphU64_NextRandom() % 40 + 30, flicker->unk80 - offset) < 0 ? 0 : ((offset = GraphU64_NextRandom() % 40 + 30, flicker->unk80 - offset) >= 0x100 ? 0xFF : (offset = temp = GraphU64_NextRandom() % 40 + 30, flicker->unk80 - offset));
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
  r = Frontend_FindWidgetByResourceId(Frontend_GetScreenData(GetMenuScreenOwner()), arg0 & 65535);
  Frontend_GetScreenData(GetMenuScreenOwner());
  p = Cache_AllocateMemory(0x88);
  XPlus_FillBytes(p, 0, 0x88);
  p->b = (kind = 0xB62);
  p->resource = r;
  p->owner.value = arg1;
  p->c = 8;
  p->a = kind;
  p->resource->value = p->owner.bytes[3];
  SmpFlicker_InitFlicker(p, -1);
  SmpFlicker_EnableFlicker(p);
  Frontend_InsertWidgetBefore(r, p);
  return p;
}
