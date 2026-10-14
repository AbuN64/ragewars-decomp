#include "shared/world.h"
#include "span_1000/code_80277444.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);
extern void func_8028FDF8_de(s32 arg0, s32 arg1);






s32 func_8028BC0C_de(void *arg0, void *arg1) {
    s32 bitIndex;
    void *field80;
    s32 field1B40C;
    void *temp_v0;
    u8 *temp_a0;
    s32 mask;

    bitIndex = ((Record14 *)arg1)->reserved13;
    field80 = ((Shared_World *)arg0)->bitSections;
    field1B40C = ((Shared_World *)arg0)->level;
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field80, 0), field1B40C), 2);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32) temp_v0, 1);
    temp_a0 = (u8 *) func_8028FDB4_de(temp_v0, 1);
    mask = 1 << (bitIndex & 7);
    if (bitIndex < 0) {
        bitIndex += 7;
    }
    return (temp_a0[bitIndex >> 3] & mask) != 0;
}
