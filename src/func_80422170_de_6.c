#include "span_16E000/code_804221A0.h"
/* Calls func_802A2394_de and then func_80298368_de with 0x16. */
extern void func_802A2394_de();
extern void func_80298368_de(int);

void func_80422F9C_de(void) {
    func_802A2394_de();
    func_80298368_de(0x16);
}
