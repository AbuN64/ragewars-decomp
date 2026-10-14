#include "types.h"

extern s32 D_80146918;
extern s32 D_801468F4;
extern s32 D_80146948;
extern s32 D_8015402C;
extern u8 D_801462D5;
extern void func_80298368_de(s32);

void func_804389F0_de(void) {
    s32 next;
    D_80146918 = 0;
    D_801468F4 = 0;
    if (D_80146948 == 1 && D_8015402C >= 35) {
        switch (D_801462D5) {
        case 4:
            next = 3;
            break;
        default:
            next = 3;
            break;
        case 1:
            next = 7;
            break;
        case 3:
            next = 3;
            break;
        }
    } else {
        next = 10;
    }
    func_80298368_de(next);
}
