#include "types.h"
#include "shared/func_80421E70_eu_closed.h"
#include "span_16E000/code_804379C8.h"
/* Calls func_8029973C_de; when func_80299A08_de reports 0x73, sets the word at offset 0x14 of the object
   D_800E58A0 points to to -1 and calls func_8041A430_de on its first word with 2. Returns zero. */
extern struct State_func_80439128_de *D_800E58A0;


s32 func_80439128_de(void) {
    struct State_func_80439128_de *state;
    func_8029973C_de();
#if defined(VERSION_DE)
    if (func_80299A08_de() == 0x71) {
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    if (func_80299A08_de() == 0x73) {
#elif defined(VERSION_EU_X)
    if (func_80299A08_de() == 0x77) {
#endif
        state = D_800E58A0;
        state->value = -1;
        func_8041A430_de((s32)state->first, 2);
    }
    return 0;
}
