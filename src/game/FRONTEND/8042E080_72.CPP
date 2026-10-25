#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "SCENE/802508E0_13.H"

/* Releases the object D_800E5550 holds through Scene_FreeMemory, clears D_800E5550, calls
   func_802A23C4_de with 2 and func_8026495C_de, and returns zero. */
extern void *D_800E5550;

extern void func_8026495C_de();

s32 func_80435C00_de(void) {
    Scene_FreeMemory(D_800E5550);
    D_800E5550 = 0;
    func_802A23C4_de(2);
    func_8026495C_de();
    return 0;
}
