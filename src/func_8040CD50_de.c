#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8040C780.h"
#include "span_16E000/code_804143D8.h"
#include "types.h"
/* Draws a widget's image as a solid textured quad: when func_8040E0D4_de places the widget it narrows
   the scissor to the widget's box if its flags ask for clipping (0x200, skipping the draw when
   nothing is left), flushes the queued text sprites through func_8040CAB0_de if any queued batch
   overlaps the widget's area, loads the image through func_80410674_de, selects render mode 0x53333
   if needed and draws the area with the draw arguments' alpha through func_80418DA0_de, restoring the
   scissor afterwards. Adapted from func_8040E67C_de with the batch overlap test as an inline helper. */











extern s32 D_8014D570;
extern BatchRec D_8014D590[];
extern s32 D_800E2AB8;


extern s32 func_8040E0D4_de(struct Shape_typemap_165 *area, struct Shape_typemap_165 *box, Widget_func_8040CD50_de *widget, DrawArgs *args);
extern void func_802A1898_de(s32 *left, s32 *right, s32 *top, s32 *bottom);
extern s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);
extern void func_802A1870_de(s32 left, s32 right, s32 top, s32 bottom);

extern s32 func_80410674_de(s32 image, s32 mode);

extern void func_804174F4_de(s32 texture);
extern void func_80418DA0_de(f32 x, f32 y, f32 z, f32 width, f32 height, s32 color);

static inline s32 func_8040CDD0_overlaps(struct Shape_typemap_165 *area) {
    BatchRec *batch;
    s32 i;

    for (i = 0; i < D_8014D570; i++) {
        batch = &D_8014D590[i];
        if (area->field_4 < batch->area.field_0 || batch->area.field_4 < area->field_0 || area->field_C < batch->area.field_8 ||
            batch->area.field_C < area->field_8) {
            continue;
        }
        return 1;
    }
    return 0;
}

void func_8040CD50_de(Widget_func_8040CD50_de *widget, DrawArgs args) {
    struct Shape_typemap_165 box;
    struct Shape_typemap_165 area;
    struct Shape_typemap_165 saved;
    struct Shape_typemap_165 clip;
    s32 clipped;
    s32 texture;
    s32 color;

    clipped = 0;
    if (func_8040E0D4_de(&area, &box, widget, &args) == 0) {
        return;
    }
    if (widget->flags & 0x200) {
        func_802A1898_de(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
        clip = saved;
        if (func_8040F488_de(&clip, &box) == 0) {
            return;
        }
        clipped = 1;
        func_802A1870_de(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
    }
    if (func_8040CDD0_overlaps(&area)) {
        func_8040CAB0_de();
    }
    texture = func_80410674_de(widget->image, 1);
    color = (args.alpha << 24) | 0xFFFFFF;
    if (D_800DEA6C != 0x53333 || D_800E2AB8 == 0) {
        D_800DEA6C = 0x53333;
        func_80417138_de(0x53333);
        D_800E2AB8 = 1;
    }
    func_804174F4_de(texture);
    func_80418DA0_de(area.field_0, area.field_8, 0.0f, area.field_4 - area.field_0 + 1, area.field_C - area.field_8 + 1, color);
    if (clipped) {
        func_802A1870_de(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
    }
}
