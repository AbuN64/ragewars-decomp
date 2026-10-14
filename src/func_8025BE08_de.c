#include "span_1000/code_8025A3EC.h"
#include "types.h"

/* Releases every occupied slot of a record, other than the one its header marks as local, whose value at slot offset 0xA8 equals the given value: marks it active, clears its flag and, when its key differs from its owner's, restarts the owner's sound with the slot's sample and invalidates the slot. */









extern void func_802B2F00_de(void *sound, s16 sample);
extern s32 func_802B2620_de(void *sound);
extern void func_802B2F60_de(void *sound);

void func_8025BE08_de(RecordRecAt4V6 *record, s32 value) {
    s32 i;
    SlotRecAtB0 *slot = record->slots;

    for (i = 0; i < 17; slot++, i++) {
        if (slot->used != -1 && record->header->local != i && slot->value == value) {
            Owner_func_8025B5F0_de *owner = slot->owner;
            void *sound;

            slot->active = 1;
            slot->flag = 0;
            if (slot->key != owner->key) {
                sound = owner->sound;
                func_802B2F00_de(sound, owner->samples[slot->index]);
                if (func_802B2620_de(sound) != 0) {
                    func_802B2F60_de(sound);
                }
                slot->state = -1;
            }
        }
    }
}
