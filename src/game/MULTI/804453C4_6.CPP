#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MENURECAT20V1.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_21.H"

#if defined(VERSION_US_REV1)
/* Points a field's text at D_800E60E4 when the option D_800D0EBC is set and at D_800E60C8 otherwise, and returns
   zero: the label an option menu shows for that option. */



s32 func_80446090_us_rev1(struct FieldRecAt14 *field) {
    if (D_800D0EBC != 0) {
        field->text = D_800E60E4;
    } else {
        field->text = D_800E60C8;
    }
    return 0;
}

/* Replaces D_800E63BC with what Pak_AdjustValue returns for the second argument, D_800E63BC, 1, 0, 1 and 1,
   and returns zero. */
extern s32 Pak_AdjustValue(void *, s32, s32, s32, s32, s32);

s32 func_804460C4_us_rev1(void *first, void *second) {
    D_800E63BC = Pak_AdjustValue(second, D_800E63BC, 1, 0, 1, 1);
    return 0;
}

/* Points a field's text at D_800E6100 when the option D_800E63BC is set and at D_800E611C otherwise, and returns
   zero: the label an option menu shows for that option. */



s32 func_8044610C_us_rev1(struct FieldRecAt14 *field) {
    if (D_800E63BC != 0) {
        field->text = D_800E6100;
    } else {
        field->text = D_800E611C;
    }
    return 0;
}

/* Calls Pak_AllocateMenu with the third argument, the second argument and the resource D_451D18,
   and returns one. */

s32 func_80446140_us_rev1(void *first, void *second, void *third) {
    Pak_AllocateMenu(third, second, D_00451D18);
    return 1;
}

/* Calls Pak_AllocateMenu with the third argument, the second argument and the resource D_451E38,
   and returns one. */

s32 func_8044616C_us_rev1(void *first, void *second, void *third) {
    Pak_AllocateMenu(third, second, D_00451E38);
    return 1;
}
#endif
