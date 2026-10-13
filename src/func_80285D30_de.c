#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028567C.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

extern s32 func_802BCF30_de(void);
extern void func_80255ED8_de(void *, s32);
extern void func_802BCF50_de(s32 arg0);







void func_80285D30_de(void *arg0) {
    void *node;
    void *next;
    s32 saved;

    saved = func_802BCF30_de();
    node = ((Pool_func_80285B64_de *)arg0)->active.head;
    if (node != 0) {
        do {
            next = ((Node_func_80285B64_de *)node)->next;
            func_80255ED8_de(&((Pool_func_80285B64_de *)arg0)->active, node);
            func_80255D14_de(arg0, node);
            node = next;
        } while (node != 0);
    }
    ((Pool_func_80285B64_de *)arg0)->baseLevel = 0;
    func_802BCF50_de(saved);
}
