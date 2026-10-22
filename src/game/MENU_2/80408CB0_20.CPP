#include "include_asm.h"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
#define func_80419F4C_eu_x func_80419F50_eu
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
INCLUDE_ASM("ovl_80400000", func_80419F50_eu);
#endif
#endif
