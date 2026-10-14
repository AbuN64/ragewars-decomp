#include "span_1000/code_8022A274.h"
#include "types.h"




f32 func_8022AA44_de(SharedRecAt848 *arg0) {
    f32 value;
    f32 scaled;
    f32 initial;
    initial = arg0->value - 285.0f;
    if (arg0->override != 0) {
        value = 1.0f;
    } else {
        scaled = initial * 0.06666667f;
        if (scaled > 1.0f) {
            value = 1.0f;
        } else {
            value = scaled;
        }
    }
    return 1.0f - value;
}
