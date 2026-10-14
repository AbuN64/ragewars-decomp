#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE254.h"
#include "types.h"
/* Reads two big-endian words from the port, passes 0x80100000 and the first word to func_802AE834_us_rev1, and when its output equals the second word stores 1, 0x80100000 and the first word into D_800D3640..D_800D3648 and returns 1. Adapted from func_802AF544_us_rev1, with the read address fixed at 0x80100000 through an addr local, the returned word compared against the second word, and the three global stores added. */

extern s32 D_8014D3E8;



extern s32 func_802AE380_us_rev1(u8 *);
extern void func_802AE834_us_rev1(s32, s32, void *);



s32 func_802AF7F8_us_rev1(void) {
    ReadWord first;
    ReadWord second;
    s32 word;
    s32 var_s2;
    s32 output;
    s32 addr;

    func_802AE380_us_rev1(&first.byte);
    var_s2 = 0;
    if (D_8014D3E8 == 0) {
        word = first.byte << 8;
        func_802AE380_us_rev1(&first.byte);
        if (D_8014D3E8 == 0) {
            word |= first.byte;
            func_802AE380_us_rev1(&first.byte);
            word <<= 8;
            if (D_8014D3E8 == 0) {
                word |= first.byte;
                func_802AE380_us_rev1(&first.byte);
                word <<= 8;
                if (D_8014D3E8 == 0) {
                    word |= first.byte;
                    first.word = word;
                    func_802AE380_us_rev1(&second.byte);
                    if (D_8014D3E8 == 0) {
                        word = second.byte << 8;
                        func_802AE380_us_rev1(&second.byte);
                        if (D_8014D3E8 == 0) {
                            word |= second.byte;
                            func_802AE380_us_rev1(&second.byte);
                            word <<= 8;
                            if (D_8014D3E8 == 0) {
                                word |= second.byte;
                                func_802AE380_us_rev1(&second.byte);
                                word <<= 8;
                                if (D_8014D3E8 == 0) {
                                    word |= second.byte;
                                    second.word = word;
                                    addr = 0x80100000;
                                    func_802AE834_us_rev1(addr, first.word, &output);
                                    if (D_8014D3E8 == 0 && second.word == output) {
                                        D_800D3640 = 1;
                                        var_s2 = 1;
                                        D_800D3644 = 0x80100000;
                                        D_800D3648 = first.word;
                                    }
                                }
                            }
                            goto block_9;
                        }
                    }
                } else {
                    goto block_9;
                }
            }
block_9:
            ;
        }
    }
    return var_s2;
}
