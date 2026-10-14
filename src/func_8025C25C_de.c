#include "span_1000/code_8025A3EC.h"
#include "types.h"



s16 func_8025C25C_de(s16 arg0, s16 arg1) {
    f32 temp_f20;
    f32 temp_f21;
    temp_f21 = (f32)arg1;
    temp_f20 = (f32)arg0;
    return (s16)(s32)(func_80274A90_de(temp_f21, temp_f20) < 0.0f
                          ? temp_f20 - func_80274A90_de(temp_f21, temp_f20)
                          : temp_f20 + func_80274A90_de(temp_f21, temp_f20));
}
