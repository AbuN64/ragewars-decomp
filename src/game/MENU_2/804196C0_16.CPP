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
#ifdef NON_MATCHING
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"
#include "RESMGR/resmgr_string_memory.H"
extern s32 func_802744D4_de(void);
extern void func_80419C84_de(func_80419D04_S1 *, s32);
s32 func_80419F4C_eu_x(func_80419D04_S1 *state) {
 s32 index,delay;
 if(state->unk84!=1) return 0;
 if(state->unk44==0) {
  delay=state->unk7C-1;
  if(delay<0) delay=0; else if(delay>=51) delay=50;
  state->unk7C=delay;
  if(delay>0) return 0;
  if(func_802744D4_de()%100>1) return 0;
  index=state->unk74; state->unk44=1;
 } else {
  state->unk78->value=state->unk80;
  state->unk60[state->unk74]--;
  index=state->unk74;
  if(state->unk60[index]>0 && index+1<state->unk48) return 0;
  index++; state->unk74=index;
  if(state->unk48<=index) {
   func_80419C84_de(state,-1);
   state->unk78->value=state->unk80;
   state->unk7C=50; return 0;
  }
 }
 state->unk78->value=state->unk4C[index];
 func_8025DF34_de(0xe75);
 return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80419F4C_eu_x);
#endif
#endif

s32 func_802744D4_de(void);

/* Allocates and initializes an object, attaches its resource and owner value, then registers it with the resource. */



extern MenuResourceWidget *func_8025305C_de(int);

extern int func_80299958_de(void);



extern void func_8040EDE4_de(Resource_func_80419E54_de *, MenuResourceWidget *);

extern void *func_80411DCC_de(s32 index);

extern void func_80419C84_de(func_80419D04_S1 *arg0, s32 arg1);

extern void func_80419F18_de(MenuResourceWidget *);

/* Initializes a flicker effect and randomizes each element's intensity. */
void func_80419C84_de(func_80419D04_S1 *arg0, s32 arg1) {
    s32 var_s1;
    s32 var_v1;
    s32 offset;
    int temp;
    arg0->unk44 = 0;
    arg0->unk74 = 0;
    if (arg1 > 0) {
        arg0->unk48 = arg1;
    } else {
        arg0->unk48 = (s32) (func_802744D4_de() % 5 + 1);
    }
    for (var_s1 = 0; var_s1 < arg0->unk48; var_s1++) {
        arg0->unk60[var_s1] = (s32) (func_802744D4_de() % 3 + 1);
        var_v1 = (offset = func_802744D4_de() % 40 + 30, arg0->unk80 - offset) < 0 ? 0 : ((offset = func_802744D4_de() % 40 + 30, arg0->unk80 - offset) >= 0x100 ? 0xFF : (offset = temp = func_802744D4_de() % 40 + 30, arg0->unk80 - offset));
        arg0->unk4C[var_s1] = var_v1;
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
  r = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), arg0 & 65535);
  func_80411DCC_de(func_80299958_de());
  p = func_8025305C_de(0x88);
  func_802A0748_de(p, 0, 0x88);
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
