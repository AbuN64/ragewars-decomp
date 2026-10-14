#include "span_16E000/code_80423280.h"
#include "types.h"

/* Calls func_8029973C_de, func_8042E988_de with -1, func_8042302C_de and func_802998A8_de, and returns zero. */
extern void func_8029973C_de();
extern void func_8042E988_de(s32);

extern void func_802998A8_de();

s32 func_80423720_de(void) {
    func_8029973C_de();
    func_8042E988_de(-1);
    func_8042302C_de();
    func_802998A8_de();
    return 0;
}
