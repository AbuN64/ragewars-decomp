#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "TYPES.H"
#include "COMMON/MENU_TEXT.H"
#include "COMMON/MENU_UI_PROVIDERS.H"

extern u8 D_80152789;
extern void func_8043F52C_de(LayeredText *, TextLayerMetrics *);
extern void func_804402DC_de(LayeredText *, MenuOptionBox *, MenuOptionBox *, int);
extern void func_8043FE3C_de(LayeredText *, MenuOptionBox *, MenuOptionBox *, int, int, int);

#if !(defined(VERSION_DE) || defined(VERSION_US_REV1))
void func_804404A8_de(LayeredText *source, MenuOptionBox *position, MenuOptionBox *bounds, int flags) {
    LayeredText current;
    TextLayerMetrics first, second, third;
    int center;
    LayeredText *draw;
    center = (bounds->left + bounds->field18) / 2;
    current = *source;
    current.mode = 0;
    func_8043F52C_de(&current, &first);
    current = *source;
    current.mode = 1;
    current.text = 0;
    func_8043F52C_de(&current, &second);
    current = *source;
    current.mode = 1;
    current.text = 0;
    func_8043F52C_de(&current, &third);
    current = *source;
    current.text = 0;
    position->top += first.height;
    if (source->flags & 1) {
        position->left = center - (second.width + third.width) / 2;
    }
    position->left += third.width / 2;
    func_804402DC_de(&current, position, bounds, flags);
    current = *source;
    current.text = 0;
    position->left += (source->spacing * second.width) / 256 - third.width / 2;
    position->top += second.height / 2 - third.height / 2;
    func_804402DC_de(&current, position, bounds, flags);
    current = *source;
    if (source->flags & 1) {
        position->left = center - first.width / 2;
    }
    draw = &current;
    func_8043FE3C_de(draw, position, bounds, flags, RW_LOCALIZED_TEXT(*draw->text, draw->text, draw->text, D_80152789), 0);
}
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* Measures three text layers, positions their labels, and renders the composite text. */
void func_804404A8_de(LayeredText *source, MenuOptionBox *position, MenuOptionBox *bounds, int flags) {
    LayeredText current;
    TextLayerMetrics first, second, third;
    int center;
    LayeredText *draw;
    center = (bounds->left + bounds->field18) / 2;
    current = *source;
    current.mode = 0;
    func_8043F52C_de(&current, &first);
    current = *source;
    current.mode = 1;
    current.text = 0;
    func_8043F52C_de(&current, &second);
    current = *source;
    current.mode = 1;
    current.text = 0;
    func_8043F52C_de(&current, &third);
    current = *source;
    current.text = 0;
    position->top += first.height;
    if (source->flags & 1) {
        position->left = center - (second.width + third.width) / 2;
    }
    position->left += third.width / 2;
    func_804402DC_de(&current, position, bounds, flags);
    current = *source;
    current.text = 0;
    position->left += (source->spacing * second.width) / 256 - third.width / 2;
    position->top += second.height / 2 - third.height / 2;
    func_804402DC_de(&current, position, bounds, flags);
    current = *source;
    if (source->flags & 1) {
        position->left = center - first.width / 2;
    }
    draw = &current;
    func_8043FE3C_de(draw, position, bounds, flags, RW_LOCALIZED_TEXT(*draw->text, draw->text, draw->text, D_80152789), 0);
}
#endif

INCLUDE_ASM("ovl_80400000", func_80440838_de);

INCLUDE_ASM("ovl_80400000", func_80440DA0_de);
