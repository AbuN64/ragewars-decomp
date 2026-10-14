#include "span_16E000/code_804251F4.h"
#include "types.h"
/* Upgrades the thirteen weapon levels of player record D_80102B00[index] from the number of its 50
   achievement flags func_80265650_de reports set: every two achievements from 2 raise one more weapon
   to level 2 and, from 28, one more of twelve to level 3, in a fixed weapon order. */

extern u8 D_80102B00[];

extern s32 func_80265650_de(u8 *, s32);

static inline s32 count_achievements(s32 index) {
    s32 count;
    s32 i;

    count = 0;
    i = 0;
    do {
        if (func_80265650_de(D_80102B00 + index * 400 + 0x4A, i) == 1) {
            count++;
        }
        i++;
    } while (i < 50);
    return count;
}

void func_804259E0_de(s32 index) {
    u8 *record;
    s32 count;

    record = D_80102B00 + index * 400;
    count = count_achievements(index);
    if (count >= 2) {
        record[0x57] = 2;
    }
    if (count >= 4) {
        record[0x5C] = 2;
    }
    if (count >= 6) {
        record[0x58] = 2;
    }
    if (count >= 8) {
        record[0x60] = 2;
    }
    if (count >= 10) {
        record[0x59] = 2;
    }
    if (count >= 12) {
        record[0x5A] = 2;
    }
    if (count >= 14) {
        record[0x61] = 2;
    }
    if (count >= 16) {
        record[0x5D] = 2;
    }
    if (count >= 18) {
        record[0x68] = 2;
    }
    if (count >= 20) {
        record[0x5E] = 2;
    }
    if (count >= 22) {
        record[0x5B] = 2;
    }
    if (count >= 24) {
        record[0x5F] = 2;
    }
    if (count >= 26) {
        record[0x69] = 2;
    }
    if (count >= 28) {
        record[0x57] = 3;
    }
    if (count >= 30) {
        record[0x5C] = 3;
    }
    if (count >= 32) {
        record[0x58] = 3;
    }
    if (count >= 34) {
        record[0x60] = 3;
    }
    if (count >= 36) {
        record[0x59] = 3;
    }
    if (count >= 38) {
        record[0x5A] = 3;
    }
    if (count >= 40) {
        record[0x61] = 3;
    }
    if (count >= 42) {
        record[0x68] = 3;
    }
    if (count >= 44) {
        record[0x5E] = 3;
    }
    if (count >= 46) {
        record[0x5B] = 3;
    }
    if (count >= 48) {
        record[0x5F] = 3;
    }
    if (count >= 50) {
        record[0x69] = 3;
    }
}
