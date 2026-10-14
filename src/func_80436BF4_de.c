#include "types.h"
#include "shared/func_80421E70_eu_closed.h"
#include "span_16E000/code_804366C4.h"
/* Calls func_8029973C_de; when func_80299A08_de reports 0x60, passes the word at offset 0x28 of the object
   D_800E5690 points to to func_804367A8_de, then sets its word at 0x20 to -1 and calls func_8041A430_de
   on its first word with 2. Returns zero. */
extern struct State_func_80436BF4_de *D_800E5690;


extern void func_804367A8_de(s32);
s32 func_80436BF4_de(void) {
    struct State_func_80436BF4_de *state;
    func_8029973C_de();
#if defined(VERSION_DE)
    if (func_80299A08_de() == 0x5E) {
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    if (func_80299A08_de() == 0x60) {
#elif defined(VERSION_EU_X)
    if (func_80299A08_de() == 0x64) {
#endif
        func_804367A8_de(D_800E5690->item);
        state = D_800E5690;
        state->value = -1;
        func_8041A430_de((s32)state->first, 2);
    }
    return 0;
}
