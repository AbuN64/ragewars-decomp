#include "span_1000/code_8025A3EC.h"
#include "types.h"

extern f32 D_800C3F90_de[];
extern f32 D_800C3F98_de;


f32 func_8025C2EC_de(u8 arg0, u8 arg1) {
    f32 first;
    f32 second;

    first = arg0 * D_800C3F90_de[1];
    second = arg1 * D_800C3F90_de[1];
    if (first == D_800C3F98_de) {
        return D_800C3F98_de;
    }
    if (second == first) {
        return first;
    }
    return first + func_80274564_de(second - first);
}
