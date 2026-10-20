#ifndef AUDIO_EXTERNS_H
#define AUDIO_EXTERNS_H
#include "TYPES.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/UNUSED.H"
#include "AUDIO/ALSNDP.H"
/* Finds and releases the first occupied nonlocal sound slot with matching value, identifier and flag 0x40, returning its index or -1. */









extern s32 func_802B2620_de(void *sound);

static __inline__ void release(SlotCC *slot) {
    OwnerCode8025A3EC8025B5F0 *owner = slot->owner;
    void *sound;

    slot->active = 1;
    slot->flag = 0;
    if (slot->key != owner->key) {
        sound = owner->sound;
        func_802B2F00_de(sound, owner->samples[slot->index]);
        if (func_802B2620_de(sound) != 0) {
            alSndpStop(sound);
        }
        slot->state = -1;
    }
}
#endif
