#include "include_asm.h"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU))
/* Points a field's text at the label for the state word D_80153778: one of 3 strings through the jump table
   jtbl_800E1098 for states 0 to 4, and D_800D7A0C for any other state. Returns zero. */


extern u32 D_80153778;

extern char D_800DE7BC[];

extern char D_800D7A0C[];

s32 func_8040BBC0_us(struct FieldRecAt14 *field) {
    u32 state = D_80153778;

    if (state >= 5) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto case_3;
        case 2: goto case_3;
        case 3: goto case_1;
        case 4: goto case_2;
        }
state_other:
    field->text = D_800D7A0C;
    goto done;
case_1:
    field->text = D_800D7A0C;
    goto done;
case_2:
    field->text = D_800D7A0C;
    goto done;
case_3:
    field->text = D_800DE7BC;
done:
    return 0;
}
#endif

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", rodata_unresolved_8040BC2C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E88BC);
#endif
