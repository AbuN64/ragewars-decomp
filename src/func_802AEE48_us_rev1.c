#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE254.h"
#include "types.h"

extern s32 D_8014D3E8;
extern s32 (*D_800D364C)(s32 arg0);
extern void func_802AE380_us_rev1(u8 *arg0);
extern s32 func_802AE5AC_us_rev1(s32);



s32 func_802AEE48_us_rev1(void) {
    ReadWord first;
    s32 word;
    u32 value;

    first.word = 0;
    func_802AE380_us_rev1(&first.byte);
    value = 0;
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
                    if (D_800D364C != 0) {
                        value = D_800D364C(first.word);
                    }
                    func_802AE5AC_us_rev1(value >> 24);
                    if (D_8014D3E8 == 0) {
                        func_802AE5AC_us_rev1((value >> 16) & 0xFF);
                        if (D_8014D3E8 == 0) {
                            func_802AE5AC_us_rev1((value >> 8) & 0xFF);
                            if (D_8014D3E8 == 0) {
                                func_802AE5AC_us_rev1(value & 0xFF);
                            }
                        }
                    }
                    if (D_8014D3E8 == 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
