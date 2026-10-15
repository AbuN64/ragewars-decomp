#include "span_16E000/code_8044ACCC.h"
#include "types.h"

/* Sets the resource transition state and sound, while its adjacent helper refreshes the controller-option bit. */


extern int D_800CC380;
extern void func_8025DF34_de(int),func_8044BE04_de(void);
void func_8044D528_de(State_func_8044D528_de *state,int selection,int mode) {
 state->active=1;
 state->mode=mode;
 state->selection=selection;
 if(mode==2 && selection!=999)func_8025DF34_de(0x21C);
}
void func_8044D580_de(State_func_8044D528_de *state) {
 func_8044BE04_de();
 D_800CC380=(state->input->value>>2)&1;
}

/* Processes both pending object lists between update barriers. */

void func_802458C4_de();                                  /* extern */
void func_802458D8_de();                                  /* extern */
void func_8028787C_de(void *, s32);                       /* extern */

void func_8044D5C4_de(State_func_8044D5C4_de *arg0) {
 s32 i,n;
 func_802458D8_de();
 n=arg0->unk11C0;
 for(i=0;i<n;i++) func_8028787C_de(arg0,arg0->unk11D0+i*20);
 n=arg0->unk11C4;
 for(i=0;i<n;i++) func_8028787C_de(arg0,arg0->unk11D4+i*20);
 func_802458C4_de();
}
