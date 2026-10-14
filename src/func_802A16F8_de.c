#include "span_1000/code_802A1264.h"
#include "types.h"

extern s32 func_8025305C_de(s32 arg0);
extern void func_802A1270_de(void);
extern s32 D_800CD964[2];
extern s32 D_80147054;
extern s32 D_80147050_de;
extern s32 D_800CD960_de;

void func_802A16F8_de(s32 arg0) {
    s32 size;

    size = (arg0 + 7) & ~7;
    D_800CD964[0] = func_8025305C_de(size);
    D_800CD964[1] = func_8025305C_de(size);
    D_80147054 = size;
    D_80147050_de = 0;
    func_802A1270_de();
    D_800CD960_de = 1;
}
