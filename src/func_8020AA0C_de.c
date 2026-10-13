#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80209AE8.h"
#include "types.h"
/** Returns the difference between the constant after D_800C6E20 and func_80209AE8_de's result, scaled by D_800C6E28. */

extern f32 func_80209AE8_de(void);
extern f32 D_800C1D34_de;

f32 func_8020AA0C_de(void) {
    return (D_800C1D34_de - func_80209AE8_de()) * (D_800C6E28);
}
