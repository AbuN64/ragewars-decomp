#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802646F4.h"
#include "span_1000/code_8028567C.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);

extern void func_80255ED8_de(void *, void *);







static inline IntrusiveList *active_list(Pool_func_80285B64_de *pool) {
    return &pool->active;
}

void func_80285C78_de(void *arg0) {
    Node_func_80285B64_de *node;
    Node_func_80285B64_de *next;
    s32 flag;
    u32 saved;
    Node_func_80285B64_de **inner;

    saved = func_802BCF30_de();
    for (node = (*active_list(arg0)).head; node != 0; node = next) {
        next = node->next;
        flag = 0;
        if (func_80264DF0_de(&node->amplitudeHandle) != 0 || func_80264DF0_de(&node->lifetimeHandle) != 0) {
            flag = 1;
        }
        if (flag == 0) {
            continue;
        }
        inner = node->owner;
        if (inner != 0) {
            *inner = 0;
        }
        func_80255ED8_de(&(*active_list(arg0)), node);
        func_80255D14_de(arg0, node);
    }
    func_802BCF50_de(saved);
}
