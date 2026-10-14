#include "span_1000/code_8020EAE0.h"
#include "types.h"
#include "common/draft_fields_func_8020F5A4_de.h"


extern s32 func_8022AAD4_de(void *, s32);

s32 func_8020F5A4_de(void **arg0) {
    s32 temp_v0;
    void *temp_a0;

    temp_a0 = *arg0;
    temp_v0 = func_8022AAD4_de(temp_a0, (s32) ((struct MeasuredRecAt62EV1 *)(temp_a0))->value);
    switch (temp_v0) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 7;
        default:
            return 4;
    }
}
