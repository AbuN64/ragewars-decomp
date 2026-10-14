#include "shared/world.h"
#include "span_1000/code_80293A04.h"
#include "types.h"

extern void func_80293334_de(void *arg0, void *arg1, void *arg2);
extern void func_80286AA8_de(void *, void *, void *);
extern void func_80298368_de(s32 arg0);


extern s32 D_8014288C;

void func_802943C4_de(void *arg0) {
    func_80293334_de(arg0, 0, 0);
    func_80286AA8_de(&D_8011FE88, 0, 0);
    D_8014288C = 0;
    func_80298368_de(0x18);
    func_8025E2D4_de(0x34);
}
