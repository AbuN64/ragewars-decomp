#include "common/unused.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_804264F0.h"
#include "shared/preview_statistics.h"
#include "common/data.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_80438614_de_closed.h"
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
