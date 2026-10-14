#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8023B9A0.h"
#include "types.h"

extern s32 D_800FF254;

extern void func_802BAC60_de(void *arg0, s32 arg1, s32 arg2);
extern void func_802BB420_de(void *arg0, void *arg1, s32 arg2);
extern void func_802BB2A0_de(s32, s32, s32);
extern void func_80253838_de(s32 arg0, void *arg1);






void func_8023C85C_de(s32 arg0) {
    char sp10[0x18];
    Block_func_8023C85C_de block;
    s32 sp38;
    void *sp3C;

    func_802BAC60_de(sp10, (s32)&sp38, 1);
    block.type = 2;
    block.value = arg0;
    block.data = sp10;
    func_802BB420_de(&D_800FF254, &block, 1);
    func_802BB2A0_de(sp10, &sp3C, 1);
    func_80253838_de(0, ((Draw *)(sp3C))->model);
}
