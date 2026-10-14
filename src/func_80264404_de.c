#include "span_1000/code_802636D0.h"
#include "types.h"

extern void func_802644A8_de(void *arg0);
extern s32 func_802A23B4_de(void);
extern s32 func_802A23A4_de(void);
extern void func_8029A650_de(void *arg0);

extern u8 D_800CBC10;
extern s32 D_8010F328;
extern u8 D_8010B0E0;

void func_80264404_de(void) {
    s32 i;
    u8 *p;
    s32 temp;
    s32 one;

    if (D_800CBC10 != 0) {
        i = 0;
        one = 1;
        p = &D_8010F328;
        for (; i < 4; i++, p += 0x224) {
            func_802644A8_de(p);
            temp = func_802A23B4_de();
            if (temp != one) {
                continue;
            }
            if (func_802A23A4_de() != temp) {
                continue;
            }
            func_8029A650_de(p);
        }
        func_802644A8_de(&D_8010B0E0);
    }
}
