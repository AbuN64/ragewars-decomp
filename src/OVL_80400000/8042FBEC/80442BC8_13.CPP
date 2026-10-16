#include "span_16E000/code_80442BC8.h"
#include "TYPES.H"
#include "common/unused.h"
#include "span_16E000/code_80405DC0.h"

/* Loads the owner at offset 0x1C of the second argument into D_80145040 through func_8022A5A0_de,
   calls func_804097E8_de, and hands the owner, its word at 0x698 and a zero with the resource
   D_44F0DC to func_80442574_de for the block 0x5DC bytes into D_80145040. Returns one. */




extern char D_80145040[];
extern void func_8022A5A0_de(void *, struct OwnerRecAt698 *);
extern void func_80442574_de(void *, void *, struct OwnerRecAt698 *, s32, s32);

s32 func_80443694_de(void *unused, struct HolderRecAt1CV1 *holder) {
    struct OwnerRecAt698 *owner = holder->owner;

    func_8022A5A0_de(D_80145040, owner);
    func_804097E8_de();
    func_80442574_de(D_80145040 + 0x5DC, D_0044E48C, owner, owner->value, 0);
    return 1;
}
