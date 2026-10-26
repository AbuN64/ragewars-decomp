#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_20.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"

/* Points a field's text at the label for the state word D_80153778: one of 3 strings through the jump table
   jtbl_800E1080 for states 0 to 4, and D_800D7A08 for any other state. Returns zero. */





s32 func_8040BAD4_de(struct FieldRecAt14 *field) {
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
    field->text = D_800D7A08;
    goto done;
case_1:
    field->text = D_800D7A08;
    goto done;
case_2:
    field->text = D_800D7A08;
    goto done;
case_3:
    field->text = D_800D39D4;
done:
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DBD14[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E88A4[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800ED6E4[1] = {
    0x00000000,
};
#endif
