#include "span_1000/code_802A0AC4.h"
#include "types.h"
/* Allocates the resource once and marks its five-word state ready. */
extern s32 D_801011B8;
extern s32 func_8025305C_de(s32 arg0);
extern s32 func_8025637C_de(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_802A109C_de(void) {
    s32 temp_v0;
    s32 *p2;
    if (D_800CD940_de[4] != 1) {
#if defined(VERSION_DE)
        D_800CD940_de[2] = 0x8BB01;
        temp_v0 = func_8025305C_de(0x8BB01);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        D_800CD940_de[2] = 0x8B245;
        temp_v0 = func_8025305C_de(0x8B245);
#elif defined(VERSION_EU_X)
        D_800CD940_de[2] = 0x90385;
        temp_v0 = func_8025305C_de(0x90385);
#endif
        D_800CD940_de[0] = temp_v0;
        func_8025637C_de(&D_801011B8, 0x200000, D_800CD940_de[2], temp_v0);
        p2 = &D_800CD940_de[0];
        p2[3] = 0;
        D_800CD940_de[4] = 1;
    }
}
