#include "span_1000/code_8027451C.h"
#include "types.h"

extern f32 D_800C4960_de[2];
extern f32 D_800D2988;

void func_80274870_de(f32 *value, f32 target, f32 rate) {
    f32 current;
    f32 next;

    current = *value;
    next = (target - current) * rate * D_800D2988;
    if (rate == D_800C4960_de[1]) {
        *value = target;
    } else if (current < target) {
        *value += next;
        if (target < *value) {
            *value = target;
        }
    } else if (target < current) {
        *value += next;
        if (*value < target) {
            *value = target;
        }
    }
}
