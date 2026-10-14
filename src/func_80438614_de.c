#include "span_C76B0/data.h"
#include "span_16E000/code_804379C8.h"
#include "shared/func_80438614_de_closed.h"

void func_80438614_de(void) {
 SetupModelVector scale,offset,angle,position;
 s32 index, displacement, model;
 MenuWidget *item;
 ModelPreviewScreen *slot;
 index=D_800E5830->selected;
 displacement=index*20;
 model=D_800E5830->rows[index].unk0;
 if(model>=0) {
  /* the hub's Item view shares the MenuWidget prefix; this unit writes alpha and image through its own view */
  item=(MenuWidget *)func_8040EC30_de(D_800E5830->window,MENU_804387F4_642);
  func_8040E8D8_de(item,1);
  item->alpha=0xAF;
  item->image=D_800E5830->rows[index].unk10;
  if ((u32)(model-0x1389)<2U || model==0x139F || model==0x13A0 || model==0x13C1 || model==0x1398 || model==0x13BD) {
   scale.value.x=0.3f; scale.value.y=0.3f; scale.value.z=0.3f;
  } else { scale.value.x=0.009f; scale.value.y=0.009f; scale.value.z=0.009f; }
  angle.value.x=0;angle.value.y=0;angle.value.z=0;
  position.value.x=0;position.value.y=3.0f;position.value.z=0;
  offset.value.x=0;offset.value.y=-5.0f;offset.value.z=-100.0f;
  if (model==0x1390 || model==0x1392) {
   offset.value.x=0;offset.value.y=-30.0f;offset.value.z=-100.0f;
   scale.value.x=D_800DDF38_de;scale.value.y=D_800DDF38_de;scale.value.z=D_800DDF38_de;
  }
  func_80439B5C_de(&D_800E5830->modelWorkspace,0,scale.words,offset.words);
  func_80439BE0_de(&D_800E5830->modelWorkspace,angle.words);
  func_80439C30_de(&D_800E5830->modelWorkspace,position.words);
  func_80439C80_de(&D_800E5830->modelWorkspace,model);
  D_800E5830->rows[index].unk4=0;
  D_800E5830->rows[index].unk8=10;
 }
}

