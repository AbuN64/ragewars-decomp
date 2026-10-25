#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"

/* Returns the index of the first of the seventeen 0x70-byte slots of D_800E3A54 whose leading word equals the argument, or zero when none does. */



extern struct SlotRecAt0V1 D_800E3A54[];

s32 Frontend_FindKeyIndex(s32 key) {
    s32 index = 0;
    s32 found = 0;
    s32 i;

    for (i = 0; i < 17 && !found; i++) {
        if (D_800E3A54[i].key == key) {
            found = 1;
            index = i;
        }
    }
    return index;
}
