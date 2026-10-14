#include "span_1000/code_8024E914.h"
#include "span_1000/code_802508E0.h"
#include "types.h"

extern void *func_802507AC_de(ResourceOwner *owner,s32 index);
extern void func_8026E158_de(void **arg0);
extern s32 func_80251F6C_de(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, void *arg7, s32 arg8);
extern void func_80253754_de(s32 arg0, s32 arg1);

extern s32 D_800CD3F0;
extern char D_00250C2C;
extern char D_800C3E40_de;




void func_802509A8_de(void *arg0) {
    struct ResourceBinding *o = (struct ResourceBinding *) arg0;
    void *temp_v0;
    s32 ret2;

    if (!(o->status & 0x40)) {
        temp_v0 = func_802507AC_de(arg0, o->variant);
        if (temp_v0 != 0) {
            func_8026E158_de((void **) temp_v0);
            ret2 = func_80251F6C_de(0, o->registrationFlags | D_800CD3F0, temp_v0, (s32)o->resource, 8, arg0, &D_00250C2C, &D_800C3E40_de, 0);
            if (ret2 != 0) {
                func_80253754_de(0, ret2);
            }
            func_80253754_de(0, (s32) temp_v0);
        }
    }
}
