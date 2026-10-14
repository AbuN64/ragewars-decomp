#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802646F4.h"
#include "types.h"

extern void func_80264248_de(void *arg0);
extern void func_80285D30_de(s32 *);
extern s32 D_8010F328;
extern s32 D_8010EC90;




void func_80264854_de(s32 a) {
    ControllerProfile *var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = (ControllerProfile *)&D_8010F328;
    do {
        var_s0->mode = a;
        if (a == 0) {
            func_80264248_de(var_s0);
        }
        var_s1 += 1;
        var_s0 += 1;
    } while (var_s1 < 4);
    if (a == 0) {
        func_80285D30_de(&D_8010EC90);
    }
}
