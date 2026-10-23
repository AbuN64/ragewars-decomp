#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V1.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.H"
#include "sdk/al_globals.h"

void func_802B2450_de(ListLink *arg0) {
    if (arg0->next != 0) {
        arg0->next->prev = arg0->prev;
    }
    if (arg0->prev != 0) {
        arg0->prev->next = arg0->next;
    }
}

void func_802B2480_de(void *arg0, void **arg1) {
    void *temp;

    temp = *arg1;
    ((Field_void_4 *)(arg0))->value = arg1;
    *(void **)arg0 = temp;
    temp = *arg1;
    if (temp != 0) {
        ((Field_void_4 *)(temp))->value = arg0;
    }
    *arg1 = arg0;
}

extern void func_802B3770_de(void);

void func_802B24A0_de(void *arg0) {
    void **p;

    p = (void **)&D_800D4070;
    if (*p == 0) {
        *p = arg0;
        func_802B3770_de();
    }
}


void func_802B24D0_de(s32 *arg0) {
    void **p;

    p = (void **)&D_800D4070;
    if (*p != 0) {
        func_802B31F0_de(arg0);
        *p = 0;
    }
}
