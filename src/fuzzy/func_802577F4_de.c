#include "TYPES.H"

typedef struct SoundSlot {
    char pad00[0xC]; s32 id; char pad10[8]; s32 rate;
    char pad1C[4]; s16 volume;
    char pad22[2]; s32 pitch; char pad28[1]; u8 pan; char pad2A[2]; f32 gain;
    char pad30[0x70]; s32 playing; u32 flags; char padA8[0x1C]; s32 scaled; char padC8[4];
} SoundSlot;
typedef struct SoundManager { s32 header; SoundSlot slots[17]; } SoundManager;
typedef struct SoundContext {
    char pad00[0x84]; char voice[0x7E]; s16 pending;
    char pad104[0x34]; char sequence[0x1C80]; SoundManager manager;
    char pad2B48[0x54]; s32 volume;
    f32 gain; char pad2BA4[4]; f32 specialGain; char pad2BAC[0xC]; s32 scaled;
} SoundContext;
extern f32 D_800C3ED8_de;
extern void func_80259784_de(void *, s32);
extern s32 func_8025B854_de(void *, s16);
extern void func_8025B8BC_de(void *, s16);
extern void alSndpSetPitch(void *, s32);
extern void func_802B2DE0_de(void *, u8);
extern void alSndpSetPan(void *, u8);
extern void func_802B2F10_de(void *, s16);

s32 func_802577F4_de(SoundContext *context, s32 id) {
    s32 i;
    s16 index;
    SoundSlot *slot;
    u8 volume;
    f32 gain;
    if (id == -1) return -1;
    for (i = 0; i < 17; ++i)
        if (context->manager.slots[i].id == id) break;
    if (i == 17) i = -1;
    index = i;
    if (index == -1) return -1;
    if (index == 16) {
        func_80259784_de(context->sequence, 16);
        return -1;
    }
    slot = &context->manager.slots[index];
    if (slot->rate == 0 && !(slot->flags & 4)) {
        slot->flags |= 8;
        context->pending = -1;
        return 0;
    }
    if (!func_8025B854_de(&context->manager, index)) {
        alSndpSetPitch(context->voice, slot->pitch);
        volume = 127;
        if (slot->volume + context->volume < 128)
            volume = (u8)slot->volume + (u8)context->volume;
        func_802B2DE0_de(context->voice, volume);
        alSndpSetPan(context->voice, slot->pan);
        if (slot->flags & 0x200) gain = context->specialGain;
        else {
            gain = context->gain;
            if (slot->scaled && context->scaled) gain *= D_800C3ED8_de;
        }
        func_802B2F10_de(context->voice, (s16)(s32)((f32)slot->rate * gain * slot->gain));
        if (!slot->playing) func_8025B8BC_de(&context->manager, index);
    }
    context->pending = -1;
    return 0;
}
