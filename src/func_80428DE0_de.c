#include "span_16E000/code_804264F0.h"
#include "types.h"

/* Calls func_8029973C_de and func_804273D4_de, then func_8042E988_de with 0xE, and returns zero. */
extern void func_8029973C_de();

extern void func_8042E988_de(s32);

s32 func_80428DE0_de(void) {
    func_8029973C_de();
    func_804273D4_de();
    func_8042E988_de(0xE);
    return 0;
}
