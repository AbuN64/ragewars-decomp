#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

extern void func_802BAC60_de(s32 arg0, s32 arg1, s32 arg2);
extern void func_802BB550_de(s32 arg0, s32 arg1, s32 arg2);
extern void func_802A001C_de(s32 arg0, s32 arg1, s32 arg2);
extern void func_802BAC90_de(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_802BB750_de(s32 arg0);

extern char D_0025657C;


void func_80256280_de(s32 arg0, s32 arg1) {
    s32 s0;
    s32 s1;

    func_802BAC60_de(arg0 + 0x230, arg0 + 0x248, 0x200);
    s0 = arg0 + 0xA48;
    func_802BAC60_de(s0, arg0 + 0xA60, 1);
    func_802BB550_de(8, s0, 0x7D1);
    func_80255CA0_de(arg0 + 0x5068, 0x18, 0x1C);
    func_80255CA0_de(arg0 + 0x507C, 0x18, 0x1C);
    s1 = 0;
    s0 = 0xE68;
    do {
        ((struct func_80204468_S3 *) (arg0 + s0))->unk14 = 0;
        func_80255D14_de(arg0 + 0x5068, arg0 + s0);
        s1 += 1;
        s0 += 0x20;
    } while (s1 < 0x210);
    func_802A001C_de(arg0 + 0xA68, arg1, 0x400);
    func_802BAC90_de(arg0, arg1, &D_0025657C, arg0, arg0 + 0xE68, D_800CD8C4_de);
    func_802BB750_de(arg0);
}
