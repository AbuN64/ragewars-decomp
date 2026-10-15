#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80246E34.h"
#include "types.h"



extern s32 *func_8024BFD4_de(char *arg0, s8 arg1);
extern s32 *func_8028FDB4_de(void *arg0, s32 arg1);
extern void func_80253754_de(s32 arg0, s32 *arg1);
extern void func_80271F68_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_8027207C_de(Vec3 *arg0);
extern void func_80271F9C_de(Vec3 *out, Vec3 *in, f32 scale);






void func_80247F18_de(char *arg0, char *arg1, char *arg2, Vec3 arg3,
                   Vec3 arg6, s32 arg9) {
    Vec3 sp10;
    Vec3 sp20;
    Vec3 sp30;
    s32 *temp_v0;
    s32 *temp_v0_2;
    s32 var_a0;
    s32 var_v1;
    char *var_a1;

    if (arg1[0x34] != 0x3C) {
      if (arg1[0x12] < 0x17) {
       temp_v0 = func_8024BFD4_de(arg0, arg0[1]);
       if (temp_v0 != 0) {
        temp_v0_2 = func_8028FDB4_de((void *)*temp_v0, 5);
        var_a1 = (char *)temp_v0_2 + ((arg9 * *temp_v0_2) + 8);
        var_a0 = arg9;
        if ((((u8 *)var_a1)[0x65] & 3) == 3) {
            func_80253754_de(0, temp_v0);
            return;
        }
        var_v1 = 0;
        do {
            *(arg1 + var_v1 + 0x14) = var_a0;
            var_a0 = var_a1[0x64];
            var_v1++;
            if (var_a0 != -1) {
                var_a1 = (char *)temp_v0_2 + ((var_a0 * *temp_v0_2) + 8);
            }
        } while (var_v1 < 4);
        func_80253754_de(0, temp_v0);
        arg1[0x12] = 0x19;
        sp20.x = ((Matrix *)arg2)->m[12];
        sp20.y = ((Matrix *)arg2)->m[13];
        sp20.z = ((Matrix *)arg2)->m[14];
        func_80271F68_de(&arg3, &arg3, &sp20);
        func_80272018_de(&sp10, &arg3, &arg6);
        func_8027207C_de(&sp10);
        func_8027207C_de(&arg3);
        func_8027207C_de(&arg6);
        func_80272018_de(&sp30, &sp10, &arg3);
        func_80271F9C_de(&sp10, &sp10,
                      (sp30.x * arg6.x) + (sp30.y * arg6.y) +
                          (sp30.z * arg6.z));
        func_8027207C_de(&sp10);
        ((Field_Vec_18 *)(arg1))->value = sp10;
       }
      }
    }
}
