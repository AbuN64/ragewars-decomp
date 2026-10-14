#include "span_1000/code_8024E130.h"
#include "types.h"

extern void func_802165F8_de(void *arg0, void *arg1, void *arg2);

f32 func_8024E73C_de(u8 *arg0) {
    char buf[0x40];
    if (*arg0 == 1) {
        func_802165F8_de(arg0, arg0 + 0x170, buf);
        return ((struct FloatState3C *) buf)->unk_38;
    }
    return 0.0f;
}
