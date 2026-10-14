#include "span_16E000/code_804379C8.h"
#include "span_16E000/code_804379C8.h"
#include "types.h"

/* Calls func_8041B110_de with 0x3D0 and then 0x3D1, and returns zero. */
extern void func_8041B110_de(s32);

s32 func_80438618_eu(void) {
    func_8041B110_de(0x3D0);
    func_8041B110_de(0x3D1);
    return 0;
}
