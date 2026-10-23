#include "MENU/OBJECT1C8.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/MENURECAT24.H"
#include "MENU/ITEMS/80442BC8_16.H"
#include "MENU/PAK/80405DC0_2.H"

/* Loads the owner at offset 0x1C of the second argument into D_80145040 through func_8022A5A0_de,
   calls func_804097E8_de, and hands the owner, its word at 0x698 and a zero with the resource
   D_44F0DC to Pak_OpenDialog for the block 0x5DC bytes into D_80145040. Returns one. */




extern char D_80145040[];
extern void func_8022A5A0_de(void *, struct OwnerRecAt698 *);
extern void Pak_OpenDialog(void *, void *, struct OwnerRecAt698 *, s32, s32);

s32 func_80443694_de(void *unused, struct HolderRecAt1CV1 *holder) {
    struct OwnerRecAt698 *owner = holder->owner;

    func_8022A5A0_de(D_80145040, owner);
    func_804097E8_de();
    Pak_OpenDialog(D_80145040 + 0x5DC, D_0044E48C, owner, owner->value, 0);
    return 1;
}
