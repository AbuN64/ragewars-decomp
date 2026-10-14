#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025E568.h"
#include "types.h"
/* Reads one envelope segment from a bitstream, either as raw floats or as scaled table values. */




extern s32 D_8010AC78;

extern s32 D_8010AC80;

extern u32 func_802607B8_de(u32 *arg0, s32 arg1);

extern f32 func_80260650_de(f32 arg0, f32 arg1, s32 arg2);
extern void func_8025FD74_de(Segment8025FFD0 *arg0);

void func_8025FFB0_de(Segment8025FFD0 *arg0, u32 *arg1) {
    u32 bits;
    u32 first;
    u32 second;
    f32 lo;
    f32 hi;

    bits = *arg1;
    arg0->unk2C = func_802607B8_de(&bits, 6);
    if (D_8010AC78 != 0) {
        first = func_802607B8_de(&bits, 0x20);
        second = func_802607B8_de(&bits, 0x20);
        lo = *(f32 *)&first;
        hi = *(f32 *)&second;
    } else {
        first = func_802607B8_de(&bits, 6);
        second = func_802607B8_de(&bits, 6);
        lo = func_80260634_de((f32)first, 6);
        hi = func_80260634_de((f32)second, 6);
        lo = func_80260650_de(lo, D_8010AC7C, D_8010AC80);
        hi = func_80260650_de(hi, D_8010AC7C, D_8010AC80);
    }
    arg0->unk4 = lo;
    arg0->unk8 = hi - lo;
    do {
        arg0->unk0 = func_802607B8_de(&bits, 6);
        arg0->unk28 = 0;
        arg0->unk24 = 0;
        arg0->unkC = bits;
        func_8025FD74_de(arg0);
    } while (0);
    *arg1 = bits;
}
