#include "span_1000/code_8022AE90.h"
#include "types.h"

extern void func_80226DD0_de(void *arg0, s8 *arg1);
extern void func_802732D0_de(char *, f32 *);

void func_8022B144_de(void *arg0, f32 *arg1) {
    s8 sp10[0x40];
    func_80226DD0_de(arg0, sp10);
    func_802732D0_de(sp10, arg1);
}
