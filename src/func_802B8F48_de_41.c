#include "common/unused.h"
#include "hardware_io.h"
#include "span_1000/code_802B9ED8.h"



extern void func_802BAC50_de(void *arg0, void *arg1, s32 arg2);
extern s32 func_802BBBC0_de(s32);

extern s32 D_800C79B0_de;
extern s32 D_800C79B4_de;

s32 func_802B9FD0_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg1 & 7) {
        func_802BAC50_de(&D_800C79B0_de, &D_800C79B4_de, 0x3A);
    }
    if (arg2 & 7) {
        func_802BAC50_de(&D_800C79B0_de, &D_800C79B4_de, 0x3B);
    }
    if (arg3 & 7) {
        func_802BAC50_de(&D_800C79B0_de, &D_800C79B4_de, 0x3C);
    }
    if (func_802B9FB0_de() != 0) {
        return -1;
    }
    IO_READ_WORD(0xA4040000U) = arg1;
    IO_READ_WORD(0xA4040004U) = func_802BBBC0_de(arg2);
    if (arg0 == 0) {
        IO_READ_WORD(0xA404000CU) = arg3 - 1;
    } else {
        IO_READ_WORD(0xA4040008U) = arg3 - 1;
    }
    return 0;
}
