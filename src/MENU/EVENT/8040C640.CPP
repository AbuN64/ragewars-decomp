#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "MENU/EXTERNS.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "MATH/802A2870.H"

#if defined(VERSION_US)
extern s32 func_8040E0D4_de(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *, void *, Args *);

extern void func_802A1898_de(u32 *, u32 *, u32 *, u32 *);

extern s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


extern void func_8040E7FC_de(void *, Args);

s32 func_8040C638_us(s32 arg0) {
    arg0 << 0;
    return 0;
}

void func_8040C648_us(void *arg0, Args args) {
    func_802A2BE0_S1 *record = arg0;
    Quad_func_802A1BE0_de first;
    Quad_func_802A1BE0_de basis;
    Quad_func_802A1BE0_de value;
    Quad_func_802A1BE0_de transformed;
    s32 changed;

    changed = 0;
    if (func_8040E0D4_de(&first, &basis, arg0, &args) != 0) {
        if ((record->unk12 & 0x200) != 0) {
            func_802A1898_de(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            func_8040F488_de(&transformed, &basis);
            func_802A1870_de(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        func_8040E7FC_de(record->unk8, args);
        if (changed != 0) {
            func_802A1870_de(value.x, value.z, value.y, value.w);
        }
    }
}
#endif

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", func_8040C77C_us_padding_17077C);
#endif
