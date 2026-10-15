#include "span_16E000/code_80409A88.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040A83C.h"
#include "types.h"
#include "common/unused.h"

/* Points a field's text at the label for the state word D_80153788: the second string through the jump table
   jtbl_800E0FC8 for states 0 to 15, and D_800D7824 for any other state. Returns zero. An earlier attempt misjudged this switch as a dispatch head whose
   cases lay outside the interval; its case bodies are inside it. */


extern u32 D_80153788;



s32 func_8040B27C_de(struct FieldRecAt14 *field) {
    u32 state = D_80153788;

    if (state >= 16) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto state_other;
        case 2: goto state_other;
        case 3: goto state_other;
        case 4: goto state_other;
        case 5: goto state_other;
        case 6: goto state_other;
        case 7: goto state_other;
        case 8: goto case_1;
        case 9: goto state_other;
        case 10: goto state_other;
        case 11: goto state_other;
        case 12: goto state_other;
        case 13: goto state_other;
        case 14: goto state_other;
        case 15: goto state_other;
        }
state_other:
    field->text = D_800D7824;
    goto done;
case_1:
    field->text = D_800D37FC;
done:
    return 0;
}
