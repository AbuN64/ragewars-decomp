#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"

extern void *func_8028FDB4_de(void *, s32);
extern void func_8028FDF8_de(s32 arg0, s32 arg1);






s32 func_8028B988_de(void *arg0, struct LevelBitRecord *arg1) {
    s32 bitIndex;
    void *field80;
    s32 field1B40C;
    void *temp_v0;
    u8 *temp_a0;
    s32 mask;

    bitIndex = arg1->bitIndex;
    field80 = ((World_func_8028787C_de *)(arg0))->levels;
    field1B40C = ((World_func_8028787C_de *)(arg0))->level;
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field80, 0), field1B40C), 1);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32) temp_v0, 1);
    temp_a0 = (u8 *) func_8028FDB4_de(temp_v0, 1);
    mask = 1 << (bitIndex & 7);
    if (bitIndex < 0) {
        bitIndex += 7;
    }
    return (temp_a0[bitIndex >> 3] & mask) != 0;
}
