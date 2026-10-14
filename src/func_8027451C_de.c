#include "span_1000/code_8027451C.h"
#include "types.h"

extern u32 D_80111D28;

s32 func_8027451C_de(void) {
    u32 temp_v1;

    temp_v1 = (D_80111D28 * 0xA84A5B53) + 0x58348C2D;
    D_80111D28 = temp_v1;
    return ((temp_v1 << 0x10) | (temp_v1 >> 0x10)) & 0x7FFFFFFF;
}
