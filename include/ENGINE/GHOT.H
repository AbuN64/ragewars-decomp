#ifndef ENGINE_GHOT_H
#define ENGINE_GHOT_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"

struct AttachmentEffectBinding {
    u32 effectMask;
    u16 boneIndex;
    char pad4[0xE];
};
struct ModelAttachmentEffect {
    char pad0[0xC];
    u32 effectMask;
    u16 bone;
    u16 reserved;
};
struct AttachmentTable {
    s32 stride;
    u8 pad4[0x6A];
    u8 bytes[1];
};
struct AttachmentEffectActorView {
    char pad0[0x18];
    s32 *definition;
    char pad18[0x188];
    s8 action;
    char pad1A4[0xB];
    f32 effectThresholdValue;
    char pad1B0[0x24];
    PlayerWeaponStateView *player;
    char pad1D8[0x6C];
    Triple attachmentPosition;
    Triple attachmentDirection;
    Triple secondaryAttachmentPosition;
    char pad268[0x74];
    s32 attachmentEffectMask;
};
#endif
