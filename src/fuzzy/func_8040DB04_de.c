#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8040C780.h"
#include "types.h"

typedef struct DraftWidget {
    struct DraftWidget *parent;
    struct DraftWidget *next;
    struct DraftWidget *child;
    s16 id;
    u16 type;
    u16 unk10;
    u16 flags;
    s16 x;
    s16 y;
    s16 width;
    s16 height;
    char pad1C[0x10];
    struct DraftWidget *normal;
    struct DraftWidget *selected;
    struct DraftWidget *disabled;
} DraftWidget;

extern s32 D_800E2AB8;
extern s32 func_8040E0D4_de(struct Shape_typemap_165 *, struct Shape_typemap_165 *, void *, DrawArgs *);
extern s32 func_8040F488_de(struct Shape_typemap_165 *, struct Shape_typemap_165 *);
extern void func_802A1898_de(s32 *, s32 *, s32 *, s32 *);
extern void func_802A1870_de(s32, s32, s32, s32);
extern void func_8040E7FC_de(void *, DrawArgs);
extern void func_8040CD50_de(void *, DrawArgs);
extern void func_8040D2D0_de(void *, DrawArgs);
extern void func_8040CF8C_de(void *, DrawArgs);
extern s32 func_80299838_de(s32);
extern s32 func_80299A80_de(void *, DrawArgs);
extern void func_802A18FC_de(void);
extern void func_802A18F4_de(void);

void func_8040DB04_de(DraftWidget *widget, DrawArgs args) {
    switch (widget->type) {
    case 1: {
        DrawArgs local;
        struct Shape_typemap_165 box;
        struct Shape_typemap_165 area;
        struct Shape_typemap_165 saved;
        struct Shape_typemap_165 clip;
        s32 clipped;
        local = args;
        clipped = 0;
        if (func_8040E0D4_de(&area, &box, widget, &local)) {
            if (widget->flags & 0x200) {
                func_802A1898_de(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
                clip = saved;
                if (!func_8040F488_de(&clip, &box)) return;
                clipped = 1;
                func_802A1870_de(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
            }
            func_8040E7FC_de(widget->child, local);
            if (clipped) func_802A1870_de(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
        }
        break;
    }
    case 2: {
        DrawArgs local;
        struct Shape_typemap_165 box;
        struct Shape_typemap_165 saved;
        struct Shape_typemap_165 clip;
        struct Shape_typemap_165 area;
        s32 clipped;
        local = args;
        clipped = 0;
        D_800E2AB8 = 0;
        if (func_8040E0D4_de(&area, &box, widget, &local)) {
            if (widget->flags & 0x200) {
                func_802A1898_de(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
                clip = saved;
                if (!func_8040F488_de(&clip, &box)) return;
                clipped = 1;
                func_802A1870_de(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
            }
            func_8040E7FC_de(widget->child, local);
            if (clipped) func_802A1870_de(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
        }
        break;
    }
    case 3:
        func_8040CD50_de(widget, args);
        break;
    case 4:
        func_8040D2D0_de(widget, args);
        break;
    case 6:
        func_8040CF8C_de(widget, args);
        break;
    case 8: {
        DrawArgs local;
        struct Shape_typemap_165 area;
        struct Shape_typemap_165 box;
        DraftWidget *child;
        local = args;
        if (func_8040E0D4_de(&area, &box, widget, &local)) {
            if (local.flags & 0x100) child = widget->disabled;
            else if (local.flags & 0x40) child = widget->selected;
            else child = widget->normal;
            if (child) {
                local.x -= (s32)(child->x * local.scaleX);
                local.y -= (s32)(child->y * local.scaleY);
                func_8040DB04_de(child, local);
            }
        }
        break;
    }
    default: {
        s32 flags;
        flags = func_80299838_de(widget->type);
        if (!(flags & 1)) {
            func_802A18FC_de();
            D_800E2AB8 = 0;
        }
        if (func_80299A80_de(widget, args) && !(flags & 1)) {
            func_802A18F4_de();
            D_800E2AB8 = 0;
        }
        break;
    }
    }
}
