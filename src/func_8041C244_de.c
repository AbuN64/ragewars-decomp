#include "span_16E000/code_8041BEA8.h"
#include "types.h"

/* Advances the slot-dialog retry counter. Before the fourth attempt it updates
 * the dialog; later attempts start the transition and mark it active. */
extern s32 D_800DF4C0;
extern s32 D_8014ADA0;
extern void func_802A2394_de();
extern void func_8029973C_de();
extern void func_80298368_de(s32);
extern void func_8041BE90_de(void);

void func_8041C244_de(void) {
    D_800DF4C0++;
    if (D_800DF4C0 >= 4) {
        func_802A2394_de();
        func_8029973C_de();
        func_80298368_de(2);
        D_8014ADA0 = 1;
    } else {
        func_8041BE90_de();
    }
}
