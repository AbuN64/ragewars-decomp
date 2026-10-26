#include "COMMON/OBJB.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "MENU/8044ACCC.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"

/* Sets the resource transition state and sound, while its adjacent helper refreshes the controller-option bit. */


extern void OvlScene_LoadSceneLight(void);
void OvlScene_SetSelection(ItemsSelectionState *state,int selection,int mode) {
 state->active=1;
 state->mode=mode;
 state->selection=selection;
 if(mode==2 && selection!=999)SoundElement_PlayFlatSound(0x21C);
}
void OvlScene_LoadSelectionLighting(ItemsSelectionState *state) {
 OvlScene_LoadSceneLight();
 D_800CC380=(state->input->value>>2)&1;
}

/* Processes both pending object lists between update barriers. */

void func_802458C4_de();                                  /* extern */
void func_802458D8_de();                                  /* extern */
void Scene_DispatchEnabledEntityTrigger(void *, s32);                       /* extern */

void OvlScene_UpdatePendingObjects(ItemsPendingState *pendingWorld) {
 s32 i,n;
 func_802458D8_de();
 n=pendingWorld->unk11C0;
 for(i=0;i<n;i++) Scene_DispatchEnabledEntityTrigger(pendingWorld,pendingWorld->unk11D0+i*20);
 n=pendingWorld->unk11C4;
 for(i=0;i<n;i++) Scene_DispatchEnabledEntityTrigger(pendingWorld,pendingWorld->unk11D4+i*20);
 func_802458C4_de();
}
