#include "span_16E000/code_8040B45C.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80412270.h"
#include "span_16E000/code_80413728.h"
#include "types.h"

/* The same table as func_80413608_de reads, at the field 24 bytes into the 52-byte record. The
   debugger returned 1 on every one of 400 calls, so the observed records all carry a non-zero
   value here and the zero arm is untested by execution. */
extern s32 D_800E2B40[][13];

/* Copies record i of the 52-byte table D_800E2B20 into the destination. */


extern struct Format D_800E2B20[];

int func_8041369C_de(int *value) {
    return value[4];
}

int func_804136A8_de(int *value) {
    return value[3];
}

/* Returns the word at offset 0x18 of a record. */
s32 func_804136B4_de(s32 *record) {
    return record[0x18 / 4];
}

/* Returns the word at offset 0x14 of a record. */
s32 func_804136C0_de(s32 *record) {
    return record[0x14 / 4];
}

int func_804136CC_de(void *object) {
    func_8022BC04_S3 *record = object;
    return record->unk10 > 0;
}

s32 func_804136D8_de(u8 *record) {
    return D_800E2B40[*record][0] != 0;
}

/* Returns bit 1 of the flag byte at offset 1 of a record; func_80413714_de returns bit 0. */
u8 func_80413704_de(u8 *record) {
    return (record[1] >> 1) & 1;
}

/* Returns bit 0 of the flag byte at offset 1 of a record; func_80413704_de returns bit 1. */
u8 func_80413714_de(u8 *record) {
    return record[1] & 1;
}

void func_80413720_de(struct Config *out, unsigned char type, short x, short y,
                  short a, short b, int enable1, int d, int e, int enable2,
                  int f, int g, short last) {
    out->type = type;
    out->x = x;
    out->y = y;
    out->flags = 0;
    out->last = last;
    out->a = a;
    out->b = b;
    out->g = e;
    out->d = d;
    out->f = g;
    out->e = f;
    if (enable1) {
        out->flags = 1;
    }
    if (enable2) {
        out->flags |= 2;
    }
}

void func_8041379C_de(s32 index, struct Format *out) {
    *out = D_800E2B20[index];
}
