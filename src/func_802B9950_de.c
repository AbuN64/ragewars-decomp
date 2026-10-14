#include "span_1000/code_802B8DD0.h"
#include "types.h"

extern s32 D_800D83C0;
extern s32 D_8014EA50;
extern s32 D_8014EA58;

extern void func_802BAC60_de(s32 *arg0, s32 *arg1, s32 arg2);
extern void func_802BB420_de(s32 *arg0, s32 arg1, s32 arg2);

void func_802B9950_de(void) {
    D_800D83C0 = 1;
    func_802BAC60_de(&D_8014EA58, &D_8014EA50, 1);
    func_802BB420_de(&D_8014EA58, 0, 0);
}
