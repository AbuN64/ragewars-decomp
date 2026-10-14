#include "span_1000/code_8024E914.h"
#include "span_1000/code_802508E0.h"
#include "types.h"

extern void *func_802507AC_de(ResourceOwner *owner,s32 index);
extern s32 *func_8026E27C_de(void **arg0, s32 arg1, s32 *arg2);
extern s32 func_80251F6C_de(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, void *arg7, s32 arg8);

extern s32 D_800CD3F0;
extern char D_00250C2C;
extern char D_800C3E40_de;




s32 *func_80250B24_de(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    struct ResourceBinding *o = (struct ResourceBinding *) arg0;
    void *temp_v0;
    s32 *var_s1;
    s32 ret2;

    var_s1 = arg3;
    temp_v0 = func_802507AC_de(arg0, arg2);
    if (temp_v0 != 0) {
        o->loadedResource = temp_v0;
        *var_s1 = (s32) temp_v0;
        var_s1 = func_8026E27C_de(temp_v0, arg1, var_s1 + 1);
        ret2 = func_80251F6C_de(0, o->registrationFlags | D_800CD3F0, temp_v0, (s32)o->resource, 8, arg0, &D_00250C2C, &D_800C3E40_de, 1);
        if (ret2 != 0) {
            *var_s1 = ret2;
            var_s1 += 1;
        }
    }
    return var_s1;
}
