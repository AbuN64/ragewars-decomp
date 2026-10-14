#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802508E0.h"
#include "types.h"

extern s32 D_800CD3F0;

extern void func_80253F8C_de(s32 arg0, s32 arg1);




void func_80250AD4_de(void *arg0) {
    struct ResourceBinding *binding = arg0;
    if (!(binding->status & 0x40) && (binding->colorFrame != D_800D297B)) {
        func_80253F8C_de(0, binding->registrationFlags | D_800CD3F0);
    }
}
