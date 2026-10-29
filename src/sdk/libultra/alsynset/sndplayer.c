#include "sdk/libgultra.h"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

s16 alSndpAllocate(SoundPlayerSlotPool *pool, void *owner) {
    s32 count = pool->count;
    SoundPlayerSlot *slots = pool->slots;

    if (count > 0) {
        s16 i = 0;
        s16 state = 5;
        f32 value = g_soundPlayerSlotInitialValue;
        u8 flags = 0x40;
        do {
        s16 index = i;
        SoundPlayerSlot *slot = (SoundPlayerSlot *)(index * sizeof(*slots) + (u32)slots);
        if (slot->owner == 0) {
            slot->owner = owner;
            slot->state = state;
            slot->timer = 0;
            slot->value = value;
            slot->flags = flags;
            slot->extra = 0;
            slot->amount = ((((struct ALSound *)(owner))->sampleVolume * 0x7FFF) / 127);
            return index;
        }
        i++;
        } while ((s16)i < pool->count);
    }
    return -1;
}

/* ROM-grounded data: src/g_alSndpAllocateConstantWords_Sndplayer.c */
const unsigned int g_alSndpAllocateConstantWords[1] = {
    0x3F800000,
};

#if defined(VERSION_EU_X)
unsigned int k_SndplayerEncodedWordsBlock5[3] = {
    0xFFFF0000, 0x06A503E8, 0x06A601F4,
};
#endif

#if defined(VERSION_EU)
unsigned int k_SndplayerEncodedWordsBlock3[3] = {
    0x0022EC3C, 0x0022EC80, 0x0022EC3C,
};
#endif

#if defined(VERSION_DE)
unsigned int k_SndplayerEncodedWordsBlock2[3] = {
    0x002B2908, 0x002B2978, 0x002B2A60,
};
#endif
