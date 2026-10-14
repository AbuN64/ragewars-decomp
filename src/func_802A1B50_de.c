#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802A1264.h"
#include "types.h"
#include "span_16E000/code_8040C780.h"

extern s32 D_800CD9B0;
extern s32 D_800CD9B4;
extern Handler802A2B50 D_800CD9B8;

s32 func_802A1B50_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800CD9B8 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800CD9B8;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800CD9B0)) + offset))->field_0 == arg1) {
                actor_kind = ((struct Tree *)arg0)->id;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800CD9B4)) + offset))->field_0;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler802A2B50 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            offset += 0xC;
        } while (*(Handler802A2B50 *)entry != 0);
    }
    return 0;
}

extern s32 func_8040E0D4_de(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *, void *, Args *);
extern void func_802A1898_de(u32 *, u32 *, u32 *, u32 *);
extern s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);
extern void func_802A1870_de(u32, u32, u32, u32);
extern void func_8040E7FC_de(void *, Args);




void func_802A1BE0_de(void *arg0, Args args) {
    Quad_func_802A1BE0_de first;
    Quad_func_802A1BE0_de basis;
    Quad_func_802A1BE0_de value;
    Quad_func_802A1BE0_de transformed;
    s32 changed;

    changed = 0;
    if (func_8040E0D4_de(&first, &basis, arg0, &args) != 0) {
        if ((((Widget_func_8040E67C_de *)arg0)->flags & 0x200) != 0) {
            func_802A1898_de(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            func_8040F488_de(&transformed, &basis);
            func_802A1870_de(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        func_8040E7FC_de(((struct Tree *)arg0)->child, args);
        if (changed != 0) {
            func_802A1870_de(value.x, value.z, value.y, value.w);
        }
    }
}
