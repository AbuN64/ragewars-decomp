#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"




extern void func_8024796C_de(void *arg0);
extern void func_80274244_de(void *arg0, void *arg1);
extern void func_80272898_de(void *, void *, void *);

void *func_8024BC94_de(void *arg0, s32 unused1, struct IntPair arg2) {
    s32 sp10[4];
    s32 sp20[16];
    Triple sp60;

    func_8024796C_de(sp10);
    func_80274244_de(sp10, sp20);
    func_80272898_de(sp20, &arg2, &sp60);
    *(Triple *)arg0 = sp60;
    return arg0;
}
