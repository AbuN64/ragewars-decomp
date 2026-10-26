#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"
#include "SCENE/802508E0_13.H"

/* Releases the object D_800E54A4 holds through Cache_FreeMemory, clears D_800E54A4, calls
   func_802A2360_de and func_802A2418_de with 1, and returns zero. */
extern void func_802A2360_de();
extern void func_802A2418_de(s32);

s32 func_804359D0_de(void) {
    Cache_FreeMemory(D_800E54A4);
    D_800E54A4 = 0;
    func_802A2360_de();
    func_802A2418_de(1);
    return 0;
}
