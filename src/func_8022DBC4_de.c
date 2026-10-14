#include "span_C76B0/data.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022D944.h"
#include "types.h"
/* Returns the constant after D_800C7EC0 less the cube of its difference from the argument. */






f32 func_8022DBC4_de(f32 arg0) {
    f32 temp = D_800C2DD4_de - arg0;
    return D_800C2DD4_de - (temp * temp * temp);
}
