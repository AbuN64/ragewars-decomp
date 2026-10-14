#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_802A1264.h"
#include "span_16E000/code_8040C780.h"
#include "types.h"











extern Manager_func_80298FE8_de *D_8014D080;
extern s32 D_80146E04;


extern s32 D_8014D0A0;

extern f64 func_802A18CC_de(void);
extern void func_8029764C_de(s32, s32, s32, void *, s32);

extern void func_8040E67C_de(void *, Args_func_80298FE8_de);


extern s32 func_8040E0D4_de(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *, void *, Args_func_80298FE8_de *);

void func_80298FE8_de(void) {
    Args_func_80298FE8_de args;
    Quad_func_802A1BE0_de first;
    Quad_func_802A1BE0_de basis;
    s32 delta;
    s32 index;
    s32 offset;
    s32 now;

    args.word0 = D_8014D080->field534;
    args.word4 = D_8014D080->field538;
    args.byte14 = 0xFF;
    args.word8 = 0;
    args.wordC = D_800C5678_de;
    args.word10 = D_800C5678_de;
    args.word18 = D_8014D080->field534;
    D_80146E04 = 0;
    args.word20 = D_8014D080->field538;
    args.word1C = D_80146E08 - 1;
    args.word24 = D_80146E0C - 1;

    now = (s32)(func_802A18CC_de() * D_800C5680_de);
    if (D_800CD8E0 == 0) {
        D_800CD8E0 = now;
    }
    delta = now - D_800CD8E0;
    D_800CD8E0 = now;
    func_8029764C_de(0, 0xE0A, 0, &args, delta);

    index = D_8014D080->lowIndex;
    if (D_8014D080->index >= index) {
        offset = index * 0x1C;
        do {
            index++;
            func_802A18F4_de();
            func_8040E67C_de(*(void **)(offset + (s32)D_8014D080->entries), args);
            func_8040E894_de();
            func_802A18FC_de();
            func_8040E0D4_de(&first, &basis,
                          *(void **)(offset + (s32)D_8014D080->entries), &args);
            offset += 0x1C;
        } while (D_8014D080->index >= index);
    }
    func_8029764C_de(0, 0xE0A, 1, 0, delta);
    D_8014D0A0 = 0;
}
