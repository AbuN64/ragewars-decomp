#include "span_16E000/code_804290E8.h"
#include "types.h"

/* Calls func_8029973C_de, then passes 0xB to func_8042E988_de when func_802999A0_de reports 0xB for zero
   and -1 otherwise, then calls func_802998A8_de. Returns zero. */
extern void func_8029973C_de();
extern s32 func_802999A0_de(s32);
extern void func_8042E988_de(s32);
extern void func_802998A8_de();

s32 func_804290F4_de(void) {
    func_8029973C_de();
    func_8042E988_de(func_802999A0_de(0) == 0xB ? 0xB : -1);
    func_802998A8_de();
    return 0;
}
