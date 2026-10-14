#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE254.h"
#include "types.h"

extern s32 D_8014D3E8;
extern s32 func_802AE380_us_rev1(u8 *);
extern void func_802AEAB4_us_rev1(s32, s32);



s32 func_802AF6A0_us_rev1(void) {
    ReadWord first;
    ReadWord second;
    s32 word;
    s32 var_s2;

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
                                    func_802AEAB4_us_rev1(first.word, word);
                                    var_s2 = D_8014D3E8 == 0;
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
