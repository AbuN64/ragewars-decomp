#include "include_asm.h"

#if defined(VERSION_EU)
#include "COMMON/ANIMATION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/INTEGERSTATE530.H"
#include "stddef.h"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MENU_2/804196C0_16.H"
#include "FRONTEND/8040B45C_33.H"
#include "TYPES.H"
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
