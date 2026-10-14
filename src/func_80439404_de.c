#include "span_16E000/code_804379C8.h"
#include "types.h"

/* Calls func_8029973C_de, then passes -1 to func_8042E988_de when func_802999A0_de reports 0x16 for zero
   and 0xB otherwise, then calls func_802998A8_de. Returns zero. */
extern void func_8029973C_de();
extern s32 func_802999A0_de(s32);
extern void func_8042E988_de(s32);
extern void func_802998A8_de();

s32 func_80439404_de(void) {
    func_8029973C_de();
    func_8042E988_de(func_802999A0_de(0) == 0x16 ? -1 : 0xB);
    func_802998A8_de();
    return 0;
}
