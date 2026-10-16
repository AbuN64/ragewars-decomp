#include "span_16E000/code_804290E8.h"
#include "TYPES.H"
#include "span_1000/code_80297CD0.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_804366C4.h"

/* Calls func_8029973C_de, then passes 0xB to func_8042E988_de when func_802999A0_de reports 0xB for zero
   and -1 otherwise, then calls func_802998A8_de. Returns zero. */
extern void func_8029973C_de();

s32 func_804290F4_de(void) {
    func_8029973C_de();
    func_8042E988_de(func_802999A0_de(0) == 0xB ? 0xB : -1);
    func_802998A8_de();
    return 0;
}
