#include "COMMON/LISTHEADER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "LISTS/80279520.H"

/* Picks a random entry from a table of mask and id records ending in -1: every id whose mask shares
   a bit with flags and that func_80246A08_de finds for the owner is added to a weighted picker with
   weight 10, a zero mask ends the search once something was added, the first id is added when the
   picker is still empty, and the pick is returned when func_80246A08_de finds it, otherwise the first
   id. */





extern void func_8027985C_de(WeightedTable *);
extern s32 func_80246A08_de(s32, s32, s32);

s32 func_802166F4_de(s32 owner, s32 unused, struct IntPair *table, s32 flags) {
    WeightedTable picker;
    s32 first;
    s16 pick;

    func_8027985C_de(&picker);
    first = table->field_4;
    while (table->field_0 != -1) {
        if (table->field_0 == 0 && picker.count != 0) {
            goto choose;
        }
        if ((flags & table->field_0) && func_80246A08_de(owner, table->field_4, -1) != -1) {
            func_80279864_de(&picker, (s16) table->field_4, 10);
        }
        table++;
    }
    if (picker.count == 0) {
        func_80279864_de(&picker, (s16) first, 10);
    }
choose:
    pick = func_802798A8_de(&picker);
    if (func_80246A08_de(owner, pick, -1) == -1) {
        return first;
    }
    return pick;
}
