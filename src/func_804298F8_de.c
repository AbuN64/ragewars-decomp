#include "span_16E000/code_804290E8.h"
#include "types.h"

/* Calls func_8029973C_de and, unless func_8043C308_de reports one for the object D_800E4EF0 holds, calls
   func_804294C4_de, func_8042E988_de with -1 and func_802998A8_de. Returns zero. */
extern void *D_800E4EF0;
extern void func_8029973C_de();
extern s32 func_8043C308_de(void *);

extern void func_8042E988_de(s32);
extern void func_802998A8_de();

s32 func_804298F8_de(void) {
    func_8029973C_de();
    if (func_8043C308_de(D_800E4EF0) == 1) {
        return 0;
    }
    func_804294C4_de();
    func_8042E988_de(-1);
    func_802998A8_de();
    return 0;
}
