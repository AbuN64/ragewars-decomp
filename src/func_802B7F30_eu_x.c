#include "span_1000/code_802BB15C.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802B7B80.h"
#include "span_1000/code_802B9BB4.h"
#include "types.h"

extern void *D_800D8380[];
extern u8 D_8014D4B0;
extern u8 D_8014D5E0[];
extern u8 D_8014D6E0;
extern u8 D_80154110[];


extern s32 func_802B9CB0_de(s32, s32);
extern u32 func_802B8C88_de(void *arg0);


u32 func_802B7F30_eu_x(Triple *arg0) {
    Block40 saved;
    u8 *source;
    s32 i;

    source = D_80154110;
    if (D_800D8380[arg0->z] == 0) {
        return 5;
    } else {
        u32 result;
        s32 count;

        func_802B9C14_de();
        D_8014D4B0 = 3;
        func_802B9CB0_de(1, &D_8014D5E0[arg0->z << 6]);
        func_802BB2A0_de(arg0->y, 0, 1);
        func_802B9CB0_de(0, D_80154110);
        func_802BB2A0_de(arg0->y, 0, 1);
        count = arg0->z;
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
        if ((result == 0) && ((func_802B8C88_de(&D_8014D6E0) & 0xFF) != saved.bytes[0x26])) {
            result = 4;
        }
        func_802B9C80_de();
        return result;
    }
}

extern void *D_800D8380[];
extern u8 D_8014D4B0;
extern u8 D_8014D4C0[];
extern u8 D_8014D5C0;
extern u8 D_80154110[];


extern s32 func_802B9CB0_de(s32, s32);
extern u32 func_802B8C88_de(void *arg0);


u32 func_802B80F4_eu_x(Triple *arg0) {
    Block40 saved;
    u8 *source;
    s32 i;

    source = D_80154110;
    if (D_800D8380[arg0->z] == 0) {
        return 5;
    } else {
        u32 result;
        s32 count;

        func_802B9C14_de();
        D_8014D4B0 = 3;
        func_802B9CB0_de(1, &D_8014D4C0[arg0->z << 6]);
        func_802BB2A0_de(arg0->y, 0, 1);
        func_802B9CB0_de(0, D_80154110);
        func_802BB2A0_de(arg0->y, 0, 1);
        count = arg0->z;
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
