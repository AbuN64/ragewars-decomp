#include "span_166000/code_80426310.h"
#include "span_16E000/code_8041B020.h"
#include "types.h"
/* Calls func_8041B110_de with 0x3D0 and then 0x3D1, and returns zero. */
s32 func_804377E8_de(void) {
#if defined(VERSION_DE)
    func_8041B110_de(0x3CA);
    func_8041B110_de(0x3CB);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    func_8041B110_de(0x3D0);
    func_8041B110_de(0x3D1);
#elif defined(VERSION_EU_X)
    func_8041B110_de(0x3D4);
    func_8041B110_de(0x3D5);
#endif
    return 0;
}
