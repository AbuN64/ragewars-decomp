#include "shared/level_actor.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022C894.h"
#include "types.h"

extern void func_80274870_de(f32 *, f32, f32);
extern void func_802231D4_de(s32, s32, void *);
extern void func_802233F0_de(s32 arg0, s32 arg1, void *arg2);
extern s32 func_8024E62C_de(void *arg0);
extern void func_802227F4_de(void *, void *, s32);
extern char D_800CE7E4;
extern char D_800C9558_de;




void func_8022CE78_de(s32 arg0, s32 arg1) {
    func_80274870_de(arg0 + 0x72C, 0.0f, 0.25f);
    func_802231D4_de(arg0, arg1, &D_800CE7E4);
    func_802233F0_de(arg0, arg1, &D_800C9558_de);
    if (((Actor_func_8024A7A0_de *)arg1)->position1.y <= 0.0f) {
        if (func_8024E62C_de((void *) arg1) != 0) {
            func_802227F4_de((void *) arg0, (void *) arg1, 2);
        }
    }
}
