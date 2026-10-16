#include "OVL_80400000/804245C0.H"
#include "common/data.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "shared/func_80438614_de_closed.h"
#include "shared/preview_statistics.h"
#include "span_16E000/code_804264F0.h"
#include "span_16E000/code_804379C8.h"
#include "span_C76B0/data.h"

extern Profile D_80102B00[];

extern s32 func_802A0C08_de(void *, s32, ...);

/* Fill the selected player's preview statistics and optional rank badge. */
void func_8043829C_de(void) {
    MenuWidget *item, *lastItem;
    func_8041F2A0_Config *record;
    s32 denominator;
    s32 player;
    s32 statIndex;
    s32 percent;

    player = D_800E5830->player;
    statIndex = player;
    record = &D_80146398[player];
    item = func_8040EC30_de(D_800E5830->window, (0x279 + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0x96;
    item->value = D_800E3A58[func_8041F140_de((s32) record->kind)].pad0;
    item = func_8040EC30_de(D_800E5830->window, (0x27a + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0xAF;
    item->text = D_80102B00[player].name;
    item = func_8040EC30_de(D_800E5830->window, (0x27b + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0x73;
    item->text = func_80424DE8_de(player);
    item = func_8040EC30_de(D_800E5830->window, (0x27c + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0xAF;
    func_802A0C08_de(D_800E5830->killsText, (s32)previewNumberFormat(), record->kills);
    item->text = D_800E5830->killsText;
    item = func_8040EC30_de(D_800E5830->window, (0x27d + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0xAF;
    func_802A0C08_de(D_800E5830->scoreText, (s32)previewNumberFormat(), record->score + record->total);
    item->text = D_800E5830->scoreText;
    item = func_8040EC30_de(D_800E5830->window, (0x27e + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0xAF;
    denominator = D_800FF140_de[statIndex];
    percent = 0;
    if (denominator > 0) {
        percent = (s32) (D_800FEAE0[statIndex] * 0x64) / denominator;
    }
    func_802A0C08_de(D_800E5830->ratioText, (s32)D_800E1F48, percent);
    item->text = D_800E5830->ratioText;
    item = func_8040EC30_de(D_800E5830->window, (0x27f + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0xAF;
    lastItem=item;
    switch (D_8014DD98) {
    case 0: func_802A0C08_de(D_800E5830->otherText, (s32)previewNumberFormat(), record->other); break;
    case 1: func_802A0C08_de(D_800E5830->otherText, (s32)previewNumberFormat(), record->selected); break;
    default: func_802A0C08_de(D_800E5830->otherText, (s32)previewNumberFormat(), 0); break;
    }
    lastItem->text = D_800E5830->otherText;
    if (D_800E5830->badge != -1) {
        item = func_8040EC30_de(D_800E5830->window, (0x280 + PREVIEW_ID_SHIFT));
        item->alpha = 0x96;
        func_8040E8D8_de(item, 1);
        item->value = D_800E01B0_de[D_800E5830->badge];
    }
}

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
