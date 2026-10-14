#include "span_1000/code_8025A3EC.h"
#include "common/unused.h"
#include "span_1000/code_802B7B80.h"
#include "shared/func_802B80B4_eu_closed.h"

u32 func_802B80B4_eu(void *arg0) {
    Block40 saved;
    u8 *source;
    s32 i;

    source = D_80154110;
    if (D_800D8380[((func_802B80B4_eu_Arg *)arg0)->index] == 0) {
        return 5;
    } else {
        u32 result;
        s32 count;

        func_802B9C14_de();
        D_8014D4B0 = 3;
        func_802B9CB0_de(1, &D_8014D4C0[((func_802B80B4_eu_Arg *)arg0)->index << 6]);
        func_802BB2A0_de(((func_802B80B4_eu_Arg *)arg0)->field4, 0, 1);
        func_802B9CB0_de(0, D_80154110);
        func_802BB2A0_de(((func_802B80B4_eu_Arg *)arg0)->field4, 0, 1);
        count = ((func_802B80B4_eu_Arg *)arg0)->index;
        if (count != 0) {
            i = 0;
            if (count > 0) {
                do {
                    i++;
                    source++;
                } while (i < count);
            }
        }
        saved = *(Block40 *)source;
        result = (saved.bytes[2] & 0xC0) >> 4;
        if ((result == 0) && ((func_802B8C88_de(&D_8014D5C0) & 0xFF) != saved.bytes[0x26])) {
            result = 4;
        }
        func_802B9C80_de();
        return result;
    }
}
