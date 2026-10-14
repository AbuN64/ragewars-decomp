#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE254.h"
#include "types.h"

extern s32 D_8014D3E8;
extern s32 func_802AE380_us_rev1(u8 *);
extern s32 func_802AE5AC_us_rev1(s32);



s32 func_802AF33C_us_rev1(void) {
    ReadWord first;
    s32 word;
    s32 result;
    u16 value;

    func_802AE380_us_rev1(&first.byte);
    result = 0;
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
                    value = *(u16 *)first.word;
                    func_802AE5AC_us_rev1(value >> 8);
                    if (D_8014D3E8 == 0) {
                        func_802AE5AC_us_rev1(value & 0xFF);
                        result = D_8014D3E8 == 0;
                    }
                }
            }
        }
    }
    return result;
}
