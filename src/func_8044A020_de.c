#include "span_16E000/code_80447BB0.h"
#include "types.h"

/* Sets the byte at offset 0x78 of the object at 0x5D8 of an actor, calls func_80448EF4_de with the
   actor, its second argument and one, then func_80214178_de on offsets 0x2E8 and 0x458 with two and
   func_8021B1E4_de with D_80146898, zero and one. */




extern s32 D_80146898;
extern void func_80448EF4_de(struct Actor_func_8044A020_de *, void *, s32);
extern void func_80214178_de(void *, void *, s32);
extern void func_8021B1E4_de(struct Actor_func_8044A020_de *, s32, s32, s32);




void func_8044A020_de(struct Actor_func_8044A020_de *actor, void *second) {
    actor->part->active = 1;
    func_80448EF4_de(actor, second, 1);
    func_80214178_de(&actor->firstEffect, &actor->secondEffect, 2);
    func_8021B1E4_de(actor, D_80146898, 0, 1);
}
