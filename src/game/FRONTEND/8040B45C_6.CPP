#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_20.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"

/* Points a field's text at the label for the state word D_80153778: one of 4 strings through the jump table
   jtbl_800E1068 for states 0 to 4, and D_800D79A8 for any other state. Returns zero. */








s32 Frontend_SelectPakOperationTextFive(struct FieldRecAt14 *field) {
    u32 state = D_80153778;

    if (state >= 5) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto case_1;
        case 2: goto case_2;
        case 3: goto case_3;
        case 4: goto case_4;
        }
state_other:
    field->text = D_800D79A8;
    goto done;
case_1:
    field->text = D_800D3990;
    goto done;
case_2:
    field->text = D_800D39A4;
    goto done;
case_3:
    field->text = D_800D39B8;
    goto done;
case_4:
    field->text = D_800D39CC;
done:
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DBCFC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E888C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800ED6CC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD04C[1] = {
    0x00000000,
};
#endif
