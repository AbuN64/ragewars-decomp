#include "shared/gameplay_transition.h"
#include "span_C76B0/data.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022D944.h"
#include "types.h"
/* Reports whether the object's float at 0x718 is above the constant after D_800C7EC8. */








s32 func_8022DC1C_de(void *arg0) {
    f32 field = ((Shared_ActorView *)arg0)->speed;
    f32 konst = D_800C2DDC_de;
    s32 result = 1;
    if (!(konst < field)) {
        result = 0;
    }
    return result;
}
