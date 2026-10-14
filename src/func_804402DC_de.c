#include "span_16E000/menu_ui_providers.h"
/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "types.h"
/* Draws a menu option as a highlighted box or as text, with state-dependent opacity. */



/* The values func_804402DC_de loads by address:
 * 0x800E24AC = 255.0 (float, D_800DE47C_de in this cartridge's tables)
 */
u32 func_80265350_de(void);
int func_802934F8_de(void);
void func_802A9234_de(s32);
void func_802AA9F4_de(void);
s32 func_802AAC28_de(s32, s32, s16, s16, f32, f32, s32);












void func_804402DC_de(MenuOption *arg0, MenuOptionBox *arg1, s32 arg2, MenuOptionFade *arg3) {
    s32 var_v1;
    f32 right;
    f32 bottom;
    f32 width;
    f32 height;
    s32 *active;

    if (((func_802934F8_de() != 0) && (arg0->flags & 0x40000000)) || ((D_801462E5 != 0) && (arg0->flags < 0) && (func_80265350_de() == 0x400000))) {
        arg3->highlighted = 1;
        if (D_800E1E20 != 3) {
            D_800E1E20 = 3;
        }
        func_802AA9F4_de();
        width = (f32)arg1->width * arg1->scaleX;
        height = (f32)arg1->height * arg1->scaleY;
        bottom = (f32)arg1->top;
        right = (f32)arg1->left;
        right += width;
        bottom += height;
        active = &D_80146894;
        if (*active != 0) {
            if (D_801462E5 == 0) {
                var_v1 = 0x80;
            } else if (arg0->flags < 0) {
                var_v1 = 0xFF;
            } else {
                var_v1 = 0xC0;
            }
        } else {
            var_v1 = 0x80;
        }
        func_802A7DE4_de(arg1->left, arg1->top, (s32)right, (s32)bottom, 1, 0, 0, 0, 0, var_v1);
        return;
    }
    if (D_800E1E20 != 3) {
        D_800E1E20 = 3;
        func_802A9234_de((s32) (arg3->fade * (arg3->alpha * D_800DE47C_de)));
    }
    func_802AAC28_de(arg0->resource, 0, (s16)arg1->left, (s16)arg1->top, arg1->scaleX, arg1->scaleY, 1);
}
