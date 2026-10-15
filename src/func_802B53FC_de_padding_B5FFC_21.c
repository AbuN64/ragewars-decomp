#include "span_1000/code_802B53FC.h"
#include "types.h"

void func_802B6B80_de(s32 *arg0) {
    f32 matrix[16];
    u8 *diagBase;
    u8 *diag;
    u8 *elem;
    u8 *row;
    s32 r;
    s32 c;
    f32 one;
    s32 *outLo;
    s32 *outHi;
    f32 *inRow;
    f32 *inPair;
    f32 mult;
    u32 mask;
    f32 t1;
    f32 t0;
    s32 v0;
    s32 v1;
    s32 i;
    s32 j;

    r = 0;
    one = D_800C7880_de;
    diagBase = (u8 *)matrix;
    row = (u8 *)matrix;
    do {
        c = 0;
        diag = diagBase;
        elem = row;
        do {
            if (r == c) {
                *(f32 *)diag = one;
            } else {
                *(s32 *)elem = 0;
            }
            c++;
            elem += 4;
        } while (c < 4);
        diagBase += 0x14;
        r++;
        row += 0x10;
    } while (r < 4);

    outLo = arg0;
    outHi = arg0 + 8;
    i = 0;
    mult = D_800C7884_de;
    mask = 0xFFFF0000;
    inRow = matrix;
    do {
        j = 0;
        inPair = inRow;
        do {
            t1 = inPair[0] * mult;
            t0 = inPair[1] * mult;
            inPair += 2;
            j++;
            v0 = (s32)t1;
            v1 = (s32)t0;
            *outLo = (v0 & mask) | ((u32)v1 >> 16);
            outLo++;
            *outHi = ((v0 << 16) & mask) | (v1 & 0xFFFF);
            outHi++;
        } while (j < 2);
        i++;
        inRow += 4;
    } while (i < 4);
}

void func_802B6C6C_de(u8 *arg0) {
    u8 *diag;
    u8 *elem;
    s32 r;
    s32 c;
    f32 one;

    r = 0;
    one = D_800C7888_de;
    diag = arg0;
    do {
        c = 0;
        elem = arg0;
        do {
            if (r == c) {
                *(f32 *)diag = one;
            } else {
                *(s32 *)elem = 0;
            }
            c += 1;
            elem += 4;
        } while (c < 4);
        diag += 0x14;
        r += 1;
        arg0 += 0x10;
    } while (r < 4);
}

void func_802B6CBC_de(f32 *arg0, s32 *arg1) {
    s32 *outLo;
    s32 *outHi;
    f32 *inRow;
    f32 *inPair;
    f32 mult;
    u32 mask;
    f32 t1;
    f32 t0;
    s32 v0;
    s32 v1;
    s32 i;
    s32 j;

    outLo = arg1;
    outHi = arg1 + 8;
    i = 0;
    mult = D_800C788C_de;
    mask = 0xFFFF0000;
    inRow = arg0;
    do {
        j = 0;
        inPair = inRow;
        do {
            t1 = inPair[0] * mult;
            t0 = inPair[1] * mult;
            inPair += 2;
            j += 1;
            v0 = (s32) t1;
            v1 = (s32) t0;
            *outLo = (v0 & mask) | ((u32) v1 >> 16);
            outLo += 1;
            *outHi = ((v0 << 16) & mask) | (v1 & 0xFFFF);
            outHi += 1;
        } while (j < 2);
        i += 1;
        inRow += 4;
    } while (i < 4);
}
