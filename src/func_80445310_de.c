#include "span_16E000/code_804453C4.h"
#include "common/unused.h"
#include "types.h"
#include "common/types_1dc8418c21db.h"

/* Points a field's text at one of D_800D7DD0, D_800D7DCC or D_800D7DC8 when the option byte D_801462E1 measured from 0x80 in steps of eight is zero, fifteen or minus sixteen, and otherwise at D_800D7DD4 with the step formatted into it, returning zero. Adapted from func_80445AB8 with D_801462E2 changed to D_801462E1 and the text slots D_800D7DD8..D_800D7DE4 changed to D_800D7DC8..D_800D7DD4. */

extern u8 D_801462E1;
extern char *D_800D7DC8;
extern char *D_800D7DCC;
extern char *D_800D7DD0;
extern char *D_800D7DD4;
extern char D_800E27E0[];
extern char D_800E27E8[];
extern s32 func_80441FE8_de(struct Field *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_80445310_de(struct Field *field) {
    s32 step = (D_801462E1 - 0x80) / 8;
    char *text;

    if (step == 0) {
        field->text = &D_800D7DD0;
    } else if (step == 15) {
        field->text = &D_800D7DCC;
    } else if (step == -16) {
        field->text = &D_800D7DC8;
    } else if (step > 0) {
        field->text = &D_800D7DD4;
        text = *field->text;
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800E27E0, step);
    } else {
        field->text = &D_800D7DD4;
        text = *field->text;
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800E27E8, step);
    }
    return 0;
}
