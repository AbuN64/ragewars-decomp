#include "TYPES.H"
#include "n64sdk.h"
typedef struct { char pad[16]; u8 value; } DraftWidget;
typedef struct { u8 pad[3]; u8 value; } DraftFrame;
typedef struct { char pad[0x44]; s32 active,count; DraftFrame frames[5]; s32 timers[5]; s32 index; DraftWidget *widget; s32 delay; u8 pad80[3],original; s32 enabled; } DraftBlink;
extern s32 func_802744D4_de(void);
extern void func_80419C84_de(DraftBlink *,s32);
extern void func_8025DF34_de(s16);
s32 func_80419F4C_eu_x(DraftBlink *state) {
 s32 index,delay;
 if(state->enabled!=1) return 0;
 if(state->active==0) {
  delay=state->delay-1;
  if(delay<0) delay=0; else if(delay>=51) delay=50;
  state->delay=delay;
  if(delay>0) return 0;
  if(func_802744D4_de()%100>1) return 0;
  index=state->index; state->active=1;
 } else {
  state->widget->value=state->original;
  state->timers[state->index]--;
  index=state->index;
  if(state->timers[index]>0 && index+1<state->count) return 0;
  index++; state->index=index;
  if(state->count<=index) {
   func_80419C84_de(state,-1);
   state->widget->value=state->original;
   state->delay=50; return 0;
  }
 }
 state->widget->value=state->frames[index].value;
 func_8025DF34_de(0xe75);
 return 0;
}
