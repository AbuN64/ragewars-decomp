#include "types.h"
#include "span_1000/code_802944E8.h"

/* Resets the menu viewport and selects the row identified by the owner's current index. */
extern void func_8028D90C_de(void);


void func_8029459C_de(int arg0) {
    func_8028D90C_de();
    func_80293998_de(arg0, ((Shared_Legacy_func_80294608_S1 *)arg0)->unk26DD8 + 0x259);
}
