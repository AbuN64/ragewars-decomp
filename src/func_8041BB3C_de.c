#include "span_16E000/code_8041B020.h"
#include "types.h"

/* Calls func_8029973C_de and, for an event of kind one on a slot with no word at 0x5C whose child at 0x4C has flag 0x10 of its halfword at 0x12 set and a target at 0x34, passes the owner, the slot and the target to func_8041B8DC_de, returning zero. */




extern void func_8029973C_de();
extern void func_8041B8DC_de(struct Owner_func_8041BB3C_de *, s32, void *);

s32 func_8041BB3C_de(struct Owner_func_8041BB3C_de *owner, s32 arg1, s32 slot, s32 kind) {
    struct Child *child;

    func_8029973C_de();
    if (kind != 1) {
        return 0;
    }
    if (owner->busy[(u16)slot] != 0) {
        return 0;
    }
    child = owner->children[(u16)slot];
    if (child == 0) {
        return 0;
    }
    if (!(child->flags & 0x10)) {
        return 0;
    }
    if (child->target == 0) {
        return 0;
    }
    func_8041B8DC_de(owner, (u16)slot, child->target);
    return 0;
}
