#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043F69C.h"
#include "types.h"
#include "menu_text.h"
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif
/* Measures three text layers, positions their labels, and renders the composite text. */
extern void func_8043F52C_de(LayeredText *, TextLayerMetrics *);
extern void func_804402DC_de(LayeredText *, TextLayerRect *, TextLayerRect *, int);
extern void func_8043FE3C_de(LayeredText *, TextLayerRect *, TextLayerRect *, int, int, int);
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU_X)
extern void func_8043F52C_de(LayeredText *, TextLayerMetrics *);
#endif
void func_804404A8_de(LayeredText *source, TextLayerRect *position, TextLayerRect *bounds, int flags) {
    LayeredText current;
    TextLayerMetrics first, second, third;
    int center;
    LayeredText *draw;
    center = (bounds->x + bounds->right) / 2;
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
    position->y += first.height;
    if (source->flags & 1) {
        position->x = center - (second.width + third.width) / 2;
    }
    position->x += third.width / 2;
    func_804402DC_de(&current, position, bounds, flags);
    current = *source;
    current.text = 0;
    position->x += (source->spacing * second.width) / 256 - third.width / 2;
    position->y += second.height / 2 - third.height / 2;
    func_804402DC_de(&current, position, bounds, flags);
    current = *source;
    if (source->flags & 1) {
        position->x = center - first.width / 2;
    }
    draw = &current;
    func_8043FE3C_de(draw, position, bounds, flags, RW_LOCALIZED_TEXT(*draw->text, draw->text, draw->text, D_80152789), 0);
}
