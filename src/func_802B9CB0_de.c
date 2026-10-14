#include "span_1000/code_802B9BB4.h"
#include "common/unused.h"
#include "device_io.h"
#include "types.h"


extern void func_802BAC50_de(void *arg0, void *arg1, s32 arg2);
extern int func_802B9D70_de(void);
extern void func_802BD280_de(s32 arg0, s32 arg1);
extern s32 func_802BBBC0_de(s32);
extern void func_802BCF70_de(s32 arg0, s32 arg1);

extern s32 D_800C7990_de;
extern s32 D_800C7994_de;

s32 func_802B9CB0_de(s32 arg0, s32 arg1) {
    if (arg1 & 3) {
        func_802BAC50_de(&D_800C7990_de, &D_800C7994_de, 0x37);
    }
    if (func_802B9D70_de() != 0) {
        return -1;
    }
    if (arg0 == 1) {
        func_802BD280_de(arg1, 0x40);
    }
    IO_WRITE(0xA4800000U, func_802BBBC0_de(arg1));
    if (arg0 == 0) {
        IO_WRITE(0xA4800004U, 0x1FC007C0U);
    } else {
        IO_WRITE(0xA4800010U, 0x1FC007C0U);
    }
    if (arg0 == 0) {
        func_802BCF70_de(arg1, 0x40);
    }
    return 0;
}
