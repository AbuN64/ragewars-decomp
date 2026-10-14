#include "span_164000/code_80405DB4.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041B020.h"
#include "types.h"

extern s32 func_8040E0D4_de(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *, void *, Args *);
extern void func_802A1898_de(u32 *, u32 *, u32 *, u32 *);
extern void func_8040F488_de(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *);
extern void func_802A1870_de(u32, u32, u32, u32);
extern void func_8040E7FC_de(void *, Args);

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
