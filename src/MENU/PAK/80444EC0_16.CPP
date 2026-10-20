#include "include_asm.h"
#include "MENU/OPTIONEDITSTATE.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/S1_2.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "COMMON/EXTERNS_21.H"
#include "SYSTEM_2/8025E280.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern s32 D_800E63B0, D_800E63B4, D_800E63B8;
extern char D_00451094[];
extern void func_802649FC_de(void);

s32 func_80445504_de(void *first, void *second, void *third) {
    func_8025E3A8_de();
    D_800E63B0 = func_8025E2C4_de();
    func_8025E2D4_de(D_800E63B8);
    func_8025E384_de();
    func_8025E29C_de(1);
    D_800E63B4 = 1;
    func_802649FC_de();
    func_804427C4_de(third, second, D_00451094);
    return 1;
}
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* Restarts sound: calls func_8025E3A8_de, records what func_8025E2C4_de returns in D_800E63B0, passes
   D_800E63B8 to func_8025E2D4_de, calls func_8025E384_de and func_8025E29C_de with 1, sets D_800E63B4,
   calls func_802649FC_de and then func_804427C4_de with the third argument, the second and D_451F58.
   Returns one. */


s32 func_80445504_de(void *first, void *second, void *third) {
    func_8025E3A8_de();
    D_800E63B0 = func_8025E2C4_de();
    func_8025E2D4_de(D_800E63B8);
    func_8025E384_de();
    func_8025E29C_de(1);
    D_800E63B4 = 1;
    func_802649FC_de();
    func_804427C4_de(third, second, D_00451094);
    return 1;
}
#endif
