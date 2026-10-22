#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"
#include "SCENE/802508E0_13.H"

#if !(defined(VERSION_US))
/* Releases the object D_800E42D0 holds through func_802547E4_de, clears D_800E42D0, calls
   func_802A2360_de and func_802A23C4_de with 2, and returns zero. */
extern void *D_800E42D0;
extern void func_802A2360_de();


s32 func_80420B10_de(void) {
    func_802547E4_de(D_800E42D0);
    D_800E42D0 = 0;
    func_802A2360_de();
    func_802A23C4_de(2);
    return 0;
}

/* Calls func_802A23C4_de with 1 and func_8025DF34_de with 0xE78, and returns zero. */


s32 func_80420B50_de(void) {
    func_802A23C4_de(1);
    func_8025DF34_de(0xE78);
    return 0;
}
#endif
