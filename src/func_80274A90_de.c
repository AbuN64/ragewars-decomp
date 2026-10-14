#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8027451C.h"
#include "types.h"





f32 func_80274A90_de(f32 arg0, f32 arg1) {
    f32 temp_f1;
    u32 temp_a1;
    s32 rotated;

    temp_a1 = (D_80111D24 * 0xA84A5B53) + 0x58348C2D;
    rotated = ((temp_a1 << 0x10) | (temp_a1 >> 0x10)) & 0x7FFFFFFF;
    rotated = rotated % 10000;
    temp_f1 = (f32)rotated * D_800C4998_de;
    D_80111D24 = temp_a1;
    return (temp_f1 * arg0) + ((D_800C499C_de - temp_f1) * arg1);
}
