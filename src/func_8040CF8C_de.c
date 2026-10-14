#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8040C780.h"
#include "span_16E000/code_804143D8.h"
#include "types.h"
/* Draws a widget as an untextured four-colour gradient quad: when func_8040E0D4_de places the widget
   and any corner colour has alpha, it narrows the scissor to the widget's box if its flags ask for
   clipping (0x200, skipping the draw when nothing is left), flushes the queued text sprites through
   func_8040CAB0_de if any queued batch overlaps the widget's area, selects render mode 0x53533 if
   needed, clears the texture and draws the area with each corner colour's alpha scaled by the draw
   arguments' alpha through func_80418DE0_de, restoring the scissor afterwards. Adapted from
   func_8040CD50_de. */











extern s32 D_8014D570;
extern BatchRec D_8014D590[];
extern s32 D_800E2AB8;


extern s32 func_8040E0D4_de(struct Shape_typemap_165 *area, struct Shape_typemap_165 *box, Widget_func_8040CF8C_de *widget, DrawArgs *args);
extern void func_802A1898_de(s32 *left, s32 *right, s32 *top, s32 *bottom);
extern s32 func_8040F488_de(struct Shape_typemap_165 *clip, struct Shape_typemap_165 *box);
extern void func_802A1870_de(s32 left, s32 right, s32 top, s32 bottom);


extern void func_804174F4_de(s32 texture);
extern void func_80418DE0_de(f32 x, f32 y, f32 z, f32 width, f32 height, u32 c0, u32 c1, u32 c2, u32 c3);

static inline s32 func_8040D00C_overlaps(struct Shape_typemap_165 *area) {
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

void func_8040CF8C_de(Widget_func_8040CF8C_de *widget, DrawArgs args) {
    struct Shape_typemap_165 box;
    struct Shape_typemap_165 area;
    struct Shape_typemap_165 saved;
    struct Shape_typemap_165 clip;
    s32 clipped;

    clipped = 0;
    if (func_8040E0D4_de(&area, &box, widget, &args) == 0) {
        return;
    }
    if (((u8)(widget->colors[0] >> 24) | (u8)(widget->colors[1] >> 24) | (u8)(widget->colors[2] >> 24) |
         (u8)(widget->colors[3] >> 24)) == 0) {
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
    if (func_8040D00C_overlaps(&area)) {
        func_8040CAB0_de();
    }
    if (D_800DEA6C != 0x53533 || D_800E2AB8 == 0) {
        D_800DEA6C = 0x53533;
        func_80417138_de(0x53533);
        D_800E2AB8 = 1;
    }
    func_804174F4_de(0);
    func_80418DE0_de(area.field_0, area.field_8, 0.0f, area.field_4 - area.field_0 + 1, area.field_C - area.field_8 + 1,
                  (widget->colors[0] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[0] >> 24) / 255) << 24),
                  (widget->colors[1] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[1] >> 24) / 255) << 24),
                  (widget->colors[2] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[2] >> 24) / 255) << 24),
                  (widget->colors[3] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[3] >> 24) / 255) << 24));
    if (clipped) {
        func_802A1870_de(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
    }
}
