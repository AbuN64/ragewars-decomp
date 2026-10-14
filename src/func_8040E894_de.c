#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8040C780.h"
/* Resets the state and copies the two configured values after initialization. */

extern int D_800DEA60;
extern int D_800E2AB4_de;




extern struct Shape_typemap_165 D_8014D580;

void func_8040E894_de(void) {

    struct Shape_typemap_165 *state;

    func_8040CAB0_de();
    state = &D_8014D580;
    state->field_8 = 0;
    state->field_0 = 0;
    state->field_4 = D_800DEA60;
    state->field_C = D_800E2AB4_de;
}
