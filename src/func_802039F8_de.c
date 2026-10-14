#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802022E0.h"
/** Run the object's update hook, then advance its timer and fire the expiry action when due. */


extern float D_800D2988;

extern void func_80214178_de(void *, void *, int);






void func_802039F8_de(char *arg0, Obj *arg1) {
    if (arg1->hook != 0 && arg1->hook->fn != 0) {
        arg1->hook->fn(arg0, arg1);
    }
    if (((struct OwnerRecAtE4 *)(arg0))->id == 0x40C) {
        arg1->timer += D_800D2988;
        if (D_800C1A48_de < arg1->timer || arg1->count <= 0) {
            func_80214178_de(arg0, arg1, 0x40);
        }
    }
}
