#include "common/types_1dc8418c21db.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_804264F0.h"
#include "shared/func_80425674_de_layout.h"
#include "common/data.h"
#include "common/unused.h"
#include "types.h"

extern void *D_800E39C0;
extern struct Request_func_8041E100_de D_80153F80[];
extern struct TextEntry D_800E381C[][17];
extern u8 *func_802A025C_de(u8 *, u8 *);
enum { DRAW_ICON=909, DRAW_NAME=911, DRAW_VARIANT=910, DRAW_FIRST=912, DRAW_SECOND=913 };
void func_8041E408_de(s32 index) {
    void *window;
    RequestDrawScreen *screen;
    MenuWidget *widget;
    s32 model;
    char *name;
    void *widgetObject;
    void *variantObject;
    char ***variantSlot;
    screen = D_800E39C0;
    window = screen->roots[index];
    if (screen->count < index || D_80153F80[index].id < 0) {
        func_8040E8D8_de(window, 0);
    } else {
        widgetObject = func_8040EC30_de(window, DRAW_ICON);
        widget = widgetObject;
        widget->alpha = 125;
        model = func_8041F140_de(D_80153F80[index].id);
        widget->value = D_800E3A58[model].pad0;
        widgetObject = func_8040EC30_de(window, DRAW_NAME);
        widget = widgetObject;
        widget->alpha = 125;
        model = func_8041EC44_de(D_80153F80[index].variant, D_80153F80[index].id);
    name = D_80153F80[index].name;
        func_802A025C_de((u8 *)name,
          (u8 *)*D_800E381C[D_80153F80[index].variant][model].text
        );
        widget->text = name;
        widgetObject = func_8040EC30_de(window, DRAW_VARIANT);
        widget = widgetObject;
        widget->alpha = 125;
        variantObject = &D_800DF964[D_80153F80[index].variant];
        variantSlot = variantObject;
        widget->text = **variantSlot;
        widgetObject = func_8040EC30_de(window, DRAW_FIRST);
        widget = widgetObject;
        widget->alpha = 125;
        widget->value = D_800DF740[D_80153F80[index].word8].first;
        widgetObject = func_8040EC30_de(window, DRAW_SECOND);
        widget = widgetObject;
        widget->alpha = 125;
        widget->value = D_800DF740[D_80153F80[index].word8].second;
    }
}
