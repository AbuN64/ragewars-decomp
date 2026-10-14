#include "span_16E000/code_8041B020.h"
#include "span_16E000/code_804366C4.h"
#include "types.h"
/* Calls func_8041B110_de with 0x13B, 0x13A and 0x13C in turn and returns zero. */
s32 func_80437414_de(void) {
#if defined(VERSION_DE)
    func_8041B110_de(0x139);
    func_8041B110_de(0x138);
    func_8041B110_de(0x13A);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    func_8041B110_de(0x13B);
    func_8041B110_de(0x13A);
    func_8041B110_de(0x13C);
#elif defined(VERSION_EU_X)
    func_8041B110_de(0x13F);
    func_8041B110_de(0x13E);
    func_8041B110_de(0x140);
#endif
    return 0;
}
