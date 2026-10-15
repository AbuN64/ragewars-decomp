/* Copies four selected player records and marks absent selections; -fno-strength-reduce reproduces the reference pointer induction exactly. */
#include "types.h"
void func_802A0724_de(void *, void *, s32);                       /* extern */
typedef struct { char pad[12]; s8 unkC, unkD; char rest[0x182]; } Record;
extern Record D_80102B00[];
extern void *D_800E54A4;                          /* const */

void func_804355E8_de(void) {
    Record *var_s1;
    s32 temp_s0;
    s32 temp_v1;
    s32 var_s2;
    s32 var_s3;
    void *temp_v0;

    s32 absent;
    var_s3 = 0;
    absent = -1;
    var_s1 = D_80102B00;
    var_s2 = 0;
    do {
        temp_v0 = D_800E54A4 + var_s2;
        temp_v1 = (*(s32 *)(temp_v0+0x2DF8));
        temp_s0 = (*(s32 *)(temp_v0+0x2DFC));
        if (temp_v1 != absent) {
            func_802A0724_de(var_s1, D_800E54A4 + ((temp_v1 * 0xB68) + 0x58) + ((temp_s0 * 0x190) + 0x18), 0x190);
            var_s1->unkC = (s8) temp_s0;
        } else {
            var_s1->unkD = (s8) temp_v1;
        }
        var_s1++;
        var_s3 += 1;
        var_s2 += 0xC;
    } while (var_s3 < 4);
}
