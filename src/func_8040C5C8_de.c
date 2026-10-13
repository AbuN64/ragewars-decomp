#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_166000/code_80403E88.h"
#include "types.h"

/* Processes a widget with clipping and drawing operations. */





extern s32 func_8040E0D4_de(struct Shape_typemap_165 *, struct Shape_typemap_165 *, void *, Args *);
extern void func_802A1898_de(s32 *, s32 *, s32 *, s32 *);
extern s32 func_8040F488_de(struct Shape_typemap_165 *, struct Shape_typemap_165 *);
extern void func_802A1870_de(s32, s32, s32, s32);
extern void func_8040E7FC_de(void *, Args);




void func_8040C5C8_de(void *widget, Args args) {
    func_802A2BE0_S1 *record = widget;
    struct Shape_typemap_165 first;
    struct Shape_typemap_165 basis;
    struct Shape_typemap_165 value;
    struct Shape_typemap_165 transformed;
    s32 changed;

    changed = 0;
    if (func_8040E0D4_de(&first, &basis, widget, &args) != 0) {
        if ((record->unk12 & 0x200) != 0) {
            func_802A1898_de(&value.field_0, &value.field_8, &value.field_4, &value.field_C);
            transformed = value;
            func_8040F488_de(&transformed, &basis);
            func_802A1870_de(transformed.field_0, transformed.field_8, transformed.field_4, transformed.field_C);
            changed = 1;
        }
        func_8040E7FC_de(record->unk8, args);
        if (changed != 0) {
            func_802A1870_de(value.field_0, value.field_8, value.field_4, value.field_C);
        }
    }
}
