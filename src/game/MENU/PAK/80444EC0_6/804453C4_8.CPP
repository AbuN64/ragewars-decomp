#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MENURECAT20V1.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/TEXTURE_REQUEST.H"

#if defined(VERSION_US_REV1)
/* Flips D_800D2AE0 between zero and one and returns zero. */

s32 Pak_ToggleTextureVariationBypass(void) {
    D_800D2AE0 = D_800D2AE0 == 0;
    return 0;
}

/* Points a field's text at D_800E6058 when the option D_800D2AE0 is set and at D_800E6074 otherwise, and returns
   zero: the label an option menu shows for that option. */



s32 Pak_UpdateTextureVariationBypassText(struct FieldRecAt14 *field) {
    if (D_800D2AE0 != 0) {
        field->text = D_800E6058;
    } else {
        field->text = D_800E6074;
    }
    return 0;
}
#endif
