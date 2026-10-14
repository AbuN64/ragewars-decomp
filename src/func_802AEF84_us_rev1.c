#include "span_1000/code_802AE254.h"
#include "common/unused.h"
#include "span_1000/code_802AE254.h"

extern u8 D_800CB480;


extern s32 func_802AE380_us_rev1(u8 *);
extern s32 func_802AE5AC_us_rev1(s32);
extern void func_802AEAB4_us_rev1(s32, s32);
extern s32 func_802BD400_de(u8 *arg0);

s32 func_802AEF84_us_rev1(void) {
    ReadWordRecAt4 first;
    u32 word;
    s32 result;
    u32 var_s0;
    u8 *data;

    result = 0;
    func_802AE380_us_rev1(&first.byte);
    data = &D_800CB480;
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
                    if (first.word >= (u32)func_802BD400_de(data)) {
                        var_s0 = func_802BD400_de(data);
                    } else {
                        var_s0 = first.word;
                    }
                    first.word = var_s0;
                    func_802AE5AC_us_rev1(var_s0 >> 24);
                    if (D_8014D3E8 == 0) {
                        func_802AE5AC_us_rev1((var_s0 >> 16) & 0xFF);
                        if (D_8014D3E8 == 0) {
                            func_802AE5AC_us_rev1((var_s0 >> 8) & 0xFF);
                            if (D_8014D3E8 == 0) {
                                func_802AE5AC_us_rev1(var_s0 & 0xFF);
                            }
                        }
                    }
                    func_802AEAB4_us_rev1(data, first.word);
                    if (D_8014D3E8 == 0) {
                        result = 1;
                    }
                }
            }
        }
    }
    return result;
}
