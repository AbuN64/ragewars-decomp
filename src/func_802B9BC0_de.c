#include "span_1000/code_802B9BB4.h"
#include "types.h"

extern s32 D_800D83D0;
extern s32 D_8014EA70;
extern s32 D_8014EA78;

extern void func_802BAC60_de(s32 *arg0, s32 *arg1, s32 arg2);
extern void func_802BB420_de(s32 *arg0, s32 arg1, s32 arg2);

void func_802B9BC0_de(void) {
    D_800D83D0 = 1;
    func_802BAC60_de(&D_8014EA78, &D_8014EA70, 1);
    func_802BB420_de(&D_8014EA78, 0, 0);
}
