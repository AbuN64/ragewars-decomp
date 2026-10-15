#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802A25C4.h"
#include "types.h"




extern void *func_802A5734_de(void *arg0, s32 arg1);
extern void func_802732D0_de(char *object, f32 *output);
extern void func_802732EC_de(void *arg0, f32 *arg1);
extern void func_8027027C_de(void *arg0, f32 *arg1);
extern void func_80271F68_de(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2);
extern f32 func_802B72B0_de(f32);










void *func_802A25D0_de(void *arg0, void *arg1, void *arg2) {
    Vec3 sp10;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f1;
    void *temp_s1;
    char *var_s0;
    char *temp_s2;

    temp_s2 = func_802A5734_de(arg0, (s32)arg1);
    var_s0 = temp_s2;
    if (temp_s2 != 0) {
        ((ObjectLinks54 *)(arg1))->unk_50 = 0;
        ((ObjectLinksB4 *)(var_s0))->unk_8 = ((struct ObjectState20 *) ((ObjectLinks54 *) arg1)->unk_8)->unk_8;
        ((ObjectLinksB4 *)(var_s0))->unk_B0 = 0;
        func_802732D0_de(arg2, &((ObjectLinksB4 *)(var_s0))->unk_10.v0);
        if (((ObjectLinks54 *)(arg1))->unk_3C & 4) {
            func_802732EC_de(arg2, &((ObjectLinksB4 *)(var_s0))->unk_1C);
        } else {
            func_8027027C_de(arg2, &((ObjectLinksB4 *)(var_s0))->unk_28);
            func_8027027C_de(arg2, &((ObjectLinksB4 *)(var_s0))->unk_68);
        }
        temp_s1 = *(void **)var_s0;
        ((ObjectLinksB4 *)(var_s0))->unk_AC.v0 = 0;
        ((ObjectLinksB4 *)(var_s0))->unk_A8 = 0.0f;
        if (temp_s1 != 0) {
            func_80271F68_de(&sp10, &((ObjectLinksB4 *)(var_s0))->unk_10.v1, &((ObjectStateB0 *)(temp_s1))->unk_10);
            temp_f0 = func_802B72B0_de((sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z));
            ((ObjectStateB0 *)(temp_s1))->unk_AC = temp_f0;
            ((ObjectLinks54 *)(arg1))->unk_4C += temp_f0;
        }
        if (((struct ObjectState20 *) ((ObjectLinks54 *) arg1)->unk_8)->unk_1C == 0) {
            if (((ObjectLinks54 *)(arg1))->unk_4C > 0.0f) {
                var_f1 = 0.0f;
                var_s0 = ((ObjectLinks54 *)(arg1))->unk_40;
                if (var_s0 != 0) {
                    do {
                        ((ObjectLinksB4 *)(var_s0))->unk_A8 = var_f1 / ((ObjectLinks54 *)(arg1))->unk_4C;
                        temp_f0_2 = ((ObjectLinksB4 *)(var_s0))->unk_AC.v1;
                        var_s0 = ((ObjectLinksB4 *)(var_s0))->unk_4;
                        var_f1 += temp_f0_2;
                    } while (var_s0 != 0);
                }
            }
        } else {
            if (temp_s1 != 0) {
                ((ObjectLinks54 *)(arg1))->unk_28 += ((ObjectStateB0 *)(temp_s1))->unk_AC * D_800C5DC0_de;
            }
            ((ObjectLinksB4 *)(var_s0))->unk_A8 = ((ObjectLinks54 *)(arg1))->unk_28;
        }
    }
    return temp_s2;
}
