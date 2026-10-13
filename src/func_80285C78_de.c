#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802646F4.h"
#include "span_1000/code_8028567C.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);

extern void func_80255ED8_de(void *, s32);







void func_80285C78_de(void *arg0) {
    void *node;
    void *next;
    s32 flag;
    u32 saved;
    s32 *inner;

    saved = func_802BCF30_de();
    for (node = ((func_8025CA44_S1 *)(arg0))->unk14.head; node != 0; node = next) {
        next = ((func_80285C48_S2 *)(node))->unk4;
        flag = 0;
        if (func_80264DF0_de((char *)node + 0x20) != 0 || func_80264DF0_de((char *)node + 0x2C) != 0) {
            flag = 1;
        }
        if (flag == 0) {
            continue;
        }
        inner = ((func_80285C48_S2 *)(node))->unk38;
        if (inner != 0) {
            *inner = 0;
        }
        func_80255ED8_de(&((func_8025CA44_S1 *)(arg0))->unk14, node);
        func_80255D14_de(arg0, node);
    }
    func_802BCF50_de(saved);
}
