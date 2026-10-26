#include "include_asm.h"
#include "COMMON/EXTERNS_20.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"

/* Points a field's text at the label for the state word D_80153778: one of 4 strings through the jump table
   jtbl_800E1050 for states 0 to 4, and D_800D79A4 for any other state. Returns zero. */



extern char D_800D79A4[];

extern char D_800D398C[];

extern char D_800D39A0[];

extern char D_800D39B4[];

extern char D_800D39C8[];

s32 func_8040B9DC_de(struct FieldRecAt14 *field) {
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
    field->text = D_800D79A4;
    goto done;
case_1:
    field->text = D_800D398C;
    goto done;
case_2:
    field->text = D_800D39A0;
    goto done;
case_3:
    field->text = D_800D39B4;
    goto done;
case_4:
    field->text = D_800D39C8;
done:
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DBCE4[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E8874[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800ED6B4[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD034[1] = {
    0x00000000,
};
#endif
