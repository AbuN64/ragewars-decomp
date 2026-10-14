#include "shared/world.h"
#include "span_16E000/code_80409A88.h"
#include "types.h"

/* Calls func_80264788_de on its second argument, then func_8044D528_de on D_8011FE88 with D_8013B2C8
   and 2. */

extern s32 D_8013B2C8;
extern void func_80264788_de(void *);
extern void func_8044D528_de(void *, s32, s32);

void func_80409F6C_de(void *unused, void *object) {
    func_80264788_de(object);
    func_8044D528_de(&D_8011FE88, D_8013B2C8, 2);
}
