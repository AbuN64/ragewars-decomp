#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"
#include "stddef.h"
/* Refreshes and probes a controller slot while holding the device lock. */
void func_80263740_de(); /* extern */
 /* extern */
void func_8026454C_de(); /* extern */
void func_80404018_de(s32); /* extern */
s32 func_80447F30_de(void *); /* extern */
extern s8 D_8010BBB8;
extern char D_8014D280[];
s32 func_80405290_de(s32 arg0) {
    s32 var_s0;
    if (D_801534F0[arg0] != 3) {
        return -2;
    }
    ((void (*)(s32))func_802644FC_de)(1);
    func_80263740_de();
    D_8010BBB8 = 2;
    var_s0 = func_80447F30_de((arg0 * 0x68) + D_8014D280);
    if (var_s0 != 0) {
        var_s0 = -1;
    }
    func_80404018_de(arg0);
    func_8026454C_de();
    return var_s0;
}
