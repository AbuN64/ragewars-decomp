#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804453C4.h"
#include "types.h"

/* Points a field's text at D_800E60E4 when the option D_800D0EBC is set and at D_800E60C8 otherwise, and returns
   zero: the label an option menu shows for that option. */


extern s32 D_800D0EBC;
extern char D_800E60E4[];
extern char D_800E60C8[];

s32 func_80446090_us_rev1(struct FieldRecAt14 *field) {
    if (D_800D0EBC != 0) {
        field->text = D_800E60E4;
    } else {
        field->text = D_800E60C8;
    }
    return 0;
}

/* Replaces D_800E63BC with what func_804423BC_de returns for the second argument, D_800E63BC, 1, 0, 1 and 1,
   and returns zero. */
extern s32 D_800E63BC;
extern s32 func_804423BC_de(void *, s32, s32, s32, s32, s32);

s32 func_804460C4_us_rev1(void *first, void *second) {
    D_800E63BC = func_804423BC_de(second, D_800E63BC, 1, 0, 1, 1);
    return 0;
}

/* Points a field's text at D_800E6100 when the option D_800E63BC is set and at D_800E611C otherwise, and returns
   zero: the label an option menu shows for that option. */


extern s32 D_800E63BC;
extern char D_800E6100[];
extern char D_800E611C[];

s32 func_8044610C_us_rev1(struct FieldRecAt14 *field) {
    if (D_800E63BC != 0) {
        field->text = D_800E6100;
    } else {
        field->text = D_800E611C;
    }
    return 0;
}

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_451D18,
   and returns one. */
extern char D_00451D18[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_80446140_us_rev1(void *first, void *second, void *third) {
    func_804427C4_de(third, second, D_00451D18);
    return 1;
}

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_451E38,
   and returns one. */
extern char D_00451E38[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_8044616C_us_rev1(void *first, void *second, void *third) {
    func_804427C4_de(third, second, D_00451E38);
    return 1;
}
