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
extern s32 func_802744D4_de(void);
extern void func_80419C84_de(func_80419D04_S1 *, s32);
/* Per-frame step of a menu widget flicker: while the effect is armed (state 1) the timer counts down to 0 (capped at 50); at 0 a roll below 2 in 100
   starts the flicker (flag set, current entry shown on the widget, sound 0xE75). While flickering each frame spends one hold count of the current
   entry and moves on to the next entry; after the last one the effect is re-rolled and the timer rewinds to 50. Returns 0. */
s32 Menu_UpdateFlicker(func_80419D04_S1 *flicker) {
 s32 entry,timer,next;
 func_80419D04_S1 *widgetOwner = flicker;
 if(flicker->unk84==1) {
  if(flicker->unk44==0) {
   timer=flicker->unk7C-1<0?0:flicker->unk7C-1>50?50:flicker->unk7C-1;
   widgetOwner->unk7C=timer;
   if(timer<=0 && func_802744D4_de()%100<2) {
    widgetOwner->unk44=1;
    widgetOwner->unk78->value=widgetOwner->unk4C[widgetOwner->unk74];
    func_8025DF34_de(0xe75);
   }
  } else {
   flicker->unk78->value=flicker->unk80;
   flicker->unk60[flicker->unk74]--;
   entry=flicker->unk74;
   if(flicker->unk60[entry]<=0 || entry+1>=flicker->unk48) {
    next=entry+1; flicker->unk74=next;
    if(flicker->unk48<=next) {
     func_80419C84_de(flicker,-1);
     flicker->unk78->value=flicker->unk80;
     flicker->unk7C=50;
    } else {
     widgetOwner->unk78->value=widgetOwner->unk4C[next];
     func_8025DF34_de(0xe75);
    }
   }
  }
 }
 return 0;
}
#endif

s32 func_802744D4_de(void);

/* Allocates and initializes an object, attaches its resource and owner value, then registers it with the resource. */



extern MenuResourceWidget *func_8025305C_de(int);

extern int GetMenuScreenOwner(void);



extern void func_8040EDE4_de(Resource_func_80419E54_de *, MenuResourceWidget *);

extern void *Frontend_GetScreenData(s32 index);

extern void func_80419C84_de(func_80419D04_S1 *arg0, s32 arg1);

extern void func_80419F18_de(MenuResourceWidget *);

/* Initializes a flicker effect and randomizes each element's intensity. */
void func_80419C84_de(func_80419D04_S1 *flicker, s32 arg1) {
    s32 i;
    s32 var_v1;
    s32 offset;
    int temp;
    flicker->unk44 = 0;
    flicker->unk74 = 0;
    if (arg1 > 0) {
        flicker->unk48 = arg1;
    } else {
        flicker->unk48 = (s32) (func_802744D4_de() % 5 + 1);
    }
    for (i = 0; i < flicker->unk48; i++) {
        flicker->unk60[i] = (s32) (func_802744D4_de() % 3 + 1);
        var_v1 = (offset = func_802744D4_de() % 40 + 30, flicker->unk80 - offset) < 0 ? 0 : ((offset = func_802744D4_de() % 40 + 30, flicker->unk80 - offset) >= 0x100 ? 0xFF : (offset = temp = func_802744D4_de() % 40 + 30, flicker->unk80 - offset));
        flicker->unk4C[i] = var_v1;
    }
}

void func_80419E24_de(void) {
    func_802982C4_de(0xB62, D_00419F9C, D_0041A02C, 3);
}

MenuResourceWidget *func_80419E54_de(int arg0, int arg1)
{
  Resource_func_80419E54_de *r;
  MenuResourceWidget *p;
  int kind;
  r = func_8040EC30_de(Frontend_GetScreenData(GetMenuScreenOwner()), arg0 & 65535);
  Frontend_GetScreenData(GetMenuScreenOwner());
  p = func_8025305C_de(0x88);
  Resmgr_FillBytes(p, 0, 0x88);
  p->b = (kind = 0xB62);
  p->resource = r;
  p->owner.value = arg1;
  p->c = 8;
  p->a = kind;
  p->resource->value = p->owner.bytes[3];
  func_80419C84_de(p, -1);
  func_80419F18_de(p);
  func_8040EDE4_de(r, p);
  return p;
}
