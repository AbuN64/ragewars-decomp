#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/NODERECAT2A8.H"
#include "TYPES.H"

/* Points a field's text at D_800D7970 when the option D_80153734 is set and at D_800D797C otherwise, and returns
   zero: the label an option menu shows for that option. */



s32 func_8040B3DC_de(struct FieldRecAt14 *field) {
    if (D_80153734 != 0) {
        field->text = D_800D7970;
    } else {
        field->text = D_800D797C;
    }
    return 0;
}

/* Points a field's text at D_800D7974 when the option D_80153734 is set and at D_800D7980 otherwise, and returns
   zero: the label an option menu shows for that option. */



s32 func_8040B410_de(struct FieldRecAt14 *field) {
    if (D_80153734 != 0) {
        field->text = D_800D7974;
    } else {
        field->text = D_800D7980;
    }
    return 0;
}
