#include "span_1000/code_802A6AC0.h"
#include "types.h"

extern void func_80295E84_de(s32 *arg0, s32 arg1);
extern void func_80283064_de(void *arg0, s32 *arg1);




void func_802A5F9C_de(void *unused, void *arg1, void *arg2) {
    Entry_func_802A6F68_de *entry = arg1;
    s32 field34;
    s32 *p;

    field34 = entry->unk34;
    if (field34 != -1) {
        p = &entry->unk14;
        func_80295E84_de(p, field34);
        if (arg2 != 0) {
            func_80283064_de(arg2, p);
        }
    }
}
