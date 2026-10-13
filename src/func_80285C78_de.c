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
    Node_func_80285B64_de **inner;

    saved = func_802BCF30_de();
    for (node = ((Pool_func_80285B64_de *)arg0)->active.head; node != 0; node = next) {
        next = ((Node_func_80285B64_de *)node)->next;
        flag = 0;
        if (func_80264DF0_de((char *)node + 0x20) != 0 || func_80264DF0_de((char *)node + 0x2C) != 0) {
            flag = 1;
        }
        if (flag == 0) {
            continue;
        }
        inner = ((Node_func_80285B64_de *)node)->owner;
        if (inner != 0) {
            *inner = 0;
        }
        func_80255ED8_de(&((Pool_func_80285B64_de *)arg0)->active, node);
        func_80255D14_de(arg0, node);
    }
    func_802BCF50_de(saved);
}
