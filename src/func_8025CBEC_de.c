#include "span_1000/code_8025C544.h"
#include "span_1000/code_8025D948.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"




extern void func_80255ED8_de(void *, s32);





void func_8025CBEC_de(void *arg0) {
    Node_func_8025CBEC_de *cur;
    Node_func_8025CBEC_de *next;
    s32 value;

    cur = ((func_8025CC0C_S1 *)(arg0))->unk14.head;
    if (cur != 0) {
        do {
            value = cur->value;
            next = cur->next;
            func_8025E174_de(value);
            cur->state = -1;
            cur->value = -1;
            func_80255ED8_de(&((func_8025CC0C_S1 *)(arg0))->unk14, cur);
            func_80255D14_de(arg0, cur);
            cur = next;
        } while (cur != 0);
    }
}
