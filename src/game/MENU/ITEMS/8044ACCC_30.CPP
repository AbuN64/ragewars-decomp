#include "COMMON/OBJB.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "MENU/8044ACCC.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"

/* Sets the resource transition state and sound, while its adjacent helper refreshes the controller-option bit. */


extern void Items_LoadSceneLight(void);
void Items_SetSelection(ItemsSelectionState *state,int selection,int mode) {
 state->active=1;
 state->mode=mode;
 state->selection=selection;
 if(mode==2 && selection!=999)Render_PlayFlatSound(0x21C);
}
void func_8044D580_de(ItemsSelectionState *state) {
 Items_LoadSceneLight();
 D_800CC380=(state->input->value>>2)&1;
}

/* Processes both pending object lists between update barriers. */

void func_802458C4_de();                                  /* extern */
void func_802458D8_de();                                  /* extern */
void func_8028787C_de(void *, s32);                       /* extern */

void Items_UpdatePendingObjects(ItemsPendingState *arg0) {
 s32 i,n;
 func_802458D8_de();
 n=arg0->unk11C0;
 for(i=0;i<n;i++) func_8028787C_de(arg0,arg0->unk11D0+i*20);
 n=arg0->unk11C4;
 for(i=0;i<n;i++) func_8028787C_de(arg0,arg0->unk11D4+i*20);
 func_802458C4_de();
}
