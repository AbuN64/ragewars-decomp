#include "COMMON/RECORD.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "RESMGR/802A23A4_6.H"
#include "SCENE/802508E0_13.H"

extern s32 Scene_AllocateMemory(s32 arg0);


void func_802A16F8_de(s32 arg0) {
    extern void func_802A1270_de(void);
    s32 size;

    size = (arg0 + 7) & ~7;
    D_800CD964[0] = Scene_AllocateMemory(size);
    D_800CD964[1] = Scene_AllocateMemory(size);
    D_80147054 = size;
    D_80147050_de = 0;
    func_802A1270_de();
    D_800CD960_de = 1;
}

void func_802A176C_de(void) {
    if (D_800CD960_de != 0) {
        Scene_FreeMemory(D_800CD964[0]);
        Scene_FreeMemory(D_800CD964[1]);
        D_800CD964[0] = 0;
        D_800CD964[1] = 0;
        D_800CD960_de = 0;
    }
}
