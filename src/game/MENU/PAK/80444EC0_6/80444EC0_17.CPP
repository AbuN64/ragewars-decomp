#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/OPTIONEDITSTATE.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"

#if defined(VERSION_US_REV1)
/* Toggles the owner at offset 0x1C of the second argument between states 1 and 2 through its word
   at 0x5D0, leaving any other state alone; returns zero. */




s32 Pak_ToggleOwnerMode(void *unused, struct Holder *holder) {
    struct OwnerRecAt5D0 *owner = holder->owner;

    if (owner == 0) {
        return 0;
    }
    if (owner->value == 1) {
        owner->value = 2;
    } else if (owner->value == 2) {
        owner->value = 1;
    }
    return 0;
}

/* Points a field's text at D_800E6090 when the owner at offset 0x1C of the second argument has its
   word at 0x5D0 equal to one, and at D_800E60AC otherwise; returns zero, doing nothing without an
   owner. */







s32 Pak_UpdateOwnerModeText(struct FieldRecAt14 *field, struct Holder *holder) {
    if (holder->owner == 0) {
        return 0;
    }
    if (holder->owner->value == 1) {
        field->text = D_800E6090;
    } else {
        field->text = D_800E60AC;
    }
    return 0;
}

/* Replaces D_800D0EBC with what Pak_AdjustValue returns for the second argument, D_800D0EBC, 1, 0, 1 and 1,
   and returns zero. */
extern s32 Pak_AdjustValue(void *, s32, s32, s32, s32, s32);

s32 Pak_AdjustOwnerNotificationOption(void *first, void *second) {
    D_800D0EBC = Pak_AdjustValue(second, D_800D0EBC, 1, 0, 1, 1);
    return 0;
}
#endif
