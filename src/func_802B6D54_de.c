#include "span_1000/code_802B7058.h"
#include "types.h"



void func_802B6D54_de(f32 *arg0, s32 *arg1) {
    s32 *inLo;
    u32 *inHi;
    f32 *outRow;
    f32 *outPair;
    f32 mult;
    u32 mask;
    s32 raw0;
    u32 raw1;
    s32 v0;
    s32 v1;
    s32 i;
    s32 j;

    inLo = arg1;
    inHi = (u32 *) (arg1 + 8);
    i = 0;
    mask = 0xFFFF0000;
    mult = D_800C7890_de;
    outRow = arg0;
    do {
        j = 0;
        outPair = outRow;
        do {
            raw0 = *inLo;
            raw1 = *inHi;
            inHi += 1;
            v0 = (raw0 & mask) | (raw1 >> 16);
            v1 = ((raw0 << 16) & mask) | (raw1 & 0xFFFF);
            inLo += 1;
            j += 1;
            outPair[0] = (f32) v0 * mult;
            outPair[1] = (f32) v1 * mult;
            outPair += 2;
        } while (j < 2);
        i += 1;
        outRow += 4;
    } while (i < 4);
}
