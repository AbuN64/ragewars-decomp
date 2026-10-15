#include "span_16E000/code_8043E9A8.h"
#include "types.h"

/* Restarts sound: calls func_8025E214_de with -1, records what func_8025E2C4_de returns in D_800E63B0,
   passes D_800E63B8 to func_8025E2D4_de, calls func_8025E29C_de with 1, clears D_800E63B4, calls
   func_802649FC_de and then func_804427C4_de with the third argument, the second and D_451F58.
   Returns one. */
extern s32 D_800E63B0;
extern s32 D_800E63B4;
extern s32 D_800E63B8;
extern char D_00451094[];

extern s32 func_8025E2C4_de();

extern void func_8025E29C_de(s32);
extern void func_802649FC_de();
extern void func_804427C4_de(void *, void *, void *);

s32 func_8043ECC4_de(void *first, void *second, void *third) {
    func_8025E214_de(-1);
    D_800E63B0 = func_8025E2C4_de();
    func_8025E2D4_de(D_800E63B8);
    func_8025E29C_de(1);
    D_800E63B4 = 0;
    func_802649FC_de();
    func_804427C4_de(third, second, D_00451094);
    return 1;
}
